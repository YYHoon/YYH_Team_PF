#pragma once
#include "gameNode.h"
#include "MovieManager.h"

using namespace cv;

class VideoScene : public gameNode
{
private:
	Mat _IFrame;
	bool _Start = false;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	int IntroVideo();
};

