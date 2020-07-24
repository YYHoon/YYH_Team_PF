#pragma once
#include "gameNode.h"
#include "Player.h"

enum SGSTATE
{
	SgIdle,
	SgBegging,
	SgBlownback,
	SgDazed,
	SgGetOnehit,
	SgGetTwohit,
	SgGetThreehit,
	SgHold,
	SgHoldhit,
	SgHoldrelrase,
	SgJumpKnee,
	SgKick,
	SgKnockdown,
	SgRun,
	SgJab,
	SgTaunt,
	SgWalk,
	SgWeaponSwing,
	SgDown,
	SgUp
};

class EnemySchoolGirl : public gameNode
{
private:

	SGSTATE _SgState;

	animation* _SgAni;
	Player* _pl;
	image* _SgShadowImage;
	image* _SgImage;

	MYRECT _SgShadow;				//적 그림자
	MYRECT _SgHit;					//적 캐릭터 및 충돌처리용 사각형
	MYRECT _SgAttack;				//적이 공격시 충돌처리용
	MYRECT _SgLAttack;

	float _ShadowX, _ShadowY;  //그림자의 중점(캐릭터그릴떄 사용)
	float _EnemyX, _EnemyY;    //캐릭터의 중점(공격 영역및 공격시 사용)

	float _ChaseAngle; //이동관련된거	
	float _Distance;   //이동관련된거	

	int _Hp;
	float _StunGage;
	float _Speed;

	float _CountTime;

	float setX, setY;

	int _Time;
	int _NTime;

	bool _IsRight; //왼쪽오른쪽
	bool _IsLeft;

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float _SgCenterX, _SgCenterY;


	float GetSchoolGirlCenterX() { return _SgCenterX; } //중점	
	float GetSchoolGirlCenterY() { return _SgCenterY; } //중점	

	float GetSchoolGirlX() { return _EnemyX; }
	float GetSchoolGirlY() { return _EnemyY; }

	float GetChaseAngle() { return _ChaseAngle; }
	MYRECT GetSchoolGirlHit() { return _SgHit; }	//피격영역
	MYRECT GetSchoolGirlAttack() { return _SgAttack; } //공격시 영역

	POINTFLOAT GetPt() { POINTFLOAT temp; temp.x = _SgCenterX; temp.y = _SgCenterY; return temp; }

	float GetHP() { return _Hp; }

	SGSTATE GetSgState() { return _SgState; }
	animation* GetSgAni() { return _SgAni;}

	void SmHitHP(float damge);
	void SetStunGage(float damge);

	void SetCenterX(float x);
	void SetCenterY(float y);


	void SetSgImage(image* Sgim) { _SgImage = Sgim; }
	void SetPlayer(Player* _p) { _pl = _p; }
	void SetSgState(SGSTATE stat) { _SgState = stat; }
	void SetSgAni(animation* ani) { _SgAni = ani; }

	static void RightBlownback(void* obj);
	static void RightDown(void* obj);
	static void RightUp(void* obj);

	static void LeftBlownback(void* obj);
	static void LeftDown(void* obj);
	static void LeftUp(void* obj);
	void LeftTherr(void* obj);
	void RightTherr(void* obj);
};