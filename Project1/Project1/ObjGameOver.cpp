//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjGameOver::CObjGameOver(int map)
{
	m_map = map;
}

//イニシャライズ
void CObjGameOver::Init()
{

}

//アクション
void CObjGameOver::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(m_map));
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}
	}

}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"失敗(´・ω・｀)", 90, 60, 80, c);
	Font::StrDraw(L"次は頑張ってね!", 20, 250, 100, c);
	Font::StrDraw(L"Enterキーを押してリトライする", 120, 500, 40, c);
	
}