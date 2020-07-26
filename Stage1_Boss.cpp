#include "stdafx.h"
#include "Stage1_Boss.h"
#include "Player.h"
#include "AllObstacle.h"
#include "Boss.h"
#include "BossProgressBar.h"

HRESULT Stage1_Boss::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Boss");
	_Player->SetMapName("Stage1_Boss_Pixel");
	_Player->SetMapY(00);
	//if (!SOUNDMANAGER->isPlaySound("Stage_Boss"))
	//	SOUNDMANAGER->play("Stage_Boss", 0.3f);
		_BossProgressBar = new BossProgressBar;

	_BossProgressBar->init(457, 720, 572, 43);
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
	_BossProgressBar->update();
	_BossProgressBar->setGauge(_Boss->GetBossHp(), 90);
	_Test.set(_Player->GetAttackRC1().left, _Player->GetAttackRC1().top, _Player->GetAttackRC1().right, _Player->GetAttackRC1().bottom);

	CAMERAMANAGER->setX(_Player->GetShadowCenterX());
	CAMERAMANAGER->setY(_Player->GetShadowCenterY() - 200);
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD7))
	{
		_Boss->SetBossHp(1);
	}
}
void Stage1_Boss::render()
{
	CAMERAMANAGER->render(getMemDC(), _Img, 0, 0);
	if (KEYMANAGER->isStayKeyDown(VK_CONTROL))
	{
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("Stage1_Start_Pixel"), 0, 100);
		CAMERAMANAGER->rectangle(getMemDC(), _Player->GetAttackRC1());
	}
	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	}
	_Boss->render();
	
	ZORDER->ZOrderRender();
	//CAMERAMANAGER->rectangle(getMemDC(), _Test);
	_BossProgressBar->render();
	IMAGEMANAGER->findImage("RCG_bossmeter_frame")->render(getMemDC(), 427, 707);
	IMAGEMANAGER->findImage("MISUZU_NAME_HP_BAR")->render(getMemDC(), 665, 717);


}