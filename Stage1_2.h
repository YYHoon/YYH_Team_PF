#pragma once
#include "ParentStage.h"

class Event;
class SchoolGirl;

class Stage1_2 : public ParentStage
{
private:
	Event* _Ev;
	SchoolGirl* _SchoolGirl;
public:
	virtual HRESULT init()override;
	void render()override;
	virtual void EventScript()override;
};

