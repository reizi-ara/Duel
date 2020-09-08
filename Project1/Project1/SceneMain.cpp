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
CSceneMain::CSceneMain(int map)
{
	m_map = map;
}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	
	//�O���f�[�^�̓ǂݎ��i�X�e�[�W���j
	unique_ptr<wchar_t>p1;//�X�e�[�W���|�C���^�[
	int size1;//�X�e�[�W���̑傫��
	p1 = Save::ExternalDataOpen(L"stage01.csv", &size1);//�O���f�[�^�ǂݍ���

	int map1[20][25];
	int count1 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p1.get()[count1], L"%d", &w);

			map1[i][j] = w;

			if (w >= 10)
			{
				count1 += 3;
			}
			else
			{
				count1 += 2;
			}
		}
	}

	//�O���f�[�^�̓ǂݎ��i�X�e�[�W���j
	unique_ptr<wchar_t>p2;//�X�e�[�W���|�C���^�[
	int size2;//�X�e�[�W���̑傫��
	p2 = Save::ExternalDataOpen(L"stage02.csv", &size2);//�O���f�[�^�ǂݍ���

	int map2[20][25];
	int count2 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p2.get()[count2], L"%d", &w);

			map2[i][j] = w;

			if (w >= 10)
			{
				count2 += 3;
			}
			else
			{
				count2 += 2;
			}
		}
	}

	//�O���f�[�^�̓ǂݎ��i�X�e�[�W���j
	unique_ptr<wchar_t>p3;//�X�e�[�W���|�C���^�[
	int size3;//�X�e�[�W���̑傫��
	p3 = Save::ExternalDataOpen(L"stage03.csv", &size3);//�O���f�[�^�ǂݍ���

	int map3[20][25];
	int count3 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p3.get()[count3], L"%d", &w);

			map3[i][j] = w;

			if (w >= 10)
			{
				count3 += 3;
			}
			else
			{
				count3 += 2;
			}
		}
	}

	//�O���f�[�^�̓ǂݎ��i�X�e�[�W���j
	unique_ptr<wchar_t>p4;//�X�e�[�W���|�C���^�[
	int size4;//�X�e�[�W���̑傫��
	p4 = Save::ExternalDataOpen(L"stage04.csv", &size4);//�O���f�[�^�ǂݍ���

	int map4[20][25];
	int count4 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p4.get()[count4], L"%d", &w);

			map4[i][j] = w;

			if (w >= 10)
			{
				count4 += 3;
			}
			else
			{
				count4 += 2;
			}
		}
	}

	//�O���f�[�^�̓ǂݎ��i�X�e�[�W���j
	unique_ptr<wchar_t>p5;//�X�e�[�W���|�C���^�[
	int size5;//�X�e�[�W���̑傫��
	p5 = Save::ExternalDataOpen(L"stage05.csv", &size5);//�O���f�[�^�ǂݍ���

	int map5[20][25];
	int count5 = 1;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int w = 0;
			swscanf_s(&p5.get()[count5], L"%d", &w);

			map5[i][j] = w;

			if (w >= 10)
			{
				count5 += 3;
			}
			else
			{
				count5 += 2;
			}
		}
	}
	

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"image.png", 10, TEX_SIZE_512);


	Draw::LoadImage(L"fallenAngel1.png", 0, TEX_SIZE_256);

	Draw::LoadImage(L"Stage1.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"WaterItem.png", 2, TEX_SIZE_64);//�������A�C�e��

	Draw::LoadImage(L"BubbleItem.png", 3, TEX_SIZE_64);//�����A�C�e��

	Draw::LoadImage(L"GoalBlock.png", 4, TEX_SIZE_64);//�S�[���u���b�N

	

	
	if (m_map == 1)
	{
		//block�I�u�W�F�N�g�쐬
		CObjBlock* objb = new CObjBlock(map1);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 2)
	{
		//block�I�u�W�F�N�g�쐬
		CObjBlock* objb = new CObjBlock(map2);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 3)
	{
		//block�I�u�W�F�N�g�쐬
		CObjBlock* objb = new CObjBlock(map3);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 4)
	{
		//block�I�u�W�F�N�g�쐬
		CObjBlock* objb = new CObjBlock(map4);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	if (m_map == 5)
	{
		//block�I�u�W�F�N�g�쐬
		CObjBlock* objb = new CObjBlock(map5);
		Objs::InsertObj(objb, OBJ_BLOCK, 9);
	}
	

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 1);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(m_map); //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 5); //������I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}


