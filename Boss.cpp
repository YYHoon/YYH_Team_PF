#include "stdafx.h"
#include "Boss.h"
#include "Player.h"


HRESULT Boss::init()
{
    _ShadowImg = IMAGEMANAGER->addImage("Shadow", "image/Boss/Shadow.bmp", 200, 59, true, RGB(255, 0, 255));
    _CrackImg = IMAGEMANAGER->addImage("CRACK", "image/Boss/CRACK.bmp", 819, 256, true, RGB(255, 0, 255));
    _Img = IMAGEMANAGER->addFrameImage("IDLE", "image/Boss/idle.bmp", 0, 0, 2772, 566, 12, 2, true, RGB(255, 0, 255));

    _Bs = BOSS_STATE::IDLE;
    _ExBs = BOSS_STATE::IDLE;
    _Pz = PHAZE::FIRST;

    _Center.x = 1600;
    _Center.y = 800;

    _Hit = { 100,100,200,200 };
    _Rc = { _Center.x - 50,_Center.y - 50,_Center.x + 50,_Center.y + 50 };
    _Shadow = { _Center.x - 50,_Center.y - 50,_Center.x + 50,_Center.y + 50 };
    _Attack = { 0,0,0,0 };
    _Speed = 2.0f;
    _Hp = 90;
    _Time = 0;
    _JumpTime = 0;
    _HitTime = 100;
    _AttackNum = 0;
    _HitNum = 0;
    _Alpha = 0;
    _IsLookLeft = true;

    int Right_Idle[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    KEYANIMANAGER->addArrayFrameAnimation("RightIdle", "IDLE", Right_Idle, 12, 10, true);

    int Left_Idle[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftIdle", "IDLE", Left_Idle, 12, 10, true);

    int Right_Wake[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
    KEYANIMANAGER->addArrayFrameAnimation("RightWake", "WAKE", Right_Wake, 19, 10, false, RightIDLE, this);

    int Left_Wake[] = { 37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftWake", "WAKE", Left_Wake, 19, 10, false, LeftIDLE, this);

    int Right_Move[] = { 0,1,2,3,4,5,6,7,8 };
    KEYANIMANAGER->addArrayFrameAnimation("RightMove", "WALK", Right_Move, 9, 10, true);

    int Left_Move[] = { 17,16,15,14,13,12,11,10,9 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftMove", "WALK", Left_Move, 9, 10, true);

    int Right_Attack[] = { 0,1,2,3,4,5,6,7,8,9 };
    KEYANIMANAGER->addArrayFrameAnimation("RightAttack", "ATTACK", Right_Attack, 10, 10, false, RightIDLE, this);

    int Left_Attack[] = { 19,18,17,16,15,14,13,12,11,10 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftAttack", "ATTACK", Left_Attack, 10, 10, false, LeftIDLE, this);

    int Right_Slap[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    KEYANIMANAGER->addArrayFrameAnimation("RightSlap", "SLAP", Right_Slap, 14, 10, false, RightIDLE, this);

    int Left_Slap[] = { 27,26,25,24,23,22,21,20,19,18,17,16,15,14 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftSlap", "SLAP", Left_Slap, 14, 10, false, LeftIDLE, this);

    int Right_Slap_Red[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("RightSlapRed", "SLAPRED", Right_Slap_Red, 14, 10, false, RightIDLE, this);

    int Left_Slap_Red[] = { 27,26,25,24,23,22,21,20,19,18,17,16,15,14 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftSlapRed", "SLAPRED", Left_Slap_Red, 14, 10, false, LeftIDLE, this);

    int Right_Punch[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
    KEYANIMANAGER->addArrayFrameAnimation("RightPunch", "PUNCH", Right_Punch, 27, 10, false, RightIDLE, this);

    int Left_Punch[] = { 53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftPunch", "PUNCH", Left_Punch, 27, 10, false, LeftIDLE, this);

    int Right_Punch_red[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
    KEYANIMANAGER->addArrayFrameAnimation("RightPunchred", "PUNCHRED", Right_Punch_red, 27, 10, false, RightIDLE, this);

    int Left_Punch_red[] = { 53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftPunchred", "PUNCHRED", Left_Punch_red, 27, 10, false, LeftIDLE, this);
    //히트 1
    int Right_Hit1[] = { 0,1,2 };
    KEYANIMANAGER->addArrayFrameAnimation("RightHit1", "HIT", Right_Hit1, 3, 7, false, RightIDLE, this);

    int Left_Hit1[] = { 11,10,9 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftHit1", "HIT", Left_Hit1, 3, 7, false, LeftIDLE, this);
    //히트 2
    int Right_Hit2[] = { 3,4,5 };
    KEYANIMANAGER->addArrayFrameAnimation("RightHit2", "HIT", Right_Hit2, 3, 7, false, RightIDLE, this);

    int Left_Hit2[] = { 14,13,12 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftHit2", "HIT", Left_Hit2, 3, 7, false, LeftIDLE, this);
    //히트 3
    int Right_Hit3[] = { 6,7,8 };
    KEYANIMANAGER->addArrayFrameAnimation("RightHit3", "HIT", Right_Hit3, 3, 7, false, RightIDLE, this);

    int Left_Hit3[] = { 17,16,15 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftHit3", "HIT", Left_Hit3, 3, 7, false, LeftIDLE, this);
    //
    int Right_Knock[] = { 9,8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("RightKnock", "KNOCK", Right_Knock, 10, 7, false, RightSIT, this);

    int Left_Knock[] = { 10,11,12,13,14,15,16,17,18,19 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftKnock", "KNOCK", Left_Knock, 10, 7, false, LeftSIT, this);

    int Right_Sit[] = { 0,1,2,3 };
    KEYANIMANAGER->addArrayFrameAnimation("RightSit", "SIT", Right_Sit, 4, 5, false, RightWAKE, this);

    int Left_Sit[] = { 7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftSit", "SIT", Left_Sit, 4, 5, false, LeftWAKE, this);

    int Right_Taunt[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 };
    KEYANIMANAGER->addArrayFrameAnimation("RightTaunt", "TAUNT", Right_Taunt, 23, 10, false, RightRUSH, this);

    int Left_Taunt[] = { 45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftTaunt", "TAUNT", Left_Taunt, 23, 10, false, LeftRUSH, this);

    int Right_Taunt_Red[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 };
    KEYANIMANAGER->addArrayFrameAnimation("RightTauntRed", "TAUNTRED", Right_Taunt_Red, 23, 10, false, RightRUSH, this);

    int Left_Taunt_Red[] = { 45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftTauntRed", "TAUNTRED", Left_Taunt_Red, 23, 10, false, LeftRUSH, this);

    int Right_Roar[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    KEYANIMANAGER->addArrayFrameAnimation("RightRoar", "ROAR", Right_Roar, 12, 8, false, RightTAUNT, this);

    int Left_Roar[] = { 23,22,21,20,19,18,17,16,15,14,13,12 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftRoar", "ROAR", Left_Roar, 12, 8, false, LeftTAUNT, this);

    int Right_Idle_Rush[] = { 0,1,2,3,4 };
    KEYANIMANAGER->addArrayFrameAnimation("Right_Idle_Rush", "IDLE_RUSH", Right_Idle_Rush, 5, 10, false, RightRUSH, this);

    int Left_Idle_Rush[] = { 9,8,7,6,5 };
    KEYANIMANAGER->addArrayFrameAnimation("Left_Idle_Rush", "IDLE_RUSH", Left_Idle_Rush, 5, 10, false, LeftRUSH, this);

    int Right_Rush[] = { 0,1,2,3,4,5,6,7 };
    KEYANIMANAGER->addArrayFrameAnimation("RightRush", "RUSH", Right_Rush, 8, 10, true);

    int Left_Rush[] = { 15,14,13,12,11,10,9,8 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftRush", "RUSH", Left_Rush, 8, 10, true);

    int Right_Turn[] = { 0,1,2 };
    KEYANIMANAGER->addArrayFrameAnimation("RightTurn", "RUSHTURN", Right_Turn, 3, 8, false, LeftRUSH, this);

    int Left_Turn[] = { 5,4,3 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftTurn", "RUSHTURN", Left_Turn, 3, 8, false, RightRUSH, this);

    int Right_Jump[] = { 0,1,2,3,4,5 };
    KEYANIMANAGER->addArrayFrameAnimation("RightJump", "JUMP", Right_Jump, 6, 10, false, RightJUMP, this);

    int Left_Jump[] = { 11,10,9,8,7,6 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftJump", "JUMP", Left_Jump, 6, 10, false, LeftTJUMP, this);

    int Right_Up[] = { 0,1,2,3 };
    KEYANIMANAGER->addArrayFrameAnimation("RightUp", "UP", Right_Up, 4, 10, true);

    int Left_Up[] = { 7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftUp", "UP", Left_Up, 4, 10, true);

    int Right_Down[] = { 0,1,2 };
    KEYANIMANAGER->addArrayFrameAnimation("RightDown", "DOWN", Right_Down, 3, 10, true);

    int Left_Down[] = { 5,4,3 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftDown", "DOWN", Left_Down, 3, 10, true);

    int Right_Land_Hit[] = { 0,1,2,3,4,5,6,7,8 };
    KEYANIMANAGER->addArrayFrameAnimation("RightLandHit", "LANDHIT", Right_Land_Hit, 9, 10, false, RightIDLE, this);

    int Left_Land_Hit[] = { 17,16,15,14,13,12,11,10,9 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftLandHit", "LANDHIT", Left_Land_Hit, 9, 10, false, LeftIDLE, this);

    int Right_Dead[] = { 0,1,2,3,4,5,6,7,8 };
    KEYANIMANAGER->addArrayFrameAnimation("RightDead", "DEAD", Right_Dead, 9, 10, false, RightCRY, this);

    int Left_Dead[] = { 17,16,15,14,13,12,11,10,9 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftDead", "DEAD", Left_Dead, 9, 10, false, LeftCRY, this);

    int Right_Cry[] = { 0,1,2,3 };
    KEYANIMANAGER->addArrayFrameAnimation("RightCry", "CRY", Right_Cry, 4, 10, true);

    int Left_Cry[] = { 7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("LeftCry", "CRY", Left_Cry, 4, 10, true);

    SetAni(KEYANIMANAGER->findAnimation("LeftIdle"));
    _Ani->start();

    return S_OK;
}

void Boss::release()
{
}

void Boss::update()
{
    _Angle = getAngle(_Center.x, _Center.y, _Player->GetShadowCenterPoint().x, _Player->GetShadowCenterPoint().y);

    _Time++;
    if (_JumpTime < 1000)
    {
        _JumpTime++;
    }
    if (_HitTime < 100)
    {
        _HitTime++;
    }

    if (_Alpha > 0)
    {
        _Alpha--;
    }

    cout << _Hp << endl;

    if (KEYMANAGER->isOnceKeyDown('1')) _Bs = BOSS_STATE::IDLE;
    if (KEYMANAGER->isOnceKeyDown('2')) _Bs = BOSS_STATE::WALK;
    if (KEYMANAGER->isOnceKeyDown('3')) _Bs = BOSS_STATE::JUMP;
    if (KEYMANAGER->isOnceKeyDown('4')) _Bs = BOSS_STATE::ROAR;
    if (KEYMANAGER->isOnceKeyDown('5')) _Bs = BOSS_STATE::KNOCK;
    if (KEYMANAGER->isOnceKeyDown('6')) _Bs = BOSS_STATE::PUNCH;
    if (KEYMANAGER->isOnceKeyDown('7')) _Bs = BOSS_STATE::SLAP;
    if (KEYMANAGER->isOnceKeyDown('8')) _Bs = BOSS_STATE::DEAD;

    if (KEYMANAGER->isOnceKeyDown('Z')) _Ani->start();
    if (KEYMANAGER->isOnceKeyDown('Q')) _Hp -= 10;

    if (_Bs != BOSS_STATE::IDLE && _Bs != BOSS_STATE::DOWN)
    {
        _Time = 100;
    }

    if (_Bs == BOSS_STATE::LANDHIT)
    {
        _JumpTime = 0;
    }

    if ((_Pz != PHAZE::FIRST) && (_JumpTime > 600) && ((_Bs == BOSS_STATE::IDLE) || (_Bs == BOSS_STATE::WALK)) &&
        (getDistance(_Center.x, _Center.y, _Player->GetShadowCenterPoint().x, _Player->GetShadowCenterPoint().y) > 700))
    {
        _Bs = BOSS_STATE::JUMP;
    }

    if (_Bs == BOSS_STATE::WALK || _Bs == BOSS_STATE::DOWN || _Bs == BOSS_STATE::HIT)
    {
        if (_Center.x > _Player->GetShadowCenterPoint().x)
        {
            _IsLookLeft = true;
        }
        else
        {
            _IsLookLeft = false;
        }
    }
    if (_Bs != BOSS_STATE::UP && _Bs != BOSS_STATE::DOWN && _Bs != BOSS_STATE::KNOCK)
    {
        _Jump = 0;
    }

    if (_Hp == -200)
    {
        _Hp--;
        _Bs = BOSS_STATE::DEAD;
    }

    if (_Bs == BOSS_STATE::IDLE || _Bs == BOSS_STATE::WALK || _Bs == BOSS_STATE::ATTACK)
    {
        if (_HitTime > 30)
        {
            if (isCollision(_Player->GetAttackRC1(), _Rc))
            {
                SOUNDMANAGER->play("HITSOUND1", 0.1f);
                _Bs = BOSS_STATE::HIT;
                _HitNum = 1;
                _Hp -= 4;

            }
            else if (isCollision(_Player->GetAttackRC2(), _Rc))
            {
                SOUNDMANAGER->play("HITSOUND2", 0.1f);
                _Bs = BOSS_STATE::HIT;
                _HitNum = 2;
                _Hp -= 4;

            }
            else if (isCollision(_Player->GetAttackRC3(), _Rc))
            {
                SOUNDMANAGER->play("HITSOUND4", 0.1f);
                _Bs = BOSS_STATE::KNOCK;
                _Hp -= 8;

            }
            else if (isCollision(_Player->GetAttackRCH(), _Rc))
            {
                SOUNDMANAGER->play("HITSOUND4", 0.1f);
                _Bs = BOSS_STATE::KNOCK;
                _Hp -= 8;

            }
            else if (isCollision(_Player->GetAttackRCDash(), _Rc))
            {
                SOUNDMANAGER->play("HITSOUND4", 0.1f);
                _Bs = BOSS_STATE::KNOCK;
                _Hp -= 8;

            }
            _HitTime = 0;
        }
    }
    switch (_Bs)
    {
    case BOSS_STATE::IDLE:

        if ((_Hp <= 60) && (_Hp > 30))
        {
            if ((_Pz == PHAZE::FIRST))
            {
                _Bs = BOSS_STATE::ROAR;
            }
            _Pz = PHAZE::SECOND;
        }
        else if ((_Hp <= 30) && (_Hp > 0))
        {
            if ((_Pz == PHAZE::SECOND))
            {
                _Bs = BOSS_STATE::ROAR;
            }
            _Pz = PHAZE::THIRD;
        }
        else if ((_Hp <= 0) && (_Hp >= -50))
        {
            _Hp = -200;
        }

        _Img = IMAGEMANAGER->findImage("IDLE");
        if (_Time > 200)
        {
            _Bs = BOSS_STATE::WALK;
        }
        break;
    case BOSS_STATE::WALK:
        _Img = IMAGEMANAGER->findImage("WALK");
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        if (!_IsLookLeft)
        {
            if (getDistance(_Center.x, _Center.y, _Player->GetShadowCenterPoint().x, _Player->GetShadowCenterPoint().y) < 150 &&
                (_Center.y + 30 > _Player->GetShadowCenterPoint().y) &&
                (_Center.y - 30 < _Player->GetShadowCenterPoint().y))
            {
                _AttackNum = RND->getInt(4);

                _Time = 100;
                switch (_AttackNum)
                {
                case 0:
                    _Bs = BOSS_STATE::ATTACK;
                    break;
                case 1:
                    _Bs = BOSS_STATE::SLAP;
                    break;
                case 2:
                    _Bs = BOSS_STATE::PUNCH;
                    break;
                }
            }
        }
        else
        {
            if (getDistance(_Center.x, _Center.y, _Player->GetShadowCenterPoint().x, _Player->GetShadowCenterPoint().y) < 150 &&
                (_Center.y + 30 > _Player->GetShadowCenterPoint().y) &&
                (_Center.y - 30 < _Player->GetShadowCenterPoint().y))
            {
                _AttackNum = RND->getInt(4);

                _Time = 100;
                switch (_AttackNum)
                {
                case 0:
                    _Bs = BOSS_STATE::ATTACK;
                    break;
                case 1:
                    _Bs = BOSS_STATE::SLAP;
                    break;
                case 2:
                    _Bs = BOSS_STATE::PUNCH;
                    break;
                }
            }
        }
        break;
    case BOSS_STATE::ATTACK:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("ATTACK");
        break;
    case BOSS_STATE::SLAP:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        if (_Pz != PHAZE::THIRD)
        {
            _Img = IMAGEMANAGER->findImage("SLAP");
        }
        else
        {
            _Img = IMAGEMANAGER->findImage("SLAPRED");
        }
        break;
    case BOSS_STATE::GUARD:
        break;
    case BOSS_STATE::PUNCH:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        if (_Pz != PHAZE::THIRD)
        {
            _Img = IMAGEMANAGER->findImage("PUNCH");
        }
        else
        {
            _Img = IMAGEMANAGER->findImage("PUNCHRED");
        }
        break;
    case BOSS_STATE::ROAR:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("ROAR");
        _ExBs = BOSS_STATE::ROAR;
        if (_Ani->getNowAniIndex() == 8)
        {
            _Attack = { _Center.x - 400, _Center.y - 200, _Center.x + 400, _Center.y + 200 };
        }
        else
        {
            _Attack = { 0,0,0,0 };
        }
        break;
    case BOSS_STATE::IDLE_RUSH:
        _Img = IMAGEMANAGER->findImage("IDLE_RUSH");
        _ExBs = BOSS_STATE::IDLE_RUSH;
        break;
    case BOSS_STATE::RIGHTRUSH:
        _Img = IMAGEMANAGER->findImage("RUSH");
        if (isCollision(_Rc, _Player->GetShadowRect()))
        {
            SOUNDMANAGER->stop("RUSHSOUND");
            _ExBs = BOSS_STATE::RIGHTRUSH;
            _Ani->stop();
            RightTAUNT(this);
            _Attack = { 0,0,0,0 };
        }
    case BOSS_STATE::LEFTRUSH:
        _Img = IMAGEMANAGER->findImage("RUSH");
        if (isCollision(_Rc, _Player->GetShadowRect()))
        {
            SOUNDMANAGER->stop("RUSHSOUND");
            _ExBs = BOSS_STATE::LEFTRUSH;
            _Ani->stop();
            LeftTAUNT(this);
            _Attack = { 0,0,0,0 };
        }
        break;
    case BOSS_STATE::RUSHTURN:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("RUSHTURN");
        _ExBs = BOSS_STATE::RUSHTURN;
        break;
    case BOSS_STATE::JUMP:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("JUMP");
        break;
    case BOSS_STATE::UP:
        _Img = IMAGEMANAGER->findImage("UP");
        break;
    case BOSS_STATE::DOWN:
        _Img = IMAGEMANAGER->findImage("DOWN");
        break;
    case BOSS_STATE::LANDHIT:
        _Img = IMAGEMANAGER->findImage("LANDHIT");
        if (_Ani->getNowAniIndex() == 0)
        {
            _Attack = { _Center.x - 400, _Center.y - 200, _Center.x + 400, _Center.y + 200 };
        }
        else
        {
            _Attack = { 0,0,0,0 };
        }
        break;
    case BOSS_STATE::HIT:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("HIT");
        break;
    case BOSS_STATE::GROUNDHIT:
        break;
    case BOSS_STATE::KNOCK:
        _Img = IMAGEMANAGER->findImage("KNOCK");

        break;
    case BOSS_STATE::SIT:
        _Img = IMAGEMANAGER->findImage("SIT");
        break;
    case BOSS_STATE::WAKE:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("WAKE");
        if (_Ani->getNowAniIndex() == 10)
        {
            SOUNDMANAGER->play("LANDHITSOUND", 0.1f);
            _ExCenter.x = _Center.x - (IMAGEMANAGER->findImage("IDLE")->getFrameWidth() * 0.5) - 280;
            _ExCenter.y = _Center.y - 120;
            _Alpha = 255;
            _Attack = { _Center.x - 400, _Center.y - 200, _Center.x + 400, _Center.y + 200 };
        }
        else
        {
            _Attack = { 0,0,0,0 };
        }
        break;
    case BOSS_STATE::TAUNT:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        if (_Pz != PHAZE::THIRD)
        {
            _Img = IMAGEMANAGER->findImage("TAUNT");

        }
        else
        {
            _Img = IMAGEMANAGER->findImage("TAUNTRED");
        }
        break;
    case BOSS_STATE::DEAD:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        _Img = IMAGEMANAGER->findImage("DEAD");

        break;

    case BOSS_STATE::CRY:
        _Img = IMAGEMANAGER->findImage("CRY");
        break;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    switch (_Bs)
    {
    case BOSS_STATE::IDLE:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightIdle");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftIdle");
        }
        break;
    case BOSS_STATE::WALK:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightMove");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftMove");
        }

        if ((_Center.x > _Player->GetShadowCenterPoint().x + 50) || (_Center.x < _Player->GetShadowCenterPoint().x - 50))
        {
            _Center.x += cosf(_Angle) * _Speed;
        }
        if ((_Center.y > _Player->GetShadowCenterPoint().y + 5) || (_Center.y < _Player->GetShadowCenterPoint().y - 5))
        {
            _Center.y += -sinf(_Angle) * _Speed;
        }
        break;
    case BOSS_STATE::ATTACK:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightAttack");
            if (_Ani->getNowAniIndex() == 5)
            {
                SOUNDMANAGER->play("ATTACKSOUNT", 0.5f);
                _Attack = { _Center.x, _Center.y - 30, _Center.x + 200, _Center.y + 30 };
            }
            else
            {
                _Attack = { 0,0,0,0 };
            }
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftAttack");
            if (_Ani->getNowAniIndex() == 5)
            {
                SOUNDMANAGER->play("ATTACKSOUNT", 0.5f);
                _Attack = { _Center.x - 200, _Center.y - 30, _Center.x, _Center.y + 30 };
            }
            else
            {
                _Attack = { 0,0,0,0 };
            }
        }
        break;
    case BOSS_STATE::SLAP:
        if (!_IsLookLeft)
        {

            if (_Pz != PHAZE::THIRD)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightSlap");
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("RightSlapRed");
            }
            if (_Ani->getNowAniIndex() == 8)
            {
                SOUNDMANAGER->play("SLAPSOUNT", 0.5f);
                _Attack = { _Center.x, _Center.y - 30, _Center.x + 200, _Center.y + 30 };
            }
            else
            {
                _Attack = { 0,0,0,0 };
            }
        }
        else
        {
            if (_Pz != PHAZE::THIRD)
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftSlap");
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftSlapRed");
            }

            if (_Ani->getNowAniIndex() == 8)
            {
                SOUNDMANAGER->play("SLAPSOUNT", 0.5f);
                _Attack = { _Center.x - 200, _Center.y - 30, _Center.x, _Center.y + 30 };
            }
            else
            {
                _Attack = { 0,0,0,0 };
            }
        }
        break;
    case BOSS_STATE::GUARD:
        break;
    case BOSS_STATE::PUNCH:

        if (_Ani->getNowAniIndex() < 12 && (_Pz == PHAZE::THIRD))
        {
            if (_IsLookLeft)
            {
                if (_Player->GetShadowCenterX() >= _Center.x - 150)
                {
                    _PLCenter.x = _Player->GetShadowCenterX() - 10;
                }
                else
                {
                    _PLCenter.x = _Player->GetShadowCenterX() + 10;;
                }
                if (_Player->GetShadowCenterY() >= _Center.y)
                {
                    _PLCenter.y = _Player->GetShadowCenterY() - 10;
                }
                else
                {
                    _PLCenter.y = _Player->GetShadowCenterY() + 10;
                }
            }
            else
            {

                if (_Player->GetShadowCenterX() >= _Center.x + 150)
                {
                    _PLCenter.x = _Player->GetShadowCenterX() - 10;
                }
                else
                {
                    _PLCenter.x = _Player->GetShadowCenterX() + 10;;
                }
                if (_Player->GetShadowCenterY() >= _Center.y)
                {
                    _PLCenter.y = _Player->GetShadowCenterY() - 10;
                }
                else
                {
                    _PLCenter.y = _Player->GetShadowCenterY() + 10;
                }
            }
            _Player->SetCenterX1(_PLCenter.x);
            _Player->SetCenterY1(_PLCenter.y);
        }

        if (!_IsLookLeft)
        {
            if (_Pz != PHAZE::THIRD)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightPunch");

                if (_Ani->getNowAniIndex() == 2)
                {
                    SOUNDMANAGER->play("PUNCHSOUND", 0.1f);
                }
                if (_Ani->getNowAniIndex() > 12 && _Ani->getNowAniIndex() < 19)
                {
                    _Center.x += 8;
                    _Center.y += -sinf(_Angle) * 8;
                }
                if (_Ani->getNowAniIndex() == 17)
                {
                    _Attack = { _Center.x - 200, _Center.y - 30, _Center.x + 200, _Center.y + 30 };
                }
                else
                {
                    _Attack = { 0,0,0,0 };
                }
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("RightPunchred");

                if (_Ani->getNowAniIndex() == 2)
                {
                    SOUNDMANAGER->play("PUNCHSOUND", 0.1f);
                }

                if (_Ani->getNowAniIndex() == 17)
                {
                    _Attack = { _Center.x - 200, _Center.y - 30, _Center.x + 200, _Center.y + 30 };
                }
                else
                {
                    _Attack = { 0,0,0,0 };
                }
            }

        }
        else
        {
            if (_Pz != PHAZE::THIRD)
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftPunch");

                if (_Ani->getNowAniIndex() == 2)
                {
                    SOUNDMANAGER->play("PUNCHSOUND", 0.1f);
                }
                if (_Ani->getNowAniIndex() > 12 && _Ani->getNowAniIndex() < 19)
                {
                    _Center.x -= 8;
                    _Center.y += -sinf(_Angle) * 8;
                }
                if (_Ani->getNowAniIndex() == 17)
                {
                    _Attack = { _Center.x - 200, _Center.y - 30, _Center.x + 200, _Center.y + 30 };
                }
                else
                {
                    _Attack = { 0,0,0,0 };
                }
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftPunchred");

                if (_Ani->getNowAniIndex() == 2)
                {
                    SOUNDMANAGER->play("PUNCHSOUND", 0.1f);
                }

                if (_Ani->getNowAniIndex() == 17)
                {
                    _Attack = { _Center.x - 200, _Center.y - 30, _Center.x + 200, _Center.y + 30 };
                }
                else
                {
                    _Attack = { 0,0,0,0 };
                }
            }
        }
        break;
    case BOSS_STATE::ROAR:

        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightRoar");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftRoar");
        }

        break;
    case BOSS_STATE::IDLE_RUSH:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("Right_Idle_Rush");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("Left_Idle_Rush");
        }
        break;
    case BOSS_STATE::RIGHTRUSH:
        if (_IsLookLeft)
        {
            _IsLookLeft = false;
        }
        _Attack = { _Center.x - 50, _Center.y - 30, _Center.x + 150, _Center.y + 30 };

        _Ani = KEYANIMANAGER->findAnimation("RightRush");
        _Center.x += _Speed * 2;

        if ((_Center.y > _Player->GetShadowCenterPoint().y + 5) || (_Center.y < _Player->GetShadowCenterPoint().y - 5))
        {
            _Center.y += -sinf(_Angle) * 4;
        }

        if (_Center.x - 500 > _Player->GetShadowCenterPoint().x)
        {
            SOUNDMANAGER->stop("RUSHSOUND");
            _Bs = BOSS_STATE::RUSHTURN;
        }
        break;
    case BOSS_STATE::LEFTRUSH:
        if (!_IsLookLeft)
        {
            _IsLookLeft = true;
        }

        _Attack = { _Center.x - 150, _Center.y - 30, _Center.x + 50, _Center.y + 30 };

        _Ani = KEYANIMANAGER->findAnimation("LeftRush");
        _Center.x -= _Speed * 2;

        if ((_Center.y > _Player->GetShadowCenterPoint().y + 5) || (_Center.y < _Player->GetShadowCenterPoint().y - 5))
        {
            _Center.y += -sinf(_Angle) * 4;
        }
        if (_Center.x + 700 < _Player->GetShadowCenterPoint().x)
        {
            SOUNDMANAGER->stop("RUSHSOUND");
            _Bs = BOSS_STATE::RUSHTURN;
        }
        break;
    case BOSS_STATE::RUSHTURN:

        _Attack = { 0,0,0,0 };

        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightTurn");
            _Center.x += 1;
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftTurn");
            _Center.x -= 1;
        }
        break;
    case BOSS_STATE::JUMP:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightJump");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftJump");
        }
        break;
    case BOSS_STATE::UP:
        if (_Center.y - 240 - _Jump > -1000)
        {
            _Jump += 40;
        }

        if (_Center.y - 240 - _Jump < -600)
        {
            float X = _Player->GetShadowCenterPoint().x;
            float Y = _Player->GetShadowCenterPoint().y;
            _Center.x = X;
            _Center.y = Y;
            _Bs = BOSS_STATE::DOWN;
        }
        break;
    case BOSS_STATE::DOWN:
        if (_Jump > 0 && (_Time > 150))
        {
            _Jump -= 60;
            if (!_IsLookLeft)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightDown");
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftDown");
            }
        }
        if (_Jump <= 0)
        {
            SOUNDMANAGER->play("LANDHITSOUND", 0.1f);
            _ExCenter.x = _Center.x - (IMAGEMANAGER->findImage("IDLE")->getFrameWidth() * 0.5) - 280;
            _ExCenter.y = _Center.y - 120;
            _Alpha = 255;
            _Bs = BOSS_STATE::LANDHIT;
        }
        break;
    case BOSS_STATE::LANDHIT:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightLandHit");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftLandHit");
        }
        break;
    case BOSS_STATE::HIT:
        switch (_HitNum)
        {
        case 1:
            if (!_IsLookLeft)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightHit1");
                _Center.x -= 1;
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftHit1");
                _Center.x += 1;
            }
            break;
        case 2:
            if (!_IsLookLeft)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightHit2");
                _Center.x -= 1;
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftHit2");
                _Center.x += 1;
            }
            break;
        case 3:
            if (!_IsLookLeft)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightHit3");
                _Center.x -= 1;
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftHit3");
                _Center.x += 1;
            }
            break;
        }
        break;
    case BOSS_STATE::GROUNDHIT:
        break;
    case BOSS_STATE::KNOCK:
        if (!_Ani->isPlay())
        {
            _Ani->start();
        }
        if (_Ani->getNowAniIndex() < 5)
        {
            _Jump += 1;
        }
        else if (_Ani->getNowAniIndex() > 4)
        {
            _Jump -= 2;
        }

        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightKnock");
            _Center.x -= 2;
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftKnock");
            _Center.x += 2;
        }
        break;
    case BOSS_STATE::SIT:
        break;
    case BOSS_STATE::WAKE:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightWake");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftWake");
        }
        break;
    case BOSS_STATE::TAUNT:
        if (!_IsLookLeft)
        {
            if (_Pz != PHAZE::THIRD)
            {
                _Ani = KEYANIMANAGER->findAnimation("RightTaunt");
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("RightTauntRed");
            }
        }
        else
        {
            if (_Pz != PHAZE::THIRD)
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftTaunt");
            }
            else
            {
                _Ani = KEYANIMANAGER->findAnimation("LeftTauntRed");
            }
        }
        break;
    case BOSS_STATE::DEAD:
        if (!_IsLookLeft)
        {
            _Ani = KEYANIMANAGER->findAnimation("RightDead");
        }
        else
        {
            _Ani = KEYANIMANAGER->findAnimation("LeftDead");
        }
        break;
    case BOSS_STATE::CRY:
        break;
    }

    _Rc = { _Center.x - 120 , _Center.y - 30, _Center.x + 120, _Center.y + 35 };
}

void Boss::render()
{
    CAMERAMANAGER->alpharender(getMemDC(), _CrackImg, _ExCenter.x, _ExCenter.y, _Alpha);

    CAMERAMANAGER->render(getMemDC(), _ShadowImg, _Center.x - (IMAGEMANAGER->findImage("IDLE")->getFrameWidth() * 0.5) + 10, _Center.y - 30);

    if (KEYMANAGER->isStayKeyDown(VK_CONTROL))
    {
        CAMERAMANAGER->rectangle(getMemDC(), _Attack);
        CAMERAMANAGER->rectangle(getMemDC(), _Rc);
    }

    if (_Pz != PHAZE::THIRD)
    {
        switch (_Bs)
        {
        case BOSS_STATE::IDLE:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280, _Ani, _Center.y);
            break;
        case BOSS_STATE::WALK:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y);
            break;
        case BOSS_STATE::ATTACK:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 10, _Center.y - 290, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 290, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::SLAP:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 50, _Center.y - 260, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 50, _Center.y - 260, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::GUARD:
            break;
        case BOSS_STATE::PUNCH:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 330, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 330, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::ROAR:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 5, _Center.y - 260, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::IDLE_RUSH:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y);
            break;
        case BOSS_STATE::RIGHTRUSH:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 250, _Ani, _Center.y);

            break;
        case BOSS_STATE::LEFTRUSH:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 250, _Ani, _Center.y);

            break;
        case BOSS_STATE::RUSHTURN:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y);
            break;
        case BOSS_STATE::JUMP:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 290, _Ani, _Center.y);
            break;
        case BOSS_STATE::UP:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280 - _Jump, _Ani, _Center.y);
            break;
        case BOSS_STATE::DOWN:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280 - _Jump, _Ani, _Center.y);
            break;
        case BOSS_STATE::LANDHIT:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280, _Ani, _Center.y);
            break;
        case BOSS_STATE::HIT:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y);
            break;
        case BOSS_STATE::GROUNDHIT:
            break;
        case BOSS_STATE::KNOCK:
            ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260 - _Jump, _Ani, _Center.y);
            break;
        case BOSS_STATE::SIT:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 190, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 190, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::WAKE:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 250, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 250, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::TAUNT:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 330, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 330, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::DEAD:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 25, _Center.y - 280, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 25, _Center.y - 280, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::CRY:

            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 25, _Center.y - 280, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 25, _Center.y - 280, _Ani, _Center.y);
            }
            break;
        }
    }
    else
    {
        // 이건 3페이즈 빨갛게 바뀌는 것
        switch (_Bs)
        {
        case BOSS_STATE::IDLE:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::WALK:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::ATTACK:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 10, _Center.y - 290, _Ani, _Center.y, 200);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 290, _Ani, _Center.y, 200);
            }
            break;
        case BOSS_STATE::SLAP:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 50, _Center.y - 260, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 50, _Center.y - 260, _Ani, _Center.y, 200);
            }
            break;
        case BOSS_STATE::GUARD:
            break;
        case BOSS_STATE::PUNCH:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 330, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 330, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::ROAR:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 5, _Center.y - 260, _Ani, _Center.y, 200);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y, 200);
            }
            break;
        case BOSS_STATE::IDLE_RUSH:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::RIGHTRUSH:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 250, _Ani, _Center.y, 200);

            break;
        case BOSS_STATE::LEFTRUSH:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 250, _Ani, _Center.y, 200);

            break;
        case BOSS_STATE::RUSHTURN:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::JUMP:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 290, _Ani, _Center.y, 200);

            break;
        case BOSS_STATE::UP:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280 - _Jump, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::DOWN:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280 - _Jump, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::LANDHIT:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 280, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::HIT:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::GROUNDHIT:
            break;
        case BOSS_STATE::KNOCK:
            ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 260 - _Jump, _Ani, _Center.y, 200);
            break;
        case BOSS_STATE::SIT:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 190, _Ani, _Center.y, 200);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 190, _Ani, _Center.y, 200);
            }
            break;
        case BOSS_STATE::WAKE:

            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 250, _Ani, _Center.y, 200);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::KEYANIALPHARENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 250, _Ani, _Center.y, 200);
            }
            break;
        case BOSS_STATE::TAUNT:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 20, _Center.y - 330, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5), _Center.y - 330, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::DEAD:
            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 25, _Center.y - 280, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 25, _Center.y - 280, _Ani, _Center.y);
            }
            break;
        case BOSS_STATE::CRY:

            if (!_IsLookLeft)
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) + 25, _Center.y - 280, _Ani, _Center.y);
            }
            else
            {
                ZORDER->ZOrderPush(getMemDC(), RenderType::ANIRENDER, _Img, _Center.x - (_Img->getFrameWidth() * 0.5) - 25, _Center.y - 280, _Ani, _Center.y);
            }
            break;
        }
    }
}


void Boss::RightIDLE(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::IDLE);
    b->SetAni(KEYANIMANAGER->findAnimation("RightIdle"));
    b->GetAni()->start();
}

void Boss::LeftIDLE(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::IDLE);
    b->SetAni(KEYANIMANAGER->findAnimation("LeftIdle"));
    b->GetAni()->start();
}

void Boss::RightRUSH(void* obj)
{
    Boss* b = (Boss*)obj;

    if (b->GetExState() == BOSS_STATE::ROAR)
    {
        b->SetState(BOSS_STATE::IDLE_RUSH);
        b->SetAni(KEYANIMANAGER->findAnimation("Right_Idle_Rush"));
        b->GetAni()->start();
    }
    else if (b->GetExState() == BOSS_STATE::IDLE_RUSH ||
        b->GetExState() == BOSS_STATE::RUSHTURN)
    {
        b->SetState(BOSS_STATE::RIGHTRUSH);
        b->SetAni(KEYANIMANAGER->findAnimation("RightRush"));
        b->GetAni()->start();
        SOUNDMANAGER->play("RUSHSOUND", 0.3f);
    }
    else
    {
        b->SetState(BOSS_STATE::IDLE);
        b->SetAni(KEYANIMANAGER->findAnimation("RightIdle"));
        b->GetAni()->start();
    }
}


void Boss::LeftRUSH(void* obj)
{
    Boss* b = (Boss*)obj;
    if (b->GetExState() == BOSS_STATE::ROAR)
    {
        b->SetState(BOSS_STATE::IDLE_RUSH);
        b->SetAni(KEYANIMANAGER->findAnimation("Left_Idle_Rush"));
        b->GetAni()->start();
    }
    else if (b->GetExState() == BOSS_STATE::IDLE_RUSH ||
        b->GetExState() == BOSS_STATE::RUSHTURN)
    {
        b->SetState(BOSS_STATE::LEFTRUSH);
        b->SetAni(KEYANIMANAGER->findAnimation("LeftRush"));
        b->GetAni()->start();
        SOUNDMANAGER->play("RUSHSOUND", 0.3f);
    }
    else
    {
        b->SetState(BOSS_STATE::IDLE);
        b->SetAni(KEYANIMANAGER->findAnimation("LeftIdle"));
        b->GetAni()->start();
    }
}

void Boss::RightTAUNT(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::TAUNT);
    b->SetAni(KEYANIMANAGER->findAnimation("RightTaunt"));
    b->GetAni()->start();
    SOUNDMANAGER->play("TAUNTSOUND", 0.5f);
}

void Boss::LeftTAUNT(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::TAUNT);
    b->SetAni(KEYANIMANAGER->findAnimation("LeftTaunt"));
    b->GetAni()->start();
    SOUNDMANAGER->play("TAUNTSOUND", 0.5f);
}

void Boss::RightJUMP(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::UP);
    b->SetAni(KEYANIMANAGER->findAnimation("RightUp"));
    b->GetAni()->start();
    SOUNDMANAGER->play("JUMPSOUND", 0.5f);
}

void Boss::LeftTJUMP(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::UP);
    b->SetAni(KEYANIMANAGER->findAnimation("LeftUp"));
    b->GetAni()->start();
    SOUNDMANAGER->play("JUMPSOUND", 0.5f);
}

void Boss::RightCRY(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::CRY);
    b->SetAni(KEYANIMANAGER->findAnimation("RightCry"));
    b->GetAni()->start();
}

void Boss::LeftCRY(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::CRY);
    b->SetAni(KEYANIMANAGER->findAnimation("LeftCry"));
    b->GetAni()->start();
}

void Boss::RightSIT(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::SIT);
    b->SetAni(KEYANIMANAGER->findAnimation("RightSit"));
    b->GetAni()->start();
}

void Boss::LeftSIT(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::SIT);
    b->SetAni(KEYANIMANAGER->findAnimation("LeftSit"));
    b->GetAni()->start();
}

void Boss::RightWAKE(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::WAKE);
    b->SetAni(KEYANIMANAGER->findAnimation("RightWake"));
    b->GetAni()->start();
}

void Boss::LeftWAKE(void* obj)
{
    Boss* b = (Boss*)obj;

    b->SetState(BOSS_STATE::WAKE);
    b->SetAni(KEYANIMANAGER->findAnimation("LeftWake"));
    b->GetAni()->start();
}