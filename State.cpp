#include "stdafx.h"
#include "State.h"

PlayLeftIdle* PlayLeftIdle::_Instance;
PlayRightIdle* PlayRightIdle::_Instance;
BattleStart* BattleStart::_Instance;
PlayLeftRun* PlayLeftRun::_Instance;
PlayRightRun* PlayRightRun::_Instance;
PlayLeftJump* PlayLeftJump::_Instance;
PlayRightJump* PlayRightJump::_Instance;
PlayLeftFall* PlayLeftFall::_Instance;
PlayRightFall* PlayRightFall::_Instance;
PlayLeftHit* PlayLeftHit::_Instance;
PlayRightHit* PlayRightHit::_Instance;
PlayLeftDown* PlayLeftDown::_Instance;
PlayRightDown* PlayRightDown::_Instance;
PlayLeftStun* PlayLeftStun::_Instance;
PlayRightStun* PlayRightStun::_Instance;



HRESULT State::Init()
{
	_Left = false;
	return S_OK;
}

void State::Update()
{
	_PlayerRc.set(_Center.x-(_PlayerImg->getFrameWidth()*0.5f),
		_Center.y-_PlayerImg->getFrameHeight(),
		_Center.x+(_PlayerImg->getFrameWidth()*0.5f),
		_Center.y);
	KEYANIMANAGER->update();
	ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _PlayerImg, _PlayerRc.left, _PlayerRc.top, _PlayerAni, _PlayerRc.bottom);

}

void State::Render()
{

	_PlayerImg->aniRender(getMemDC(), _PlayerRc.left, _PlayerRc.top, _PlayerAni);
}

void State::DebugRender()
{
	//CAMERAMANAGER->rectangle(getMemDC(), _PlayerRc);
	//CAMERAMANAGER->rectangle(getMemDC(), _AttackRc);
}

void State::Release()
{

}



/// <summary>
/// ///////////////////////////////////////////////////
/// </summary>
/// <returns></returns>
BattleStart* BattleStart::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new BattleStart;
	}
	return _Instance;
}

void BattleStart::Walk(Player* player)
{
}

void BattleStart::Attack1(Player* player)
{
}

void BattleStart::Attack2(Player* player)
{
}

void BattleStart::Attack3(Player* player)
{
}

void BattleStart::StandUp(Player* player)
{
}

void BattleStart::Skill1(Player* player)
{
}

void BattleStart::Skill2(Player* player)
{
}

void BattleStart::Guard(Player* Player)
{
}

void BattleStart::GameOver(Player* player)
{
}

void BattleStart::DiveAttack(Player* player)
{
}

void BattleStart::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerBattleStart");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightBattleStart");
	_PlayerAni->start();

}


////////////////////아이들
PlayLeftIdle* PlayLeftIdle::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftIdle;
	}
	return _Instance;
}

void PlayLeftIdle::Walk(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerWalk");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftWalk");
	_PlayerAni->start();
	
}

void PlayLeftIdle::Attack1(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerAttack1");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftAttack1");
	
	_PlayerAni->start();
	
	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.left, _PlayerRc.top + 50, _PlayerRc.left + 50, _PlayerRc.top + 200);
	}
	
}

void PlayLeftIdle::Attack2(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerAttack2");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftAttack2");
	_PlayerAni->start();
	

	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.left, _PlayerRc.top + 50, _PlayerRc.left + 50, _PlayerRc.top + 200);
	}
}

void PlayLeftIdle::Attack3(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerAttack3");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftAttack3");
	_PlayerAni->start();

	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.left, _PlayerRc.top + 50, _PlayerRc.left + 50, _PlayerRc.top + 200);
	}
}

void PlayLeftIdle::StandUp(Player* player)
{
}

void PlayLeftIdle::Skill1(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerHKick");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerHurrKick");
	_PlayerAni->start();
}

void PlayLeftIdle::Skill2(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerDap");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftDap");
	_PlayerAni->start();
}

void PlayLeftIdle::Guard(Player* Player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerGuard");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftGuard");
	_PlayerAni->start();
}

void PlayLeftIdle::GameOver(Player* player)
{
}

void PlayLeftIdle::DiveAttack(Player* player)
{
}

void PlayLeftIdle::Default(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerIdle");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftIdle");
	_PlayerAni->start();

}


////////////////////////////////////////////////////

PlayRightIdle* PlayRightIdle::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightIdle;
	}
	return _Instance;
}

void PlayRightIdle::Walk(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerWalk");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightWalk");
	_PlayerAni->start();
}

void PlayRightIdle::Attack1(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerAttack1");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightAttack1");
	

	_PlayerAni->start();
	
	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.right, _PlayerRc.top + 50, _PlayerRc.right - 50, _PlayerRc.top + 200);
	}
}

void PlayRightIdle::Attack2(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerAttack2");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightAttack2");
	_PlayerAni->start();

	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.right, _PlayerRc.top + 50, _PlayerRc.right - 50, _PlayerRc.top + 200);
	}
}

void PlayRightIdle::Attack3(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerAttack3");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightAttack3");
	_PlayerAni->start();

	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.right, _PlayerRc.top + 50, _PlayerRc.right - 50, _PlayerRc.top + 200);
	}
}

void PlayRightIdle::StandUp(Player* player)
{
}

void PlayRightIdle::Skill1(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerHKick");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerHurrKick");
	_PlayerAni->start();
	if (_PlayerAni->isPlay())
	{
		_AttackRc.set(_PlayerRc.left-30, _PlayerRc.top, _PlayerRc.right+30, _PlayerRc.bottom);
	}
}

void PlayRightIdle::Skill2(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerDap");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightDap");
	_PlayerAni->start();
}

void PlayRightIdle::Guard(Player* Player)
{

	_PlayerImg = IMAGEMANAGER->findImage("PlayerGuard");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightGuard");
	_PlayerAni->start();
}

void PlayRightIdle::GameOver(Player* player)
{
}

void PlayRightIdle::DiveAttack(Player* player)
{
}

void PlayRightIdle::Default(Player* player)
{

	_PlayerImg = IMAGEMANAGER->findImage("PlayerIdle");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightIdle");
	_PlayerAni->start();
}


//////////////////////아이들







PlayLeftRun* PlayLeftRun::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftRun;
	}
	return _Instance;
}

void PlayLeftRun::Walk(Player* player)
{
}

void PlayLeftRun::Attack1(Player* player)
{
}

void PlayLeftRun::Attack2(Player* player)
{
}

void PlayLeftRun::Attack3(Player* player)
{
}

void PlayLeftRun::StandUp(Player* player)
{
}

void PlayLeftRun::Skill1(Player* player)
{
}

void PlayLeftRun::Skill2(Player* player)
{
}

void PlayLeftRun::Guard(Player* Player)
{
}

void PlayLeftRun::GameOver(Player* player)
{
}

void PlayLeftRun::DiveAttack(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerDiveAttack");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftDiveAttack");
	_PlayerAni->start();
}

void PlayLeftRun::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerRun");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftRun");
	_PlayerAni->start();
}

////////////////////////////////////////////

PlayRightRun* PlayRightRun::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightRun;
	}
	return _Instance;
}

void PlayRightRun::Walk(Player* player)
{
}

void PlayRightRun::Attack1(Player* player)
{
}

void PlayRightRun::Attack2(Player* player)
{
}

void PlayRightRun::Attack3(Player* player)
{
}

void PlayRightRun::StandUp(Player* player)
{
}

void PlayRightRun::Skill1(Player* player)
{
}

void PlayRightRun::Skill2(Player* player)
{
}

void PlayRightRun::Guard(Player* Player)
{
}

void PlayRightRun::GameOver(Player* player)
{
}

void PlayRightRun::DiveAttack(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerDiveAttack");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightDiveAttack");
	_PlayerAni->start();
}

void PlayRightRun::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerRun");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightRun");
	_PlayerAni->start();
}

//////////////////////////////////////////////달리기

PlayLeftJump* PlayLeftJump::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftJump;
	}
	return _Instance;
}

void PlayLeftJump::Walk(Player* player)
{
}

void PlayLeftJump::Attack1(Player* player)
{
}

void PlayLeftJump::Attack2(Player* player)
{
}

void PlayLeftJump::Attack3(Player* player)
{
}

void PlayLeftJump::StandUp(Player* player)
{
}

void PlayLeftJump::Skill1(Player* player)
{
}

void PlayLeftJump::Skill2(Player* player)
{
}

void PlayLeftJump::Guard(Player* Player)
{
}

void PlayLeftJump::GameOver(Player* player)
{
}

void PlayLeftJump::DiveAttack(Player* player)
{
}

void PlayLeftJump::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerJump");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftJump");
	_PlayerAni->start();
}
//////////////////////////////////////////////////

PlayRightJump* PlayRightJump::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightJump;
	}
	return _Instance;
}

void PlayRightJump::Walk(Player* player)
{
}

void PlayRightJump::Attack1(Player* player)
{
}

void PlayRightJump::Attack2(Player* player)
{
}

void PlayRightJump::Attack3(Player* player)
{
}

void PlayRightJump::StandUp(Player* player)
{
}

void PlayRightJump::Skill1(Player* player)
{
}

void PlayRightJump::Skill2(Player* player)
{
}

void PlayRightJump::Guard(Player* Player)
{
}

void PlayRightJump::GameOver(Player* player)
{
}

void PlayRightJump::DiveAttack(Player* player)
{
}

void PlayRightJump::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerJump");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightJump");
	_PlayerAni->start();
}
//////////////////////////////////점프

PlayLeftFall* PlayLeftFall::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftFall;
	}
	return _Instance;
}

void PlayLeftFall::Walk(Player* player)
{
}

void PlayLeftFall::Attack1(Player* player)
{
}

void PlayLeftFall::Attack2(Player* player)
{
}

void PlayLeftFall::Attack3(Player* player)
{
}

void PlayLeftFall::StandUp(Player* player)
{
}

void PlayLeftFall::Skill1(Player* player)
{
}

void PlayLeftFall::Skill2(Player* player)
{
}

void PlayLeftFall::Guard(Player* Player)
{
}

void PlayLeftFall::GameOver(Player* player)
{
}

void PlayLeftFall::DiveAttack(Player* player)
{
}

void PlayLeftFall::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerJump");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftFall");
	_PlayerAni->start();
}
////////////////////////////////////////////

PlayRightFall* PlayRightFall::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightFall;
	}
	return _Instance;
}

void PlayRightFall::Walk(Player* player)
{
}

void PlayRightFall::Attack1(Player* player)
{
}

void PlayRightFall::Attack2(Player* player)
{
}

void PlayRightFall::Attack3(Player* player)
{
}

void PlayRightFall::StandUp(Player* player)
{
}

void PlayRightFall::Skill1(Player* player)
{
}

void PlayRightFall::Skill2(Player* player)
{
}

void PlayRightFall::Guard(Player* Player)
{
}

void PlayRightFall::GameOver(Player* player)
{
}

void PlayRightFall::DiveAttack(Player* player)
{
}

void PlayRightFall::Default(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerJump");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightFall");
	_PlayerAni->start();
}
///////////////////////////////피격

PlayLeftHit* PlayLeftHit::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftHit;
	}
	return _Instance;
}

void PlayLeftHit::Walk(Player* player)
{
}

void PlayLeftHit::Attack1(Player* player)
{
}

void PlayLeftHit::Attack2(Player* player)
{
}

void PlayLeftHit::Attack3(Player* player)
{
}

void PlayLeftHit::StandUp(Player* player)
{
}

void PlayLeftHit::Skill1(Player* player)
{
}

void PlayLeftHit::Skill2(Player* player)
{
}

void PlayLeftHit::Guard(Player* Player)
{
}

void PlayLeftHit::GameOver(Player* player)
{
}

void PlayLeftHit::DiveAttack(Player* player)
{
}

void PlayLeftHit::Default(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerHit");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftHit");
	_PlayerAni->start();
}
////////////////////////////////////////////

PlayRightHit* PlayRightHit::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightHit;
	}
	return _Instance;
}

void PlayRightHit::Walk(Player* player)
{
}

void PlayRightHit::Attack1(Player* player)
{
}

void PlayRightHit::Attack2(Player* player)
{
}

void PlayRightHit::Attack3(Player* player)
{
}

void PlayRightHit::StandUp(Player* player)
{
}

void PlayRightHit::Skill1(Player* player)
{
}

void PlayRightHit::Skill2(Player* player)
{
}

void PlayRightHit::Guard(Player* Player)
{
}

void PlayRightHit::GameOver(Player* player)
{
}

void PlayRightHit::DiveAttack(Player* player)
{
}

void PlayRightHit::Default(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerHit");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightHit");
	_PlayerAni->start();
}
/////////////////////피격

PlayLeftDown* PlayLeftDown::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftDown;
	}
	return _Instance;
}

void PlayLeftDown::Walk(Player* player)
{
}

void PlayLeftDown::Attack1(Player* player)
{
}

void PlayLeftDown::Attack2(Player* player)
{
}

void PlayLeftDown::Attack3(Player* player)
{
}

void PlayLeftDown::StandUp(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerStandUp");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftStandUp");
	_PlayerAni->start();
}

void PlayLeftDown::Skill1(Player* player)
{
}

void PlayLeftDown::Skill2(Player* player)
{
}

void PlayLeftDown::Guard(Player* Player)
{
}

void PlayLeftDown::GameOver(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerGameOver");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftGameOver");
	_PlayerAni->start();
}

void PlayLeftDown::DiveAttack(Player* player)
{
}

void PlayLeftDown::Default(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerDown");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftDown");
	_PlayerAni->start();
}
////////////////////////////////////

PlayRightDown* PlayRightDown::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightDown;
	}
	return _Instance;
}

void PlayRightDown::Walk(Player* player)
{
}

void PlayRightDown::Attack1(Player* player)
{
}

void PlayRightDown::Attack2(Player* player)
{
}

void PlayRightDown::Attack3(Player* player)
{
}

void PlayRightDown::StandUp(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerStandUp");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightStandUp");
	_PlayerAni->start();
}

void PlayRightDown::Skill1(Player* player)
{
}

void PlayRightDown::Skill2(Player* player)
{
}

void PlayRightDown::Guard(Player* Player)
{
}

void PlayRightDown::GameOver(Player* player)
{
	
	_PlayerImg = IMAGEMANAGER->findImage("PlayerGameOver");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightGameOver");
	_PlayerAni->start();
}

void PlayRightDown::DiveAttack(Player* player)
{
}

void PlayRightDown::Default(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerDown");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightDown");
	_PlayerAni->start();
}
////////////////////////////////////다운

PlayLeftStun* PlayLeftStun::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayLeftStun;
	}
	return _Instance;
}

void PlayLeftStun::Walk(Player* player)
{
}

void PlayLeftStun::Attack1(Player* player)
{
}

void PlayLeftStun::Attack2(Player* player)
{
}

void PlayLeftStun::Attack3(Player* player)
{
}

void PlayLeftStun::StandUp(Player* player)
{
}

void PlayLeftStun::Skill1(Player* player)
{
}

void PlayLeftStun::Skill2(Player* player)
{
}

void PlayLeftStun::Guard(Player* Player)
{
}

void PlayLeftStun::GameOver(Player* player)
{
}

void PlayLeftStun::DiveAttack(Player* player)
{
}

void PlayLeftStun::Default(Player* player)
{
	_PlayerImg = IMAGEMANAGER->findImage("PlayerStnned");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerLeftStnned");
	_PlayerAni->start();
}
////////////////////////////////////////////////

PlayRightStun* PlayRightStun::GetInstance()
{
	if (_Instance == nullptr)
	{
		_Instance = new PlayRightStun;
	}
	return _Instance;
}

void PlayRightStun::Walk(Player* player)
{
}

void PlayRightStun::Attack1(Player* player)
{
}

void PlayRightStun::Attack2(Player* player)
{
}

void PlayRightStun::Attack3(Player* player)
{
}

void PlayRightStun::StandUp(Player* player)
{
}

void PlayRightStun::Skill1(Player* player)
{
}

void PlayRightStun::Skill2(Player* player)
{
}

void PlayRightStun::Guard(Player* Player)
{
}

void PlayRightStun::GameOver(Player* player)
{
}

void PlayRightStun::DiveAttack(Player* player)
{
}

void PlayRightStun::Default(Player* player)
{

	_PlayerImg = IMAGEMANAGER->findImage("PlayerStnned");
	_PlayerRc.set(_Center.x - (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y - _PlayerImg->getFrameHeight(),
		_Center.x + (_PlayerImg->getFrameWidth() * 0.5f),
		_Center.y);
	_PlayerAni = KEYANIMANAGER->findAnimation("PlayerRightStnned");
	_PlayerAni->start();
}
