#pragma once
#include "ParentStage.h"
#include "Boss.h"

class Stage1_Boss : public ParentStage
{
private:
	Boss* _Boss;

public:
	void update()override;
	HRESULT init()override;
	void render()override;

};

