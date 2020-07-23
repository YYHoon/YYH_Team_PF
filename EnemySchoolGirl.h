#pragma once
#include "gameNode.h"



enum SGSTATE
{
	SgBegging,
	SgBlownback,
	SgDazed,
	SgGethit,
	SgHold,
	SgHoldhit,
	SgHoldrelrase,
	SgIdle,
	SgJumpKnee,
	SgKick,
	SgKnockdown,
	SgRun,
	SgJab,
	SgTaunt,
	SgWalk,
	SgWeaponSwing
};

class EnemySchoolGirl : public gameNode
{
private:
	

	SGSTATE _SgState;

	animation* _SgAni;

	image* _SgShadowImage;
	image* _SgImage;

	MYRECT _SgShadow;				//적 그림자
	MYRECT _SgHit;					//적 캐릭터 및 충돌처리용 사각형
	MYRECT _SgAttackExploration;	//플레이어 들어올시 공격하는 영역
	MYRECT _SgAttack;				//적이 공격시 충돌처리용

	float _SgCenterX, _SgCenterY;
	float _ShadowX, _ShadowY;  //그림자의 중점(캐릭터그릴떄 사용)
	float _EnemyX, _EnemyY;    //캐릭터의 중점(공격 영역및 공격시 사용)

	float _ChaseAngle;
	float _Distance;

	float _Hp;
	float _StunGage;
	float _Speed;

	float _CountTime;

	int _Time;

	int _StunTime;

	bool _IsRight; //왼쪽오른쪽

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	void SgState();

	float GetSchoolGirlCenterX() { return _SgCenterX; } //중점	
	float GetSchoolGirlCenterY() { return _SgCenterY; } //중점	
	float GetChaseAngle() { return _ChaseAngle; }
	MYRECT GetSchoolGirlHit() { return _SgHit; }	//피격영역
	MYRECT GetSchoolGirlAttackExplor() { return _SgAttackExploration; } //플레이어가 들어올시 공격
	MYRECT GetSchoolGirlAttack() { return _SgAttack; } //공격시 영역

	SGSTATE GetSgState() { return _SgState; }

	POINTFLOAT GetPt() { POINTFLOAT temp; temp.x = _SgCenterX; temp.y = _SgCenterY; return temp; }

	
	float GetHP() { return _Hp; }
	float GetStunGage() { return _StunGage;  }

	void SmHitHP(float damge);
	void SetStunGage(float damge);



	void SetCenterX(float x);
	void SetCenterY(float y);
};