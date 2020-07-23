#include "stdafx.h"
#include "VideoScene.h"

HRESULT VideoScene::init()
{
	if (!_Start)
	{
		IntroVideo();
		_Start = true;
	}

	return S_OK;
}

void VideoScene::release()
{
}

void VideoScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN) || KEYMANAGER->isOnceKeyDown(VK_ESCAPE) || _IFrame.empty())
	{
		destroyWindow("IntroVideo");
		SCENEMANAGER->changeScene("IntroMenuScene");
	}
}

void VideoScene::render()
{
}

int VideoScene::IntroVideo()
{
	VideoCapture cap("Movies/RCG_Intro.mp4");

	if (!cap.isOpened())
	{
		return -1;
	}
	while (1)
	{
		cap.read(_IFrame);

		if (_IFrame.empty()) break;

		imshow("IntroVideo", _IFrame);

		if (waitKey(24) >= 0) break;
	}
	destroyWindow("IntroVideo");
	return 0;
}