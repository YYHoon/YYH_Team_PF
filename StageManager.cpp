#include "stdafx.h"
#include "StageManager.h"
#include "Player.h"
#include "AllStage.h"


HRESULT StageManager::init()
{
	_Player = new Player;
	_Player->Init();
	
	_EM = new EnemyManager;
	_EM->SetPlayerLink(_Player);
	_Player->SetAddressEM(_EM);
	_EM->Init(_vSpawn);
	

	ParentStage* _Stage1_Start = new Stage1_Start;
	_Stage1_Start->SetPlayerMemoryAddressLink(_Player);
	_vStageName.push_back("Stage1_Start");
	_vStage.push_back(_Stage1_Start);

	ParentStage* _Stage1_1 = new Stage1_1;
	_Stage1_1->SetPlayerMemoryAddressLink(_Player);
	_vStageName.push_back("Stage1_1");
	_vStage.push_back(_Stage1_1);

	ParentStage* _Stage1_2 = new Stage1_2;
	_Stage1_2->SetPlayerMemoryAddressLink(_Player);
	_vStageName.push_back("Stage1_2");
	_vStage.push_back(_Stage1_2);

	ParentStage* _Stage1_Boss = new Stage1_Boss;
	_Stage1_Boss->SetPlayerMemoryAddressLink(_Player);
	_vStageName.push_back("Stage1_Boss");
	_vStage.push_back(_Stage1_Boss);

	SCENEMANAGER->addScene(_vStageName[0], _Stage1_Start);
	SCENEMANAGER->addScene(_vStageName[1], _Stage1_1);
	SCENEMANAGER->addScene(_vStageName[2], _Stage1_2);
	SCENEMANAGER->addScene(_vStageName[3], _Stage1_Boss);

	_CurrentStageIndex = 0;

	SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);

	return S_OK;
}

void StageManager::update()
{
	SCENEMANAGER->update();
	
	int RndX = RND->getFromIntTo(100, 1500);

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_CurrentStageIndex++;
		SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		TagEnemySpawn _EnSpawn;

		_EnSpawn.EmType = SchoolGirl;
		_EnSpawn.XY.x = RndX;
		_EnSpawn.XY.y = 500;


		_vSpawn.push_back(_EnSpawn);
		_EM->SpawnEnemyTest(_vSpawn);
		_EM->GetEnemySchoolMan().size();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		TagEnemySpawn _EnSpawn;

		_EnSpawn.EmType = SchoolMan;
		_EnSpawn.XY.x = 1000;
		_EnSpawn.XY.y = 500;

		_vSpawn.push_back(_EnSpawn);
		_EM->SpawnEnemyTest(_vSpawn);
	}
	MoveStage();
	_Player->Update();
	_EM->Updata();
}

void StageManager::render()
{
	SCENEMANAGER->render();
}

void StageManager::MoveStage()
{
	for (int i = 0; i < _vStage.size(); i++)
	{
		if (_vStage[i]->IsColRightExit() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_CurrentStageIndex += 1;
			SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);
			_vStage[_CurrentStageIndex - 1]->release();

			if (i == 0)
			{
				
				_Player->SetShadowCenterX(PointFloatMake(1270, 500));
				break;
			}else
			if (i == 1)
			{
				_Player->SetShadowCenterX(PointFloatMake(150, 800));
				break;
			}else
			if (i == 2)
			{
				_Player->SetShadowCenterX(PointFloatMake(1100, 850));
				break;
			}

		}
		if (_vStage[i]->IsColLefttExit() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_CurrentStageIndex -= 1;
			SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);
			if (i == 1)
			{
				_Player->SetShadowCenterX(PointFloatMake(1370, 400));
				break;
			}
			if (i == 2)
			{
				_Player->SetShadowCenterX(PointFloatMake(1910, 650));
				break;
			}
		}
	}




}

