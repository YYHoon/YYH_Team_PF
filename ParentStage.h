#pragma once
#include "gameNode.h"
#include <vector>

class Player;
class ParentsObstacle;

class ParentStage : public gameNode
{
protected:
	image* _Img;
	string _Name;
	MYRECT _RightExit;
	MYRECT _LeftExit;
	MYRECT _EventArea;
	POINT_FLOAT _EventCenterSpot;
	POINT_FLOAT _PlayerSpawnXY;
	bool _IsOnceClear;
	bool _IsEventPlay;
	int _StageIndex;
	int _WaveCount;
	Player* _Player;
	ParentsObstacle* _Obstacle;

	vector<ParentsObstacle*> _vObstacle;
public:
	ParentStage();

	virtual HRESULT init() = 0;
	virtual void release();
	virtual void update();
	virtual void render();
	
	virtual POINT_FLOAT GetEventSpot() { return _EventCenterSpot; }
	virtual MYRECT GetEventArea() { return _EventArea; }

	virtual void EventScript() {};

	virtual void SetPlayerMemoryAddressLink(Player* memory) { _Player = memory; }
	virtual bool IsColRightExit();
	virtual bool IsColLefttExit();
	virtual bool IsInEventArea();

};

