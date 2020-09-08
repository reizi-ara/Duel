//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHero::CObjHero(int map)
{
	m_map = map;
}

//イニシャライズ
void CObjHero::Init()
{
	m_px = 70.0f;        //位置
	m_py = 550.0f;
	m_vx = 0.0f;        //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;   //右向き0.0f　左向き1.0f
	m_b = 0.0f;         //泡を出す
	m_w = 0.0f;         //水を出す

	m_ani_time = 0;
	m_ani_frame = 1;     //静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;  //アニメーション間隔幅

	//blockとの衝突状態確認用
	bool m_hit_up = false;
	bool m_hit_down = false;
	bool m_hit_left = false;
	bool m_hit_right = false;

	
	m_block_type = 0;     //踏んでいるblockの種類を確認用

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	
	

	//Xキー入力でジャンプ
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -10;
		}
	}
	if (flagb==true)
	{
		//Cキー入力で泡発射
		if (Input::GetVKey('C') == true)
		{
			//泡アイテムオブジェクト作成
			CObjBubbleRide* obj_b = new CObjBubbleRide(m_px, m_py);
			Objs::InsertObj(obj_b, OBJ_ITEM, 3);
		}
	}
	

	//Vキー入力で水発射
	if (Input::GetVKey('V') == true)
	{
		//水アイテムオブジェクト作成
		CObjWaterItem* obj_w = new CObjWaterItem(m_px, m_py);
		Objs::InsertObj(obj_w, OBJ_ITEM, 2);
	}

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;  //キー入力が無い場合は静止フレームにする
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);
	
	//主人公の位置X(m_px)+主人公機の幅分+X軸方向に領域外を認識
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type);

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HiitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	//主人公が画面下に落ちたらゲームオーバーに移行
	if (m_py > 1000.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//主人公のHPがゼロになった時ゲームオーバー画面に移行する
		Scene::SetScene(new CSceneGameOver(m_map));
	}

	//主人公が当たった時にtrueにする
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		//プレイヤーに当たってtrueになったらfalseにし、消す
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	if (m_block_type == 5)//主人公がゴールブロックを踏むとステージ移行
	{
		this->SetStatus(false);//主人公オブジェクト削除
		Hits::DeleteHitBox(this);//ヒットボックス削除

		Scene::SetScene(new CSceneClear(m_map));
	}

	hit->SetPos(m_px , m_py);

}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};

	//描画カラー情報　
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f ;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (32.0f * m_posture) + m_px;
	dst.m_right = (32 - 32.0f * m_posture) + m_px;
	dst.m_bottom = 32.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//交点
	float cc[4] = { 1.0f,0.0f,0.0f,1.0f };
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = 320.0f + 64.0f;
	src.m_bottom = 64.0f;
	dst.m_top = py;
	dst.m_left = px;
	dst.m_right = dst.m_left + 10.0f;
	dst.m_bottom = dst.m_top + 10.0f;
	Draw::Draw(0, &src, &dst, cc, 0.0f);
}