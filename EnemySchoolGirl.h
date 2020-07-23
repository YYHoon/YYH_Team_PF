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

	MYRECT _SgShadow;				//�� �׸���
	MYRECT _SgHit;					//�� ĳ���� �� �浹ó���� �簢��
	MYRECT _SgAttackExploration;	//�÷��̾� ���ý� �����ϴ� ����
	MYRECT _SgAttack;				//���� ���ݽ� �浹ó����

	float _SgCenterX, _SgCenterY;
	float _ShadowX, _ShadowY;  //�׸����� ����(ĳ���ͱ׸��� ���)
	float _EnemyX, _EnemyY;    //ĳ������ ����(���� ������ ���ݽ� ���)

	float _ChaseAngle;
	float _Distance;

	float _Hp;
	float _StunGage;
	float _Speed;

	float _CountTime;

	int _Time;

	int _StunTime;

	bool _IsRight; //���ʿ�����

public:
	virtual HRESULT init();
	virtual HRESULT Init(POINTFLOAT pt);

	void SgAniInit();
	void SgAniSet(SGSTATE state);

	virtual void Release();
	virtual void Update();
	virtual void Render();

	void SgState();

	float GetSchoolGirlCenterX() { return _SgCenterX; } //����	
	float GetSchoolGirlCenterY() { return _SgCenterY; } //����	
	float GetChaseAngle() { return _ChaseAngle; }
	MYRECT GetSchoolGirlHit() { return _SgHit; }	//�ǰݿ���
	MYRECT GetSchoolGirlAttackExplor() { return _SgAttackExploration; } //�÷��̾ ���ý� ����
	MYRECT GetSchoolGirlAttack() { return _SgAttack; } //���ݽ� ����

	SGSTATE GetSgState() { return _SgState; }

	POINTFLOAT GetPt() { POINTFLOAT temp; temp.x = _SgCenterX; temp.y = _SgCenterY; return temp; }

	
	float GetHP() { return _Hp; }
	float GetStunGage() { return _StunGage;  }

	void SmHitHP(float damge);
	void SetStunGage(float damge);



	void SetCenterX(float x);
	void SetCenterY(float y);
};