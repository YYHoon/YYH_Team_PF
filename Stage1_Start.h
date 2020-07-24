#pragma once
#include "ParentStage.h"
#include "EnemyManager.h"

class Player;
class ParentsObstacle;

class Stage1_Start : public ParentStage
{
private:
	vector<TagEnemySpawn> _vspawn;
	int _WaveInCountTime;
public:
	HRESULT init()override;
	void update()override;
	void render()override;
	

};

