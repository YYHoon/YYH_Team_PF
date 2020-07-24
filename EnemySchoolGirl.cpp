#include "stdafx.h"
#include "EnemySchoolGirl.h"

HRESULT EnemySchoolGirl::init()
{
	return S_OK;
}

HRESULT EnemySchoolGirl::Init(POINTFLOAT pt)
{
	_IsRight = true;
	_IsLeft = false;
	SgAniInit();
	SgAniSet(SgIdle);

	//_SgState = SgIdle;

	_SgCenterX = pt.x;
	_SgCenterY = pt.y;

	//적 그림자
	_SgShadowImage = IMAGEMANAGER->addImage("Showdow", "image/enemy/Enemy_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));

	_SgShadow.MYRectMakeCenter(_SgCenterX, _SgCenterY, _SgShadowImage->getWidth(), _SgShadowImage->getHeight());

	_ShadowX = (_SgShadow.left + _SgShadow.right) / 2;
	_ShadowY = (_SgShadow.top + _SgShadow.bottom) / 2;

	_SgHit.MYRectMakeCenter(_ShadowX, _ShadowY - _SgImage->getFrameHeight() / 2, _SgImage->getFrameWidth(), _SgImage->getFrameHeight());

	_EnemyX = (_SgHit.left + _SgHit.right) / 2;
	_EnemyY = (_SgHit.top + _SgHit.bottom) / 2;

	_Hp = 10;
	_Speed = 3.0f;
	_ChaseAngle = 0;
	_Distance = 0;
	_Time = _NTime = 0;

	setX = setY = 0;

	return S_OK;
}

void EnemySchoolGirl::Release()
{

}

void EnemySchoolGirl::Update()
{
	_Time++;

	_Distance = getDistance(_SgCenterX, _SgCenterY, _pl->GetShadowCenterX(), _pl->GetShadowCenterY());
	_ChaseAngle = getAngle(_SgCenterX, _SgCenterY, _pl->GetShadowCenterX(), _pl->GetShadowCenterY());

	if (_SgCenterX < _pl->GetShadowCenterX())
	{
		_IsRight = true;
		_IsLeft = false;
	}
	if (_SgCenterX >= _pl->GetShadowCenterX())
	{
		_IsRight = false;
		_IsLeft = true;
	}

	if (_IsRight && !_IsLeft)
	{
		if (_Distance > 75 && _Distance <= 299 && _SgState != SgBegging && _SgState != SgGetOnehit && _SgState != SgGetTwohit && _SgState != SgGetThreehit)
		{
			if (_SgState != SgWalk ) SgAniSet(SgWalk);			
		}
		if (_Distance < 600 && _Distance >= 300 && _SgState != SgBegging && _SgState != SgGetOnehit && _SgState != SgGetTwohit && _SgState != SgGetThreehit)
		{
			if (_SgState != SgRun)  SgAniSet(SgRun);
		}
		if (_Distance > 600 && _SgState != SgBegging && _SgState != SgBlownback && _SgState != SgDown && _SgState != SgUp 
			&& _SgState != SgGetOnehit && _SgState != SgGetTwohit && _SgState != SgGetThreehit)
		{
			if (_SgState != SgIdle) SgAniSet(SgIdle);
		}
		if (_Time < 100)
		{
			if (_Distance <= 75 && _SgState != SgBegging && _SgState != SgGetOnehit)
			{
				if (_SgState != SgJab) SgAniSet(SgJab);	
			}
		}
		if (_Time >= 100 && _Time <= 150)
		{
			if (_Distance <= 75 && _SgState != SgBegging && _SgState != SgGetOnehit)
			{
				if (_SgState != SgJumpKnee) SgAniSet(SgJumpKnee);
			}
		}

		if (_SgState != SgWalk && _SgState != SgRun && _Time > 150)
		{
			if (_Distance <= 75 && _SgState != SgBegging && _SgState != SgGetOnehit)
			{
				if (_SgState != SgKick) SgAniSet(SgKick);				
				if (_Time > 200) _Time = 0;
			}
		}

		if (isCollision(_SgHit, _pl->GetAttackRC1()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}

		if (isCollision(_SgHit, _pl->GetAttackRC2()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}

		if (isCollision(_SgHit, _pl->GetAttackRC3()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}

		if (isCollision(_SgHit, _pl->GetAttackRCH()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}

		if (isCollision(_SgHit, _pl->GetAttackRCDAP()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}
	}
	if (!_IsRight && _IsLeft)
	{
		if (_Distance > 75 && _Distance <= 299 && _SgState != SgBegging && _SgState != SgGetOnehit && _SgState != SgGetTwohit && _SgState != SgGetThreehit)
		{
			if (_SgState != SgWalk) SgAniSet(SgWalk);
		}
		if (_Distance < 600 && _Distance >= 300 && _SgState != SgBegging && _SgState != SgGetOnehit && _SgState != SgGetTwohit && _SgState != SgGetThreehit)
		{
			if (_SgState != SgRun)  SgAniSet(SgRun);
		}
		if (_Distance > 600 && _SgState != SgBegging && _SgState != SgBlownback && _SgState != SgDown && _SgState != SgUp
			&& _SgState != SgGetOnehit && _SgState != SgGetTwohit && _SgState != SgGetThreehit)
		{
			if (_SgState != SgIdle) SgAniSet(SgIdle);
		}
		if (_Time < 100)
		{
			if (_Distance <= 75 && _SgState != SgBegging && _SgState != SgGetOnehit)
			{
				if (_SgState != SgJab) SgAniSet(SgJab);
			}
		}
		if (_Time >= 100 && _Time <= 150)
		{
			if (_Distance <= 75 && _SgState != SgBegging && _SgState != SgGetOnehit)
			{
				if (_SgState != SgJumpKnee) SgAniSet(SgJumpKnee);
			}
		}
		if (_SgState != SgWalk && _SgState != SgRun && _Time > 150)
		{
			if (_Distance <= 75 && _SgState != SgBegging && _SgState != SgGetOnehit)
			{
				if (_SgState != SgKick) SgAniSet(SgKick);
				if (_Time > 200) _Time = 0;
			}
		}

		if (isCollision(_SgHit, _pl->GetAttackRC1()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;
		}

		if (isCollision(_SgHit, _pl->GetAttackRC2()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}

		if (isCollision(_SgHit, _pl->GetAttackRC3()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;
		}

		if (isCollision(_SgHit, _pl->GetAttackRCH()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}
		if (isCollision(_SgHit, _pl->GetAttackRCDAP()))
		{
			_SgCenterX += -cosf(_ChaseAngle) * 50;

		}
	}

	if (_Time > 200) _Time = 0;

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		if (_SgState != SgGetOnehit && _SgState != SgBegging) SgAniSet(SgGetOnehit);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		if (_SgState != SgGetTwohit && _SgState != SgBegging) SgAniSet(SgGetTwohit);
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		if (_SgState != SgGetThreehit && _SgState != SgBegging) SgAniSet(SgGetThreehit);
	}
	if (KEYMANAGER->isOnceKeyDown('4')) //히트3번 or 강공격 당해날아감 다운 기상 
	{
		SgAniSet(SgDown);
	}
		
	
}



void EnemySchoolGirl::Render()
{
	_SgHit.render(getMemDC());
	_SgShadowImage->alphaRender(getMemDC(), _SgShadow.left, _SgShadow.top, 170);
	_SgImage->aniRender(getMemDC(), _SgHit.left, _SgHit.top + setY, _SgAni);
	//_SgAttack.render(getMemDC());
	
}

void EnemySchoolGirl::SmHitHP(float damge)
{
	_Hp -= damge;
}

void EnemySchoolGirl::SetStunGage(float damge)
{
	_StunGage += damge;
}

void EnemySchoolGirl::SetCenterX(float x)
{
	_SgCenterX += x;
}	

void EnemySchoolGirl::SetCenterY(float y)
{
	_SgCenterY += y;
}

void EnemySchoolGirl::RightTherr(void* obj)
{
}

void EnemySchoolGirl::RightBlownback(void* obj)
{
	EnemySchoolGirl* JK = (EnemySchoolGirl*)obj;

	JK->SetSgState(SgDown);
	JK->SetSgAni(KEYANIMANAGER->findAnimation("SgRDown"));
	JK->GetSgAni()->start();
}

void EnemySchoolGirl::RightDown(void* obj)
{
	EnemySchoolGirl* JK = (EnemySchoolGirl*)obj;

	JK->SetSgState(SgUp);
	JK->SetSgAni(KEYANIMANAGER->findAnimation("SgRUp"));
	JK->GetSgAni()->start();
}

void EnemySchoolGirl::RightUp(void* obj)
{
	EnemySchoolGirl* JK = (EnemySchoolGirl*)obj;

	JK->SetSgState(SgIdle);
	JK->SetSgImage(IMAGEMANAGER->findImage("SgIdle"));
	JK->SetSgAni(KEYANIMANAGER->findAnimation("SgRIdle"));
	JK->GetSgAni()->start();
}


void EnemySchoolGirl::LeftTherr(void* obj)
{
}

void EnemySchoolGirl::LeftBlownback(void* obj)
{
	EnemySchoolGirl* JK = (EnemySchoolGirl*)obj;

	JK->SetSgState(SgDown);
	JK->SetSgAni(KEYANIMANAGER->findAnimation("SgLDown"));
	JK->GetSgAni()->start();
}

void EnemySchoolGirl::LeftDown(void* obj)
{
	EnemySchoolGirl* JK = (EnemySchoolGirl*)obj;

	JK->SetSgState(SgUp);
	JK->SetSgAni(KEYANIMANAGER->findAnimation("SgLUp"));
	JK->GetSgAni()->start();
}

void EnemySchoolGirl::LeftUp(void* obj)
{
	EnemySchoolGirl* JK = (EnemySchoolGirl*)obj;

	JK->SetSgState(SgIdle);
	JK->SetSgImage(IMAGEMANAGER->findImage("SgIdle"));
	JK->SetSgAni(KEYANIMANAGER->findAnimation("SgLIdle"));
	JK->GetSgAni()->start();
}


void EnemySchoolGirl::SgAniInit()
{
	//여학생 항복
	IMAGEMANAGER->addFrameImage("SgBegging", "image/enemy/sg/sg_begging.bmp", 0, 0, 378, 336, 3, 2, true, RGB(255, 0, 255));
	int Sg_R_Begging[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRBegging", "SgBegging", Sg_R_Begging, 2, 10, true);
	int Sg_L_Begging[] = { 4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLBegging", "SgBegging", Sg_L_Begging, 2, 10, true);

	//여학생 다운
	IMAGEMANAGER->addFrameImage("SgBlowback", "image/enemy/sg/sg_blownback.bmp", 0, 0, 2925, 1080, 13, 6, true, RGB(255, 0, 255));
	int Sg_R_Blowback[] = { 0,1,2,3,4,5,6,7,8,9,10,11};
	KEYANIMANAGER->addArrayFrameAnimation("SgRBlowback", "SgBlowback", Sg_R_Blowback, 12, 10, false , RightBlownback, this);
	int Sg_L_Blowback[] = {51,50,49,48,47,46,45,44,43,42,41,40};
	KEYANIMANAGER->addArrayFrameAnimation("SgLBlowback", "SgBlowback", Sg_L_Blowback, 12, 10, false, LeftBlownback, this);

	int Sg_R_Down[] = {12,13,14,15,16,17,18,19,20,21,22,23,24};
	KEYANIMANAGER->addArrayFrameAnimation("SgRDown", "SgBlowback", Sg_R_Down, 13, 10, false, RightDown, this);
	int Sg_L_Down[] = {39,64,63,62,61,60,59,58,57,56,55,54,53};
	KEYANIMANAGER->addArrayFrameAnimation("SgLDown", "SgBlowback", Sg_L_Down, 13, 10, false, LeftDown, this);

	int Sg_R_Down2[] = { 12,13,14,15,16,17,18,19,20,21,22,23,24 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRDown2", "SgBlowback", Sg_R_Down, 13, 10, false);
	int Sg_L_Down2[] = { 39,64,63,62,61,60,59,58,57,56,55,54,53 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLDown2", "SgBlowback", Sg_L_Down, 13, 10, false);



	int Sg_R_Up[] = { 25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRUp", "SgBlowback", Sg_R_Up, 7, 10, false , RightUp, this);
	int Sg_L_Up[] = { 52,77,76,75,74,73,72 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLUp", "SgBlowback", Sg_L_Up, 7, 10, false, LeftUp, this);

	//여학생 기절
	IMAGEMANAGER->addFrameImage("SgDazed", "image/enemy/sg/sg_dazed.bmp", 0, 0, 456, 324, 4, 2, true, RGB(255, 0, 255));
	int Sg_R_Dazed[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRDazed", "SgDazed", Sg_R_Dazed, 4, 5, true);
	int Sg_L_Dazed[] = { 7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLDazed", "SgDazed", Sg_L_Dazed, 4, 5, true);

	//여학생 피격모션
	IMAGEMANAGER->addFrameImage("SgGethit", "image/enemy/sg/sg_gethit.bmp", 0, 0, 1431, 360, 9, 2, true, RGB(255, 0, 255));

	//1타
	int Sg_R_Hit[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRGethit", "SgGethit", Sg_R_Hit, 3, 10, true);
	int Sg_L_Hit[] = { 17,16,15 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLGethit", "SgGethit", Sg_L_Hit, 3, 10, true);

	//2타
	int Sg_R_TwoHit[] = { 3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRGetTwohit", "SgGethit", Sg_R_TwoHit, 3, 10, true);
	int Sg_L_TwoHit[] = { 14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLGetTwohit", "SgGethit", Sg_L_TwoHit, 3, 10, true);

	//3타
	int Sg_R_ThreeHit[] = { 6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRGetThreehit", "SgGethit", Sg_R_ThreeHit, 3, 10, true);
	int Sg_L_ThreeHit[] = { 11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLGetThreehit", "SgGethit", Sg_L_ThreeHit, 3, 10, true);

	//여학생 다운공격맞을떄
	IMAGEMANAGER->addFrameImage("SgGroundhit", "image/enemy/sg/sg_groundhit.bmp", 0, 0, 639, 132, 3, 2, true, RGB(255, 0, 255));
	int Sg_R_Ground[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRGroundhit", "SgGroundhit", Sg_R_Ground, 3, 10, true);
	int Sg_L_Ground[] = { 5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLGroundhit", "SgGroundhit", Sg_L_Ground, 3, 10, true);

	//여학생 잡기
	IMAGEMANAGER->addFrameImage("SgHold", "image/enemy/sg/sg_held.bmp", 0, 0, 1128, 360, 8, 2, true, RGB(255, 0, 255));

	int Sg_R_hold[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRHold", "SgHold", Sg_R_hold, 1, 10, true);
	int Sg_L_hold[] = { 13 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLHold", "SgHold", Sg_L_hold, 1, 10, true);

	int Sg_R_holdHit[] = {1,4,6};
	KEYANIMANAGER->addArrayFrameAnimation("SgRHoldhit", "SgHold", Sg_R_holdHit, 3, 2, true);
	int Sg_L_holdHit[] = {14,11,9};
	KEYANIMANAGER->addArrayFrameAnimation("SgLHoldhit", "SgHold", Sg_L_holdHit, 3, 2, true);

	int Sg_R_holdRe[] = { 3,5,7,0 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRHoldrelrase", "SgHold", Sg_R_holdRe, 4, 5, true);
	int Sg_L_holdRe[] = { 12,10,8,15 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLHoldrelrase", "SgHold", Sg_L_holdRe, 4, 5, true);

	//여학생 기본
	IMAGEMANAGER->addFrameImage("SgIdle", "image/enemy/sg/sg_idle.bmp", 0, 0, 1170, 354, 10, 2, true, RGB(255, 0, 255));
	int Sg_R_Idle[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRIdle", "SgIdle", Sg_R_Idle, 10, 10, true);
	int Sg_L_Idle[] = { 19,18,17,16,15,14,13,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLIdle", "SgIdle", Sg_L_Idle, 10, 10, true);

	//여학생 일반공격
	IMAGEMANAGER->addFrameImage("SgJab", "image/enemy/sg/sg_jab.bmp", 0, 0, 1239, 354, 7, 2, true, RGB(255, 0, 255));
	int Sg_R_Jab[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRJab", "SgJab", Sg_R_Jab, 7, 10, true);
	int Sg_L_Jab[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLJab", "SgJab", Sg_L_Jab, 7, 10, true);

	//여학생 점프
	IMAGEMANAGER->addFrameImage("SgJump", "image/enemy/sg/sg_jump.bmp", 0, 0, 333, 366, 3, 2, true, RGB(255, 0, 255));
	int Sg_R_Jump[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRJump", "SgJump", Sg_R_Jump, 3, 10, true);
	int Sg_L_Jump[] = { 5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLJump", "SgJump", Sg_L_Jump, 3, 10, true);

	//여학생 점프 공격
	IMAGEMANAGER->addFrameImage("SgJumpKnee", "image/enemy/sg/sg_jump_knee.bmp", 0, 0, 1197, 354, 7, 2, true, RGB(255, 0, 255));
	int Sg_R_Jumpknee[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRJumpKnee", "SgJumpKnee", Sg_R_Jumpknee, 7, 10, true);
	int Sg_L_Jumpknee[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLJumpKnee", "SgJumpKnee", Sg_L_Jumpknee, 7, 10, true);

	//여학생 지상 발공격
	IMAGEMANAGER->addFrameImage("SgKick", "image/enemy/sg/sg_kick.bmp", 0, 0, 2412, 414, 12, 2, true, RGB(255, 0, 255));
	int Sg_R_Kick[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRKick", "SgKick", Sg_R_Kick, 12, 10, true);
	int Sg_L_Kick[] = { 23,22,21,20,19,18,17,16,15,14,13,12};
	KEYANIMANAGER->addArrayFrameAnimation("SgLKick", "SgKick", Sg_L_Kick, 12, 10, true);

	//여학생 다운 및 기상
	IMAGEMANAGER->addFrameImage("SgKnockdown", "image/enemy/sg/sg_knockdown.bmp", 0, 0, 2925, 1080, 13, 6, true, RGB(255, 0, 255));
	int Sg_R_Knockdown[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRKnockdown", "SgKnockdown", Sg_R_Knockdown, 33, 10, true);
	int Sg_L_Knockdown[] = { 51,50,49,48,47,46,45,44,43,42,41,40,39,64,63,62,61,60,59,58,57,56,55,54,53,52,77,76,75,74,73,72,71 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLKnockdown", "SgKnockdown", Sg_L_Knockdown, 33, 10, true);

	//여학생 달리기
	IMAGEMANAGER->addFrameImage("SgRun", "image/enemy/sg/sg_run.bmp", 0, 0, 1470, 330, 10, 2, true, RGB(255, 0, 255));
	int Sg_R_Run[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRRun", "SgRun", Sg_R_Run, 10, 10, true);
	int Sg_L_Run[] = { 19,18,17,16,15,14,13,12,11 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLRun", "SgRun", Sg_L_Run, 9, 10, true);

	//여학생 도발
	IMAGEMANAGER->addFrameImage("SgTaunt", "image/enemy/sg/sg_taunt.bmp", 0, 0, 2970, 732, 22, 4, true, RGB(255, 0, 255));
	int Sg_R_Taunt[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRTaunt", "SgTaunt", Sg_R_Taunt, 26, 10, true);
	int Sg_L_Taunt[] = {65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,87,86,85,84};
	KEYANIMANAGER->addArrayFrameAnimation("SgLTaunt", "SgTaunt", Sg_L_Taunt, 26, 10, true);

	//여학생 걷기
	IMAGEMANAGER->addFrameImage("SgWalk", "image/enemy/sg/sg_walk.bmp", 0, 0, 1296, 372, 12, 2, true, RGB(255, 0, 255));
	int Sg_R_Walk[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRWalk", "SgWalk", Sg_R_Walk, 12, 10, true);
	int Sg_L_Walk[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLWalk", "SgWalk", Sg_L_Walk, 12, 10, true);

	//여학생 무기로 쓸떄
	IMAGEMANAGER->addFrameImage("SgWeaponSwing", "image/enemy/sg/sg_weapon_swing2.bmp", 0, 0, 2646, 456, 7, 2, true, RGB(255, 0, 255));
	int Sg_R_Weapon[] = {0,1,2,3,4,5,6};
	KEYANIMANAGER->addArrayFrameAnimation("SgRWeaponSwing", "SgWeaponSwing", Sg_R_Weapon, 6, 5, true);
	int Sg_L_Weapon[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLWeaponSwing", "SgWeaponSwing", Sg_L_Weapon, 6, 5, true);

}

void EnemySchoolGirl::SgAniSet(SGSTATE state)
{
	if (_IsRight && !_IsLeft)
	{
		switch (state)
		{
		case SgBegging:
			_SgImage = IMAGEMANAGER->findImage("SgBegging");
			_SgAni = KEYANIMANAGER->findAnimation("SgRBegging");
			_SgAni->start();
			_SgState = SgBegging;
			break;
		case SgBlownback:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgRBlowback");
			_SgAni->start();
			_SgState = SgBlownback;
			break;
		case SgDazed:
			_SgImage = IMAGEMANAGER->findImage("SgDazed");
			_SgAni = KEYANIMANAGER->findAnimation("SgRDazed");
			_SgAni->start();
			_SgState = SgDazed;
			break;
		case SgGetOnehit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgRGethit");
			_SgAni->start();
			_SgState = SgGetOnehit;
			break;
		case SgGetTwohit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgRGetTwohit");
			_SgAni->start();
			_SgState = SgGetTwohit;
			break;
		case SgGetThreehit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgRGetThreehit");
			_SgAni->start();
			_SgState = SgGetThreehit;
			break;
		case SgHold:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgRHold");
			_SgAni->start();
			_SgState = SgHold;
			break;
		case SgHoldhit:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgRHoldhit");
			_SgAni->start();
			_SgState = SgHoldhit;
			break;
		case SgHoldrelrase:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgRHoldrelrase");
			_SgAni->start();
			_SgState = SgHoldrelrase;
			break;
		case SgIdle:
			_SgImage = IMAGEMANAGER->findImage("SgIdle");
			_SgAni = KEYANIMANAGER->findAnimation("SgRIdle");
			_SgAni->start();
			_SgState = SgIdle;
			break;
		case SgJumpKnee:
			_SgImage = IMAGEMANAGER->findImage("SgJumpKnee");
			_SgAni = KEYANIMANAGER->findAnimation("SgRJumpKnee");
			_SgAni->start();
			_SgState = SgJumpKnee;
			break;
		case SgKick:
			_SgImage = IMAGEMANAGER->findImage("SgKick");
			_SgAni = KEYANIMANAGER->findAnimation("SgRKick");
			_SgAni->start();
			_SgState = SgKick;
			break;
		case SgKnockdown:
			_SgImage = IMAGEMANAGER->findImage("SgKnockdown");
			_SgAni = KEYANIMANAGER->findAnimation("SgRKnockdown");
			_SgAni->start();
			_SgState = SgKnockdown;
			break;
		case SgRun:
			_SgImage = IMAGEMANAGER->findImage("SgRun");
			_SgAni = KEYANIMANAGER->findAnimation("SgRRun");
			_SgAni->start();
			_SgState = SgRun;
			break;
		case SgJab:
			_SgImage = IMAGEMANAGER->findImage("SgJab");
			_SgAni = KEYANIMANAGER->findAnimation("SgRJab");
			_SgAni->start();
			_SgState = SgJab;
			break;
		case SgTaunt:
			_SgImage = IMAGEMANAGER->findImage("SgTaunt");
			_SgAni = KEYANIMANAGER->findAnimation("SgRTaunt");
			_SgAni->start();
			_SgState = SgTaunt;
			break;
		case SgWalk:
			_SgImage = IMAGEMANAGER->findImage("SgWalk");
			_SgAni = KEYANIMANAGER->findAnimation("SgRWalk");
			_SgAni->start();
			_SgState = SgWalk;
			break;
		case SgWeaponSwing:
			_SgImage = IMAGEMANAGER->findImage("SgWeaponSwing");
			_SgAni = KEYANIMANAGER->findAnimation("SgRWeaponSwing");
			_SgAni->start();
			_SgState = SgWeaponSwing;
			break;
		case SgDown:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgRDown");
			_SgAni->start();
			_SgState = SgDown;
			break;
		case SgUp:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgRUp");
			_SgAni->start();
			_SgState = SgUp;
			break;
		}
	}
	if (!_IsRight && _IsLeft)
	{
		switch (state)
		{
		case SgBegging:
			_SgImage = IMAGEMANAGER->findImage("SgBegging");
			_SgAni = KEYANIMANAGER->findAnimation("SgLBegging");
			_SgAni->start();
			_SgState = SgBegging;
			break;
		case SgBlownback:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgLBlowback");
			_SgAni->start();
			_SgState = SgBlownback;
			break;
		case SgDazed:
			_SgImage = IMAGEMANAGER->findImage("SgDazed");
			_SgAni = KEYANIMANAGER->findAnimation("SgLDazed");
			_SgAni->start();
			_SgState = SgDazed;
			break;
		case SgGetOnehit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgLGethit");
			_SgAni->start();
			_SgState = SgGetOnehit;
			break;
		case SgGetTwohit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgLGetTwohit");
			_SgAni->start();
			_SgState = SgGetTwohit;
			break;
		case SgGetThreehit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgLGetThreehit");
			_SgAni->start();
			_SgState = SgGetThreehit;
			break;
		case SgHold:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgLHold");
			_SgAni->start();
			_SgState = SgHold;
			break;
		case SgHoldhit:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgLHoldhit");
			_SgAni->start();
			_SgState = SgHoldhit;
			break;
		case SgHoldrelrase:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgLHoldrelrase");
			_SgAni->start();
			_SgState = SgHoldrelrase;
			break;
		case SgIdle:
			_SgImage = IMAGEMANAGER->findImage("SgIdle");
			_SgAni = KEYANIMANAGER->findAnimation("SgLIdle");
			_SgAni->start();
			_SgState = SgIdle;
			break;
		case SgJumpKnee:
			_SgImage = IMAGEMANAGER->findImage("SgJumpKnee");
			_SgAni = KEYANIMANAGER->findAnimation("SgLJumpKnee");
			_SgAni->start();
			_SgState = SgJumpKnee;
			break;
		case SgKick:
			_SgImage = IMAGEMANAGER->findImage("SgKick");
			_SgAni = KEYANIMANAGER->findAnimation("SgLKick");
			_SgAni->start();
			_SgState = SgKick;
			break;
		case SgKnockdown:
			_SgImage = IMAGEMANAGER->findImage("SgKnockdown");
			_SgAni = KEYANIMANAGER->findAnimation("SgLKnockdown");
			_SgAni->start();
			_SgState = SgKnockdown;
			break;
		case SgRun:
			_SgImage = IMAGEMANAGER->findImage("SgRun");
			_SgAni = KEYANIMANAGER->findAnimation("SgLRun");
			_SgAni->start();
			_SgState = SgRun;
			break;
		case SgJab:
			_SgImage = IMAGEMANAGER->findImage("SgJab");
			_SgAni = KEYANIMANAGER->findAnimation("SgLJab");
			_SgAni->start();
			_SgState = SgJab;
			break;
		case SgTaunt:
			_SgImage = IMAGEMANAGER->findImage("SgTaunt");
			_SgAni = KEYANIMANAGER->findAnimation("SgLTaunt");
			_SgAni->start();
			_SgState = SgTaunt;
			break;
		case SgWalk:
			_SgImage = IMAGEMANAGER->findImage("SgWalk");
			_SgAni = KEYANIMANAGER->findAnimation("SgLWalk");
			_SgAni->start();
			_SgState = SgWalk;
			break;
		case SgWeaponSwing:
			_SgImage = IMAGEMANAGER->findImage("SgWeaponSwing");
			_SgAni = KEYANIMANAGER->findAnimation("SgLWeaponSwing");
			_SgAni->start();
			_SgState = SgWeaponSwing;
			break;
		case SgDown:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgLDown");
			_SgAni->start();
			_SgState = SgDown;
			break;
		case SgUp:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgLUp");
			_SgAni->start();
			_SgState = SgUp;
			break;
		}
	}
}