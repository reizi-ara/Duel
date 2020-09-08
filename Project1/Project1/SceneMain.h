#pragma once
//使用するネームスペース
#include"GameL/SceneManager.h"

using namespace GameL;

class CSceneMain :public CScene
{
	public:
		CSceneMain(int map);
		~CSceneMain();
		void InitScene();
		void Scene();
	private:
		int m_map;
};