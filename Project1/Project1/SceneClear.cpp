//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneClear::CSceneClear(int map)
{
	m_map = map;
}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化メソッド
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"STAGE CLEAR");
	Font::SetStrTex(L"Enterキーを押して次のステージへGO！");

	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear(m_map);//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);//クリアオブジェクト登録
}

//実行中メソッド
void CSceneClear::Scene()
{


}