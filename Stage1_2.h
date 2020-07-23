#pragma once
#include "ParentStage.h"

class Event;

class Stage1_2 : public ParentStage
{
private:
	Event* _Ev;

public:
	virtual HRESULT init()override;
	void render()override;
	virtual void EventScript()override;
};

