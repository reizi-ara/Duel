//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjClear::CObjClear(int map)
{
	m_map = map;
}

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;

}

//アクション
void CObjClear::Action()
{
	//エンターキーを押してシーン：次のステージに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(m_map+1));
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}

	}

}

//ドロー
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"STAGE CLEAR",120,200,100,c);
	Font::StrDraw(L"Enterキーを押して次のステージへGO！",60,450,40,c);


}