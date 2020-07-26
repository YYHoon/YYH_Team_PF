#include "stdafx.h"
#include "InGameUI.h"
#include "BossProgressBar.h"

InGameUI::InGameUI()
{
}

InGameUI::~InGameUI()
{
}

HRESULT InGameUI::init()
{


	IMAGEMANAGER->findImage("KyokoIntro")->setX(_KyokoX);

	_KyokoX = -IMAGEMANAGER->findImage("KyokoIntro")->getWidth();
	_KyokoY = WINSIZEY - IMAGEMANAGER->findImage("KyokoIntro")->getHeight();

	_MisuzuX = WINSIZEX + IMAGEMANAGER->findImage("fx_battle_portraits_misuzu")->getWidth();
	_MisuzuY = WINSIZEY - IMAGEMANAGER->findImage("fx_battle_portraits_misuzu")->getHeight();
	_BattleIntroCount = 0;
	_BattleIntroAlphaValue = 0;
	_ScreenLockAlphaValue = 0;
	_StageToggle = true;
	/// <summary>
	_SimulationValue = 100;
	_IsSimulKeyPress = false;
	/// </summary>
	return S_OK;
}

void InGameUI::release()
{
	
}

void InGameUI::update()
{
	if (_KyokoX < -30) _KyokoX += 40.0f;
	if (_MisuzuX > 1000) _MisuzuX -= 100.0f;
}

void InGameUI::render()
{
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD5)) _StageToggle = false;
	if (KEYMANAGER->isOnceKeyUp(VK_NUMPAD5))  _StageToggle = true;
	if (!_StageToggle)
	{
		IMAGEMANAGER->findImage("UI_Screen_Lock_Chain")->alphaRender(getMemDC(), _ScreenLockAlphaValue);
		if (_ScreenLockAlphaValue <= 255)
		{
			_ScreenLockAlphaValue += 50;
			if (_ScreenLockAlphaValue > 255) _ScreenLockAlphaValue = 255;
		}
	}

	if (_StageToggle)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5))
		{
			_StageToggle = false;
		}
		IMAGEMANAGER->findImage("UI_Screen_Lock_Chain")->alphaRender(getMemDC(), _ScreenLockAlphaValue);
		if (_ScreenLockAlphaValue >= 0)
		{
			_ScreenLockAlphaValue -= 50;
			if (_ScreenLockAlphaValue < 0) _ScreenLockAlphaValue = 0;
		}
	}

	IMAGEMANAGER->findImage("UI_FrontEnd_FileSelect_002_LETTERBOX")->render(getMemDC());
	IMAGEMANAGER->findImage("UI_HUD_player_BG")->render(getMemDC(), 310, 42);
	IMAGEMANAGER->findImage("UI_HUD_Nplayer_BG")->render(getMemDC(), 1045, 42);
	IMAGEMANAGER->findImage("UI_RCG_HUD_portrait_Kyoko_default")->render(getMemDC(), 201, 1);

	if (_PlayerHP >= 24) _PlayerHP = 24;

	for (int i = 0; i < _PlayerHP; i++)
	{
		IMAGEMANAGER->findImage("UI_HUD_player_Digit")->render(getMemDC(), 13 * i + 324, 42);
	}

	if (_StageBoss)
	{
		IMAGEMANAGER->findImage("UI_FrontEnd_FileSelect_002_LETTERBOX")->render(getMemDC());
		IMAGEMANAGER->findImage("UI_BOSS_Dialog_Alpha")->alphaRender(getMemDC(), 100);
		_Bosscount++;
		cout << _Bosscount << endl;
		if (_Bosscount<=50)
		{
			IMAGEMANAGER->findImage("KyokoIntro")->render(getMemDC(), _KyokoX, _KyokoY);
			IMAGEMANAGER->findImage("fx_battle_portraits_misuzu")->render(getMemDC(), _MisuzuX, _MisuzuY);
			IMAGEMANAGER->findImage("fx_vs_L_CORNER_PINK")->alphaRender(getMemDC(), -50, WINSIZEY - IMAGEMANAGER->findImage("fx_vs_L_CORNER_PINK")->getHeight(), _BattleIntroAlphaValue);
			IMAGEMANAGER->findImage("fx_vs_R_CORNER_PINK")->alphaRender(getMemDC(), 50 + WINSIZEX - IMAGEMANAGER->findImage("fx_vs_R_CORNER_PINK")->getWidth(), WINSIZEY - IMAGEMANAGER->findImage("fx_vs_R_CORNER_PINK")->getWidth(), _BattleIntroAlphaValue);
			IMAGEMANAGER->findImage("UI_Battle_Intro")->alphaRender(getMemDC(), 0, 510, _BattleIntroAlphaValue);

			if (_BattleIntroAlphaValue < 255)_BattleIntroAlphaValue += 40;
			if (_BattleIntroAlphaValue >= 255) _BattleIntroAlphaValue = 255;
		}

		if (_Bosscount>50)
		{
			if (_BattleIntroAlphaValue > 0) _BattleIntroAlphaValue -= 40;
			if (_BattleIntroAlphaValue <= 0) {
				_BattleIntroAlphaValue = 0;
				_StageBoss = false;
			}
		}
	}

	if (_PlayerHP < 0)
	{
		_PlayerHP = 0;
		//SCENEMANAGER->changeScene("");
	}

}
