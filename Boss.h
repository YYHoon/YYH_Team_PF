#pragma once
#include "gameNode.h"

//class Boss_State;
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
	ATTACK,
	SLAP,
	GUARD,
	PUNCH,
	ROAR,
	IDLE_RUSH,
	RIGHTRUSH,
	LEFTRUSH,
	RUSHTURN,
	JUMP,
	UP,
	DOWN,
	LANDHIT,
	HIT,
	GROUNDHIT,
	KNOCK,
	SIT,
	WAKE,
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
	MYRECT _Hit;//��Ʈ�ڽ�
	MYRECT _Shadow;
	MYRECT _Rc; // ���ݷ�Ʈ
	MYRECT _Attack;
	POINT_FLOAT _Center;
	BOSS_STATE _Bs;
	BOSS_STATE _ExBs;//���� ����
	PHAZE _Pz;
	float _Angle;
	float _ExAngle;//������ ���� �ޱ�
	float _Speed;
	float _Jump;
	int _Hp;
	int _Time;//��� ��Ÿ��
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

	animation* GetAni() { return _Ani; }
	BOSS_STATE GetState() { return _Bs; }
	BOSS_STATE GetExState() { return _ExBs; }

	void SetAni(animation* ani) { _Ani = ani; }
	void SetState(BOSS_STATE bs) { _Bs = bs; }
	void SetPlayerAddressLink(Player* player) { _Player = player; }
};
