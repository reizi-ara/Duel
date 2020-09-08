//デバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define __HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字グラフィックを作成する
	Font::SetStrTex(L"Bubble Road Enterキーを押してね");

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();    //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10); //主人公オブジェクト登録

}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}