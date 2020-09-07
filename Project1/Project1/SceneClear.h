#pragma once
//使用するヘッダファイル
#include "GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:クリア
class CSceneClear :public CScene
{
public:
	CSceneClear();
	~CSceneClear();
	void InitScene();
	void Scene();

private:
	bool m_key_flag;//


};