#include "stdafx.h"
#include "StageManager.h"
#include "Player.h"
#include "AllStage.h"

HRESULT StageManager::init()
{
	_Player = new Player;
	_Player->Init();
	_InGameUI = new InGameUI;
	_InGameUI->init();
	_Boss = new Boss;
	_Player->SetBossMemoryAddressLink(_Boss);
	ParentStage* _Stage1_Start = new Stage1_Start;
	_Stage1_Start->SetPlayerMemoryAddressLink(_Player);
	//_Stage1_Start->init();
	_vStageName.push_back("Stage1_Start");
	_vStage.push_back(_Stage1_Start);

	ParentStage* _Stage1_1 = new Stage1_1;
	_Stage1_1->SetPlayerMemoryAddressLink(_Player);
	//_Stage1_1->init();
	_vStageName.push_back("Stage1_1");
	_vStage.push_back(_Stage1_1);

	ParentStage* _Stage1_2 = new Stage1_2;
	_Stage1_2->SetPlayerMemoryAddressLink(_Player);
	//_Stage1_2->init();
	_vStageName.push_back("Stage1_2");
	_vStage.push_back(_Stage1_2);

	ParentStage* _Stage1_Boss = new Stage1_Boss;
	_Stage1_Boss->SetPlayerMemoryAddressLink(_Player);
	//_Stage1_Boss->init();
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
	
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_CurrentStageIndex++;
		SCENEMANAGER->changeScene(_vStageName[_CurrentStageIndex]);
	}
	MoveStage();
	_Player->Update();
	_InGameUI->update();
}

void StageManager::render()
{
	SCENEMANAGER->render();
	_InGameUI->render();
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
				_Player->SetShadowCenterX(PointFloatMake(260, 700));
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

