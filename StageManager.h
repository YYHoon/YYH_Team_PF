#pragma once
#include "gameNode.h"
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

	int _CurrentStageIndex;
	Player* _Player;


public:
	HRESULT init();
	void update();
	void render();

	void MoveStage();
};

