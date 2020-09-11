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
CSceneSetumei::CSceneSetumei()
{

}

//デストラクタ
CSceneSetumei::~CSceneSetumei()
{

}

//ゲームメイン初期化メソッド
void CSceneSetumei::InitScene()
{
	//出力させる文字グラフィックを作成する
	Font::SetStrTex(L"Bubble Road Enterキーを押してね");
	Font::SetStrTex(L"→:右移動");
	Font::SetStrTex(L"←:左移動");
	Font::SetStrTex(L"スペースキー:ジャンプ");
	Font::SetStrTex(L"Gキー:リセット");

	Font::SetStrTex(L"Enterキーでゲームスタート！");

	//タイトルオブジェクト作成
	Setumei* obj = new Setumei();    //説明オブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10); //主人公オブジェクト登録

}

//ゲームメイン実行中メソッド
void CSceneSetumei::Scene()
{

}