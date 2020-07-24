#pragma once
#include "gameNode.h"
#include "Stage1_Start.h"

class CharacterSelectScene : public gameNode
{
private:
	int _x, _y;

	Stage1_Start* _Stage1;

public:
	CharacterSelectScene();
	~CharacterSelectScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

