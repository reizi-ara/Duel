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


	//block�Ƃ̏Փˏ�ԗp�m�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;



	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_ix, m_iy, 36, 30, ELEMENT_ITEM, OBJ_ITEM, 1);
}

//�A�N�V����
void CObjBubbleItem::Action()
{

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻��
	/*CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_ix, &m_iy,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type);*/


		//�ʒu�̍X�V
	m_ix += m_vx;
	m_iy += m_vy;

	float line =  500;

	int ex = ((int)line) / 64;

	/*if (m_map[])
	{
		CObjBubbleItem* obj = new CObjBubbleItem(500.0f, 50);
		Objs::InsertObj(obj, OBJ_ITEM, 1);
	}*/

	//HiitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);



	if (hit->CheckElementHit(ELEMENT_PLAYER) != false)
	{

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
	dst.m_right = 64.0f + m_ix;
	dst.m_bottom = 64.0f + m_iy;


	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);

}
