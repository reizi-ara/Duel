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
	bx = x;    //位置
	by = y;

}

//イニシャライズ
void CObjBubbleRide::Init()
{
	
}

//アクション
void CObjBubbleRide::Action()
{

	



}


//ドロー
void CObjBubbleRide::Draw()
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
	dst.m_top = 0.0f + m_iy;
	dst.m_left = 0.0f + m_ix;
	dst.m_right = 32.0f + m_ix;
	dst.m_bottom = 32.0f + m_iy;


	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);

}
