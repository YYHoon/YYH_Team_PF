#pragma once
#include "gameNode.h"
#include "Player.h"


enum SMSTATE
{
	SmBegging,
	SmBlownback,
	SmDazed,
	SmGethit,
	SmHoldhit,
	SmHoldrelrase,
	SmIdle,
	SmJumpPunch,
	SmKick,
	SmKnockdown,
	SmRun,
	SmSideKick,
	SmStPunch,
	SmTaunt,
	SmUpercut,
	SmWalk,
	SmWeaponSwing
};

class EnemySchoolMan : public gameNode
{
private:
	SMSTATE _SmState;

	animation* _SmAni;

	Player* _ply;

	image* _SmShadowImage;
	image* _SmImage;

	MYRECT _SmShadow;				//�� �׸���
	MYRECT _SmHit;				    //�� ĳ���� �� �浹ó���� �簢��
	MYRECT _SmAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _SmAttack;				//���� ���ݽ� �浹ó����

	float _SmCenterX, _SmCenterY;

	float _ShadowX, _ShadowY; //�׸����� ���� (EnemyCore�� ���)

	float _EnemyX, _EnemyY; //ĳ������ ����

	float _ChaseAngle;
	float _Distance;

	int _Time;

	float _Speed;
	float _Hp;

	bool _IsRight; //���ʿ�����

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SmAniInit();
	void SmAniSet(SMSTATE state);

	void SmState();

	virtual void Release();
	virtual void Update();
	virtual void Render();

	float GetSmCenterX() { return _SmCenterX;  }
	float GetSmCenterY() { return _SmCenterY; }
	MYRECT GetSchoolManHit() { return _SmHit; } //�ǰݿ���
	MYRECT GetSchoolManAttackExploration() { return _SmAttackExploration; }
	MYRECT GetSchoolManAttack() { return _SmAttack; }


	SMSTATE GetSmState() { return _SmState; }

	POINTFLOAT GetSmPt() { POINTFLOAT temp; temp.x = _SmCenterX; temp.y = _SmCenterY; return temp; }

	void SetSmCenterX(float x) { _SmCenterX	= x;}
	void SetSmCenterY(float y) { _SmCenterY = y;}

	void SmHitHP(float damge);

	float setHP() { return _Hp; }

	void SetPlayer(Player* _p) { _ply = _p; }
};