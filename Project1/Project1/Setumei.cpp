//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "Setumei.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void Setumei::Init()
{

}

//アクション
void Setumei::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain(1));
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void Setumei::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"→:右移動", 120, 100, 50, c);
	Font::StrDraw(L"←:左移動", 120, 150, 50, c);
	Font::StrDraw(L"スペースキー:ジャンプ", 120, 200, 50, c);
	Font::StrDraw(L"Cキー:泡生成アイテム使用",120,250,50,c);
	Font::StrDraw(L"Gキー:リセット", 120, 300, 50, c);

	float s[4] = { 0.0f,1.0f,0.0f,1.0f };
	Font::StrDraw(L"Enterキーでゲームスタート！",60, 450, 50, s);

}