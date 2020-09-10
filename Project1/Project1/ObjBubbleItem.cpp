// �g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjBubbleItem.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBubbleItem::CObjBubbleItem(float x, float y)
{
	m_ix = x;    //�ʒu
	m_iy = y;

}

//�C�j�V�����C�Y
void CObjBubbleItem::Init()
{
	m_vx = 0.0f;    //�ړ��x�N�g��
	m_vy = 0.0f;


	m_sx = 64;  //�摜�T�C�Y��BlockHit�ɓn���p
	m_sy = 64;  


	


	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_ix, m_iy, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 3);
}

//�A�N�V����
void CObjBubbleItem::Action()
{

	//�u���b�N�E��l�����������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);


	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�ʒu�̍X�V
	m_ix += m_vx;
	m_iy += m_vy;

	//HiitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ix, m_iy);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		hero->Getflag(4);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);//�����L����HitBox�ɏ�������B
	}

	hit->SetPos(m_ix, m_iy);
	
	

}



//�h���[
void CObjBubbleItem::Draw()
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
