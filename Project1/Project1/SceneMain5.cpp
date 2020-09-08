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
#include "SceneMain5.h"
#include "GameHead.h"
//コンストラクタ
CSceneMain5::CSceneMain5()
{

}

//デストラクタ
CSceneMain5::~CSceneMain5()
{

}

//ゲームメイン初期化メソッド
void CSceneMain5::InitScene()
{

	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"stage05.csv", &size);//外部データ読み込み

	int map[20][25];
	int count = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
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
	Draw::LoadImage(L"image.png", 10, TEX_SIZE_512);


	Draw::LoadImage(L"fallenAngel1.png", 0, TEX_SIZE_256);

	Draw::LoadImage(L"Stage1.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"WaterItem.png", 2, TEX_SIZE_64);//水生成アイテム

	Draw::LoadImage(L"BubbleItem.png", 3, TEX_SIZE_64);//生成アイテム

	Draw::LoadImage(L"GoalBlock.png", 4, TEX_SIZE_64);//ゴールブロック



	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(1); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 1); //作ったオブジェクトをオブジェクトマネージャーに登録

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//背景オブジェクト作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 5);
}

//ゲームメイン実行化メソッド
void CSceneMain5::Scene()
{

}