#pragma once
#include "ParentStage.h"

class Merge;

class Player;
class ParentsObstacle;

class Stage1_Start : public ParentStage
{
private:
	Merge* ZM;
	vector<MYRECT> ZList;
public:
	HRESULT init()override;
	void render()override;
	

};

