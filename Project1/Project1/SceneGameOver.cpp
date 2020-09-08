//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver(int map)
{
	m_map = map;
}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字グラフィックを作成する
	Font::SetStrTex(L"失敗(´・ω・｀) 次は頑張ってね! Enterキーを押してリトライする");

	//タイトルオブジェクト作成
	CObjGameOver* obj = new CObjGameOver(m_map);
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//ゲームメイン実行中メソッド
void CSceneGameOver::Scene()
{

}