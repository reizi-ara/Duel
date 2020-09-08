//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneGameOver.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver(int map)
{
	m_map = map;
}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���O���t�B�b�N���쐬����
	Font::SetStrTex(L"���s(�L�E�ցE�M) ���͊撣���Ă�! Enter�L�[�������ă��g���C����");

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver(m_map);
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//�Q�[�����C�����s�����\�b�h
void CSceneGameOver::Scene()
{

}