//�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define __HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSetumei::CSceneSetumei()
{

}

//�f�X�g���N�^
CSceneSetumei::~CSceneSetumei()
{

}

//�Q�[�����C�����������\�b�h
void CSceneSetumei::InitScene()
{
	//�o�͂����镶���O���t�B�b�N���쐬����
	Font::SetStrTex(L"Bubble Road Enter�L�[�������Ă�");
	Font::SetStrTex(L"��:�E�ړ�");
	Font::SetStrTex(L"��:���ړ�");
	Font::SetStrTex(L"�X�y�[�X�L�[:�W�����v");
	Font::SetStrTex(L"G�L�[:���Z�b�g");

	Font::SetStrTex(L"Enter�L�[�ŃQ�[���X�^�[�g�I");

	//�^�C�g���I�u�W�F�N�g�쐬
	Setumei* obj = new Setumei();    //�����I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10); //��l���I�u�W�F�N�g�o�^

}

//�Q�[�����C�����s�����\�b�h
void CSceneSetumei::Scene()
{

}