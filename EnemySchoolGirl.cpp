#include "stdafx.h"
#include "EnemySchoolGirl.h"


HRESULT EnemySchoolGirl::init()
{
	return S_OK;
}

HRESULT EnemySchoolGirl::Init(POINTFLOAT pt)
{
	_IsRight = true;

	SgAniInit();
	//SgAniSet(SgIdle);
	SgState();

	_SgState = SgIdle;

	

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

	_SgAttackExploration.MYRectMakeCenter(_EnemyX, _EnemyY, 200, 200);

	_Hp = 10.f;
	_Speed = 3.0f;
	_ChaseAngle = 0;
	_Distance = 0;
	_Time = 0;


	return S_OK;
}

void EnemySchoolGirl::Release()
{

}

void EnemySchoolGirl::Update()
{
	//if (KEYMANAGER->isStayKeyDown('W')) _Hp -= 1;
	//_Jump->jumping(&_EnemyX, &_EnemyY, 7.0f, 0.3f);

	_Time++;


	//_Distance = getDistance(_EnemyX, _EnemyY, _Test->GetCnetX(), _Test->GetCnetY());
	//_ChaseAngle = getAngle(_EnemyX, _EnemyY, _Test->GetCnetX(), _Test->GetCnetY());
	//
	//if (_SgCenterX > _Test->GetCnetX())
	//{
	//	_IsRight = false;
	//}
	//else if (_SgCenterX < _Test->GetCnetX())
	//{
	//	_IsRight = true;
	//}

		//if (KEYMANAGER->isOnceKeyDown('Q')) SgAniSet(SgDazed);
		//if (KEYMANAGER->isOnceKeyDown('W')) SgAniSet(SgWeaponSwing);
		//if (KEYMANAGER->isOnceKeyDown('E')) SgAniSet(SgKnockdown);
		//if (KEYMANAGER->isOnceKeyDown('R')) SgAniSet(SgHoldrelrase);

	if (_IsRight)
	{
		/*if (_StunGage <= 100)
		{
			if (_SgState != SgDazed) SgAniSet(SgDazed);

			_StunTime++;
		}
		if (_StunTime <= 300)
		{
			if (_SgState == SgDazed) SgAniSet(SgIdle);
			_StunTime = 0;
		}*/

		if (_Distance > 75 && _Distance < 300)
		{
			if (_SgState != SgWalk) SgAniSet(SgWalk);
			_SgCenterX += cosf(_ChaseAngle) * _Speed;
			_SgCenterY += -sinf(_ChaseAngle) * _Speed;
		}

		if (_Distance < 600 && _Distance > 300)
		{
			if (_SgState != SgRun)  SgAniSet(SgRun);
			_SgCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
			_SgCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
		}

		if (_SgState != SgKick)
		{
			if (_Distance <= 75)
			{
				if (_SgState != SgJab)
				{
					SgAniSet(SgJab);
					_SgAttack.MYRectMakeCenter(_EnemyX + 50, _EnemyY, 80, 150);
				}
			}
		}

		if (_SgState != SgWalk && _SgState != SgRun && _Time > 150)
		{
			if (_Distance <= 75)
			{
				if (_SgState != SgKick)
				{
					SgAniSet(SgKick);
					_SgAttack.MYRectMakeCenter(_EnemyX, _EnemyY, 200, 50);
				}
				_Time = 0;
			}
		}

	}
	else
	{
		if (_Distance > 75 && _Distance < 300)
		{
			if (_SgState != SgWalk) SgAniSet(SgWalk);

			_SgCenterX += cosf(_ChaseAngle) * _Speed;
			_SgCenterY += -sinf(_ChaseAngle) * _Speed;
		}

		if (_Distance < 600 && _Distance > 300)
		{
			if (_SgState != SgRun)  SgAniSet(SgRun);
			_SgCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
			_SgCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
		}
	
		if (_Distance <= 75)
		{
			if (_SgState != SgJab)
			{
				SgAniSet(SgJab);
				_SgAttack.MYRectMakeCenter(_EnemyX - 50, _EnemyY, 80, 150);
			}
		}	

		if (_Distance <= 75 && _Time > 100)
		{
			if (_SgState != SgKick)
			{
				SgAniSet(SgKick);
				_SgAttack.MYRectMakeCenter(_EnemyX, _EnemyY, 200, 50);
			}		
			_Time = 0;
		}

	}
		

	//if (_Hp <= 2) SgAniSet(SgBegging);


	//	switch (_SgState)
	//	{
	//	case SgBegging:
	//		if (_Hp <= 2)
	//			SgAniSet(SgBegging);
	//		break;

	//	case SgBlownback:

	//		break;
	//	case SgDazed:

	//		break;
	//	case SgGethit:

	//		break;
	//	case SgHold:

	//		break;
	//	case SgHoldhit:

	//		break;
	//	case SgHoldrelrase:

	//		break;
	//	case SgIdle:

	//		break;
	//	case SgJumpKnee:
	//		//이것이 2타
	//		break;
	//	case SgKick:
	//		//이것이 3타
	//		break;
	//	case SgKnockdown:
	//		break;
	//	case SgRun:

	//		if (_Distance < 600 && _Distance > 300)
	//		{
	//			_SgCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
	//			_SgCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
	//		}
	//		break;
	//	case SgJab:
	//		if (_Distance <= 75)
	//		{
	//			SgAniSet(SgJab);
	//			_SgAttack.MYRectMakeCenter(_EnemyX - 50, _EnemyY, 80, 150);
	//		}
	//		break;
	//	case SgTaunt:
	//		break;
	//	case SgWalk:
	//		_SgImage = IMAGEMANAGER->findImage("SgWalk");
	//		_SgAni = KEYANIMANAGER->findAnimation("SgRWak");
	//		if (_Distance > 75 && _Distance < 300)
	//		{
	//			_SgCenterX += cosf(_ChaseAngle) * _Speed;
	//			_SgCenterY += -sinf(_ChaseAngle) * _Speed;
	//		}
	//		break;
	//	case SgWeaponSwing:
	//		break;
	//	}


////////////////////////////////////////////////////////////////////////////////////////////////

	/*switch (_SgState)
	{
	case SgBegging:
		_SgImage = IMAGEMANAGER->findImage("SgBegging");
		_SgAni = KEYANIMANAGER->findAnimation("SgRBegging");
		_SgAni->start();
		break;
	case SgBlownback:
		_SgImage = IMAGEMANAGER->findImage("SgBlowback");
		_SgAni = KEYANIMANAGER->findAnimation("SgRBlowback");
		_SgAni->start();
		break;
	case SgDazed:
		_SgImage = IMAGEMANAGER->findImage("SgDazed");
		_SgAni = KEYANIMANAGER->findAnimation("SgRDazed");
		_SgAni->start();
		break;
	case SgGethit:
		_SgImage = IMAGEMANAGER->findImage("SgGethit");
		_SgAni = KEYANIMANAGER->findAnimation("SgRGethit");
		_SgAni->start();
		break;
	case SgHold:
		_SgImage = IMAGEMANAGER->findImage("SgHold");
		_SgAni = KEYANIMANAGER->findAnimation("SgRHold");
		_SgAni->start();
		break;
	case SgHoldhit:
		_SgImage = IMAGEMANAGER->findImage("SgHold");
		_SgAni = KEYANIMANAGER->findAnimation("SgRHoldhit");
		_SgAni->start();
		break;
	case SgHoldrelrase:
		_SgImage = IMAGEMANAGER->findImage("SgHold");
		_SgAni = KEYANIMANAGER->findAnimation("SgRHoldrelrase");
		_SgAni->start();
		break;
	case SgIdle:
		_SgImage = IMAGEMANAGER->findImage("SgIdle");
		_SgAni = KEYANIMANAGER->findAnimation("SgRIdle");
		_SgAni->start();
		break;
	case SgJumpKnee:
		_SgImage = IMAGEMANAGER->findImage("SgJumpKnee");
		_SgAni = KEYANIMANAGER->findAnimation("SgRJumpKnee");
		_SgAni->start();
		break;
	case SgKick:
		_SgImage = IMAGEMANAGER->findImage("SgKick");
		_SgAni = KEYANIMANAGER->findAnimation("SgRKick");
		_SgAni->start();
		break;
	case SgKnockdown:
		_SgImage = IMAGEMANAGER->findImage("SgKnockdown");
		_SgAni = KEYANIMANAGER->findAnimation("SgRKnockdown");
		_SgAni->start();
		break;
	case SgRun:
		_SgImage = IMAGEMANAGER->findImage("SgRun");
		_SgAni = KEYANIMANAGER->findAnimation("SgRRun");
		_SgAni->start();
		break;
	case SgJab:
		_SgImage = IMAGEMANAGER->findImage("SgJab");
		_SgAni = KEYANIMANAGER->findAnimation("SgRJab");
		_SgAni->start();
		break;
	case SgTaunt:
		_SgImage = IMAGEMANAGER->findImage("SgTaunt");
		_SgAni = KEYANIMANAGER->findAnimation("SgRTaunt");
		_SgAni->start();
		break;
	case SgWalk:
		_SgImage = IMAGEMANAGER->findImage("SgWalk");
		_SgAni = KEYANIMANAGER->findAnimation("SgRWalk");
		_SgAni->start();
		break;
	case SgWeaponSwing:
		_SgImage = IMAGEMANAGER->findImage("SgWeaponSwing");
		_SgAni = KEYANIMANAGER->findAnimation("SgRWeaponSwing");
		_SgAni->start();
		break;
	}*/

////////////////////////////////////////////////////////////////////////////////////////////////
	_SgShadow.MYRectMakeCenter(_SgCenterX, _SgCenterY, _SgShadowImage->getWidth(), _SgShadowImage->getHeight());

	_ShadowX = (_SgShadow.left + _SgShadow.right) / 2;
	_ShadowY = (_SgShadow.top + _SgShadow.bottom) / 2;
	_SgHit.MYRectMakeCenter(_ShadowX, _ShadowY - _SgImage->getFrameHeight() / 2, _SgImage->getFrameWidth(), _SgImage->getFrameHeight());

	_EnemyX = (_SgHit.left + _SgHit.right) / 2;
	_EnemyY = (_SgHit.top + _SgHit.bottom) / 2;

	if (_IsRight)
	{
		_SgAttackExploration.MYRectMakeCenter(_SgHit.right, _EnemyY, 200, 200);
	}
	else
	{
		_SgAttackExploration.MYRectMakeCenter(_SgHit.left, _EnemyY, 200, 200);
	}

///////////////////////////////////////////////////////////////////////////////////////////////
	ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _SgImage, _SgHit.left, _SgHit.top, _SgAni, (_SgShadow.bottom + _SgShadow.top) * 0.5);
}

void EnemySchoolGirl::Render()
{
	_SgAttackExploration.render(getMemDC());
	//_SgShadow.render(getMemDC());
	_SgShadowImage->render(getMemDC(), _SgShadow.left, _SgShadow.top);
	//_SgHit.render(getMemDC());
	//_SgImage->aniRender(getMemDC(), _SgHit.left, _SgHit.top, _SgAni);
	if (_SgState == SgJab || _SgState == SgKick)
	{
		_SgAttack.render(getMemDC());
	}
}

void EnemySchoolGirl::SgState()
{
	if (_IsRight)
	{
		switch (_SgState)
		{
		case SgBegging:
			_SgImage = IMAGEMANAGER->findImage("SgBegging");
			_SgAni = KEYANIMANAGER->findAnimation("SgRBegging");
			_SgAni->start();
			break;
		case SgBlownback:
			_SgImage = IMAGEMANAGER->findImage("SgBlowback");
			_SgAni = KEYANIMANAGER->findAnimation("SgRBlowback");
			_SgAni->start();
			break;
		case SgDazed:
			_SgImage = IMAGEMANAGER->findImage("SgDazed");
			_SgAni = KEYANIMANAGER->findAnimation("SgRDazed");
			_SgAni->start();
			break;
		case SgGethit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgRGethit");
			_SgAni->start();
			break;
		case SgHold:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgRHold");
			_SgAni->start();
			break;
		case SgHoldhit:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgRHoldhit");
			_SgAni->start();
			break;
		case SgHoldrelrase:
			_SgImage = IMAGEMANAGER->findImage("SgHold");
			_SgAni = KEYANIMANAGER->findAnimation("SgRHoldrelrase");
			_SgAni->start();
			break;
		case SgIdle:
			_SgImage = IMAGEMANAGER->findImage("SgIdle");
			_SgAni = KEYANIMANAGER->findAnimation("SgRIdle");
			_SgAni->start();
			break;
		case SgJumpKnee:
			_SgImage = IMAGEMANAGER->findImage("SgJumpKnee");
			_SgAni = KEYANIMANAGER->findAnimation("SgRJumpKnee");
			_SgAni->start();
			break;
		case SgKick:
			_SgImage = IMAGEMANAGER->findImage("SgKick");
			_SgAni = KEYANIMANAGER->findAnimation("SgRKick");
			_SgAni->start();
			break;
		case SgKnockdown:
			_SgImage = IMAGEMANAGER->findImage("SgKnockdown");
			_SgAni = KEYANIMANAGER->findAnimation("SgRKnockdown");
			_SgAni->start();
			break;
		case SgRun:
			_SgImage = IMAGEMANAGER->findImage("SgRun");
			_SgAni = KEYANIMANAGER->findAnimation("SgRRun");
			_SgAni->start();
			break;
		case SgJab:
			_SgImage = IMAGEMANAGER->findImage("SgJab");
			_SgAni = KEYANIMANAGER->findAnimation("SgRJab");
			_SgAni->start();
			break;
		case SgTaunt:
			_SgImage = IMAGEMANAGER->findImage("SgTaunt");
			_SgAni = KEYANIMANAGER->findAnimation("SgRTaunt");
			_SgAni->start();
			break;
		case SgWalk:
			_SgImage = IMAGEMANAGER->findImage("SgWalk");
			_SgAni = KEYANIMANAGER->findAnimation("SgRWalk");
			_SgAni->start();
			break;
		case SgWeaponSwing:
			break;
		}
	}
	else
	{
		switch (_SgState)
		{
		case SgBegging:
			break;
		case SgBlownback:
			break;
		case SgDazed:
			break;
		case SgGethit:
			break;
		case SgHold:
			break;
		case SgHoldhit:
			break;
		case SgHoldrelrase:
			break;
		case SgIdle:
			break;
		case SgJumpKnee:
			break;
		case SgKick:
			break;
		case SgKnockdown:
			break;
		case SgRun:	
			break;
		case SgJab:
			break;
		case SgTaunt:
			break;
		case SgWalk:			
			break;
		case SgWeaponSwing:
			break;
		}
	}
}

void EnemySchoolGirl::SmHitHP(float damge)
{
	_Hp -= damge;
}

void EnemySchoolGirl::SetStunGage(float damge)
{
	_StunGage += damge;
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
	int Sg_R_Blowback[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12, 13,14,15,16,17,18,19,20,21,22,23,24,25, 26,27,28,29,30,31,32};
	KEYANIMANAGER->addArrayFrameAnimation("SgRBlowback", "SgBlowback", Sg_R_Blowback, 33, 10, true);
	int Sg_L_Blowback[] = {51,50,49,48,47,46,45,44,43,42,41,40,39,64,63,62,61,60,59,58,57,56,55,54,53,52, 77,76,75,74,73,72,71,70};
	KEYANIMANAGER->addArrayFrameAnimation("SgLBlowback", "SgBlowback", Sg_L_Blowback, 33, 10, true);

	//여학생 기절
	IMAGEMANAGER->addFrameImage("SgDazed", "image/enemy/sg/sg_dazed.bmp", 0, 0, 456, 324, 4, 2, true, RGB(255, 0, 255));
	int Sg_R_Dazed[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRDazed", "SgDazed", Sg_R_Dazed, 4, 5, true);
	int Sg_L_Dazed[] = { 7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLDazed", "SgDazed", Sg_L_Dazed, 4, 5, true);

	//여학생 피격모션
	IMAGEMANAGER->addFrameImage("SgGethit", "image/enemy/sg/sg_gethit.bmp", 0, 0, 1431, 360, 9, 2, true, RGB(255, 0, 255));
	int Sg_R_Hit[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRGethit", "SgGethit", Sg_R_Hit, 9, 10, true);
	int Sg_L_Hit[] = { 17,16,15,14,13,12,11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLGethit", "SgGethit", Sg_L_Hit, 9, 10, true);

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
	int Sg_L_Run[] = { 19,18,17,16,15,14,13,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLRun", "SgRun", Sg_L_Run, 10, 10, true);

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
	if (_IsRight)
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
		case SgGethit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgRGethit");
			_SgAni->start();
			_SgState = SgGethit;
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
		}
	}
	else
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
		case SgGethit:
			_SgImage = IMAGEMANAGER->findImage("SgGethit");
			_SgAni = KEYANIMANAGER->findAnimation("SgLGethit");
			_SgAni->start();
			_SgState = SgGethit;
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
		}
	}
}