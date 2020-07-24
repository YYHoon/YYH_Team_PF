#pragma once
#include "gameNode.h"


enum class MOVELR
{
	LEFT_WALK,
	RIGHT_WALK,
	LEFT_RUN,
	RIGHT_RUN,
	NON
};
enum class MOVEUD
{
	UP_WALK,
	DOWN_WALK,
	UP_RUN,
	DOWN_RUN,
	NON
};
class EnemyManager;
class State;
class Boss;
class Player : public gameNode
{
private:
	
	EnemyManager* _EM;
	State* _State;//순가함 상태
	Boss* _b;
	POINTFLOAT _DummyCen;//상태전환시 좌표저장용(점프)
	POINTFLOAT _DummyCenHit;//상태전환용 좌표(피격)
	image* _Shadow;//그림자이미지
	POINTFLOAT _Center;//그림자센터
	MYRECT _ShadowRc;//그림자렉트
	MYRECT _PlayerHitRc;//플레이어피격존
	MOVELR _MoveLR;//이동함수용이넘
	MOVEUD _MoveUD;//이동함수용이넘
	float _Speed;

	MYRECT _AttackRc1;
	MYRECT _AttackRc2;
	MYRECT _AttackRc3;
	MYRECT _AttackRcH;
	MYRECT _DAP;
	MYRECT _DashAtt;

	float _Money;
	float _DownDmg = 0;
	float _Hp;
	float _Exp;
	int _Level;

	int _AttackCount = 0;
	/// <대쉬>
	bool _LRun=false;
	int _LTime = 0;
	int _LClickTime = 0;
	bool _RRun=false;
	int _RTime = 0;
	int _RClickTime = 0;
	/// </대쉬>
	
	//점프
	float _JumpStack = 0;
	float _JumpMax = 200;
	bool _Jump = false;
	bool _Fall = false;
	//점프
	bool _Hit = false;
	int _HitStack = 0;
	bool _Down = false;
	bool _StandUp = false;
	bool _DashAttbool = false;

	bool _Guard = false;
	bool _Left=false;

public:

	Player();
	virtual ~Player() {};

	virtual void PlayerImageAniStting();
	//플레이어 이미지 애니메이션 셋팅 함수


	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();
	virtual void Render();
	virtual void DebugRender();
	virtual void PlayerKeyMove();
	virtual void MoveUpdate();
	virtual void AttackUpdate();
	virtual void DashUpdate();
	virtual void DashAttUpdate();
	virtual void JumpUpdate();
	virtual void HitReaction();
	virtual void HitUpdate();
	virtual void DownReaction();
	virtual void DownUpdate();
	virtual void StandUpUpdate();




	virtual void Walk();
	virtual void Attack1();
	virtual void Attack2();
	virtual void Attack3();
	virtual void StandUp();
	virtual void Skill1();
	virtual void Skill2();
	virtual void Guard();
	virtual void GameOver();
	virtual void DiveAttack();
	virtual void Default();


	
	inline bool GetPlayerDirection() { return _Left; }	//플레이어좌우상태
	inline float GetShadowCenterX() { return _Center.x; }//그림자센터X
	inline float GetShadowCenterY() { return _Center.y; }//그림자센터Y
	inline POINTFLOAT GetShadowCenterPoint() { return _Center; }//그림자센터포인트
	inline MYRECT GetShadowRect() { return _ShadowRc; }		//플레이어그림자렉트(기준)
	inline MYRECT GetPlayerRect() { return _PlayerHitRc; } //플레이어피격렉트
	inline int GetAttackCount() { return _AttackCount; }//콤보공격카운트용
	inline MYRECT GetAttackRC1() { return _AttackRc1; }//콤보평타1번렉트
	inline MYRECT GetAttackRC2() { return _AttackRc2; }//콤보평타2번렉트
	inline MYRECT GetAttackRC3() { return _AttackRc3; }//콤보평타3번렉트
	inline MYRECT GetAttackRCH() { return _AttackRcH; }//허리케인킥렉트
	inline MYRECT GetAttackRCDAP() { return _DAP; }//댑렉트
	inline MYRECT GetAttackRCDash() { return _DashAtt; }//댑렉트
	inline int GetPlayerLevel() { return _Level; }//플레이어레벨
	inline float GetPlayerMoney() { return _Money; }//플레이어소지금
	inline float GetPlayerHp() { return _Hp; }//플레이어체력
	inline float GetPlayerExp() { return _Exp; }//플레이어경험치
	inline bool GetPlayerGuardState() { return _Guard; } //가드했는지



	inline void SetPlayerLevel(int level) { _Level = level; }//플레이어레벨
	inline void SetPlayerMoney(float money) { _Money = money; }//플레이어소지금
	inline void SetPlayerHp(float hp) { _Hp = hp; }//플레이어체력
	inline void SetPlayerExp(float exp) { _Exp = exp; }//플레이어경험치
	inline void SetAttackCount(int count) { _AttackCount += count; }
	inline void SetCenterX(float x) { _Center.x += x; }
	inline void SetCenterY(float y) { _Center.y += y; }
	inline void SetAddressBoss(Boss* b) { _b = b; }
	inline void SetAddressEM(EnemyManager* EM) { _EM = EM; }
	inline void SetShadowCenterX(POINTFLOAT XY) {
		_Center.x = XY.x;
		_Center.y = XY.y;
	}
	
	void SetState(State* state);
};
