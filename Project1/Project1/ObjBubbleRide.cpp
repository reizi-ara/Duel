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

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_ix, m_iy, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 3);

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
