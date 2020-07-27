//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLde�g�p����w�b�_�[
#include "GameL/UserData.h"
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	
	//�O���f�[�^�̓ǂݎ��i�X�e�[�W���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"test1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[20][20];
	int count = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 3;
			}
			else
			{
				count += 2;
			}
		}
	}
	

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"image.png", 10, TEX_SIZE_512);


	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_256);

	Draw::LoadImage(L"Stage1.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"WaterItem.png", 2, TEX_SIZE_64);//�������A�C�e��

	Draw::LoadImage(L"BubbleItem.png", 3, TEX_SIZE_64);//�����A�C�e��

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(); //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 1); //������I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);
}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}


