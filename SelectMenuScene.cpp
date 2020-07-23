#include "stdafx.h"
#include "SelectMenuScene.h"

SelectMenuScene::SelectMenuScene()
{
}

SelectMenuScene::~SelectMenuScene()
{
}

HRESULT SelectMenuScene::init()
{
    _x = 853;

    _y[0] = 71;
    _y[1] = 304;
    _y[2] = 537;

    _BGRect = RectMake(WINSIZEX - IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Blue")->getWidth(),
        WINSIZEY - IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Blue")->getHeight(),
        IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Blue")->getWidth(),
        IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Blue")->getHeight());

    _LoopX = _LoopY = 0;

    _FileCharacterX = WINSIZEX;
    _FileCharacterY = WINSIZEY - IMAGEMANAGER->findImage("UI_FILE_SELECT_FG_Character")->getHeight();

    SOUNDMANAGER->stop("IntroMusic");
    SOUNDMANAGER->play("MenuMusic", 0.3f);

    _KeyCount = 0;

    return S_OK;
}

void SelectMenuScene::release()
{

}

void SelectMenuScene::update()
{
   if (KEYMANAGER->isOnceKeyDown(VK_UP))
   {
       _KeyCount--;
       if (_KeyCount <= 0) _KeyCount = 0;

       SOUNDMANAGER->play("MemuCursor", 0.3f);

   }

   if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
   {
       _KeyCount++;
       if (_KeyCount >= 2) _KeyCount = 2;

       SOUNDMANAGER->play("MemuCursor", 0.3f);
   }

   if (KEYMANAGER->isOnceKeyDown(VK_BACK))
   {
       SCENEMANAGER->changeScene("IntroMenuScene");
       SOUNDMANAGER->play("MemuBack", 0.3f);
   }

   _LoopX += 1;
   _LoopY += 2;

   if (_FileCharacterX >= 70) _FileCharacterX -= 100.0f;

}

void SelectMenuScene::render()
{
    IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Blue")->loopRender(getMemDC(), &_BGRect, _LoopX, _LoopY);
    IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Pink")->render(getMemDC());
    IMAGEMANAGER->findImage("UI_FILE_SELECT_BG_Yellow")->render(getMemDC(), 803, 39);
    IMAGEMANAGER->findImage("UI_FILE_SELECT_MENU")->render(getMemDC(),
        WINSIZEX - IMAGEMANAGER->findImage("UI_FILE_SELECT_MENU")->getWidth(),
        WINSIZEY - IMAGEMANAGER->findImage("UI_FILE_SELECT_MENU")->getHeight());

    switch (_KeyCount)
    {
        case 0:
        {
            IMAGEMANAGER->findImage("UI_FILE_A")->render(getMemDC(), _x, _y[0]);

            if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
            {
                SCENEMANAGER->changeScene("CharacterSelectScene");
                SOUNDMANAGER->play("MemuConfirm", 0.3f);
            }
        }
        break;
        case 1:
        {
            IMAGEMANAGER->findImage("UI_FILE_B")->render(getMemDC(), _x, _y[1]);

            if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
            {
                SCENEMANAGER->changeScene("CharacterSelectScene");
                SOUNDMANAGER->play("MemuConfirm", 0.3f);
            }
        }
        break;
        case 2:
        {
            IMAGEMANAGER->findImage("UI_FILE_C")->render(getMemDC(), _x+1, _y[2]);

            if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
            {
                SCENEMANAGER->changeScene("CharacterSelectScene");
                SOUNDMANAGER->play("MemuConfirm", 0.3f);
            }
        }
        break;
    }
    IMAGEMANAGER->findImage("MenuFrontGround")->render(getMemDC());
    IMAGEMANAGER->findImage("UI_FILE_SELECT_FG_Character")->render(getMemDC(), _FileCharacterX, _FileCharacterY);
    IMAGEMANAGER->findImage("UI_FILE_SELECT_FG")->render(getMemDC());
}
