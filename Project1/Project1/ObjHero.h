#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero :public CObj
{
public:
	CObjHero(int map);
	~CObjHero() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetBT() { return m_block_type; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	int SetBT(int t) { return m_block_type = t; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	void Getflag(int f) { flagb += f; }
	int Getbubble() { return flagb; }
	void Setbubble() { flagb -= 1; }
	float Getpos() { return m_posture; }

private:
	float m_px;         //位置
	float m_py;
	float m_vx;         //移動ベクトル
	float m_vy;
	float m_posture;    //姿勢
	float m_b;          //泡を出す
	float m_w;          //水を出す

	int m_ani_time;  //アニメーションフレーム動作間隔
	int m_ani_frame; //描画フレーム

	float m_speed_power;   //スピードパワー
	float m_ani_max_time;//アニメーション間隔幅

	int flagb;
	bool flagw;

	bool push;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類を確認用
	int m_block_type;

	//テスト用
	float px, py;  //交点

	int m_map;


};