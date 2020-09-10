// 使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBubbleItem.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBubbleItem::CObjBubbleItem(float x, float y)
{
	m_ix = x;    //位置
	m_iy = y;

}

//イニシャライズ
void CObjBubbleItem::Init()
{
	m_vx = 0.0f;    //移動ベクトル
	m_vy = 0.0f;


	m_sx = 64;  //画像サイズをBlockHitに渡す用
	m_sy = 64;  


	


	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ix, m_iy, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 3);
}

//アクション
void CObjBubbleItem::Action()
{

	//ブロック・主人公情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);


	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//位置の更新
	m_ix += m_vx;
	m_iy += m_vy;

	//HiitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ix, m_iy);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		hero->Getflag(4);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);//が所有するHitBoxに消去する。
	}

	hit->SetPos(m_ix, m_iy);
	
	

}



//ドロー
void CObjBubbleItem::Draw()
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
