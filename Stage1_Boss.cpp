#include "stdafx.h"
#include "Stage1_Boss.h"
#include "Player.h"
#include "AllObstacle.h"

HRESULT Stage1_Boss::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Boss");

	CAMERAMANAGER->setConfig(0, -200, WINSIZEX, WINSIZEY, 0, 0, 2769, 1280);
	return S_OK;
}

void Stage1_Boss::render()
{
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new DestructiblePillar;
		i->init(x, WINSIZEY*0.5, true);
		_vObstacle.push_back(i);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new DestructiblePillar;
		i->init(x, WINSIZEY*0.5, false);
		_vObstacle.push_back(i);
	};

	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}
	cout << _vObstacle.size() << endl;
}
