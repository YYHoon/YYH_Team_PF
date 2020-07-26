#pragma once
#include "ParentStage.h"
#include "Boss.h"

class BossProgressBar;
class Stage1_Boss : public ParentStage
{
private:
	Boss* _Boss;
	BossProgressBar* _BossProgressBar;
	MYRECT _Test;
public:
	void update()override;
	HRESULT init()override;
	void render()override;

};

