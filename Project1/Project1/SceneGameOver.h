#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�^�C�g��
class CSceneGameOver :public CScene
{
public:
	CSceneGameOver(int map);
	~CSceneGameOver();
	void InitScene();//�^�C�g���̏��������\�b�h
	void Scene();    //�^�C�g���̎��s�����\�b�h

private:
	int m_map;
};