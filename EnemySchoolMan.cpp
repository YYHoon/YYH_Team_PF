#include "stdafx.h"
#include "EnemySchoolMan.h"


HRESULT EnemySchoolMan::init()
{
    return S_OK;
}

HRESULT EnemySchoolMan::Init(POINTFLOAT pt)
{
	_IsRight = true;

	_SmCenterX = pt.x;
	_SmCenterY = pt.y; 

	SmAniInit();
	SmAniSet(SmIdle);

	//적 그림자
	_SmShadowImage = IMAGEMANAGER->addImage("Showdow", "image/enemy/Enemy_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));

	_SmShadow.MYRectMakeCenter(_SmCenterX, _SmCenterY, _SmShadowImage->getWidth(), _SmShadowImage->getHeight());

	_ShadowX = (_SmShadow.left + _SmShadow.right) / 2;
	_ShadowY = (_SmShadow.top + _SmShadow.bottom) / 2;

	_SmHit.MYRectMakeCenter(_ShadowX, _ShadowY - _SmImage->getFrameHeight() / 2, _SmImage->getFrameWidth(), _SmImage->getFrameHeight());

	_EnemyX = (_SmHit.left + _SmHit.right) / 2;
	_EnemyY = (_SmHit.top +  _SmHit.bottom) / 2;

	_SmAttackExploration.MYRectMakeCenter(_SmHit.left, _EnemyY, 200, 200);

	_Hp = 10.f;
	_Speed = 3.0f;
	_ChaseAngle = 0;
	_Distance = 0;

    return S_OK;
}

void EnemySchoolMan::SmAniInit()
{
	//남학생 항복
	IMAGEMANAGER->addFrameImage("SmBegging", "image/enemy/sb/sm_begging.bmp", 0, 0, 216, 354, 2, 2, true, RGB(255, 0, 255));
	int Sm_R_Begging[] = {0,1};
	KEYANIMANAGER->addArrayFrameAnimation("SmRBegging", "SmBegging", Sm_R_Begging, 2, 10, true);
	int Sm_L_Begging[] = { 3,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLBegging", "SmBegging", Sm_L_Begging, 2, 10, true);

	//남학생 강공격 맞고 다운 및 기상
	IMAGEMANAGER->addFrameImage("SmBlownback", "image/enemy/sb/sm_blownback.bmp", 0, 0, 2970, 1260, 11, 6, true, RGB(255, 0, 255));
	int Sm_R_Blownback[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,32};
	KEYANIMANAGER->addArrayFrameAnimation("SmRBlownback", "SmBlownback", Sm_R_Blownback, 33, 10, true);
	int Sm_L_Blownback[] = { 43,42,41,40,39,38,37,36,35,34,33,54,53,52,51,50,49,48,47,46,45,44,65,64,63,62,61,60,59,58,57,56,55 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLBlownback", "SmBlownback", Sm_L_Blownback, 33, 10, true);

	//남학생 기절
	IMAGEMANAGER->addFrameImage("SmDazed", "image/enemy/sb/sm_dazed2.bmp", 0, 0, 670, 432, 4, 2, true, RGB(255, 0, 255));
	int Sm_R_Dazed[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRDazed", "SmDazed", Sm_R_Begging, 4, 10, true);
	int Sm_L_Dazed[] = { 7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLDazed", "SmDazed", Sm_L_Begging, 4, 10, true);

	//남학생 피격
	IMAGEMANAGER->addFrameImage("SmGetHit", "image/enemy/sb/sm_gethit.bmp", 0, 0, 1728, 450, 9, 2, true, RGB(255, 0, 255));
	int Sm_R_Gethit[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRGetHit", "SmGetHit", Sm_R_Gethit, 9, 10, true);
	int Sm_L_Gethit[] = { 17,16,15,14,13,12,11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLGetHit", "SmGetHit", Sm_L_Gethit, 9, 10, true);

	//남학생 걷기
	IMAGEMANAGER->addFrameImage("SmWalk", "image/enemy/sb/sm_walk.bmp", 0, 0, 1620, 444, 12, 2, true, RGB(255, 0, 255));
	int Sm_R_Walk[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRWalk", "SmWalk", Sm_R_Walk, 12, 10, true);
	int Sm_L_Walk[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLWalk", "SmWalk", Sm_L_Walk, 12, 10, true);

	//남학생 기본
	IMAGEMANAGER->addFrameImage("SmIdle", "image/enemy/sb/sm_idle.bmp", 0, 0, 1224, 432, 8, 2, true, RGB(255, 0, 255));
	int Sm_R_Idle[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRIdle", "SmIdle", Sm_R_Idle, 8, 10, true);
	int Sm_L_Idle[] = { 15,14,13,12,11,10,9,8 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLIdle", "SmIdle", Sm_L_Idle, 8, 10, true);

	//남학생 달리기
	IMAGEMANAGER->addFrameImage("SmRun", "image/enemy/sb/sm_run.bmp", 0, 0, 1920, 390, 10, 2, true, RGB(255, 0, 255));
	int Sm_R_Run[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRRun", "SmRun", Sm_R_Run, 10, 10, true);
	int Sm_L_Run[] = { 19,18,17,16,15,14,13,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLRun", "SmRun", Sm_L_Run, 10, 10, true);

	//남학생 플레이어가 무기로 쓸때
	IMAGEMANAGER->addFrameImage("SmWeponSwing", "image/enemy/sb/sm_weapon_swing.bmp", 0, 0, 2646, 456, 7, 2, true, RGB(255, 0, 255));
	int Sm_R_Wepom[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRWeponSwing", "SmWeponSwing", Sm_R_Wepom, 7, 10, true);
	int Sm_L_Wepom[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLWeponSwing", "SmWeponSwing", Sm_L_Wepom, 7, 10, true);

	//남학생 도발
	IMAGEMANAGER->addFrameImage("SmTaunt", "image/enemy/sb/sm_taunt.bmp", 0, 0, 1650, 456, 11, 2, true, RGB(255, 0, 255));
	int Sm_R_Taunt[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRTaunt", "SmTaunt", Sm_R_Taunt, 11, 10, true);
	int Sm_L_Taunt[] = { 21,20,19,18,17,16,15,14,13,12,11 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLTaunt", "SmTaunt", Sm_L_Taunt, 11, 10, true);

	//남학생 다운모션
	IMAGEMANAGER->addFrameImage("SmKnockdown", "image/enemy/sb/sm_knockdown.bmp", 0, 0, 2970, 1260, 11, 6, true, RGB(255, 0, 255));
	int Sm_R_Knockdown[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,32 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRKnockdown", "SmKnockdown", Sm_R_Knockdown, 33, 10, true);
	int Sm_L_Knockdown[] = { 43,42,41,40,39,38,37,36,35,34,33,54,53,52,51,50,49,48,47,46,45,44,65,64,63,62,61,60,59,58,57,56,55 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLKnockdown", "SmKnockdown", Sm_L_Knockdown, 33, 10, true);

	//남학생 발공격
	IMAGEMANAGER->addFrameImage("SmKick", "image/enemy/sb/sm_kick.bmp", 0, 0, 1863, 558, 9, 2, true, RGB(255, 0, 255));
	int Sm_R_Kick[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRKick", "SmKick", Sm_R_Kick, 9, 10, true);
	int Sm_L_Kick[] = { 17,16,15,14,13,12,11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLKick", "SmKick", Sm_L_Kick, 9, 10, true);

	//남학생 점프펀치
	IMAGEMANAGER->addFrameImage("SmJumpPunch", "image/enemy/sb/sm_jump_punch.bmp", 0, 0, 1188, 456, 6, 2, true, RGB(255, 0, 255));
	int Sm_R_Jump[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRJumpPunch", "SmJumpPunch", Sm_R_Jump, 6, 10, true);
	int Sm_L_Jump[] = { 11,10,9,8,7,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLJumpPunch", "SmJumpPunch", Sm_L_Jump, 6, 10, true);

	//남학생 약공 콤보 1
	IMAGEMANAGER->addFrameImage("SmStPunch", "image/enemy/sb/sm_st_punch.bmp", 0, 0, 1764, 426, 7, 2, true, RGB(255, 0, 255));
	int Sm_R_St[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRStPunch", "SmStPunch", Sm_R_St, 7, 10, true);
	int Sm_L_St[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLStPunch", "SmStPunch", Sm_L_St, 7, 10, true);

	//남학생 콤보2번쨰
	IMAGEMANAGER->addFrameImage("SmSideKick", "image/enemy/sb/sm_side_kick.bmp", 0, 0, 1764, 444, 7, 2, true, RGB(255, 0, 255));
	int Sm_R_Side[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRSideKick", "SmSideKick", Sm_R_Side, 7, 10, true);
	int Sm_L_Side[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLSideKick", "SmSideKick", Sm_L_Side, 7, 10, true);

	//남학생 강공격 콤보3
	IMAGEMANAGER->addFrameImage("SmUpercut", "image/enemy/sb/sm_upercut.bmp", 0, 0, 1386, 510, 7, 2, true, RGB(255, 0, 255));
	int Sm_R_Up[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRUpercut", "SmUpercut", Sm_R_Up, 7, 10, true);
	int Sm_L_Up[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLUpercut", "SmUpercut", Sm_L_Up, 7, 10, true);

	//남학생 잡기당한 상태로 히트시
	IMAGEMANAGER->addFrameImage("SmHoldhit", "image/enemy/sb/sm_heldhit.bmp", 0, 0, 576, 372, 3, 2, true, RGB(255, 0, 255));
	int Sm_R_hold[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRHoldhit", "SmHoldhit", Sm_R_hold, 3, 10, true);
	int Sm_L_hold[] = { 5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLHoldhit", "SmHoldhit", Sm_L_hold, 3, 10, true);

	//남학생 잡기 회복
	IMAGEMANAGER->addFrameImage("SmHoldrelease", "image/enemy/sb/sm_heldrelease.bmp", 0, 0, 589, 426, 4, 2, true, RGB(255, 0, 255));
	int Sm_R_holdRE[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SmRHoldrelease", "SmHoldrelease", Sm_R_holdRE, 4, 10, true);
	int Sm_L_holdRE[] = { 7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("SmLHoldrelease", "SmHoldrelease", Sm_L_holdRE, 4, 10, true);

}

void EnemySchoolMan::SmAniSet(SMSTATE state)
{
	if (_IsRight)
	{
		switch (state)
		{
		case SmBegging:
			_SmImage = IMAGEMANAGER->findImage("SmBegging");
			_SmAni = KEYANIMANAGER->findAnimation("SmRBegging");
			_SmAni->start();
			_SmState = SmBegging;
			break;
		case SmBlownback:
			_SmImage = IMAGEMANAGER->findImage("SmBlownback");
			_SmAni = KEYANIMANAGER->findAnimation("SmRBlownback");
			_SmAni->start();
			_SmState = SmBlownback;
			break;
		case SmDazed:
			_SmImage = IMAGEMANAGER->findImage("SmDazed");
			_SmAni = KEYANIMANAGER->findAnimation("SmRDazed");
			_SmAni->start();
			_SmState = SmDazed;
			break;
		case SmGethit:
			_SmImage = IMAGEMANAGER->findImage("SmGetHit");
			_SmAni = KEYANIMANAGER->findAnimation("SmRGetHit");
			_SmAni->start();
			_SmState = SmGethit;
			break;
		case SmHoldhit:
			_SmImage = IMAGEMANAGER->findImage("SmHoldhit");
			_SmAni = KEYANIMANAGER->findAnimation("SmRHoldhit");
			_SmAni->start();
			_SmState = SmHoldhit;
			break;
		case SmHoldrelrase:
			_SmImage = IMAGEMANAGER->findImage("SmHoldrelease");
			_SmAni = KEYANIMANAGER->findAnimation("SmRHoldrelease");
			_SmAni->start();
			_SmState = SmHoldrelrase;
			break;
		case SmIdle:
			_SmImage = IMAGEMANAGER->findImage("SmIdle");
			_SmAni = KEYANIMANAGER->findAnimation("SmRIdle");
			_SmAni->start();
			_SmState = SmIdle;
			break;
		case SmJumpPunch:
			_SmImage = IMAGEMANAGER->findImage("SmJumpPunch");
			_SmAni = KEYANIMANAGER->findAnimation("SmRJumpPunch");
			_SmAni->start();
			_SmState = SmJumpPunch;
			break;
		case SmKick:
			_SmImage = IMAGEMANAGER->findImage("SmKick");
			_SmAni = KEYANIMANAGER->findAnimation("SmRKick");
			_SmAni->start();
			_SmState = SmKick;
			break;
		case SmKnockdown:
			_SmImage = IMAGEMANAGER->findImage("SmKnockdown");
			_SmAni = KEYANIMANAGER->findAnimation("SmRKnockdown");
			_SmAni->start();
			_SmState = SmKnockdown;
			break;
		case SmRun:
			_SmImage = IMAGEMANAGER->findImage("SmRun");
			_SmAni = KEYANIMANAGER->findAnimation("SmRRun");
			_SmAni->start();
			_SmState = SmRun;
			break;
		case SmSideKick:
			_SmImage = IMAGEMANAGER->findImage("SmSideKick");
			_SmAni = KEYANIMANAGER->findAnimation("SmRSideKick");
			_SmAni->start();
			_SmState = SmSideKick;
			break;
		case SmStPunch:
			_SmImage = IMAGEMANAGER->findImage("SmStPunch");
			_SmAni = KEYANIMANAGER->findAnimation("SmRStPunch");
			_SmAni->start();
			_SmState = SmStPunch;
			break;
		case SmTaunt:
			_SmImage = IMAGEMANAGER->findImage("SmTaunt");
			_SmAni = KEYANIMANAGER->findAnimation("SmRTaunt");
			_SmAni->start();
			_SmState = SmTaunt;
			break;
		case SmUpercut:
			_SmImage = IMAGEMANAGER->findImage("SmUpercut");
			_SmAni = KEYANIMANAGER->findAnimation("SmRUpercut");
			_SmAni->start();
			_SmState = SmUpercut;
			break;
		case SmWalk:
			_SmImage = IMAGEMANAGER->findImage("SmWalk");
			_SmAni = KEYANIMANAGER->findAnimation("SmRWalk");
			_SmAni->start();
			_SmState = SmWalk;
			break;
		case SmWeaponSwing:
			_SmImage = IMAGEMANAGER->findImage("SmWeponSwing");
			_SmAni = KEYANIMANAGER->findAnimation("SmRWeponSwing");
			_SmAni->start();
			_SmState = SmWeaponSwing;
			break;	
		}
	}
	else
	{
		switch (state)
		{
		case SmBegging:
			_SmImage = IMAGEMANAGER->findImage("SmBegging");
			_SmAni = KEYANIMANAGER->findAnimation("SmLBegging");
			_SmAni->start();
			_SmState = SmBegging;
			break;
		case SmBlownback:
			_SmImage = IMAGEMANAGER->findImage("SmBlownback");
			_SmAni = KEYANIMANAGER->findAnimation("SmLBlownback");
			_SmAni->start();
			_SmState = SmBlownback;
			break;
		case SmDazed:
			_SmImage = IMAGEMANAGER->findImage("SmDazed");
			_SmAni = KEYANIMANAGER->findAnimation("SmLDazed");
			_SmAni->start();
			_SmState = SmDazed;
			break;
		case SmGethit:
			_SmImage = IMAGEMANAGER->findImage("SmGetHit");
			_SmAni = KEYANIMANAGER->findAnimation("SmLGetHit");
			_SmAni->start();
			_SmState = SmGethit;
			break;
		case SmHoldhit:
			_SmImage = IMAGEMANAGER->findImage("SmHoldhit");
			_SmAni = KEYANIMANAGER->findAnimation("SmLHoldhit");
			_SmAni->start();
			_SmState = SmHoldhit;
			break;
		case SmHoldrelrase:
			_SmImage = IMAGEMANAGER->findImage("SmHoldrelease");
			_SmAni = KEYANIMANAGER->findAnimation("SmLHoldrelease");
			_SmAni->start();
			_SmState = SmHoldrelrase;
			break;
		case SmIdle:
			_SmImage = IMAGEMANAGER->findImage("SmIdle");
			_SmAni = KEYANIMANAGER->findAnimation("SmLIdle");
			_SmAni->start();
			_SmState = SmIdle;
			break;
		case SmJumpPunch:
			_SmImage = IMAGEMANAGER->findImage("SmJumpPunch");
			_SmAni = KEYANIMANAGER->findAnimation("SmLJumpPunch");
			_SmAni->start();
			_SmState = SmJumpPunch;
			break;
		case SmKick:
			_SmImage = IMAGEMANAGER->findImage("SmKick");
			_SmAni = KEYANIMANAGER->findAnimation("SmLKick");
			_SmAni->start();
			_SmState = SmKick;
			break;
		case SmKnockdown:
			_SmImage = IMAGEMANAGER->findImage("SmKnockdown");
			_SmAni = KEYANIMANAGER->findAnimation("SmLKnockdown");
			_SmAni->start();
			_SmState = SmKnockdown;
			break;
		case SmRun:
			_SmImage = IMAGEMANAGER->findImage("SmRun");
			_SmAni = KEYANIMANAGER->findAnimation("SmLRun");
			_SmAni->start();
			_SmState = SmRun;
			break;
		case SmSideKick:
			_SmImage = IMAGEMANAGER->findImage("SmSideKick");
			_SmAni = KEYANIMANAGER->findAnimation("SmLSideKick");
			_SmAni->start();
			_SmState = SmSideKick;
			break;
		case SmStPunch:
			_SmImage = IMAGEMANAGER->findImage("SmStPunch");
			_SmAni = KEYANIMANAGER->findAnimation("SmLStPunch");
			_SmAni->start();
			_SmState = SmStPunch;
			break;
		case SmTaunt:
			_SmImage = IMAGEMANAGER->findImage("SmTaunt");
			_SmAni = KEYANIMANAGER->findAnimation("SmLTaunt");
			_SmAni->start();
			_SmState = SmTaunt;
			break;
		case SmUpercut:
			_SmImage = IMAGEMANAGER->findImage("SmUpercut");
			_SmAni = KEYANIMANAGER->findAnimation("SmLUpercut");
			_SmAni->start();
			_SmState = SmUpercut;
			break;
		case SmWalk:
			_SmImage = IMAGEMANAGER->findImage("SmWalk");
			_SmAni = KEYANIMANAGER->findAnimation("SmLWalk");
			_SmAni->start();
			_SmState = SmWalk;
			break;
		case SmWeaponSwing:
			_SmImage = IMAGEMANAGER->findImage("SmWeponSwing");
			_SmAni = KEYANIMANAGER->findAnimation("SmLWeponSwing");
			_SmAni->start();
			_SmState = SmWeaponSwing;
			break;
		}
	}
}

void EnemySchoolMan::SmState()
{
	if (_IsRight)
	{
		switch (_SmState)
		{
		case SmBegging:
			break;
		case SmBlownback:
			break;
		case SmDazed:
			break;
		case SmGethit:
			break;
		case SmHoldhit:
			break;
		case SmHoldrelrase:
			break;
		case SmIdle:
			break;
		case SmJumpPunch:
			break;
		case SmKick:
			break;
		case SmKnockdown:
			break;
		case SmRun:
			break;
		case SmSideKick:
			break;
		case SmStPunch:
			break;
		case SmTaunt:
			break;
		case SmUpercut:
			break;
		case SmWalk:
			break;
		case SmWeaponSwing:
			break;
		}
	}
	else
	{
		switch (_SmState)
		{
		case SmBegging:
			break;
		case SmBlownback:
			break;
		case SmDazed:
			break;
		case SmGethit:
			break;
		case SmHoldhit:
			break;
		case SmHoldrelrase:
			break;
		case SmIdle:
			break;
		case SmJumpPunch:
			break;
		case SmKick:
			break;
		case SmKnockdown:
			break;
		case SmRun:
			break;
		case SmSideKick:
			break;
		case SmStPunch:
			break;
		case SmTaunt:
			break;
		case SmUpercut:
			break;
		case SmWalk:
			break;
		case SmWeaponSwing:
			break;
		}
	}
}

void EnemySchoolMan::Release()
{
}

void EnemySchoolMan::Update()
{
	_Time++;

	//_Distance = getDistance(_EnemyX, _EnemyY, _Test->GetCnetX(), _Test->GetCnetY());
	//_ChaseAngle = getAngle(_EnemyX, _EnemyY, _Test->GetCnetX(), _Test->GetCnetY());
	//
	//if (_SmCenterX > _Test->GetCnetX())
	//{
	//	_IsRight = false;
	//}
	//else if (_SmCenterX < _Test->GetCnetX())
	//{
	//	_IsRight = true;
	//}

	if (_IsRight)
	{
		if (_Distance > 75 && _Distance < 300)
		{
			if (_SmState != SmWalk) SmAniSet(SmWalk);

			_SmCenterX += cosf(_ChaseAngle) * _Speed;
			_SmCenterY += -sinf(_ChaseAngle) * _Speed;
		}

		if (_Distance < 600 && _Distance > 300)
		{
			if (_SmState != SmRun)  SmAniSet(SmRun);
			_SmCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
			_SmCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
		}
		if (_Distance <= 75)
		{
			if (_SmState != SmStPunch)
			{
				SmAniSet(SmStPunch);
				_SmAttack.MYRectMakeCenter(_EnemyX + 50, _EnemyY, 80, 150);
			}
		}
	}
	else
	{
		if (_Distance > 75 && _Distance < 300)
		{
			if (_SmState != SmWalk) SmAniSet(SmWalk);

			_SmCenterX += cosf(_ChaseAngle) * _Speed;
			_SmCenterY += -sinf(_ChaseAngle) * _Speed;
		}

		if (_Distance < 600 && _Distance > 300)
		{
			if (_SmState != SmRun)  SmAniSet(SmRun);
			_SmCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
			_SmCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
		}

		if (_Distance <= 75)
		{
			if (_SmState != SmStPunch)
			{
				SmAniSet(SmStPunch);
				_SmAttack.MYRectMakeCenter(_EnemyX - 50, _EnemyY, 80, 150);
			}
		}
	}

/////////////////////////////////////////////////////////////////////////////

	_SmShadow.MYRectMakeCenter(_SmCenterX, _SmCenterY, _SmShadowImage->getWidth(), _SmShadowImage->getHeight());

	_ShadowX = (_SmShadow.left + _SmShadow.right) / 2;
	_ShadowY = (_SmShadow.top + _SmShadow.bottom) / 2;

	_SmHit.MYRectMakeCenter(_ShadowX, _ShadowY - _SmImage->getFrameHeight() / 2, _SmImage->getFrameWidth(), _SmImage->getFrameHeight());

	_EnemyX = (_SmHit.left + _SmHit.right) / 2;
	_EnemyY = (_SmHit.top + _SmHit.bottom) / 2;

	if (_IsRight)
	{
		_SmAttackExploration.MYRectMakeCenter(_SmHit.right, _EnemyY, 200, 200);
	}
	else
	{
		_SmAttackExploration.MYRectMakeCenter(_SmHit.left, _EnemyY, 200, 200);
	}
///////////////////////////////////////////////////////////////////////////
	KEYANIMANAGER->update();
}


void EnemySchoolMan::Render()
{
	//_SmAttackExploration.render(getMemDC());
	_SmShadowImage->render(getMemDC(), _SmShadow.left, _SmShadow.top);
	_SmAttack.render(getMemDC());
	_SmImage->aniRender(getMemDC(), _SmHit.left, _SmHit.top, _SmAni);
}

void EnemySchoolMan::SmHitHP(float damge)
{
	_Hp -= damge;
}
