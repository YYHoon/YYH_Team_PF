#pragma once
#include "ParentStage.h"
#include "EnemyManager.h"

class Boss;

class Player;
class ParentsObstacle;


class Stage1_1 : public ParentStage
{
public:
	HRESULT init()override;
	void update()override;
	void render()override;

};

