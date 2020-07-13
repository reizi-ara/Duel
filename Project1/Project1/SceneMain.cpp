//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLde使用するヘッダー
#include "GameL/UserData.h"
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	
	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"test.csv", &size);//外部データ読み込み

	int map[10][20];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 3;
			}
			else
			{
				count += 2;
			}
		}
	}
	

	//グラフィック読み込み
	//Draw::LoadImage(L"image.png", 0, TEX_SIZE_256);

	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_256);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 1); //作ったオブジェクトをオブジェクトマネージャーに登録

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}

//ゲームメイン実行化メソッド
void CSceneMain::Scene()
{

}


