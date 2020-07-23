#pragma once
#include "gameNode.h"

class CharacterSelectScene : public gameNode
{
private:
	int _x, _y;

public:
	CharacterSelectScene();
	~CharacterSelectScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

