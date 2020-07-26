#pragma once
#include"Player.h"
#include"gameNode.h"

class State : public gameNode
{
protected:
	State* _State;
	Player* _Player;

	image* _PlayerImg;
	animation* _PlayerAni;
	POINTFLOAT _Center;
	MYRECT _PlayerRc;
	MYRECT _AttackRc;
	
	bool _Left;

public:
	State() {};
	virtual ~State() {};

	virtual HRESULT Init();
	virtual void Update();
	virtual void Render();
	virtual void DebugRender();
	virtual void Release();


	virtual void Walk(Player* player) = 0;
	virtual void Attack1(Player* player) = 0;
	virtual void Attack2(Player* player) = 0;
	virtual void Attack3(Player* player) = 0;
	virtual void StandUp(Player* player) = 0;
	virtual void Skill1(Player* player) = 0;
	virtual void Skill2(Player* player) = 0;
	virtual void Guard(Player* Player) = 0;
	virtual void GameOver(Player* player) = 0;
	virtual void DiveAttack(Player* player) = 0;
	virtual void Default(Player* player) = 0;




	inline State* GetState() { return _State; }
	inline bool GetAniIsPlay() { return _PlayerAni->isPlay(); }
	inline bool GetLeft() { return _Left; }
	inline MYRECT GetAttRect() { return _AttackRc; }
	inline MYRECT GetPlayerRect() { return _PlayerRc; }
	inline int GetAniIndex() { return _PlayerAni->getNowAniIndex(); }
	inline POINTFLOAT GetCenterXY() { return _Center; }


	inline void SetState(State* state) { _State = state; }
	inline void SetCenterXY(POINTFLOAT XY)
	{
		_Center.x = XY.x;
		_Center.y = XY.y;
	}
	inline void SetCenterY(float y) { _Center.y = y; }
	inline void SetCenterX(float x) { _Center.x = x; }
	
	inline void SetLeft(bool left) { _Left = left; }
	inline void SetAttRect() { _AttackRc.set(0,0,0,0) ; }

};

class BattleStart : public State
{
private:
	static BattleStart* _Instance;
public:
	BattleStart() {};
	virtual ~BattleStart() {};

	static BattleStart* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
/// <summary>
/// //////////////////////////////////////배틀스타트
/// </summary>
class PlayLeftIdle : public State
{
private:

	static PlayLeftIdle* _Instance;

public:
	PlayLeftIdle() {};
	virtual ~PlayLeftIdle() {};

	static PlayLeftIdle* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);

};
class PlayRightIdle : public State
{
private:

	static PlayRightIdle* _Instance;

public:
	PlayRightIdle() {};
	virtual ~PlayRightIdle() {};

	static PlayRightIdle* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);

};
///////////////////////////////////////////////////////아이들

class PlayLeftRun : public State
{
private:
	static PlayLeftRun* _Instance;
public:
	PlayLeftRun() {};
	virtual ~PlayLeftRun() {};

	static PlayLeftRun* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};

class PlayRightRun : public State
{
private:
	static PlayRightRun* _Instance;
public:
	PlayRightRun() {};
	virtual ~PlayRightRun() {};

	static PlayRightRun* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
/// <summary>
/// /////////////////////////////////////////달리기
/// </summary>
class PlayLeftJump : public State
{
private:
	static PlayLeftJump* _Instance;
public:
	PlayLeftJump() {};
	virtual ~PlayLeftJump() {};

	static PlayLeftJump* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};

class PlayRightJump : public State
{
private:
	static PlayRightJump* _Instance;
public:
	PlayRightJump() {};
	virtual ~PlayRightJump() {};

	static PlayRightJump* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
///////////////////////////////////////점프

class PlayLeftFall : public State
{
private:
	static PlayLeftFall* _Instance;
public:
	PlayLeftFall() {};
	virtual ~PlayLeftFall() {};

	static PlayLeftFall* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};

class PlayRightFall : public State
{
private:
	static PlayRightFall* _Instance;
public:
	PlayRightFall() {};
	virtual ~PlayRightFall() {};

	static PlayRightFall* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
/// <summary>
/// ///////////////////////////하강
/// </summary>
class PlayLeftHit : public State
{
private:
	static PlayLeftHit* _Instance;
public:
	PlayLeftHit() {};
	virtual ~PlayLeftHit() {};

	static PlayLeftHit* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
class PlayRightHit : public State
{
private:
	static PlayRightHit* _Instance;
public:
	PlayRightHit() {};
	virtual ~PlayRightHit() {};

	static PlayRightHit* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
////////////////////////////////피격
class PlayLeftDown : public State
{
private:
	static PlayLeftDown* _Instance;
public:
	PlayLeftDown() {};
	virtual ~PlayLeftDown() {};

	static PlayLeftDown* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
class PlayRightDown : public State
{
private:
	static PlayRightDown* _Instance;
public:
	PlayRightDown() {};
	virtual ~PlayRightDown() {};

	static PlayRightDown* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
////////////////////////////////////////다운

class PlayLeftStun : public State
{
private:
	static PlayLeftStun* _Instance;
public:
	PlayLeftStun() {};
	virtual ~PlayLeftStun() {};

	static PlayLeftStun* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};
class PlayRightStun : public State
{
private:
	static PlayRightStun* _Instance;
public:
	PlayRightStun() {};
	virtual ~PlayRightStun() {};

	static PlayRightStun* GetInstance();

	virtual void Walk(Player* player);
	virtual void Attack1(Player* player);
	virtual void Attack2(Player* player);
	virtual void Attack3(Player* player);
	virtual void StandUp(Player* player);
	virtual void Skill1(Player* player);
	virtual void Skill2(Player* player);
	virtual void Guard(Player* Player);
	virtual void GameOver(Player* player);
	virtual void DiveAttack(Player* player);
	virtual void Default(Player* player);
};