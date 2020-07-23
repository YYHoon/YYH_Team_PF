#include "stdafx.h"
#include "EnemyManager.h"


HRESULT EnemyManager::Init(vector<TagEnemySpawn> Spawn)
{
	_vCheerLeader.clear();
	_vSchoolMan.clear();
	_vSchoolGirl.clear();
	
	for (int i = 0; i < Spawn.size(); i++)
	{
		EnemyCheerLeader* _EnemyCheerLeader;
		_EnemyCheerLeader = new EnemyCheerLeader;
		EnemySchoolMan* _EnemySchoolMan;
		_EnemySchoolMan = new EnemySchoolMan;
		EnemySchoolGirl* _EnemySchoolGirl;
		_EnemySchoolGirl = new EnemySchoolGirl;

		switch (Spawn[i].EmType)
		{
		case CheerLeader :
			_EnemyCheerLeader->Init(Spawn[i].pt);
			_vCheerLeader.push_back(_EnemyCheerLeader);
			break;
		case SchoolMan :
			_EnemySchoolMan->Init(Spawn[i].pt);
			_vSchoolMan.push_back(_EnemySchoolMan);
			break;
		case SchoolGirl :
			_EnemySchoolGirl->Init(Spawn[i].pt);
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

		if (_vCheerLeader[i]->GetClState() == CLIdle) continue;

		if ((_vCheerLeader[i]->GetClState() == CLWalk))
		{
			_vCheerLeader[i]->AniSet(CLWalk);
		}
	}

	for (int j = 0; j < _vSchoolMan.size(); j++)
	{
		_vSchoolMan[j]->Update();

		if (_vSchoolMan[j]->GetSmState() == SmIdle) continue;

		if (_vSchoolMan[j]->GetSmState() == SmWalk)
		{
			_vSchoolMan[j]->SmAniSet(SmWalk);
		}
	}

	for (int k = 0; k < _vSchoolGirl.size(); k++)
	{
		_vSchoolGirl[k]->Update();
		
		/*if (_vSchoolGirl[k]->GetSgState() == SgIdle) continue;
		
		_SgDistance = getDistance(_vSchoolGirl[k]->GetSchoolGirlCenterX(), _vSchoolGirl[k]->GetSchoolGirlCenterY(), _Player->GetCnetX(), _Player->GetCnetY());
		_SgAngle = getAngle(_vSchoolGirl[k]->GetSchoolGirlCenterX(), _vSchoolGirl[k]->GetSchoolGirlCenterY(),_Player->GetCnetX(), _Player->GetCnetY());
			
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