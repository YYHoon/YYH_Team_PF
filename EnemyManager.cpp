#include "stdafx.h"
#include "EnemyManager.h"
#include "Player.h"

HRESULT EnemyManager::Init(vector<TagEnemySpawn> Spawn)
{
	_vCheerLeader.clear();
	_vSchoolMan.clear();
	_vSchoolGirl.clear();
	
	for (int i = 0; i < Spawn.size(); i++)
	{
		switch (Spawn[i].EmType)
		{
		case CheerLeader :
			EnemyCheerLeader* _EnemyCheerLeader;
			_EnemyCheerLeader = new EnemyCheerLeader;
			_EnemyCheerLeader->SetPlayer(_Player);
			_EnemyCheerLeader->Init(Spawn[i].XY);
			_vCheerLeader.push_back(_EnemyCheerLeader);
			break;
		case SchoolMan :
			EnemySchoolMan* _EnemySchoolMan;
			_EnemySchoolMan = new EnemySchoolMan;
			_EnemySchoolMan->SetPlayer(_Player);
			_EnemySchoolMan->Init(Spawn[i].XY);
			_vSchoolMan.push_back(_EnemySchoolMan);
			break;
		case SchoolGirl :
			EnemySchoolGirl* _EnemySchoolGirl;
			_EnemySchoolGirl = new EnemySchoolGirl;
			_EnemySchoolGirl->SetPlayer(_Player);
			_EnemySchoolGirl->Init(Spawn[i].XY);
			_vSchoolGirl.push_back(_EnemySchoolGirl);
			break;
		}
	}
	return S_OK;
}

void EnemyManager::Release()
{
}

void EnemyManager::Updata()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->Update();

	/*	if (_vCheerLeader[i]->GetClState() == CLIdle) continue;

		_CLDistance = getDistance(_vCheerLeader[i]->GetEnemyX(), _vCheerLeader[i]->GetEnemyY(),_Player->GetShadowCenterX(), _Player->GetShadowCenterY());
		_CLAngle = getAngle(_vCheerLeader[i]->GetEnemyX(), _vCheerLeader[i]->GetEnemyY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());

		_CLDistance = getDistance(_vCheerLeader[i]->GetEnemyX(), _vCheerLeader[i]->GetEnemyY(),_Player->GetShadowCenterX(), _Player->GetShadowCenterY());
		_CLAngle = getAngle(_vCheerLeader[i]->GetEnemyX(), _vCheerLeader[i]->GetEnemyY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());

		if (_CLDistance > 100)
		{
			_vCheerLeader[i]->SetCenterX(cosf(_CLAngle) * 3.0f);
			_vCheerLeader[i]->SetCenterY(-sinf(_CLAngle) * 3.0f);
		}*/

	}

	for (int j = 0; j < _vSchoolMan.size(); j++)
	{
		_vSchoolMan[j]->Update();

		/*if (_vSchoolMan[j]->GetSmState() == SmIdle) continue;

		_SmDistance = getDistance(_vSchoolMan[j]->GetSmCenterX(), _vSchoolMan[j]->GetSmCenterY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());
		_SmAngle = getAngle(_vSchoolMan[j]->GetSmCenterX(), _vSchoolMan[j]->GetSmCenterY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());

		_SmDistance = getDistance(_vSchoolMan[j]->GetSmCenterX(), _vSchoolMan[j]->GetSmCenterY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());
		_SmAngle = getAngle(_vSchoolMan[j]->GetSmCenterX(), _vSchoolMan[j]->GetSmCenterY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());

		if (_SmDistance > 100)
		{
			_vSchoolMan[j]->SetSmCenterX(cosf(_SmAngle) * 3.0f);
			_vSchoolMan[j]->SetSmCenterY(-sinf(_SmAngle) * 3.0f);
		}*/

	}

	for (int k = 0; k < _vSchoolGirl.size(); k++)
	{
		_vSchoolGirl[k]->Update();
		
	/*	if (_vSchoolGirl[k]->GetSgState() == SgIdle) continue;
		
		_SgDistance = getDistance(_vSchoolGirl[k]->GetSchoolGirlCenterX(), _vSchoolGirl[k]->GetSchoolGirlCenterY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());
		_SgAngle = getAngle(_vSchoolGirl[k]->GetSchoolGirlCenterX(), _vSchoolGirl[k]->GetSchoolGirlCenterY(), _Player->GetShadowCenterX(), _Player->GetShadowCenterY());
		
		cout << _vSchoolGirl[k]->GetSchoolGirlCenterX() << "적X" << _vSchoolGirl[k]->GetSchoolGirlCenterY() << "적Y" << endl;
		cout << _Player->GetShadowCenterX() << "플레이어X" << _Player->GetShadowCenterY() << "플레이어Y" << endl;

		if (_SgDistance > 100)
		{	
			_vSchoolGirl[k]->SetCenterX(cosf(_SgAngle) * 3.0f);
			_vSchoolGirl[k]->SetCenterY(-sinf(_SgAngle) * 3.0f);
		}*/
	}
}

void EnemyManager::Render()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->Render();
	}

	for (int j = 0; j < _vSchoolMan.size(); j++)
	{
		_vSchoolMan[j]->Render();
	}

	for (int k = 0; k < _vSchoolGirl.size(); k++)
	{
		_vSchoolGirl[k]->Render();
	}
}

