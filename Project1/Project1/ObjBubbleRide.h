#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�A�C�e��
class CObjBubbleRide :public CObj
{
public:
	CObjBubbleRide(float x, float y);
	~CObjBubbleRide() {};
	void Init();	 //�C�j�V�����C�Y
	void Action();	 //�A�N�V����
	void Draw();	 //�h���[

	bool Getflag() { return flag; }

	

private:
	float bx, by;

	float m_vx; //�ړ��x�N�g��
	float m_vy;

	float m_sx;  //�摜�T�C�Y�p
	float m_sy;


	float m_ix;//�ʒu
	float m_iy;

	float  m_posture;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int hp;
	int hp_max;
	int hp_now;
	float hp_time;

	float top;
	float left;
	float right;
	float bottom;

	int m_block_type;

	float h_x;//�q�[���[�̈ʒu�擾�p�ϐ�
	float h_y;//�q�[���[�̈ʒu�擾�p�ϐ�

	bool flag;

};
