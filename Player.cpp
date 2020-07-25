#include "stdafx.h"
#include "player.h"
#include "State.h"
#include "Boss.h"
Player::Player()
{

	_State = BattleStart::GetInstance();
}

void Player::PlayerImageAniStting()
{
	IMAGEMANAGER->addFrameImage("PlayerBattleStart", "Player/Kyoko_BattleStart.bmp", 2964, 420, 26, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerIdle", "Player/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerWalk", "Player/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerRun", "Player/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerAttack1", "Player/Kyoko_ComboAttack1.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerAttack2", "Player/Kyoko_ComboAttack2.bmp", 1869, 402, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerAttack3", "Player/Kyoko_ComboAttack3.bmp", 2970, 462, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerHit", "Player/Kyoko_Hit.bmp", 246, 348, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerDown", "Player/Kyoko_Down.bmp", 4896, 366, 24, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerGuard", "Player/Kyoko_Guard.bmp", 351, 378, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerDiveAttack", "Player/Kyoko_Dive.bmp", 5040, 360, 21, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerGameOver", "Player/Kyoko_GameOver.bmp", 6240, 282, 26, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerHKick", "Player/Kyoko_HurricaneKick.bmp", 2997, 657, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerStandUp", "Player/Kyoko_StandUp.bmp", 3315, 330, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerStomp", "Player/Kyoko_Stomp.bmp", 1290, 420, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerStnned", "Player/Kyoko_Stunned.bmp", 384, 384, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerDap", "Player/Kyoko_Ultimate.bmp", 3675, 384, 25, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PlayerJump", "Player/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("PlayerShadow", "Player/KyoKo_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));

	//배틀스타트
	int lBattleStart[] = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftBattleStart", "PlayerBattleStart", lBattleStart, 26, 15, false);
	int rBattleStart[] = { 26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightBattleStart", "PlayerBattleStart", rBattleStart, 26, 15, false);

	//아이들
	int lIdele[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftIdle", "PlayerIdle", lIdele, 12, 10, true);
	int rIdle[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightIdle", "PlayerIdle", rIdle, 12, 10, true);

	//걷기
	int lWalk[] = { 11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftWalk", "PlayerWalk", lWalk, 12, 10, true);
	int rWalk[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightWalk", "PlayerWalk", rWalk, 12, 10, true);

	//달리기
	int lRun[] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftRun", "PlayerRun", lRun, 16, 15, true);
	int rRun[] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightRun", "PlayerRun", rRun, 16, 15, true);

	//평타1
	int lAttack1[] = { 5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack1", "PlayerAttack1", lAttack1, 6, 16, false);
	int rAttack1[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack1", "PlayerAttack1", rAttack1, 6, 16, false);

	//평타2
	int lAttack2[] = { 6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack2", "PlayerAttack2", lAttack2, 7, 17, false);
	int rAttack2[] = { 7,8,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack2", "PlayerAttack2", rAttack2, 7, 17, false);

	//평타3
	int lAttack3[] = { 8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftAttack3", "PlayerAttack3", lAttack3, 9, 18, false);
	int rAttack3[] = { 9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightAttack3", "PlayerAttack3", rAttack3, 9, 18, false);

	//피격
	int lHit[] = { 1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftHit", "PlayerHit", lHit, 2, 3, false);
	int rHit[] = { 2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightHit", "PlayerHit", rHit, 2, 3, false);

	//다운
	int lDown[] = { 23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDown", "PlayerDown", lDown, 24, 20, false);
	int rDown[] = { 24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDown", "PlayerDown", rDown, 24, 20, false);

	//가드
	int lGuard[] = { 2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftGuard", "PlayerGuard", lGuard, 3, 6, false);
	int rGuard[] = { 3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightGuard", "PlayerGuard", rGuard, 3, 6, false);

	//다이빙공격
	int lDive[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDiveAttack", "PlayerDiveAttack", lDive, 21, 18, false);
	int rDive[] = { 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDiveAttack", "PlayerDiveAttack", rDive, 21, 18, false);

	//게임오버
	int lGameOver[] = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftGameOver", "PlayerGameOver", lGameOver, 26, 6, false);
	int rGameOver[] = { 26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightGameOver", "PlayerGameOver", rGameOver, 26, 6, false);

	//허리케인킥
	int HKick[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerHurrKick", "PlayerHKick", HKick, 24, 13, false);

	//기상
	int lStandUp[] = { 16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStandUp", "PlayerStandUp", lStandUp, 17, 20, false);
	int rStandUp[] = { 17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStandUp", "PlayerStandUp", rStandUp, 17, 20, false);

	//밟기
	int lStomp[] = { 9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStomp", "PlayerStomp", lStomp, 10, 6, false);
	int rStomp[] = { 10,11,12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStomp", "PlayerStomp", rStomp, 10, 6, false);

	//기절
	int lStnned[] = { 3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftStnned", "PlayerStnned", lStnned, 4, 6, false);
	int rStnned[] = { 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightStnned", "PlayerStnned", rStnned, 4, 6, false);

	//댑
	int lDap[] = { 24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftDap", "PlayerDap", lDap, 25, 20, false);
	int rDap[] = { 25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightDap", "PlayerDap", rDap, 25, 20, false);

	//점프
	int lJump[] = { 2,1 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftJump", "PlayerJump", lJump, 2, 3, false);
	int rJump[] = { 4,3 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightJump", "PlayerJump", rJump, 2, 3, false);

	//착지
	int lFall[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerLeftFall", "PlayerJump", lFall, 1, 5, false);
	int rFall[] = { 5 };
	KEYANIMANAGER->addArrayFrameAnimation("PlayerRightFall", "PlayerJump", rFall, 1, 5, false);

}

HRESULT Player::Init()
{
	PlayerImageAniStting();
	_Center.x = 500;
	_Center.y = 800;
	_Shadow = IMAGEMANAGER->findImage("PlayerShadow");
	_ShadowRc.set(_Center.x - (_Shadow->getWidth() * 0.5f),
		_Center.y - (_Shadow->getHeight() * 0.5f),
		_Center.x + (_Shadow->getWidth() * 0.5f),
		_Center.y + (_Shadow->getHeight() * 0.5f));
	_PlayerHitRc.set(_Center.x - 64, _Center.y - 200, _Center.x + 64, _Center.y);
	_Speed = 5;
	_MoveLR = MOVELR::NON;
	_MoveUD = MOVEUD::NON;

	_AttackRc1.set(0, 0, 0, 0);
	_AttackRc2.set(0, 0, 0, 0);
	_AttackRc3.set(0, 0, 0, 0);
	_AttackRcH.set(0, 0, 0, 0);
	_DAP.set(0, 0, 0, 0);

	_Money = 0.0f;
	_Hp = 100.0f;
	_Exp = 0.0f;
	_Level = 0;

	_State->SetCenterXY(_Center);
	_State->Init();
	Default();

	_ProbeL = _ShadowRc.left;
	_ProbeR = _ShadowRc.right;
	_ProbeT = _ShadowRc.top;
	_ProbeB = _ShadowRc.bottom;

	return S_OK;

}

void Player::Update()
{
	if (_State == BattleStart::GetInstance() && !_State->GetAniIsPlay())
	{
		_State = PlayRightIdle::GetInstance();
		_State->SetCenterXY(_Center);
		Default();
	}
	if (_State != BattleStart::GetInstance())
	{
		AttackUpdate();
		PlayerKeyMove();
	}

	if (_State != BattleStart::GetInstance() && !_State->GetAniIsPlay())
	{
		if (_State != PlayLeftDown::GetInstance() && _State != PlayRightDown::GetInstance())Default();
	}


	if (!KEYANIMANAGER->findAnimation("PlayerHurrKick")->isPlay())_AttackRcH.set(0, 0, 0, 0);
	if (KEYANIMANAGER->findAnimation("PlayerHurrKick")->isPlay())_AttackRcH.set(_Center.x - 150, _Center.y - 170, _Center.x + 150, _Center.y);

	if (KEYANIMANAGER->findAnimation("PlayerLeftDap")->isPlay())_DAP.set(0, 0, WINSIZEX, WINSIZEY);
	if (KEYANIMANAGER->findAnimation("PlayerRightDap")->isPlay())_DAP.set(0, 0, WINSIZEX, WINSIZEY);

	if (!KEYANIMANAGER->findAnimation("PlayerLeftDap")->isPlay())_DAP.set(0, 0, 0, 0);
	if (!KEYANIMANAGER->findAnimation("PlayerRightDap")->isPlay())_DAP.set(0, 0, 0, 0);




	_ShadowRc.set(_Center.x - (_Shadow->getWidth() * 0.5f),
		_Center.y - (_Shadow->getHeight() * 0.5f),
		_Center.x + (_Shadow->getWidth() * 0.5f),
		_Center.y + (_Shadow->getHeight() * 0.5f));

	_PlayerHitRc.set(_State->GetPlayerRect().left + 30, _State->GetPlayerRect().top + 50,
		_State->GetPlayerRect().right - 30, _State->GetPlayerRect().bottom);






	if (KEYMANAGER->isOnceKeyDown('N'))_HitDmg = 10;
	if (KEYMANAGER->isOnceKeyDown('V'))_HitDmg = 50;


	if (!_Down)
	{
		if (KEYMANAGER->isOnceKeyDown('B'))
		{
			//HitReaction();
			//DownReaction();
		}//피격테스트
	}
	BossAndPlayerCol(); //보스와 플레이어 공격충돌
	HitUpdate();//플레이어 일반피격시 리액션
	DownUpdate();//플레이어 강공격피격시 리액션
	StandUpUpdate();//플레이어 다운이후 기상하는 리액션
	DashUpdate();//플레이어 대쉬 업데이트
	DashAttUpdate();//플레이어 대쉬어택 업데이트
	GuardOff();// 플레이어 가드 지속시간
	JumpUpdate();//플레이어 점프 업데이트
	AttCountTimer();//어택카운트 초기화 타임
	PixelCol();//픽셀충돌용함수

	if (!_Jump && !_Fall)
	{
		_State->SetCenterXY(_Center);

	}
	if (_Jump || _Fall)
	{
		_State->SetCenterXY(_DummyCen);
	}
	_ShadowRc.set(_Center.x - (_Shadow->getWidth() * 0.5f),
		_Center.y - (_Shadow->getHeight() * 0.5f),
		_Center.x + (_Shadow->getWidth() * 0.5f),
		_Center.y + (_Shadow->getHeight() * 0.5f));

	_PlayerHitRc.set(_State->GetPlayerRect().left + 30, _State->GetPlayerRect().top + 50,
		_State->GetPlayerRect().right - 30, _State->GetPlayerRect().bottom);

	ZORDER->ZOrderPush(getMemDC(), RenderType::RENDER, _Shadow, _ShadowRc.left, _ShadowRc.top, _ShadowRc.top);
	_State->Update();
}

void Player::Release()
{
}

void Player::Render()
{
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))DebugRender();
}

void Player::DebugRender()
{
	_State->DebugRender();
	CAMERAMANAGER->rectangle(getMemDC(), _PlayerHitRc);
	CAMERAMANAGER->rectangle(getMemDC(), _AttackRc1);
	CAMERAMANAGER->rectangle(getMemDC(), _AttackRc2);
	CAMERAMANAGER->rectangle(getMemDC(), _AttackRc3);
	CAMERAMANAGER->rectangle(getMemDC(), _AttackRcH);
	CAMERAMANAGER->rectangle(getMemDC(), _ShadowRc);
	CAMERAMANAGER->rectangle(getMemDC(), _DashAtt);

}

void Player::PlayerKeyMove()
{

	if (!KEYANIMANAGER->findAnimation("PlayerLeftAttack1")->isPlay() && !KEYANIMANAGER->findAnimation("PlayerRightAttack1")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerLeftAttack2")->isPlay() && !KEYANIMANAGER->findAnimation("PlayerRightAttack2")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerLeftAttack3")->isPlay() && !KEYANIMANAGER->findAnimation("PlayerRightAttack3")->isPlay() &&
		!_Jump && !_Fall && !_Hit && !_Down && !_StandUp && !_DashAttbool
		&& !KEYANIMANAGER->findAnimation("PlayerHurrKick")->isPlay() && !KEYANIMANAGER->findAnimation("PlayerLeftGuard")->isPlay()
		&& !KEYANIMANAGER->findAnimation("PlayerRightGuard")->isPlay() && !KEYANIMANAGER->findAnimation("PlayerLeftDap")->isPlay()
		&& !KEYANIMANAGER->findAnimation("PlayerRightDap")->isPlay())
	{
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			if (_State != PlayLeftRun::GetInstance())
			{
				_State = PlayLeftIdle::GetInstance();
				_State->SetCenterXY(_Center);
				Walk();
				_Left = true;
				_MoveLR = MOVELR::LEFT_WALK;
				_LRun = true;
				_LClickTime++;
			}
		}
		if (KEYMANAGER->isOnceKeyUp('A'))
		{
			if (_MoveLR == MOVELR::LEFT_RUN || _State == PlayLeftRun::GetInstance())
			{
				_State = PlayLeftIdle::GetInstance();
			}
			_State->SetCenterXY(_Center);
			_MoveLR = MOVELR::NON;
			if (_MoveLR != MOVELR::LEFT_WALK && _MoveLR != MOVELR::RIGHT_WALK && _MoveUD != MOVEUD::UP_WALK && _MoveUD != MOVEUD::DOWN_WALK)Default();

			_LClickTime++;
			if (_LClickTime != 2)_LClickTime = 0;
		}

		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			if (_State != PlayRightRun::GetInstance())
			{
				_State = PlayRightIdle::GetInstance();
				_State->SetCenterXY(_Center);
				Walk();
				_Left = false;
				_MoveLR = MOVELR::RIGHT_WALK;
				_RRun = true;
				_RClickTime++;
			}
		}
		if (KEYMANAGER->isOnceKeyUp('D'))
		{
			if (_MoveLR == MOVELR::RIGHT_RUN || _State == PlayRightRun::GetInstance())
			{
				_State = PlayRightIdle::GetInstance();
			}
			_State->SetCenterXY(_Center);
			_MoveLR = MOVELR::NON;
			if (_MoveLR != MOVELR::LEFT_WALK && _MoveLR != MOVELR::RIGHT_WALK && _MoveUD != MOVEUD::UP_WALK && _MoveUD != MOVEUD::DOWN_WALK)Default();
			_RClickTime++;
			if (_RClickTime != 2)_RClickTime = 0;

		}

		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			if (_State != PlayRightRun::GetInstance() && _State != PlayLeftRun::GetInstance())
			{
				if (_Left)_State = PlayLeftIdle::GetInstance();
				if (!_Left)_State = PlayRightIdle::GetInstance();
			}
			_State->SetCenterXY(_Center);
			Walk();
			_MoveUD = MOVEUD::UP_WALK;
		}
		if (KEYMANAGER->isOnceKeyUp('W'))
		{
			_MoveUD = MOVEUD::NON;
			if (_MoveLR != MOVELR::LEFT_WALK && _MoveLR != MOVELR::RIGHT_WALK && _MoveUD != MOVEUD::UP_WALK && _MoveUD != MOVEUD::DOWN_WALK)Default();

		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			if (_State != PlayRightRun::GetInstance() && _State != PlayLeftRun::GetInstance())
			{
				if (_Left)_State = PlayLeftIdle::GetInstance();
				if (!_Left)_State = PlayRightIdle::GetInstance();
			}
			_State->SetCenterXY(_Center);
			Walk();
			_MoveUD = MOVEUD::DOWN_WALK;
		}
		if (KEYMANAGER->isOnceKeyUp('S'))
		{
			_MoveUD = MOVEUD::NON;
			if (_MoveLR != MOVELR::LEFT_WALK && _MoveLR != MOVELR::RIGHT_WALK && _MoveUD != MOVEUD::UP_WALK && _MoveUD != MOVEUD::DOWN_WALK)Default();

		}
		if (KEYMANAGER->isOnceKeyDown('Y'))
		{
			if (_Left)_State = PlayLeftIdle::GetInstance();
			if (!_Left)_State = PlayRightIdle::GetInstance();
			_State->SetCenterXY(_Center);
			Skill1();
			//_AttackRcH = _State->GetAttRect();
			//cout << _AttackRcH.left << endl;
			_MoveUD = MOVEUD::NON;
			_MoveLR = MOVELR::NON;
		}
		if (KEYMANAGER->isOnceKeyDown('U'))
		{
			if (_Left)
			{
				_LGuard = true;
				_State = PlayLeftIdle::GetInstance();
			}
			if (!_Left)
			{
				_RGuard = true;
				_State = PlayRightIdle::GetInstance();
			}
			_State->SetCenterXY(_Center);


			Guard();
			_MoveUD = MOVEUD::NON;
			_MoveLR = MOVELR::NON;
		}
		if (KEYMANAGER->isOnceKeyDown('J') && !_Hit && !_Down && !_StandUp)
		{
			_DummyCen = _State->GetCenterXY();
			if (_Left)
			{
				SetState(PlayLeftJump::GetInstance());
				Default();

				_Jump = true;
			}
			else if (!_Left)
			{
				SetState(PlayRightJump::GetInstance());
				Default();
				_Jump = true;
			}

			_MoveUD = MOVEUD::NON;
			_MoveLR = MOVELR::NON;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if (_Left)_State = PlayLeftIdle::GetInstance();
			if (!_Left)_State = PlayRightIdle::GetInstance();
			_State->SetCenterXY(_Center);
			Skill2();
			_MoveUD = MOVEUD::NON;
			_MoveLR = MOVELR::NON;
		}
	}

	MoveUpdate();
}

void Player::MoveUpdate()
{
	switch (_MoveLR)
	{
	case MOVELR::LEFT_WALK:
		_Center.x -= _Speed;
		break;
	case MOVELR::RIGHT_WALK:
		_Center.x += _Speed;
		break;
	case MOVELR::LEFT_RUN:
		_Center.x -= _Speed * 1.5f;
		break;
	case MOVELR::RIGHT_RUN:
		_Center.x += _Speed * 1.5f;
		break;
	case MOVELR::NON:
		break;
	}
	switch (_MoveUD)
	{
	case MOVEUD::UP_WALK:
		_Center.y -= (_Speed * 0.5f);
		break;
	case MOVEUD::DOWN_WALK:
		_Center.y += (_Speed * 0.5f);
		break;
	case MOVEUD::UP_RUN:
		_Center.y -= _Speed;
		break;
	case MOVEUD::DOWN_RUN:
		_Center.y += _Speed;
		break;
	case MOVEUD::NON:
		break;
	}
}

void Player::AttackUpdate()
{

	if (KEYMANAGER->isOnceKeyDown('H') && !_DashAttbool)
	{
		if (_State == PlayRightRun::GetInstance())
		{
			_DashAttbool = true;
			DiveAttack();
		}
		if (_State == PlayLeftRun::GetInstance())
		{
			_DashAttbool = true;
			DiveAttack();
		}
		if (_State != PlayRightRun::GetInstance() && _State != PlayLeftRun::GetInstance())
		{
			if (_AttackCount == 0 && !KEYANIMANAGER->findAnimation("PlayerLeftAttack3")->isPlay() &&
				!KEYANIMANAGER->findAnimation("PlayerRightAttack3")->isPlay())
			{
				Attack1();
				cout << _AttackCount << endl;
				_AttCountOn = true;
				_AttackCount++;
				_AttackRc1 = _State->GetAttRect();
				_State->SetAttRect();


			}
			if (_AttackCount == 1 && !KEYANIMANAGER->findAnimation("PlayerLeftAttack1")->isPlay() &&
				!KEYANIMANAGER->findAnimation("PlayerRightAttack1")->isPlay())
			{

				Attack2();
				_AttCountOn = true;
				_AttackCount++;
				_AttackRc2 = _State->GetAttRect();
				_State->SetAttRect();

			}

			if (_AttackCount == 2 && !KEYANIMANAGER->findAnimation("PlayerLeftAttack2")->isPlay() &&
				!KEYANIMANAGER->findAnimation("PlayerRightAttack2")->isPlay())
			{

				Attack3();
				_AttCountOn = true;
				_AttackCount++;
				_AttackRc3 = _State->GetAttRect();
				_State->SetAttRect();

			}
		}
		_MoveUD = MOVEUD::NON;
		_MoveLR = MOVELR::NON;
	}

	if (!KEYANIMANAGER->findAnimation("PlayerLeftAttack1")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerRightAttack1")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerLeftAttack2")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerRightAttack2")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerLeftAttack3")->isPlay() &&
		!KEYANIMANAGER->findAnimation("PlayerRightAttack3")->isPlay())
	{
		_AttackRc1.set(0, 0, 0, 0);
		_AttackRc2.set(0, 0, 0, 0);
		_AttackRc3.set(0, 0, 0, 0);
		_AttCountOn = false;
	}

}

void Player::DashUpdate()
{
	if (_RRun)
	{
		_RTime++;
		if (_RTime < 15 && _RClickTime >= 3)
		{
			SetState(PlayRightRun::GetInstance());
			_State->SetCenterXY(_Center);
			Default();
			_MoveLR = MOVELR::RIGHT_RUN;

			_RClickTime = 0;
			_RTime = 0;
			_RRun = false;
		}
		if (_RTime == 15)
		{
			_RClickTime = 0;
			_RTime = 0;
			_RRun = false;
		}
	}
	if (_LRun)
	{
		_LTime++;
		if (_LTime < 15 && _LClickTime >= 3)
		{
			SetState(PlayLeftRun::GetInstance());
			_State->SetCenterXY(_Center);
			Default();
			_MoveLR = MOVELR::LEFT_RUN;

			_LClickTime = 0;
			_LTime = 0;
			_LRun = false;
		}
		if (_LTime == 15)
		{
			_LClickTime = 0;
			_LTime = 0;
			_LRun = false;
		}
	}
}

void Player::DashAttUpdate()
{
	if (_DashAttbool)
	{
		_DashAtt.set(0, 0, 0, 0);
		if (_State == PlayRightRun::GetInstance())
		{
			if (KEYANIMANAGER->findAnimation("PlayerRightDiveAttack")->getNowAniIndex() < 10)
			{
				_DashAtt.set(_PlayerHitRc.right, _PlayerHitRc.top, _PlayerHitRc.right + 20, _PlayerHitRc.bottom);
				_Center.x += 7;
			}
			if (!KEYANIMANAGER->findAnimation("PlayerRightDiveAttack")->isPlay())
			{
				_State = PlayRightIdle::GetInstance();
				_State->SetCenterXY(_Center);
				_DashAttbool = false;

			}
		}
		if (_State == PlayLeftRun::GetInstance())
		{
			if (KEYANIMANAGER->findAnimation("PlayerLeftDiveAttack")->getNowAniIndex() < 10)
			{
				_DashAtt.set(_PlayerHitRc.left, _PlayerHitRc.top, _PlayerHitRc.left - 20, _PlayerHitRc.bottom);
				_Center.x -= 7;
			}
			if (!KEYANIMANAGER->findAnimation("PlayerLeftDiveAttack")->isPlay())
			{
				_State = PlayLeftIdle::GetInstance();
				_State->SetCenterXY(_Center);
				_DashAttbool = false;

			}
		}
	}
}


void Player::JumpUpdate()
{
	if (!_Hit && !_Down && !_StandUp)
	{
		if (_Jump || _Fall)
		{

			if (KEYMANAGER->isStayKeyDown('W'))
			{
				_DummyCen.y -= 4;
				_Center.y -= 4;
			}
			if (KEYMANAGER->isStayKeyDown('A'))
			{
				_Left = true;
				_DummyCen.x -= 6;
				_Center.x -= 6;
			}
			if (KEYMANAGER->isStayKeyDown('S'))
			{
				_DummyCen.y += 4;
				_Center.y += 4;
			}
			if (KEYMANAGER->isStayKeyDown('D'))
			{
				_Left = false;
				_DummyCen.x += 6;
				_Center.x += 6;
			}
		}
		if (_Jump && !_Hit && !_Down)
		{
			_DummyCen.y -= 12;
			_JumpStack += 12;
			if (_JumpStack >= _JumpMax)
			{
				_JumpStack = 0;
				_Jump = false;
				if (_Left)
				{
					SetState(PlayLeftFall::GetInstance());
					Default();

					_Fall = true;
				}
				else if (!_Left)
				{
					SetState(PlayRightFall::GetInstance());
					Default();
					_Fall = true;
				}

			}
			_MoveUD = MOVEUD::NON;
			_MoveLR = MOVELR::NON;
		}

		if (_Fall)
		{
			_DummyCen.y += 10;
			_JumpStack += 10;
			if (_JumpStack >= _JumpMax)
			{
				_JumpStack = 0;
				_Fall = false;
				if (_Left)
				{
					SetState(PlayLeftIdle::GetInstance());
					Default();
				}
				else if (!_Left)
				{
					SetState(PlayRightIdle::GetInstance());
					Default();
				}
			}
			_MoveUD = MOVEUD::NON;
			_MoveLR = MOVELR::NON;
		}
	}
}



void Player::HitUpdate()
{

	if (!_Boss->GetBossLeft() && _Hit)
	{
		_Center.x += 2;
		_HitStack += 2;
		if (_HitStack == 30)
		{
			_Hit = false;
			_State = PlayLeftIdle::GetInstance();
			_State->SetCenterXY(_Center);
			_DashAttbool = false;
			_HitStack = 0;
			Default();
		}
		_MoveUD = MOVEUD::NON;
		_MoveLR = MOVELR::NON;
	}
	if (_Boss->GetBossLeft() && _Hit)
	{
		_Center.x -= 2;
		_HitStack += 2;
		if (_HitStack == 30)
		{
			_Hit = false;
			_State = PlayRightIdle::GetInstance();
			_State->SetCenterXY(_Center);
			_DashAttbool = false;
			_HitStack = 0;
			Default();
		}
		_MoveUD = MOVEUD::NON;
		_MoveLR = MOVELR::NON;
	}


}



void Player::DownUpdate()
{
	if (_Down)
	{
		_MoveUD = MOVEUD::NON;
		_MoveLR = MOVELR::NON;
		if (_Left)
		{
			if (KEYANIMANAGER->findAnimation("PlayerLeftDown")->getNowAniIndex() < 15)_Center.x += 3;
			if (_Jump || _Fall)
			{
				_DummyCen.x = _Center.x;
				if (_DummyCen.y <= _Center.y)_DummyCen.y += 2;
			}
			if (!KEYANIMANAGER->findAnimation("PlayerLeftDown")->isPlay())
			{
				if (_Hp <= 0)
				{
					GameOver();
				}
				else
				{

					_Down = false;
					_HitStack = 0;
					_StandUp = true;
					_Jump = false;
					_Fall = false;
					_JumpStack = 0;
					StandUp();
				}
			}
		}


		if (!_Left)
		{
			if (KEYANIMANAGER->findAnimation("PlayerRightDown")->getNowAniIndex() < 15)_Center.x -= 3;
			if (_Jump || _Fall)
			{
				_DummyCen.x = _Center.x;
				if (_DummyCen.y <= _Center.y)_DummyCen.y += 2;
			}

			if (!KEYANIMANAGER->findAnimation("PlayerRightDown")->isPlay())
			{
				if (_Hp <= 0)
				{
					GameOver();
				}
				else
				{

					_Down = false;
					_HitStack = 0;
					_StandUp = true;
					_Jump = false;
					_Fall = false;
					_JumpStack = 0;
					StandUp();
				}
			}
		}

	}


}

void Player::StandUpUpdate()
{
	if (_StandUp)
	{
		_MoveUD = MOVEUD::NON;
		_MoveLR = MOVELR::NON;
		if (_Left && !KEYANIMANAGER->findAnimation("PlayerLeftStandUp")->isPlay())
		{
			_State = PlayLeftIdle::GetInstance();
			_State->SetCenterXY(_Center);
			Default();
			_StandUp = false;
		}

		if (!_Left && !KEYANIMANAGER->findAnimation("PlayerRightStandUp")->isPlay())
		{
			_State = PlayRightIdle::GetInstance();
			_State->SetCenterXY(_Center);
			Default();
			_StandUp = false;
		}

	}


}

void Player::BossAndPlayerCol()
{
	if (isCollision(_PlayerHitRc, _Boss->GetAttRect()))
	{
		//보스의 왼쪽펀지
		if (_Boss->GetState() == BOSS_STATE::ATTACK && _Boss->GetBossLeft() && !_RGuard)
		{
			RightHitReaction();
		}

		//보스의 오른쪽펀치
		if (_Boss->GetState() == BOSS_STATE::ATTACK && !_Boss->GetBossLeft() && !_LGuard)
		{
			LeftHitReaction();
		}


		//보스의 왼쪽에서 땅찍기 맞을때
		if (_Boss->GetState() == BOSS_STATE::LANDHIT && _Boss->GetBossCenterX() <= _Center.x)
		{
			LeftDownReaction();
		}

		//보스의 오른쪽에서 땅찍기 맞을때	
		if (_Boss->GetState() == BOSS_STATE::LANDHIT && _Boss->GetBossCenterX() > _Center.x)
		{
			RightDownReaction();
		}
	}
}

void Player::GuardOff()
{
	if (!KEYANIMANAGER->findAnimation("PlayerRightGuard")->isPlay())
	{
		_RGuard = false;
	}
	if (!KEYANIMANAGER->findAnimation("PlayerLeftGuard")->isPlay())
	{
		_LGuard = false;
	}
}

void Player::AttCountTimer()
{
	if (_AttackCount < 0 || _AttackCount>2)_AttackCount = 0;
	if (!_AttCountOn)
	{
		_AttCountTimer++;
		if (_AttCountTimer > 20)
		{
			_AttackCount = 0;
			_AttCountTimer = 0;
		}
	}
}

void Player::RightHitReaction()
{
	_State = PlayRightHit::GetInstance();
	_State->SetCenterXY(_Center);
	_Hit = true;
	Default();
}

void Player::LeftHitReaction()
{
	_State = PlayLeftHit::GetInstance();
	_State->SetCenterXY(_Center);
	_Hit = true;
	Default();
}

void Player::RightDownReaction()
{
	_Left = false;
	_State = PlayRightDown::GetInstance();
	_State->SetCenterXY(_Center);
	_Down = true;
	Default();
}

void Player::LeftDownReaction()
{
	_Left = true;
	_State = PlayLeftDown::GetInstance();
	_State->SetCenterXY(_Center);
	_Down = true;
	Default();
}

void Player::PixelCol()
{
	_ProbeL = _ShadowRc.left;
	_ProbeR = _ShadowRc.right;
	_ProbeT = _ShadowRc.top;
	_ProbeB = _ShadowRc.bottom;


	COLORREF colorL = GetPixel(IMAGEMANAGER->findImage(_MapName)->getMemDC(), _ShadowRc.left - _MapX, _Center.y-_MapY);
	int Lr = GetRValue(colorL);
	int Lg = GetGValue(colorL);
	int Lb = GetBValue(colorL);
	if (Lr == 255 && Lg == 0 && Lb == 0)
	{
		if (_MoveLR == MOVELR::LEFT_RUN)
		{
			_Center.x = _Center.x + _Speed * 1.5f;
		}
		else
		{
			_Center.x += _Speed;
		}
	}
	COLORREF colorT = GetPixel(IMAGEMANAGER->findImage(_MapName)->getMemDC(), _Center.x - _MapX, _ShadowRc.top - _MapY);
	int Tr = GetRValue(colorT);
	int Tg = GetGValue(colorT);
	int Tb = GetBValue(colorT);
	if (Tr == 255 && Tg == 0 && Tb == 0)
	{
		if (_MoveUD == MOVEUD::UP_RUN)
		{
			_Center.y = _Center.y + _Speed;
		}
		else
		{
			_Center.y += _Speed * 0.5f;
		}
	}
	COLORREF colorB = GetPixel(IMAGEMANAGER->findImage(_MapName)->getMemDC(), _Center.x - _MapX, _ShadowRc.bottom - _MapY);
	int Br = GetRValue(colorB);
	int Bg = GetGValue(colorB);
	int Bb = GetBValue(colorB);
	if (Br == 255 && Bg == 0 && Bb == 0)
	{
		if (_MoveUD == MOVEUD::UP_RUN)
		{
			_Center.y = _Center.y - _Speed;
		}
		else
		{
			_Center.y -= _Speed * 0.5f;
		}
	}
	COLORREF colorR = GetPixel(IMAGEMANAGER->findImage(_MapName)->getMemDC(), _ShadowRc.right - _MapX, _Center.y - _MapY);
	int Rr = GetRValue(colorR);
	int Rg = GetGValue(colorR);
	int Rb = GetBValue(colorR);
	if (Rr == 255 && Rg == 0 && Rb == 0)
	{
		if (_MoveLR == MOVELR::RIGHT_RUN)
		{
			_Center.x = _Center.x - _Speed * 1.5f;
		}
		else
		{
			_Center.x -= _Speed;
		}
	}


}







void Player::Walk()
{
	_State->Walk(this);
}

void Player::Attack1()
{
	_State->Attack1(this);
}

void Player::Attack2()
{
	_State->Attack2(this);
}

void Player::Attack3()
{
	_State->Attack3(this);
}

void Player::StandUp()
{
	_State->StandUp(this);
}

void Player::Skill1()
{
	_State->Skill1(this);
}

void Player::Skill2()
{
	_State->Skill2(this);
}

void Player::Guard()
{
	_State->Guard(this);
}

void Player::GameOver()
{
	_State->GameOver(this);
}

void Player::DiveAttack()
{
	_State->DiveAttack(this);
}

void Player::Default()
{
	_State->Default(this);
}


void Player::SetState(State* state)
{
	this->_State = state;
}


