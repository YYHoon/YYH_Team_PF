#include "stdafx.h"
#include "IntroMenuScene.h"

IntroMenuScene::IntroMenuScene()
{
}


IntroMenuScene::~IntroMenuScene()
{
}

HRESULT IntroMenuScene::init()
{
	IMAGEMANAGER->findImage("KyokoIntro")->setX(_KyokoX);
	IMAGEMANAGER->findImage("KyokoIntro")->setY(_KyokoY);
	IMAGEMANAGER->findImage("MisakoIntro")->setX(_MisakoX);
	IMAGEMANAGER->findImage("MisakoIntro")->setY(_MisakoY);
	IMAGEMANAGER->findImage("Intro_UI_START")->setX(340);
	IMAGEMANAGER->findImage("Intro_UI_START")->setY(480);
	IMAGEMANAGER->findImage("Intro_UI_QUIT")->setX(345);
	IMAGEMANAGER->findImage("Intro_UI_QUIT")->setY(540);
	IMAGEMANAGER->findImage("Intro_UI_ARROW")->setX(270);
	IMAGEMANAGER->findImage("Intro_UI_ARROW")->setY(480);
	IMAGEMANAGER->findImage("Intro_UI_LOGO")->setX(140);
	IMAGEMANAGER->findImage("Intro_UI_LOGO")->setY(130);

	_AlphaValue = 0;

	_KyokoX = WINSIZEX;
	_KyokoY = WINSIZEY - IMAGEMANAGER->findImage("KyokoIntro")->getHeight();

	_MisakoX = -IMAGEMANAGER->findImage("MisakoIntro")->getWidth();
	_MisakoY = WINSIZEY - IMAGEMANAGER->findImage("MisakoIntro")->getHeight();

	return S_OK;
}

void IntroMenuScene::release()
{
}

void IntroMenuScene::update()
{
	if (_MisakoX < 700) _MisakoX += 65.0f;
	if (_KyokoX > 1030) _KyokoX -= 30.0f;

	if (_KyokoX <= 1030 || _MisakoX >= 700)
	{
		_AlphaValue += 35;
		if (_AlphaValue >= 255) _AlphaValue = 255;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		IMAGEMANAGER->findImage("Intro_UI_ARROW")->setY(540);
		SOUNDMANAGER->play("MemuCursor", 0.3f);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		IMAGEMANAGER->findImage("Intro_UI_ARROW")->setY(480);
		SOUNDMANAGER->play("MemuCursor", 0.3f);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("MemuConfirm", 0.3f);

		if (IMAGEMANAGER->findImage("Intro_UI_ARROW")->getY() == 480)
		{
			SCENEMANAGER->changeScene("SelectMenuScene");
		}

		if (IMAGEMANAGER->findImage("Intro_UI_ARROW")->getY() == 540)
		{
			PostQuitMessage(0);
		}
	}

}

void IntroMenuScene::render()
{
	IMAGEMANAGER->findImage("MenuBackGround")->render(getMemDC());
	IMAGEMANAGER->findImage("KyokoIntro")->render(getMemDC(), _KyokoX, _KyokoY);
	IMAGEMANAGER->findImage("MisakoIntro")->render(getMemDC(), _MisakoX, _MisakoY);
	IMAGEMANAGER->findImage("Intro_UI_START")->alphaRender(getMemDC(), _AlphaValue);
	IMAGEMANAGER->findImage("Intro_UI_QUIT")->alphaRender(getMemDC(), _AlphaValue);
	IMAGEMANAGER->findImage("Intro_UI_ARROW")->alphaRender(getMemDC(), _AlphaValue);
	IMAGEMANAGER->findImage("Intro_UI_LOGO")->render(getMemDC());

	IMAGEMANAGER->findImage("MenuFrontGround")->render(getMemDC(), 0, 0);
}
