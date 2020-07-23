#pragma once
#include "gameNode.h"
#include "Player.h"

enum SGSTATE
{
	SgIdle,
	SgBegging,
	SgBlownback,
	SgDazed,
	SgGethit,
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
	SgWeaponSwing
};

class EnemySchoolGirl : public gameNode
{
private:

	SGSTATE _SgState;

	animation* _SgAni;
	Player* _pl;
	image* _SgShadowImage;
	image* _SgImage;

	MYRECT _SgShadow;				//�� �׸���
	MYRECT _SgHit;					//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _SgAttack;				//���� ���ݽ� �浹ó����
	MYRECT _SgLAttack;

	float _ShadowX, _ShadowY;  //�׸����� ����(ĳ���ͱ׸��� ���)
	float _EnemyX, _EnemyY;    //ĳ������ ����(���� ������ ���ݽ� ���)

	float _ChaseAngle;
	float _Distance;

	int _Hp;
	float _StunGage;
	float _Speed;

	float _CountTime;

	int _Time;

	int _StunTime;

	bool _IsRight; //���ʿ�����
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

	void SgState();

	float GetSchoolGirlCenterX() { return _SgCenterX; } //����	
	float GetSchoolGirlCenterY() { return _SgCenterY; } //����	

	float GetSchoolGirlX() { return _EnemyX; }
	float GetSchoolGirlY() { return _EnemyY; }

	float GetChaseAngle() { return _ChaseAngle; }
	MYRECT GetSchoolGirlHit() { return _SgHit; }	//�ǰݿ���
	MYRECT GetSchoolGirlAttack() { return _SgAttack; } //���ݽ� ����

	SGSTATE GetSgState() { return _SgState; }

	POINTFLOAT GetPt() { POINTFLOAT temp; temp.x = _SgCenterX; temp.y = _SgCenterY; return temp; }

	float GetHP() { return _Hp; }
	float GetStunGage() { return _StunGage;  }

	void SmHitHP(float damge);
	void SetStunGage(float damge);

	void SetCenterX(float x);
	void SetCenterY(float y);

	void SetPlayer(Player* _p) { _pl = _p; }
};