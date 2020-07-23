#pragma once
#include "ParentStage.h"

class Player;
class ParentsObstacle;


class Stage1_1 : public ParentStage
{
private:
	

public:
	HRESULT init()override;
	void render()override;

};

