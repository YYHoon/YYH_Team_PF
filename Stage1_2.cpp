#include "stdafx.h"
#include "Stage1_2.h"
#include "Player.h"
#include "AllObstacle.h"
#include "SchoolGirl.h"
#include "Event.h"

HRESULT Stage1_2::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_2");
	_LeftExit.centerSet(50, 550, 350, 400);
	_RightExit.centerSet(2710, 550, 250, 500);
	_EventCenterSpot.x = _Img->getWidth() / 2;
	_EventCenterSpot.y = 660;
	_EventArea.centerSet(_EventCenterSpot.x, _EventCenterSpot.y, 1300, 500);

	_SchoolGirl = new SchoolGirl;
	_SchoolGirl->init(2000, 700, false);
	_SchoolGirl->SetPlayerMemoryAddressLink(_Player);

	_IsOnceClear = false;
	_IsEventPlay = false;
	_WaveCount = 0;
	_Player->SetMapName("Stage1_2_Pixel");
	_Player->SetMapY(00);

	_Ev = new StopCamera;

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2860-WINSIZEX, 1040-WINSIZEY-00);
	return S_OK;
}

void Stage1_2::render()
{
	_SchoolGirl->update();
	CAMERAMANAGER->setX(_Player->GetShadowCenterX());
	CAMERAMANAGER->setY(_Player->GetShadowCenterY() - 200);
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_WaveCount++;
	}
	EventScript();
	CAMERAMANAGER->render(getMemDC(), _Img, 0, -000);
	
	if (KEYMANAGER->isStayKeyDown(VK_CONTROL))
	{
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("Stage1_2_Pixel"), 0, 00);
		CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
		CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);
		CAMERAMANAGER->rectangle(getMemDC(), _EventArea);
	}

	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		_SchoolGirl->SetDeath(15);
	}
	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}
	_SchoolGirl->render();
	ZORDER->ZOrderRender();
}

void Stage1_2::EventScript()
{
	if (IsInEventArea())
	{
		_IsEventPlay = true;
		_Ev->EventStart(_EventCenterSpot.x, _EventCenterSpot.y);
		
	}
	if (_SchoolGirl->GetEnemyState()== EnemyState::Die)
	{
		_IsEventPlay = false;
		_IsOnceClear = true;
	}

	/*
		if(Enemy.size() == 0)
		WaveCount++;
		if(WaveCount > 4)_IsEventPlay = false;
	*/
}


