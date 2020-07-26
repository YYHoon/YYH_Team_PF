#pragma once
#include "gameNode.h"
#include "Boss.h"
#include "Player.h"
#include "ParentStage.h"
#include "StageManager.h"
#include <iostream>
#include "AllUI.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define MAGENTA RGB(255,0,255)
#define CYAN RGB(0,255,255)
#define YELLOW RGB(255,255,0)
#define BLACK RGB(0,0,0)
#define WHITE RGB(255,255,255)

class playGround : public gameNode
{
private:
	Player* p;
	Boss* b;
	StageManager* _SM;
	

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

