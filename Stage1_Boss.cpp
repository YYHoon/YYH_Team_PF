#include "stdafx.h"
#include "Stage1_Boss.h"
#include "Player.h"
#include "AllObstacle.h"
#include "Boss.h"


HRESULT Stage1_Boss::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Boss");
	_Player->SetMapName("Stage1_Boss_Pixel");
	_Player->SetMapY(00);

	_Boss = new Boss;
	_Boss->init();
	_Boss->SetPlayerAddressLink(_Player);
	_Player->SetBossMemoryAddressLink(_Boss);
	CAMERAMANAGER->setConfig(0, -200, WINSIZEX, WINSIZEY, 0, 0, 2769-WINSIZEX, 1280-WINSIZEY);
	return S_OK;
}

void Stage1_Boss::update()
{
	IsColRightExit();
	IsColLefttExit();
	IsInEventArea();
	EventScript();
	_Boss->update();

	_Test.set(_Player->GetAttackRC1().left, _Player->GetAttackRC1().top, _Player->GetAttackRC1().right, _Player->GetAttackRC1().bottom);

	CAMERAMANAGER->setX(_Player->GetShadowCenterX());
	CAMERAMANAGER->setY(_Player->GetShadowCenterY() - 200);
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new DestructiblePillar;
		i->init(x, WINSIZEY * 0.5, true);
		_vObstacle.push_back(i);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		int x = RND->getFromIntTo(300, 400);
		ParentsObstacle* i = new DestructiblePillar;
		i->init(x, WINSIZEY * 0.5, false);
		_vObstacle.push_back(i);
	}
}
void Stage1_Boss::render()
{
	CAMERAMANAGER->render(getMemDC(), _Img, 0, 0);
	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}
	_Boss->render();
	CAMERAMANAGER->rectangle(getMemDC(), _Player->GetAttackRC1());
	ZORDER->ZOrderRender();
	CAMERAMANAGER->rectangle(getMemDC(), _Test);

}


