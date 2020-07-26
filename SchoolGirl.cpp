#include "stdafx.h"
#include "SchoolGirl.h"
#include "Player.h"

HRESULT SchoolGirl::init(float centerX, float centerY, bool IsRight)
{
	ImgInit();
	_Name = "ScoolGirl";
	_Type = EnemyType::Scoolgirl;
	_State = EnemyState::Init;
	_IsRight = IsRight;
	_Anim = KEYANIMANAGER->findAnimation("SgRTaunt");
	_Img = IMAGEMANAGER->findImage("SgTaunt");
	_ShadowImg = IMAGEMANAGER->findImage("Enemy_Shadow");
	_Center.x = centerX;
	_Center.y = centerY;
	_Collision.centerSet(_Center.x, _Center.y, _Img->getFrameWidth(), _Img->getFrameHeight());
	_RangeCollision.centerSet(_Center.x, _Center.y, 300, 200);
	_ShadowCollision.centerSet(_Center.x, _Center.y + _Img->getFrameHeight() * 0.5, _ShadowImg->getWidth(), _ShadowImg->getHeight());
	_ShadowCenter.x = _Center.x;
	_ShadowCenter.y = _Center.y + _Img->getFrameHeight() * 0.5;
	_Angle = 0;
	_Velocity = 5.0f;
	_IsHit = false;
	_IsKnockDown = false;
	_IsDie = false;
	_DeathIsComing = 0;

	_Anim->start();

	return S_OK;
}

void SchoolGirl::ImgInit()
{
	//여학생 도발
	IMAGEMANAGER->addFrameImage("SgTaunt", "image/enemy/sg/sg_taunt.bmp", _Collision.left, _Collision.top, 3510, 366, 26, 2, true, RGB(255, 0, 255));
	int Sg_R_Hit[] = { 0,1,2 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRGethit", "SgGethit", Sg_R_Hit, 3, 10, false);
	int Sg_L_Hit[] = { 11,10,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLGethit", "SgGethit", Sg_L_Hit, 3, 10, false);

	int Sg_R_Idle[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRIdle", "SgIdle", Sg_R_Idle, 10, 10, true);
	int Sg_L_Idle[] = { 19,18,17,16,15,14,13,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLIdle", "SgIdle", Sg_L_Idle, 10, 10, true);

	int Sg_R_Jab[] = { 0,1,2,3,4,5,6 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRJab", "SgJab", Sg_R_Jab, 7, 10, false);
	int Sg_L_Jab[] = { 13,12,11,10,9,8,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLJab", "SgJab", Sg_L_Jab, 7, 10, false);

	int Sg_R_Knockdown[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRKnockdown", "SgKnockdown", Sg_R_Knockdown, 33, 10, false);
	int Sg_L_Knockdown[] = { 51,50,49,48,47,46,45,44,43,42,41,40,39,64,63,62,61,60,59,58,57,56,55,54,53,52,77,76,75,74,73,72,71 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLKnockdown", "SgKnockdown", Sg_L_Knockdown, 33, 10, false);
	
	int Sg_R_Run[] = { 0,1,2,3,4,5,6,7,8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRRun", "SgRun", Sg_R_Run, 10, 10, false);
	int Sg_L_Run[] = { 19,18,17,16,15,14,13,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLRun", "SgRun", Sg_L_Run, 10, 10, false);
	
	int Sg_R_Taunt[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRTaunt", "SgTaunt", Sg_R_Taunt, 26, 10, false);
	int Sg_L_Taunt[] = { 51, 50, 49,48, 47, 46,45, 44, 43, 42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLTaunt", "SgTaunt", Sg_L_Taunt, 26, 10, false);

	
	int Sg_R_Walk[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRWalk", "SgWalk", Sg_R_Walk, 12, 10, false);
	int Sg_L_Walk[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLWalk", "SgWalk", Sg_L_Walk, 12, 10, false);

	//죽는 모션
	int Sg_R_Die[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("SgRDie", "SgKnockdown", Sg_R_Die, 24, 10, false);
	int Sg_L_Die[] = { 51,50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 64, 63, 62, 61, 60, 59, 58, 57,56,55,54 };
	KEYANIMANAGER->addArrayFrameAnimation("SgLDie", "SgKnockdown", Sg_L_Die, 24, 10, false);
}

void SchoolGirl::update()
{
	_Angle = getAngle(_ShadowCenter.x, _ShadowCenter.y, _Player->GetShadowCenterPoint().x, _Player->GetShadowCenterPoint().y);
	AnimReSet();
	UpdateCollison();
	
	if (_State != EnemyState::KnockDown && _State != EnemyState::Die && !_IsKnockDown)
	{
		BeShot();
		Move();
	}
	if (_IsKnockDown)_KnockDownCount++;
	if (_KnockDownCount % 50 == 0)_IsKnockDown = false;
	if (_State == EnemyState::Walk)
	{
		_ShadowCenter.x += cosf(_Angle) * _Velocity;
		_ShadowCenter.y += -sinf(_Angle) * _Velocity;

	}
	if (_State == EnemyState::Run)
	{
		_ShadowCenter.y += -sinf(_Angle) * _Velocity * 2;
		_ShadowCenter.x += cosf(_Angle) * _Velocity * 2;
	}
	if (_DeathIsComing > 3)
	{
		_IsDie = true;
	}
	if (_IsDie)
	{
		_State = EnemyState::Die;
		_IsDie = false;
		_DeathIsComing = 0;
		_Anim->start();
	}
	if (!_Anim->isPlay() && _State != EnemyState::Die)
	{
		_Anim->start();
		_Img = IMAGEMANAGER->findImage("SgIdle");
		_State = EnemyState::Idle;
	}
	if (_Anim == KEYANIMANAGER->findAnimation("SgRKnockdown"))ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Collision.left, _Collision.top + 50, _Anim, _ShadowCollision.bottom);
	else if (_Anim == KEYANIMANAGER->findAnimation("SgLKnockdown"))ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Collision.left, _Collision.top + 50, _Anim, _ShadowCollision.bottom);
	else if (_Anim == KEYANIMANAGER->findAnimation("SgRDie"))ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Collision.left, _Collision.top + 60, _Anim, _ShadowCollision.bottom);
	else if (_Anim == KEYANIMANAGER->findAnimation("SgLDie"))ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Collision.left, _Collision.top + 60, _Anim, _ShadowCollision.bottom);
	else ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Collision.left, _Collision.top, _Anim, _ShadowCollision.bottom);
}

void SchoolGirl::Move()
{
	if (_Player->GetShadowCenterX() > _Center.x && _State != EnemyState::Init && _State != EnemyState::KnockDown && _State != EnemyState::Die)_IsRight = true;
	else if (_Player->GetShadowCenterX() < _Center.x && _State != EnemyState::Init && _State != EnemyState::KnockDown && _State != EnemyState::Die)_IsRight = false;


	if (_State != EnemyState::KnockDown || _State != EnemyState::BeShot || _State != EnemyState::Die)
	{
		if (getDistance(_ShadowCenter.x, _ShadowCenter.y, _Player->GetShadowCenterPoint().x, _Player->GetShadowCenterPoint().y) < 50)
		{
			_State = EnemyState::Attack;
		}

		else if (!isCollision(_Player->GetShadowRect(), _RangeCollision) && _State == EnemyState::Idle)
		{
			int RndAction = RND->getFromIntTo(1, 3);
			switch (RndAction)
			{
			case 1:
				_State = EnemyState::Run;
				break;
			case 2:
				_State = EnemyState::Walk;
				break;
			default:
				break;
			}
		}
	}
}


void SchoolGirl::BeShot()
{
	if (isCollision(_Player->GetAttackRC1(), _Collision) || isCollision(_Player->GetAttackRC2(), _Collision))
	{
		_State = EnemyState::BeShot;
	}
	if (isCollision(_Player->GetAttackRC3(), _Collision) || isCollision(_Player->GetAttackRCH(), _Collision))
	{
		_State = EnemyState::KnockDown;
		_IsKnockDown = true;
		_DeathIsComing++;
	}
}

void SchoolGirl::AnimReSet()
{
	switch (_State)
	{
	case EnemyState::Init:
		_Img = IMAGEMANAGER->findImage("SgTaunt");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRTaunt");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLTaunt");
		break;
	case EnemyState::Idle:
		_Img = IMAGEMANAGER->findImage("SgIdle");
		if (_IsRight) _Anim = KEYANIMANAGER->findAnimation("SgRIdle");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLIdle");
		break;
	case EnemyState::Walk:
		_Img = IMAGEMANAGER->findImage("SgWalk");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRWalk");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLWalk");
		break;
	case EnemyState::Run:
		_Img = IMAGEMANAGER->findImage("SgRun");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRRun");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLRun");
		break;
	case EnemyState::BeShot:
		_Img = IMAGEMANAGER->findImage("SgGethit");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRGethit");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLGethit");
		break;
	case EnemyState::KnockDown:
		_Img = IMAGEMANAGER->findImage("SgKnockdown");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRKnockdown");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLKnockdown");
		break;
	case EnemyState::Attack:
		_Img = IMAGEMANAGER->findImage("SgJab");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRJab");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLJab");
		break;
	case EnemyState::Die:
		_Img = IMAGEMANAGER->findImage("SgKnockdown");
		if (_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgRDie");
		else if (!_IsRight)_Anim = KEYANIMANAGER->findAnimation("SgLDie");
		break;
	default:
		break;
	}



}

void SchoolGirl::UpdateCollison()
{
	_Center.x = _ShadowCenter.x;
	_Center.y = _ShadowCenter.y - _Img->getFrameHeight() * 0.5;
	_Collision.centerSet(_Center.x, _Center.y, _Img->getFrameWidth(), _Img->getFrameHeight());
	_RangeCollision.centerSet(_Center.x, _Center.y, 500, 300);
	_ShadowCollision.centerSet(_ShadowCenter.x, _ShadowCenter.y, _ShadowImg->getWidth(), _ShadowImg->getHeight());
}

void SchoolGirl::RIdle(void* obj)
{
	SchoolGirl* Sg = (SchoolGirl*)obj;

	Sg->SetState(EnemyState::Idle);
	Sg->SetAnim(KEYANIMANAGER->findAnimation("SgRIdle"));
	Sg->GetAnim()->start();
}

void SchoolGirl::LIdle(void* obj)
{
	SchoolGirl* Sg = (SchoolGirl*)obj;

	Sg->SetState(EnemyState::Idle);
	Sg->SetAnim(KEYANIMANAGER->findAnimation("SgLIdle"));
	Sg->GetAnim()->start();
}
