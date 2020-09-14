//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "Setumei.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void Setumei::Init()
{

}

//�A�N�V����
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

//�h���[
void Setumei::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"��:�E�ړ�", 120, 100, 50, c);
	Font::StrDraw(L"��:���ړ�", 120, 150, 50, c);
	Font::StrDraw(L"�X�y�[�X�L�[:�W�����v", 120, 200, 50, c);
	Font::StrDraw(L"C�L�[:�A�����A�C�e���g�p",120,250,50,c);
	Font::StrDraw(L"G�L�[:���Z�b�g", 120, 300, 50, c);

	float s[4] = { 0.0f,1.0f,0.0f,1.0f };
	Font::StrDraw(L"Enter�L�[�ŃQ�[���X�^�[�g�I",60, 450, 50, s);

}