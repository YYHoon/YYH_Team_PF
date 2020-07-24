#include "stdafx.h"
#include "Movies.h"

HRESULT Movies::init()
{
	if (!_Start)
	{
		BossMisuzuVideo();
		_Start = true;
	}

	return S_OK;
}

void Movies::release()
{
}

void Movies::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN) || KEYMANAGER->isOnceKeyDown(VK_ESCAPE) || _IFrame.empty())
	{
		destroyWindow("BossMisuzuVideo");
		//SCENEMANAGER->changeScene("");
	}
}

void Movies::render()
{
}

int Movies::BossMisuzuVideo()
{
	VideoCapture cap("Movies/Bossintros_Misuzu.mp4");

	if (!cap.isOpened())
	{
		return -1;
	}
	while (1)
	{
		cap.read(_IFrame);

		if (_IFrame.empty()) break;

		imshow("BossMisuzuVideo", _IFrame);

		if (waitKey(24) >= 0) break;
	}
	destroyWindow("BossMisuzuVideo");
	return 0;
}