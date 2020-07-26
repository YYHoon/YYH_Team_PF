#pragma once
#include "gameNode.h"
#include "Player.h"

class BossProgressBar;

class InGameUI : public gameNode
{
private:
	BossProgressBar* _BossProgressBar;
	Player* _Player;

	int _PlayerHP;
	float _KyokoX, _MisuzuX, _KyokoY, _MisuzuY;
	int _BattleIntroAlphaValue;
	int _ScreenLockAlphaValue;
	int _BattleIntroCount;
	int _Bosscount = 0;
	bool _StageToggle;
	bool _StageBoss;
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
	void SetFight(bool enter) { _StageBoss = enter; }
	void SetStageToggle(bool isEvent) { _StageToggle = isEvent; }
	void SetStageBoss(bool isEvent) { _IsSimulKeyPress = isEvent; }
	void SetPlayerHP(int hp) { _PlayerHP = hp; }
};

