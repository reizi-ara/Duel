#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_ITEM,
	
	OBJ_BACKGROUND,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_CLEAR,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjBlock.h"
#include"ObjHero.h"
#include "ObjBackground.h"
#include "ObjWaterItem.h"
#include "ObjBubbleItem.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include "ObjClear.h"
#include "ObjBubbleRide.h"
#include "Setumei.h"


//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneMain.h"
#include"SceneMain2.h"
#include"SceneMain3.h"
#include"SceneMain4.h"
#include"SceneMain5.h"
#include "SceneTitle.h"
#include "SceneSetumei.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------