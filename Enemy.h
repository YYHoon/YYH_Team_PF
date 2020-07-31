#pragma once
#include "gameNode.h"

class Player;

enum class EnemyType
{
	Scoolgirl,
	ScoolMan,
	CheerLeader,
	End
};

enum class EnemyState
{
	Init,
	Idle,
	Walk,
	Run,
	BeShot,
	KnockDown,
	Attack,
	Die,
	End
};

class Enemy : public gameNode
{
protected:
	Player* _Player;
	string _Name;
	EnemyType _Type;
	EnemyState _State;
	MYRECT _Collision;
	MYRECT _ShadowCollision;
	MYRECT _RangeCollision;
	POINT_FLOAT _Center;
	POINT_FLOAT _ShadowCenter;
	image* _Img;
	image* _ShadowImg;
	animation* _Anim;
	float _Angle;
	float _Velocity;
	bool _IsHit;
	bool _IsKnockDown;
	bool _IsDie;
	bool _IsRight;
	int _ActionCount;
	int _KnockDownCount;
	int _DeathIsComing;

public:
	virtual HRESULT init(float centerX, float centerY, bool isRight) = 0;
	virtual void update();
	virtual void release();
	virtual void render();

	virtual void ImgInit() = 0;
	virtual void AnimReSet() = 0;
	virtual void Move();
	virtual void BeShot();
	virtual void UpdateCollison() {};

	virtual void SetAnim(animation* anim) { _Anim = anim; }
	virtual void SetState(EnemyState state) { _State = state; }
	virtual void SetDeath(int isDeath) { _DeathIsComing += isDeath; }

	virtual float GetCenterX() { return _Center.x; }
	virtual animation* GetAnim() { return _Anim; }
	virtual string GetName() {return _Name; }
	virtual EnemyType GetEnemyType() { return _Type; }
	virtual EnemyState GetEnemyState() { return _State; }
	virtual MYRECT GetCollision() { return _Collision; }
	virtual MYRECT GetShadowRect() { return _ShadowCollision; }
	virtual image* GetImage() { return _Img; }
	virtual MYRECT GetRangeCollision() { return _RangeCollision; }
	virtual int GetDeatCount() { return _DeathIsComing; }

	virtual void SetPlayerMemoryAddressLink(Player* address) { _Player = address; }

};

