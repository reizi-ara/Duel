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

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ix, m_iy, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 3);

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
