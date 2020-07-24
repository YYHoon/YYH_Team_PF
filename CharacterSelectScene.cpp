#include "stdafx.h"
#include "CharacterSelectScene.h"

CharacterSelectScene::CharacterSelectScene()
{
}

CharacterSelectScene::~CharacterSelectScene()
{
}

HRESULT CharacterSelectScene::init()
{
	_x = (WINSIZEX / 2) - IMAGEMANAGER->findImage("UI_SELECT_Character")->getCenterX();
	_y = (WINSIZEY / 2) - IMAGEMANAGER->findImage("UI_SELECT_Character")->getCenterY();

	return S_OK;
}

void CharacterSelectScene::release()
{
}

void CharacterSelectScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("MemuConfirm", 0.3f);
		SOUNDMANAGER->stop("MenuMusic");
		SCENEMANAGER->changeScene("Stage1_Start");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("SelectMenuScene");
		SOUNDMANAGER->play("MemuBack", 0.3f);
	}
}

void CharacterSelectScene::render()
{
	IMAGEMANAGER->findImage("UI_FE_Character_Select")->render(getMemDC());
	IMAGEMANAGER->findImage("UI_FILE_SELECT_Character_Shadow")->alphaRender(getMemDC(), _x + 200, _y + 40, 80);
	IMAGEMANAGER->findImage("MenuFrontGround")->render(getMemDC());
	IMAGEMANAGER->findImage("UI_SELECT_Character_Text")->render(getMemDC(), 625, 23);
	IMAGEMANAGER->findImage("UI_SELECT_Character")->render(getMemDC(), _x, _y + 40);
}
