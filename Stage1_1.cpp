#include "stdafx.h"
#include "Stage1_1.h"
#include "Player.h"
#include "AllObstacle.h"
#include "Event.h"
#include "Boss.h"

HRESULT Stage1_1::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_1");
	_LeftExit.centerSet(1270, 300, 300, 400);
	_RightExit.centerSet(2150, 500, 200, 400);
	_IsOnceClear = true;
	//if(!SOUNDMANAGER->isPlaySound("Stage_2"))
	//	SOUNDMANAGER->play("Stage_2", 0.3f);
	_Player->SetMapName("Stage1_1_Pixel");
	_Player->SetMapY(-100);
	ParentsObstacle* VendingMachine1 = new VendingMachine;
	VendingMachine1->init(500, 500);
	_vObstacle.push_back(VendingMachine1);

	CAMERAMANAGER->setConfig(0, 0, WINSIZEX, WINSIZEY, 0, 0,2400-WINSIZEX, 64);
	return S_OK;
}

void Stage1_1::render()
{
	CAMERAMANAGER->setX(_Player->GetShadowCenterX());
	CAMERAMANAGER->setY(_Player->GetShadowCenterY() - 200);

	CAMERAMANAGER->render(getMemDC(), _Img, 0, -100);

	if (KEYMANAGER->isStayKeyDown(VK_CONTROL))
	{
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("Stage1_1_Pixel"), 0, -100);
		CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
		CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);
	}

	ZORDER->ZOrderRender();
}
