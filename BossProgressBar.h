#pragma once
#include "gameNode.h"

class BossProgressBar : public gameNode
{
private:
	RECT _rcProgress;
	float _x, _y;

	float _width;	//100%
	float _hitWidth;
	image* _progressBarTop;
	image* _progressBarBottom;
	image* _progressBarMid;

public:
	BossProgressBar();
	~BossProgressBar();

	HRESULT init(float x, float y, int width, int height);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge);

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
};

