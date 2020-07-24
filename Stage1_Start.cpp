#include "stdafx.h"
#include "Stage1_Start.h"
#include "Player.h"
#include "AllObstacle.h"
#include "EnemyManager.h"

HRESULT Stage1_Start::init()
{
	_Img = IMAGEMANAGER->findImage("Stage1_Start");
	
	_EM = new EnemyManager;
	_EM->SetPlayerLink(_Player);
	_EM->Init(_vspawn);
	_Player->SetAddressEM(_EM);

	_RightExit.centerSet(1435, 350, 300, 300);

	_IsOnceClear = true;

	_WaveInCountTime = 0;

	CAMERAMANAGER->setConfig(0, -100, WINSIZEX, WINSIZEY, 0, 0, 2016-WINSIZEX, 672-WINSIZEY+100);
	
	return S_OK;
}

void Stage1_Start::update()
{
	IsColRightExit();
	IsColLefttExit();
	IsInEventArea();
	EventScript();
	
	if (_WaveInCountTime % 50 == 0)
	{
		cout << _WaveInCountTime << endl;
		TagEnemySpawn spawn;
		spawn.EmType = SchoolGirl;
		spawn.XY.x = 500;
		spawn.XY.y = 500;
		_vspawn.push_back(spawn);
		_EM->SpawnEnemyTest(_vspawn);
		_WaveCount += 1;
	}
	
	_WaveInCountTime++;
}

void Stage1_Start::render()
{
	
	CAMERAMANAGER->setX(_Player->GetShadowCenterX());
	CAMERAMANAGER->setY(_Player->GetShadowCenterY() - 200);
	CAMERAMANAGER->render(getMemDC(), _Img, 0, 100);
	CAMERAMANAGER->rectangle(getMemDC(), _RightExit);
	CAMERAMANAGER->rectangle(getMemDC(), _LeftExit);


	for (int i = 0; i < _vObstacle.size(); i++)
	{
		CAMERAMANAGER->rectangle(getMemDC(), _vObstacle[i]->GetPhysicCollision());
		CAMERAMANAGER->render(getMemDC(), _vObstacle[i]->GetImg(), _vObstacle[i]->GetCollision().left, _vObstacle[i]->GetCollision().top);
	
	}
	ZORDER->ZOrderRender();
}

