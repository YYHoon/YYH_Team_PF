#pragma once
#include "gameNode.h"
#include "Boss.h"
#include "SchoolGirl.h"
#include "InGameUI.h"
#include <vector>


class ParentStage;
class EventManager;
class Player;

class StageManager : public gameNode
{
private:
	vector<string> _vStageName;
	vector<string>::iterator _viStage;
	vector<ParentStage*> _vStage;

	EventManager* _EM;
	Boss* _Boss;
	SchoolGirl* _Enemy;
	InGameUI* _InGameUI;
	int _CurrentStageIndex;
	Player* _Player;


public:
	HRESULT init();
	void update();
	void render();

	void MoveStage();
};

