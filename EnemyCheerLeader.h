#pragma once
#include "gameNode.h"
#include "Player.h"

enum CLSTATE
{
	CLIdle,
	CLBegging,
	CLBlowback,
	CLDazed,
	CLFalling,
	CLHolding,
	CLHoldingrelease,
	CLJump,
	CLKnockdown,
	CLWalk,
	CLRun,
	CLJab,
	CLSpinpom,
	CLDoublepom,
	CLBackflip,
	CLWeaponSwing
};

class EnemyCheerLeader : public gameNode
{
private:
	CLSTATE _ClState;

	Player* _pla;

	animation* _CLAni;

	image* _EnemyShadowImage;	//그림자 이미지(중요함)
	image* _EnemyImage;		//캐릭터 이미지 자주 달라진다

	MYRECT _EnemyShadow;			//적 그림자
	MYRECT _Enemy;					//적 캐릭터 및 충돌처리용 사각형
	MYRECT _EnemyAttackExploration;	//플레이어 들어올시 공격하는 영역
	MYRECT _EnemyAttack;			//적을 공격시 충돌처리용

	float _ClCenterX, _ClCenterY;

	float _ShadowX, _ShadowY; //그림자의 중점 (Enemy에 사용)

	float _EnemyX, _EnemyY; //캐릭터의 중점

	float _ChaseAngle;
	float _Distance;

	float _Speed;
	int _Hp;
	int _Time;

	bool _IsRight; //왼쪽오른쪽

public:

	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void AniInit();
	void AniSet(CLSTATE state);

	void State();

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetEnemyX() { return _ClCenterX; }
	float GetEnemyY() { return _ClCenterY; }
	MYRECT GetEnemyHit() { return _Enemy; } //피격영역
	MYRECT GetEnemyAttackExploration() { return _EnemyAttackExploration; } //플레이어가 들어올시 공격
	MYRECT GetCheerLeaderAttack() { return _EnemyAttack; } //공격시 영역

	CLSTATE GetClState() { return _ClState; }

	POINTFLOAT GetCLPt() { POINTFLOAT temp; temp.x = _ClCenterX; temp.y = _ClCenterY; return temp; }

	void SetCenterX(float x);
	void SetCenterY(float y);

	void SetDamge(float damge);

	int GetHP() { return _Hp; }

	void SetPlayer(Player* _p) { _pla = _p; }
};