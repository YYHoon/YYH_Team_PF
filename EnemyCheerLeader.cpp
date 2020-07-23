#include "stdafx.h"
#include "EnemyCheerLeader.h"


HRESULT EnemyCheerLeader::init()
{
	return S_OK;
}

HRESULT EnemyCheerLeader::Init(POINTFLOAT pt)
{
	_IsRight = true;

	AniInit();
	AniSet(CLIdle);

	_ClCenterX = pt.x;
	_ClCenterY = pt.y;

	//적 그림자
	_EnemyShadowImage = IMAGEMANAGER->addImage("Showdow", "image/enemy/Enemy_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));

	_EnemyShadow.MYRectMakeCenter(_ClCenterX, _ClCenterY, _EnemyShadowImage->getWidth(), _EnemyShadowImage->getHeight());

	_ShadowX = (_EnemyShadow.left + _EnemyShadow.right) / 2;
	_ShadowY = (_EnemyShadow.top + _EnemyShadow.bottom) / 2;
	
	_EnemyImage = IMAGEMANAGER->findImage("CLIdle");

	_Enemy.MYRectMakeCenter(_ShadowX, _ShadowY - _EnemyImage->getFrameHeight() / 2, _EnemyImage->getFrameWidth(), _EnemyImage->getFrameHeight());

	_EnemyX = (_Enemy.left + _Enemy.right) / 2;
	_EnemyY = (_Enemy.top + _Enemy.bottom) / 2;

	_Hp = 10.f;

	_Speed = 3.0f;
	_ChaseAngle = 0;
	_Distance = 0;
	_Time = 0;
	return S_OK;
}

void EnemyCheerLeader::Release()
{
}

void EnemyCheerLeader::Update()
{


	_Time++;

	cout << _Time << endl;

	//_Distance = getDistance(_EnemyX, _EnemyY, _Test->GetCnetX(), _Test->GetCnetY());
	//_ChaseAngle = getAngle(_EnemyX, _EnemyY, _Test->GetCnetX(), _Test->GetCnetY());

	//if (_ClCenterX > _Test->GetCnetX())
	//{
	//	_IsRight = false;
	//}
	//else if (_ClCenterX < _Test->GetCnetX())
	//{
	//	_IsRight = true;
	//}

	if (_IsRight)
	{
		if (_Distance > 75 && _Distance < 300)
		{
			if (_ClState != CLWalk) AniSet(CLWalk);

			_ClCenterX += cosf(_ChaseAngle) * _Speed;
			_ClCenterY += -sinf(_ChaseAngle) * _Speed;
		}

		if (_Distance < 600 && _Distance > 300)
		{
			if (_ClState != CLRun)  AniSet(CLRun);
			_ClCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
			_ClCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
		}

		if (_Distance <= 75)
		{
			if (_ClState != CLJab)
			{
				AniSet(CLJab);
				_EnemyAttack.MYRectMakeCenter(_EnemyX + 50, _EnemyY, 80, 150);
			}
		}

	}
	else
	{
		if (_Distance > 75 && _Distance < 300)
		{
			if (_ClState != CLWalk) AniSet(CLWalk);

			_ClCenterX += cosf(_ChaseAngle) * _Speed;
			_ClCenterY += -sinf(_ChaseAngle) * _Speed;
		}

		if (_Distance < 600 && _Distance > 300)
		{
			if (_ClState != CLRun)  AniSet(CLRun);
			_ClCenterX += cosf(_ChaseAngle) * _Speed * 2.f;
			_ClCenterY += -sinf(_ChaseAngle) * _Speed * 2.f;
		}

		if (_Distance <= 75)
		{
			if (_ClState != CLJab)
			{
				AniSet(CLJab);
				_EnemyAttack.MYRectMakeCenter(_EnemyX - 50, _EnemyY, 80, 150);
			}
		}
	}

////////////////////////////////////////////////////////////////////////////////////

	_EnemyShadow.MYRectMakeCenter(_ClCenterX, _ClCenterY, _EnemyShadowImage->getWidth(), _EnemyShadowImage->getHeight());

	_ShadowX = (_EnemyShadow.left + _EnemyShadow.right) / 2;
	_ShadowY = (_EnemyShadow.top + _EnemyShadow.bottom) / 2;

	_Enemy.MYRectMakeCenter(_ShadowX, _ShadowY - _EnemyImage->getFrameHeight() / 2, _EnemyImage->getFrameWidth(), _EnemyImage->getFrameHeight());

	_EnemyX = (_Enemy.left + _Enemy.right) / 2;
	_EnemyY = (_Enemy.top + _Enemy.bottom) / 2;

	if (_IsRight)
	{
		_EnemyAttackExploration.MYRectMakeCenter(_Enemy.right, _EnemyY, 200, 200);
	}
	else
	{		
		_EnemyAttackExploration.MYRectMakeCenter(_Enemy.left, _EnemyY, 200, 200);
	}
////////////////////////////////////////////////////////////////////////////////////
}

void EnemyCheerLeader::Render()
{
	//_EnemyAttackExploration.render(getMemDC());
	_EnemyShadowImage->alphaRender(getMemDC(), _EnemyShadow.left, _EnemyShadow.top, 170);
	_EnemyImage->aniRender(getMemDC(), _Enemy.left, _Enemy.top, _CLAni);
	_EnemyAttack.render(getMemDC());
	//_EnemyShadow.render(getMemDC());
}

void EnemyCheerLeader::AniInit()
{
	//치어리더 기본상태
	IMAGEMANAGER->addFrameImage("CLIdle", "image/enemy/cr/cl_idle.bmp", 0, 0, 1980, 432, 12, 2, true, RGB(255, 0, 255));

	int CLRightIdle[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	KEYANIMANAGER->addArrayFrameAnimation("ClRightIdle", "CLIdle", CLRightIdle, 12, 10, true);
	int CLLeftIdle[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLeftIdle", "CLIdle", CLLeftIdle, 12, 10, true);

	//치어리더 항복
	IMAGEMANAGER->addFrameImage("ClBegging", "image/enemy/cr/cl_begging.bmp", 0, 0, 468, 372, 3, 2, true, RGB(255, 0, 255));

	int Cl_R_Begging[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRBegging", "ClBegging", Cl_R_Begging, 3, 10, true);
	int Cl_L_Begging[] = { 5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLBegging", "ClBegging", Cl_L_Begging, 3, 10, true);

	//치어리더 플레어의 강공격 또는 3타 맞았을때
	IMAGEMANAGER->addFrameImage("Clblownback", "image/enemy/cr/cl_blownback2.bmp", 0, 0, 3060, 1242, 12, 6, true, RGB(255, 0, 255));

	int Cl_R_Blownback[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
	KEYANIMANAGER->addArrayFrameAnimation("ClRBlownback", "Clblownback", Cl_R_Blownback, 32, 10, true);
	int Cl_L_Blownback[] = { 47,46,45,44,43,42,41,40,39,38,37,36,59,58,57,56,55,54,53,52,51,50,49,48,71,70,69};
	KEYANIMANAGER->addArrayFrameAnimation("ClLBlownback", "Clblownback", Cl_L_Blownback, 32, 10, true);

	//치어리더 회피동작
	IMAGEMANAGER->addFrameImage("ClCratwheel", "image/enemy/cr/cl_cartwheel.bmp", 0, 0, 957, 332, 22, 4, true, RGB(255, 0, 255));

	int Cl_R_Crat[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	KEYANIMANAGER->addArrayFrameAnimation("ClRCrat", "ClCratwheel", Cl_R_Crat, 15, 10, true);
	int Cl_L_Crat[] = { 32,31,30,29,28,27,26,25,24,23,22, 43,42,41,40,};
	KEYANIMANAGER->addArrayFrameAnimation("ClLCrat", "ClCratwheel", Cl_L_Crat, 15, 10, true);

	//치어리더 기절
	IMAGEMANAGER->addFrameImage("ClDazed", "image/enemy/cr/cl_dazed.bmp", 0, 0, 540, 390, 4, 2, true, RGB(255, 0, 255));

	int Cl_R_Dazed[] = {0,1,2,3};
	KEYANIMANAGER->addArrayFrameAnimation("ClRDazed", "ClDazed", Cl_R_Dazed, 4, 10, true);
	int Cl_L_Dazed[] = {7,6,5,4};
	KEYANIMANAGER->addArrayFrameAnimation("ClLDazed", "ClDazed", Cl_L_Dazed, 4, 10, true);

	//치어리더 떨어질때
	IMAGEMANAGER->addFrameImage("ClFalling", "image/enemy/cr/cl_falling.bmp", 0, 0, 624, 354, 4, 2, true, RGB(255, 0, 255));

	int Cl_R_Falling[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRFalling", "ClFalling", Cl_R_Falling, 4, 10, true);
	int Cl_L_Falling[] = { 7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLFalling", "ClFalling", Cl_L_Falling, 4, 10, true);

	//치어리더 공격당했을때 (1,2타)
	IMAGEMANAGER->addFrameImage("ClGethit", "image/enemy/cr/cl_gethit.bmp", 0, 0, 1539, 426, 9, 2, true, RGB(255, 0, 255));

	int Cl_R_Hit[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRHit", "ClGethit", Cl_R_Hit, 9, 10, true);
	int Cl_L_Hit[] = { 17,16,15,14,13,12,11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLHit", "ClGethit", Cl_L_Hit, 9, 10, true);

	//치어리더 잡혔을떄
	IMAGEMANAGER->addFrameImage("ClholdingHit", "image/enemy/cr/cl_holding_hit.bmp", 0, 0, 840, 366, 5, 2, true, RGB(255, 0, 255));

	int Cl_R_HoldHit[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRHoldHit", "ClholdingHit", Cl_R_HoldHit, 5, 10, true);
	int Cl_L_HoldHit[] = { 9,8,7,6,5 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLHoldHit", "ClholdingHit", Cl_L_HoldHit, 5, 10, true);

	//치어리더 잡기 풀었을떄
	IMAGEMANAGER->addFrameImage("ClholdingRelease", "image/enemy/cr/cl_holdingrelease.bmp", 0, 0, 840, 450, 4, 2, true, RGB(255, 0, 255));

	int Cl_R_HoldRelease[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRHoldRelease", "ClholdingRelease", Cl_R_HoldRelease, 4, 10, true);
	int Cl_L_HoldRelease[] = { 7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLHoldRelease", "ClholdingRelease", Cl_L_HoldRelease, 4, 10, true);

	//치어리더 점프공격
	IMAGEMANAGER->addFrameImage("ClJump", "image/enemy/cr/cl_jump.bmp", 0, 0, 540, 474, 3, 2, true, RGB(255, 0, 255));

	int Cl_R_Jump[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRJump", "ClJump", Cl_R_Jump, 3, 10, true);
	int Cl_L_Jump[] = { 5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLJump", "ClJump", Cl_L_Jump, 3, 10, true);

	//치어리더 다운및 기상
	IMAGEMANAGER->addFrameImage("ClKnockdown", "image/enemy/cr/cl_knockdown.bmp", 0, 0, 3060, 1242, 12, 6, true, RGB(255, 0, 255));

	int Cl_R_Knockdown[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRKnockdown", "ClKnockdown", Cl_R_Knockdown, 33, 10, true);
	int Cl_L_Knockdown[] = {47,46,45,44,43,42,41,40,39,38,37,36, 59,58,57,56,55,54,53,52,51,50,49,48,71,70,69,68,67,66,65,64,63 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLKnockdown", "ClKnockdown", Cl_L_Knockdown, 33, 10, true);

	//치어리더 걷기
	IMAGEMANAGER->addFrameImage("ClWalk", "image/enemy/cr/cl_walk.bmp", 0, 0, 2736, 438, 12, 2, true, RGB(255, 0, 255));

	int Cl_R_Walk[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRWalk", "ClWalk", Cl_R_Walk, 12, 10, true);
	int Cl_L_Walk[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLWalk", "ClWalk", Cl_L_Walk, 12, 10, true);

	//치어리더 달리기
	IMAGEMANAGER->addFrameImage("Clrun", "image/enemy/cr/cl_run.bmp", 0, 0, 1368, 318, 8, 2, true, RGB(255, 0, 255));

	int Cl_R_Run[] = { 0,1,2,3,4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRrun", "Clrun", Cl_R_Run, 8, 10, true);
	int Cl_L_Run[] = { 15,14,13,12,11,10,9,8 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLrun", "Clrun", Cl_L_Run, 8, 10, true);

	//치어리더 일반공격 & 콤보 1번
	IMAGEMANAGER->addFrameImage("ClJab", "image/enemy/cr/cl_jab.bmp", 0, 0, 1332, 468, 6, 2, true, RGB(255, 0, 255));

	int Cl_R_Jab[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRJab", "ClJab", Cl_R_Jab, 6, 10, true);
	int Cl_L_Jab[] = { 11,10,9,8,7,6 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLJab", "ClJab", Cl_L_Jab, 6, 10, true);

	//치어리더 콤보2번 공격
	IMAGEMANAGER->addFrameImage("ClSpinpom", "image/enemy/cr/cl_spinpom.bmp", 0, 0, 1827, 426, 7, 2, true, RGB(255, 0, 255));

	int Cl_R_Spinpom[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRSpinpom", "ClSpinpom", Cl_R_Spinpom, 7, 10, true);
	int Cl_L_Spinpom[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLSpinpom", "ClSpinpom", Cl_L_Spinpom, 7, 10, true);

	//치어리더 콤보 3번
	IMAGEMANAGER->addFrameImage("ClDoublepom", "image/enemy/cr/cl_doublepom.bmp", 0, 0, 2850, 816, 10, 4, true, RGB(255, 0, 255));

	int Cl_R_Doubl[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRDoublepom", "ClDoublepom", Cl_R_Doubl, 13, 10, true);
	int Cl_L_Doubl[] = { 29,28,27,26,25,24,23,22,21,20,39,38,36,37 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLDoublepom", "ClDoublepom", Cl_L_Doubl, 13, 10, true);

	//치어리더 강공격
	IMAGEMANAGER->addFrameImage("ClBackflip", "image/enemy/cr/cl_backflip.bmp", 0, 0, 3060, 1836, 10, 6, true, RGB(255, 0, 255));

	int Cl_R_Backflip[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRBackflip", "ClBackflip", Cl_R_Backflip, 22, 10, true);
	int Cl_L_Backflip[] = { 40,39,38,37,36,35,34,33,32,31,50,49,48,47,46,45,44,43,42,41,60,59 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRLackflip", "ClBackflip", Cl_L_Backflip, 22, 10, true);

	//치어리더 플레이어가 무기로 쓸때
	IMAGEMANAGER->addFrameImage("ClWeponSwing", "image/enemy/cr/cl_weapon_swing2.bmp", 0, 0, 2604, 432, 7, 2, true, RGB(255, 0, 255));

	int Cl_R_Wepon[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("ClRWepon", "ClWeponSwing", Cl_R_Wepon, 7, 10, true);
	int Cl_L_Wepon[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("ClLWepon", "ClWeponSwing", Cl_L_Wepon, 7, 10, true);
}

void EnemyCheerLeader::AniSet(CLSTATE state)
{
	
	if (_IsRight)
	{
		switch (state)
		{
		case CLIdle:
			_EnemyImage = IMAGEMANAGER->findImage("CLIdle");
			_CLAni = KEYANIMANAGER->findAnimation("ClRightIdle");
			_CLAni->start();
			_ClState = CLIdle;
			break;
		case CLBegging:
			_EnemyImage = IMAGEMANAGER->findImage("ClBegging");
			_CLAni = KEYANIMANAGER->findAnimation("ClRBegging");
			_CLAni->start();
			_ClState = CLBegging;
			break;
		case CLBlowback:
			_EnemyImage = IMAGEMANAGER->findImage("Clblownback");
			_CLAni = KEYANIMANAGER->findAnimation("ClRBlownback");
			_CLAni->start();
			_ClState = CLBlowback;
			break;
		case CLDazed:
			_EnemyImage = IMAGEMANAGER->findImage("ClDazed");
			_CLAni = KEYANIMANAGER->findAnimation("ClRDazed");
			_CLAni->start();
			_ClState = CLDazed;
			break;
		case CLFalling:
			_EnemyImage = IMAGEMANAGER->findImage("ClFalling");
			_CLAni = KEYANIMANAGER->findAnimation("ClRFalling");
			_CLAni->start();
			_ClState = CLFalling;
			break;
		case CLHolding:
			_EnemyImage = IMAGEMANAGER->findImage("ClholdingHit");
			_CLAni = KEYANIMANAGER->findAnimation("ClRHoldHit");
			_CLAni->start();
			_ClState = CLHolding;
			break;
		case CLHoldingrelease:
			_EnemyImage = IMAGEMANAGER->findImage("ClholdingRelease");
			_CLAni = KEYANIMANAGER->findAnimation("ClRHoldRelease");
			_CLAni->start();
			_ClState = CLHoldingrelease;
			break;
		case CLJump:
			_EnemyImage = IMAGEMANAGER->findImage("ClJump");
			_CLAni = KEYANIMANAGER->findAnimation("ClRJump");
			_CLAni->start();
			_ClState = CLJump;
			break;
		case CLKnockdown:
			_EnemyImage = IMAGEMANAGER->findImage("ClKnockdown");
			_CLAni = KEYANIMANAGER->findAnimation("ClRKnockdown");
			_CLAni->start();
			_ClState = CLKnockdown;
			break;
		case CLWalk:
			_EnemyImage = IMAGEMANAGER->findImage("ClWalk");
			_CLAni = KEYANIMANAGER->findAnimation("ClRWalk");
			_CLAni->start();
			_ClState = CLWalk;
			break;
		case CLRun:
			_EnemyImage = IMAGEMANAGER->findImage("Clrun");
			_CLAni = KEYANIMANAGER->findAnimation("ClRrun");
			_CLAni->start();
			_ClState = CLRun;
			break;
		case CLJab:
			_EnemyImage = IMAGEMANAGER->findImage("ClJab");
			_CLAni = KEYANIMANAGER->findAnimation("ClRJab");
			_CLAni->start();
			_ClState = CLJab;
			break;
		case CLSpinpom:
			_EnemyImage = IMAGEMANAGER->findImage("ClSpinpom");
			_CLAni = KEYANIMANAGER->findAnimation("ClRSpinpom");
			_CLAni->start();
			_ClState = CLSpinpom;
			break;
		case CLDoublepom:
			_EnemyImage = IMAGEMANAGER->findImage("ClDoublepom");
			_CLAni = KEYANIMANAGER->findAnimation("ClRDoublepom");
			_CLAni->start();
			_ClState = CLDoublepom;
			break;
		case CLBackflip:
			_EnemyImage = IMAGEMANAGER->findImage("ClBackflip");
			_CLAni = KEYANIMANAGER->findAnimation("ClRBackflip");
			_CLAni->start();
			_ClState = CLBackflip;
			break;
		case CLWeaponSwing:
			_EnemyImage = IMAGEMANAGER->findImage("ClWeponSwing");
			_CLAni = KEYANIMANAGER->findAnimation("ClRWepon");
			_CLAni->start();
			_ClState = CLWeaponSwing;
			break;
		}
	}
	else
	{
		switch (state)
		{
		case CLIdle:
			_EnemyImage = IMAGEMANAGER->findImage("CLIdle");
			_CLAni = KEYANIMANAGER->findAnimation("ClLeftIdle");
			_CLAni->start();
			_ClState = CLIdle;
			break;
		case CLBegging:
			_EnemyImage = IMAGEMANAGER->findImage("ClBegging");
			_CLAni = KEYANIMANAGER->findAnimation("ClLBegging");
			_CLAni->start();
			_ClState = CLBegging;
			break;
		case CLBlowback:
			_EnemyImage = IMAGEMANAGER->findImage("Clblownback");
			_CLAni = KEYANIMANAGER->findAnimation("ClLBlownback");
			_CLAni->start();
			_ClState = CLBlowback;
			break;
		case CLDazed:
			_EnemyImage = IMAGEMANAGER->findImage("ClDazed");
			_CLAni = KEYANIMANAGER->findAnimation("ClLDazed");
			_CLAni->start();
			_ClState = CLDazed;
			break;
		case CLFalling:
			_EnemyImage = IMAGEMANAGER->findImage("ClFalling");
			_CLAni = KEYANIMANAGER->findAnimation("ClLFalling");
			_CLAni->start();
			_ClState = CLFalling;
			break;
		case CLHolding:
			_EnemyImage = IMAGEMANAGER->findImage("ClholdingHit");
			_CLAni = KEYANIMANAGER->findAnimation("ClLHoldHit");
			_CLAni->start();
			_ClState = CLHolding;
			break;
		case CLHoldingrelease:
			_EnemyImage = IMAGEMANAGER->findImage("ClholdingRelease");
			_CLAni = KEYANIMANAGER->findAnimation("ClLHoldRelease");
			_CLAni->start();
			_ClState = CLHoldingrelease;
			break;
		case CLJump:
			_EnemyImage = IMAGEMANAGER->findImage("ClJump");
			_CLAni = KEYANIMANAGER->findAnimation("ClLJump");
			_CLAni->start();
			_ClState = CLJump;
			break;
		case CLKnockdown:
			_EnemyImage = IMAGEMANAGER->findImage("ClKnockdown");
			_CLAni = KEYANIMANAGER->findAnimation("ClLKnockdown");
			_CLAni->start();
			_ClState = CLKnockdown;
			break;
		case CLWalk:
			_EnemyImage = IMAGEMANAGER->findImage("ClWalk");
			_CLAni = KEYANIMANAGER->findAnimation("ClLWalk");
			_CLAni->start();
			_ClState = CLWalk;
			break;
		case CLRun:
			_EnemyImage = IMAGEMANAGER->findImage("Clrun");
			_CLAni = KEYANIMANAGER->findAnimation("ClLrun");
			_CLAni->start();
			_ClState = CLRun;
			break;
		case CLJab:
			_EnemyImage = IMAGEMANAGER->findImage("ClJab");
			_CLAni = KEYANIMANAGER->findAnimation("ClLJab");
			_CLAni->start();
			_ClState = CLJab;
			break;
		case CLSpinpom:
			_EnemyImage = IMAGEMANAGER->findImage("ClSpinpom");
			_CLAni = KEYANIMANAGER->findAnimation("ClLSpinpom");
			_CLAni->start();
			_ClState = CLSpinpom;
			break;
		case CLDoublepom:
			_EnemyImage = IMAGEMANAGER->findImage("ClDoublepom");
			_CLAni = KEYANIMANAGER->findAnimation("ClLDoublepom");
			_CLAni->start();
			_ClState = CLDoublepom;
			break;
		case CLBackflip:
			_EnemyImage = IMAGEMANAGER->findImage("ClBackflip");
			_CLAni = KEYANIMANAGER->findAnimation("ClLBackflip");
			_CLAni->start();
			_ClState = CLBackflip;
			break;
		case CLWeaponSwing:
			_EnemyImage = IMAGEMANAGER->findImage("ClWeponSwing");
			_CLAni = KEYANIMANAGER->findAnimation("ClLWepon");
			_CLAni->start();
			_ClState = CLWeaponSwing;
			break;
		}
	}
}

void EnemyCheerLeader::State()
{
	if (_IsRight)
	{
		switch (_ClState)
		{
		case CLIdle:
			break;
		case CLBegging:
			break;
		case CLBlowback:
			break;
		case CLDazed:
			break;
		case CLFalling:
			break;
		case CLHolding:
			break;
		case CLHoldingrelease:
			break;
		case CLJump:
			break;
		case CLKnockdown:
			break;
		case CLWalk:
			_ClCenterX += 3;
			break;
		case CLRun:
			_ClCenterX += 6;
			break;
		case CLJab:
			break;
		case CLSpinpom:
			break;
		case CLDoublepom:
			break;
		case CLBackflip:
			break;
		case CLWeaponSwing:
			break;
		}
	}
	else
	{
		switch (_ClState)
		{
		case CLIdle:
			break;
		case CLBegging:
			break;
		case CLBlowback:
			break;
		case CLDazed:
			break;
		case CLFalling:
			break;
		case CLHolding:
			break;
		case CLHoldingrelease:
			break;
		case CLJump:
			break;
		case CLKnockdown:
			break;
		case CLWalk:
			_ClCenterX -= 3;
			break;
		case CLRun:
			_ClCenterX -= 6;
			break;
		case CLJab:
			break;
		case CLSpinpom:
			break;
		case CLDoublepom:
			break;
		case CLBackflip:
			break;
		case CLWeaponSwing:
			break;

		}
	}
}



void EnemyCheerLeader::SetCenterX(float x)
{
	_ClCenterX += x;
}	

void EnemyCheerLeader::SetCenterY(float y)
{
	_ClCenterY += y;
}

void EnemyCheerLeader::SetDamge(float damge)
{
	_Hp -= damge;
}