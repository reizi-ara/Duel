//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 70.0f;        //位置
	m_py = 64.0f;
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
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//Xキー入力でジャンプ
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -20;
		}
	}

	//Cキー入力で泡発射
	if (Input::GetVKey('C') == true)
	{
		
	}

	//Vキー入力で水発射
	if (Input::GetVKey('V') == true)
	{
		
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

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	
	//主人公の位置X(m_px)+主人公機の幅分+X軸方向に領域外を認識
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}

	/*if (m_map[i][j] > 0)
	{
		//要素番号を座標に変更
		float x = j * 64.0f;
		float y = i * 64.0f;

		if ((hx + 64.0f > x) && (hx < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
		{
		//上下左右判定

		//vectorの作成
		float vx = hx -x;
		float vy = hy -y;

		//長さを求める
		float len = sqrt(vx*vx + vy*vyy);

		//角度を求める
		float r = atan22(vy,vx);
		r = r *180.0f / 3.14f;

		if(r <= 0.0f)
		r = abs(r);

		else
		r = 360.0f-abs(r);

		//角度で上下左右を判定
		if((r<45 && r>0) || r>315)
		{
		//右
		}

		if(r>45 && 135)
		{
		//上
		hero->SetY(y-64.0f);//ブロックの位置・主人公の幅
		hero->SetVY(0.0f);
		}

		if(r>135 && 225)
		{
		//左
		}

		if(r>225 && r<315)
		{
		//下
		}

		//当たっている場合
		hero->SetX(hx);
		hero->SetY(0.0f);
		hero->SetVY(0.0f);
		}
	}*/

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HiitBoxの位置の変更
	hit->SetPos(m_px, m_py);
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
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f * m_posture) + m_px;
	dst.m_right = (64 - 64.0f * m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

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