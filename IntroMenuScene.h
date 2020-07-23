#pragma once
#include "gameNode.h"
#include "MovieManager.h"

using namespace cv;

class IntroMenuScene : public gameNode
{
private:
	float _MisakoX, _MisakoY;
	float _KyokoX, _KyokoY;

	int _AlphaValue;

	bool _KeyPress;

public:
	IntroMenuScene();
	~IntroMenuScene();

	HRESULT init();
	void release();
	void update();
	void render();

	int video();
};