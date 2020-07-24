#pragma once
#include "gameNode.h"
#include "Boss.h"
#include "Player.h"
#include "ParentStage.h"
#include "StageManager.h"
#include "pixelCollsion.h"
#include "EnemySchoolGirl.h"
#include "AllUI.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define RED RGB(255, 0, 0)
#define GREED RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define MAGENTA RGB(255, 0, 255)
#define CYAN RGB(0, 255, 255)
#define YELLOW RGB(255, 255, 0)
#define BLACK RGB(0, 0, 0)
#define WHITE RGB(255, 255, 255)

class playGround : public gameNode
{
private:
	Player* p;
	Boss* b;
	StageManager* _SM;
	pixelCollsion* _pixel;
	EnemySchoolGirl* _en;
	InGameUI* _InGameUI;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void imginit();
	void soundinit();
};

