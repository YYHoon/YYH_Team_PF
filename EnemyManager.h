#pragma once
#include "gameNode.h"
#include "EnemyCheerLeader.h"
#include "EnemySchoolGirl.h"
#include "EnemySchoolMan.h"
#include <vector>

class TestTest;

enum ENEMYTYPE
{
	CheerLeader,
	SchoolMan,
	SchoolGirl
};

struct TagEnemySpawn
{
	ENEMYTYPE EmType;
	POINTFLOAT pt;
};


class EnemyManager : public gameNode
{
private:
	typedef vector<EnemyCheerLeader*> vCheerLeader;
	typedef vector<EnemySchoolMan*>   vSchoolMan;
	typedef vector<EnemySchoolGirl*>  vSchoolGirl;

	vCheerLeader _vCheerLeader;
	vSchoolMan	 _vSchoolMan;
	vSchoolGirl  _vSchoolGirl;

	TestTest* _Player;

	float _CLAngle;
	float _CLDistance;

	float _SgAngle;
	float _SgDistance;

	float _SmAngle;
	float _SmDistance;


public:
	EnemyManager() {};
	~EnemyManager() {};

	HRESULT Init(vector<TagEnemySpawn> Spawn);
	void Release();
	void Updata();
	void Render();

	vector<EnemyCheerLeader*> GetEnemyCheerLeader() { return _vCheerLeader; }
	vector<EnemySchoolMan*>   GetEnemySchoolMan()   { return _vSchoolMan; }
	vector<EnemySchoolGirl*>  GetEnemySchoolGirl()	{ return _vSchoolGirl; }


	void SetPlayerLink(TestTest* p) { _Player = p; }

};