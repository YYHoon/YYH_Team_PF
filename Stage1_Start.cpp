#include "stdafx.h"
#include "Stage1_Start.h"
#include "Player.h"
#include "AllObstacle.h"


HRESULT Stage1_Start::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Start");
	

	_RightExit.centerSet(1435, 250, 300, 300);


	_IsOnceClear = true;

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2016, 672);
	
	return S_OK;
}

void Stage1_Start::render()
{
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new Table;
		i->init(x, 0);
		_vObstacle.push_back(i);
	}


	CAMERAMANAGER->render(getMemDC(), _Img, 0, 0);
	CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
	CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);


	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->rectangle(getMemDC(), _vObstacle[i]->GetPhysicCollision());
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	
	}
}

