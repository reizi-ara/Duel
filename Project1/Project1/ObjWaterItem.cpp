// 使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjWaterItem.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjWaterItem::CObjWaterItem(float x, float y)
{
	m_ix = x;    //位置
	m_iy = y;

}

//イニシャライズ
void CObjWaterItem::Init()
{
	m_vx = 0.0f;    //移動ベクトル
	m_vy = 0.0f;


	m_sx = 64;  //画像サイズをBlockHitに渡す用
	m_sy = 64;


	//blockとの衝突状態用確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;



	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ix, m_iy, 36, 30, ELEMENT_ITEM, OBJ_ITEM, 1);
}

//アクション
void CObjWaterItem::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);



	//摩擦の計算   -(運動energy X 摩擦係数)
	m_ix += -(m_vx * 0.098);

	


	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロックとの当たり判定
	/*CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_ix, &m_iy,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type);*/

	

	//位置の更新
	m_ix += m_vx;
	m_iy += m_vy;


	//HiitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ix, m_iy);


	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);//が所有するHitBoxに消去する。

	}
}

//ドロー
void CObjWaterItem::Draw()
{

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	float c[4] = { 1,1,1,1 };


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;


	//表示位置の設定
	dst.m_top = 0.0f +m_iy;
	dst.m_left = 0.0f+m_ix;
	dst.m_right = 32.0f+m_ix;
	dst.m_bottom = 32.0f+m_iy;


	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

}
