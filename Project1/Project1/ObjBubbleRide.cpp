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
	bx = x;    //�ʒu
	by = y;

}

//�C�j�V�����C�Y
void CObjBubbleRide::Init()
{
	
}

//�A�N�V����
void CObjBubbleRide::Action()
{

	



}


//�h���[
void CObjBubbleRide::Draw()
{

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	float c[4] = { 1,1,1,1 };


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
