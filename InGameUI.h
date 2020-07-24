#pragma once
#include "gameNode.h"

class BossProgressBar;

class InGameUI : public gameNode
{
private:
	BossProgressBar* _BossProgressBar;

	int _PlayerHP;
	float _KyokoX, _MisuzuX, _KyokoY, _MisuzuY;
	int _BattleIntroAlphaValue;
	int _ScreenLockAlphaValue;
	int _BattleIntroCount;
	bool _StageToggle;

/// <summary>
	int _SimulationValue;
	bool _IsSimulKeyPress;
/// </summary>

public:
	InGameUI();
	~InGameUI();

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

