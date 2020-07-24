#pragma once
#include "ParentStage.h"

class Boss;

class Player;
class ParentsObstacle;


class Stage1_1 : public ParentStage
{
private:
	Boss* _Boss;

public:
	HRESULT init()override;
	void render()override;

};

