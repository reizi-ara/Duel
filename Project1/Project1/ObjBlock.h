#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

#include "GameL/DrawTexture.h"

//�I�u�W�F�N�g:�u���b�N&�w�i
class CObjBlock :public CObj
{

public:
	CObjBlock(int map[10][20]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	int r;
	int h;

	float m_tx;
	float m_ty;
	float m_x;
	float m_y;


	//�u���b�N�Ƃ̓����蔻��
	void BlockHit(
		float* x, float* y,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);

	void BlockBulletHit(
		float* x, float* y,  float* m_sx, float* m_sy,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);

	//��l���ƕǂ̌�������
	bool HeroBlockCrossPoint(
		float x, float y, float vx, float vy,
		float* out_px, float* out_py, float* out_len
	);

private:

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);

	int m_map[10][20];

	float Dot(float ax, float ay, float bx, float by);//����
	float Cross(float ax, float ay, float bx, float by);//�O��

	//���Ɛ��ƌ�������
	bool LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float* out_px, float* out_py
	);

};
