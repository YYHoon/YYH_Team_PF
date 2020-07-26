#pragma once
#include "gameNode.h"

class Player;

enum class PHAZE
{
	FIRST,
	SECOND,
	THIRD
};
enum class BOSS_STATE
{
	IDLE,
	WALK,
	ATTACK,		//내려찍기평타
	SLAP,		//손바닥휘두르기
	GUARD,
	PUNCH,		//강펀치
	ROAR,		//로어
	IDLE_RUSH,
	RIGHTRUSH,	//러쉬공격
	LEFTRUSH,	//러쉬공격 (그림자렉트랑반응)
	RUSHTURN,
	JUMP,
	UP,
	DOWN,
	LANDHIT,	//쿵쾅쿵쾅
	HIT,
	GROUNDHIT,
	KNOCK,
	SIT,
	WAKE,		//기상 쿵쾅쿵쾅
	TAUNT,
	DEAD,
	CRY
};

class Boss : public gameNode
{
private:
	Player* _Player;

	image* _Img;
	image* _ShadowImg;
	animation* _Ani;
	MYRECT _Hit;//히트박스
	MYRECT _Shadow;
	MYRECT _Rc; // 공격렉트
	MYRECT _Attack;
	MYRECT _AttackLeft;
	POINT_FLOAT _Center;
	POINT_FLOAT _PLCenter;
	BOSS_STATE _Bs;
	BOSS_STATE _ExBs;//이전 상태
	PHAZE _Pz;
	float _Angle;
	float _ExAngle;//러쉬용 이전 앵글
	float _Speed;
	float _Jump;
	int _Hp;
	int _Time;//기술 쿨타임
	int _JumpTime;//기술 쿨타임
	int _AttackNum;
	int _HitNum;
	bool _IsLookLeft;
	
	const char* _State[22] = { "IDLE","WALK","ATTACK","SLAP","GUARD","PUNCH",
							   "ROAR","IDLE_RUSH","RIGHTRUSH","LEFTRUSH","RUSHTURN","JUMP","UP","DOWN","LANDHIT",
							   "HIT","GROUNDHIT","KNOCK","SIT","WAKE","TAUNT","DEAD" };

	const char* _Phaze[3] = { "FIRST","SECONT","THIRD"};

public:
	Boss() {};
	~Boss() {};

	HRESULT init();
	void release();
	void update();
	void render();

	static void RightIDLE(void* obj);
	static void LeftIDLE(void* obj);
	static void RightRUSH(void* obj);
	static void LeftRUSH(void* obj);
	static void RightTAUNT(void* obj);
	static void LeftTAUNT(void* obj);
	static void RightJUMP(void* obj);
	static void LeftTJUMP(void* obj);
	static void RightCRY(void* obj);
	static void LeftCRY(void* obj);
	static void RightSIT(void* obj);
	static void LeftSIT(void* obj);
	static void RightWAKE(void* obj);
	static void LeftWAKE(void* obj);

	animation* GetAni() { return _Ani; }
	BOSS_STATE GetState() { return _Bs; }
	BOSS_STATE GetExState() { return _ExBs; }
	bool GetBossLeft() {	return _IsLookLeft;	}
	MYRECT GetAttRect() { return _Attack; }
	MYRECT GetAttRectLeft() { return _AttackLeft; }
	MYRECT GetBossShadowRect() { return _Shadow; }
	float GetBossCenterX() { return _Center.x; };
	float GetBossCenterY() { return _Center.y; };
	void SetAni(animation* ani) { _Ani = ani; }
	void SetState(BOSS_STATE bs) { _Bs = bs; }
	void SetPoint(POINT_FLOAT Center) { _Center = Center; }
	void SetPlayerAddressLink(Player* player) { _Player = player; }

	
};

