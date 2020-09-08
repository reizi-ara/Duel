//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHero::CObjHero(int map)
{
	m_map = map;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 70.0f;        //�ʒu
	m_py = 550.0f;
	m_vx = 0.0f;        //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;   //�E����0.0f�@������1.0f
	m_b = 0.0f;         //�A���o��
	m_w = 0.0f;         //�����o��

	m_ani_time = 0;
	m_ani_frame = 1;     //�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;  //�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up = false;
	bool m_hit_down = false;
	bool m_hit_left = false;
	bool m_hit_right = false;

	
	m_block_type = 0;     //����ł���block�̎�ނ��m�F�p

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	
	

	//X�L�[���͂ŃW�����v
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -10;
		}
	}
	if (flagb==true)
	{
		//C�L�[���͂ŖA����
		if (Input::GetVKey('C') == true)
		{
			//�A�A�C�e���I�u�W�F�N�g�쐬
			CObjBubbleRide* obj_b = new CObjBubbleRide(m_px, m_py);
			Objs::InsertObj(obj_b, OBJ_ITEM, 3);
		}
	}
	

	//V�L�[���͂Ő�����
	if (Input::GetVKey('V') == true)
	{
		//���A�C�e���I�u�W�F�N�g�쐬
		CObjWaterItem* obj_w = new CObjWaterItem(m_px, m_py);
		Objs::InsertObj(obj_w, OBJ_ITEM, 2);
	}

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;  //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);
	
	//��l���̈ʒuX(m_px)+��l���@�̕���+X�������ɗ̈�O��F��
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type);

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HiitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);

	//��l������ʉ��ɗ�������Q�[���I�[�o�[�Ɉڍs
	if (m_py > 1000.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//��l����HP���[���ɂȂ������Q�[���I�[�o�[��ʂɈڍs����
		Scene::SetScene(new CSceneGameOver(m_map));
	}

	//��l����������������true�ɂ���
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		//�v���C���[�ɓ�������true�ɂȂ�����false�ɂ��A����
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	if (m_block_type == 5)//��l�����S�[���u���b�N�𓥂ނƃX�e�[�W�ڍs
	{
		this->SetStatus(false);//��l���I�u�W�F�N�g�폜
		Hits::DeleteHitBox(this);//�q�b�g�{�b�N�X�폜

		Scene::SetScene(new CSceneClear(m_map));
	}

	hit->SetPos(m_px , m_py);

}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};

	//�`��J���[���@
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f ;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (32.0f * m_posture) + m_px;
	dst.m_right = (32 - 32.0f * m_posture) + m_px;
	dst.m_bottom = 32.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//��_
	float cc[4] = { 1.0f,0.0f,0.0f,1.0f };
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = 320.0f + 64.0f;
	src.m_bottom = 64.0f;
	dst.m_top = py;
	dst.m_left = px;
	dst.m_right = dst.m_left + 10.0f;
	dst.m_bottom = dst.m_top + 10.0f;
	Draw::Draw(0, &src, &dst, cc, 0.0f);
}