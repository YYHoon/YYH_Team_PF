#include "stdafx.h"
#include "Stage1_Start.h"
#include "Player.h"
#include "AllObstacle.h"


HRESULT Stage1_Start::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Start");
	_Player->SetMapName("Stage1_Start_Pixel");
	_Player->SetMapY(100);
	_Player->SetShadowCenterX(PointFloatMake(400,500));
	_RightExit.centerSet(1435, 350, 300, 300);
	SOUNDMANAGER->play("Stage_1", 0.3f);

	_IsOnceClear = true;

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2016-WINSIZEX, 672-WINSIZEY+100);
	
	return S_OK;
}

void Stage1_Start::render()
{
	
	CAMERAMANAGER->setX(_Player->GetShadowCenterX());
	CAMERAMANAGER->setY(_Player->GetShadowCenterY() - 200);
	for (int i = 0; i < ZList.size(); ++i)
	{
		
	}

	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new Table;
		i->init(x, 0);
		_vObstacle.push_back(i);
	}


	CAMERAMANAGER->render(getMemDC(), _Img, 0, 100);
	if(KEYMANAGER->isStayKeyDown(VK_CONTROL))
	{
		CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
		CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);
	}
	


	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->rectangle(getMemDC(), _vObstacle[i]->GetPhysicCollision());
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	
	}
	ZORDER->ZOrderRender();
}

