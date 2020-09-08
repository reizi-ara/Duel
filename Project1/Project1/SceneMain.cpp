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
CSceneMain::CSceneMain(int map)
{
	m_map = map;
}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	
	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p1;//ステージ情報ポインター
	int size1;//ステージ情報の大きさ
	p1 = Save::ExternalDataOpen(L"stage01.csv", &size1);//外部データ読み込み

	int map1[20][25];
	int count1 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p1.get()[count1], L"%d", &w);

			map1[i][j] = w;

			if (w >= 10)
			{
				count1 += 3;
			}
			else
			{
				count1 += 2;
			}
		}
	}

	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p2;//ステージ情報ポインター
	int size2;//ステージ情報の大きさ
	p2 = Save::ExternalDataOpen(L"stage02.csv", &size2);//外部データ読み込み

	int map2[20][25];
	int count2 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p2.get()[count2], L"%d", &w);

			map2[i][j] = w;

			if (w >= 10)
			{
				count2 += 3;
			}
			else
			{
				count2 += 2;
			}
		}
	}

	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p3;//ステージ情報ポインター
	int size3;//ステージ情報の大きさ
	p3 = Save::ExternalDataOpen(L"stage03.csv", &size3);//外部データ読み込み

	int map3[20][25];
	int count3 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p3.get()[count3], L"%d", &w);

			map3[i][j] = w;

			if (w >= 10)
			{
				count3 += 3;
			}
			else
			{
				count3 += 2;
			}
		}
	}

	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p4;//ステージ情報ポインター
	int size4;//ステージ情報の大きさ
	p4 = Save::ExternalDataOpen(L"stage04.csv", &size4);//外部データ読み込み

	int map4[20][25];
	int count4 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p4.get()[count4], L"%d", &w);

			map4[i][j] = w;

			if (w >= 10)
			{
				count4 += 3;
			}
			else
			{
				count4 += 2;
			}
		}
	}

	//外部データの読み取り（ステージ情報）
	unique_ptr<wchar_t>p5;//ステージ情報ポインター
	int size5;//ステージ情報の大きさ
	p5 = Save::ExternalDataOpen(L"stage05.csv", &size5);//外部データ読み込み

	int map5[20][25];
	int count5 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p5.get()[count5], L"%d", &w);

			map5[i][j] = w;

			if (w >= 10)
			{
				count5 += 3;
			}
			else
			{
				count5 += 2;
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

	

	
	if (m_map == 1)
	{
		//blockオブジェクト作成
		CObjBlock* objb = new CObjBlock(map1);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 2)
	{
		//blockオブジェクト作成
		CObjBlock* objb = new CObjBlock(map2);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 3)
	{
		//blockオブジェクト作成
		CObjBlock* objb = new CObjBlock(map3);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 4)
	{
		//blockオブジェクト作成
		CObjBlock* objb = new CObjBlock(map4);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 5)
	{
		//blockオブジェクト作成
		CObjBlock* objb = new CObjBlock(map5);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	

	//背景オブジェクト作成
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(m_map); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 5); //作ったオブジェクトをオブジェクトマネージャーに登録

}

//ゲームメイン実行化メソッド
void CSceneMain::Scene()
{

}


