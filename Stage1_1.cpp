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
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		for (int i = 0; i < _vObstacle.size(); ++i)
		{
			if (_vObstacle[i]->GetName() == "VendingMachine")
			{
				_vObstacle[i]->DestroyedMesh(true);

			}
		}
	}
	

	CAMERAMANAGER->render(getMemDC(), _Img, 0, -100);

	CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
	CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);
	

	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}
	ZORDER->ZOrderRender();
}
