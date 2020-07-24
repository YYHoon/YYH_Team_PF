#pragma once
#include "gameNode.h"

enum class StageChapter
{
	STAGE1,
	STAGE2,
	BOSS_BEFORE,
	BOSS_AFTER
};

class Dialogue : public gameNode
{
private:
	StageChapter _Stage;

public:
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

