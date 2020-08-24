#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：タイトル
class CSceneGameOver :public CScene
{
public:
	CSceneGameOver();
	~CSceneGameOver();
	void InitScene();//タイトルの初期化メソッド
	void Scene();    //タイトルの実行中メソッド

private:
};