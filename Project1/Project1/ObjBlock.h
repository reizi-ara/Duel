#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

#include "GameL/DrawTexture.h"

//オブジェクト:ブロック&背景
class CObjBlock :public CObj
{

public:
	CObjBlock(int map[20][25]);
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


	//ブロックとの当たり判定
	void BlockHit(
		float* x, float* y,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);

	

	//主人公と壁の交差判定
	bool HeroBlockCrossPoint(
		float x, float y, float vx, float vy,
		float* out_px, float* out_py, float* out_len
	);



private:

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);

	int m_map[20][25];

	float Dot(float ax, float ay, float bx, float by);//内積
	float Cross(float ax, float ay, float bx, float by);//外積

	//線と線と交差判定
	bool LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float* out_px, float* out_py
	);

	int px;
	int py;

	bool push_flag;
};
