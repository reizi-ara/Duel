// �g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBubbleRide.h"

//�R���X�g���N�^
CObjBubbleRide::CObjBubbleRide(float x, float y)
{
	m_ix = x;    //�ʒu
	m_iy = y;

}

//�C�j�V�����C�Y
void CObjBubbleRide::Init()
{
	//block�Ƃ̏Փˏ�ԗp�m�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

}

//�A�N�V����
void CObjBubbleRide::Action()
{
	/*//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
	if ((*x + 7 > bx) && (*x < bx + 32) && (*y + 11 > by) && (*y < by + 32))
	{
		//�㉺���E����

		//vector�̍쐬
		float rvx = *x - bx;
		float rvy = *y - by;

		//���������߂�
		float len = sqrt(rvx * rvx + rvy * rvy);

		//�p�x�����߂�
		float r = atan2(rvy, rvx);
		r = r * 180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//len��������̒����̂��Z���ꍇ����ɓ���
		if (len < 88.0f)
		{
			//�p�x�ŏ㉺���E�𔻒�
			if ((r < 45 && r>0) || r > 315)
			{
				//�E
				*right = true;
				*x = bx + 32;
				*vx = -(*vx) * 0.1f;
			}
			if (r > 45 && r < 135)
			{
				//��
				*down = true;
				*y = by - 32;
				//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
				*vy = 0.0f;
			}
			if (r > 135 && r < 225)
			{
				//��
				*left = true;
				*x = bx - 32;
				*vx = -(*vx) * 0.1f;
			}
			if (r > 225 && r < 315)
			{
				//��
				*up = true;
				*y = by + 32;
				if (*vy < 0)
				{
					*vy = 0.0f;
				}
			}
		}
	}
}*/
}



//�h���[
void CObjBubbleRide::Draw()
{

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_iy;
	dst.m_left = 0.0f + m_ix;
	dst.m_right = 32.0f + m_ix;
	dst.m_bottom = 32.0f + m_iy;


	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);

}
