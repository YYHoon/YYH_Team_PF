#pragma once
#include "gameNode.h"

class SelectMenuScene : public gameNode
{
private:
	RECT _BGRect;
	int _x, _y[3];
	int _KeyCount;
	float _FileCharacterX, _FileCharacterY;
	int _LoopX, _LoopY;

public:
	SelectMenuScene();
	~SelectMenuScene();

	HRESULT init();
	void release();
	void update();
	void render();

};