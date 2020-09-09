// 使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBubbleRide.h"

//コンストラクタ
CObjBubbleRide::CObjBubbleRide(float x, float y)
{
	m_ix = x;    //位置
	m_iy = y;

}

//イニシャライズ
void CObjBubbleRide::Init()
{
	//blockとの衝突状態用確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

}

//アクション
void CObjBubbleRide::Action()
{
	/*//オブジェクトとブロックの当たり判定
	if ((*x + 7 > bx) && (*x < bx + 32) && (*y + 11 > by) && (*y < by + 32))
	{
		//上下左右判定

		//vectorの作成
		float rvx = *x - bx;
		float rvy = *y - by;

		//長さを求める
		float len = sqrt(rvx * rvx + rvy * rvy);

		//角度を求める
		float r = atan2(rvy, rvx);
		r = r * 180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//lenがある一定の長さのより短い場合判定に入る
		if (len < 88.0f)
		{
			//角度で上下左右を判定
			if ((r < 45 && r>0) || r > 315)
			{
				//右
				*right = true;
				*x = bx + 32;
				*vx = -(*vx) * 0.1f;
			}
			if (r > 45 && r < 135)
			{
				//上
				*down = true;
				*y = by - 32;
				//種類を渡すのスタートとゴールのみ変更する
				*vy = 0.0f;
			}
			if (r > 135 && r < 225)
			{
				//左
				*left = true;
				*x = bx - 32;
				*vx = -(*vx) * 0.1f;
			}
			if (r > 225 && r < 315)
			{
				//下
				*up = true;
				*y = by + 32;
				if (*vy < 0)
				{
					*vy = 0.0f;
				}
			}
		}
	}
}*/
}



//ドロー
void CObjBubbleRide::Draw()
{

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;


	//表示位置の設定
	dst.m_top = 0.0f + m_iy;
	dst.m_left = 0.0f + m_ix;
	dst.m_right = 32.0f + m_ix;
	dst.m_bottom = 32.0f + m_iy;


	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);

}
