//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjClear::CObjClear(int map)
{
	m_map = map;
}

//�C�j�V�����C�Y
void CObjClear::Init()
{
	m_key_flag = false;

}

//�A�N�V����
void CObjClear::Action()
{
	//�G���^�[�L�[�������ăV�[���F���̃X�e�[�W�Ɉڍs����
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

//�h���[
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"STAGE CLEAR",120,200,100,c);
	Font::StrDraw(L"Enter�L�[�������Ď��̃X�e�[�W��GO�I",60,450,40,c);


}