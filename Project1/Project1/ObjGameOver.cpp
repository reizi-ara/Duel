//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjGameOver::CObjGameOver(int map)
{
	m_map = map;
}

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}

//�A�N�V����
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

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"���s(�L�E�ցE�M)", 90, 60, 80, c);
	Font::StrDraw(L"���͊撣���Ă�!", 20, 250, 100, c);
	Font::StrDraw(L"Enter�L�[�������ă��g���C����", 120, 500, 40, c);
	
}