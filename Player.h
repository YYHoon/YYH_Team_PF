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
	State* _State;//������ ����
	Boss* _b;
	POINTFLOAT _DummyCen;//������ȯ�� ��ǥ�����(����)
	POINTFLOAT _DummyCenHit;//������ȯ�� ��ǥ(�ǰ�)
	image* _Shadow;//�׸����̹���
	POINTFLOAT _Center;//�׸��ڼ���
	MYRECT _ShadowRc;//�׸��ڷ�Ʈ
	MYRECT _PlayerHitRc;//�÷��̾��ǰ���
	MOVELR _MoveLR;//�̵��Լ����̳�
	MOVEUD _MoveUD;//�̵��Լ����̳�
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
	/// <�뽬>
	bool _LRun=false;
	int _LTime = 0;
	int _LClickTime = 0;
	bool _RRun=false;
	int _RTime = 0;
	int _RClickTime = 0;
	/// </�뽬>
	
	//����
	float _JumpStack = 0;
	float _JumpMax = 200;
	bool _Jump = false;
	bool _Fall = false;
	//����
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
	//�÷��̾� �̹��� �ִϸ��̼� ���� �Լ�


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


	
	inline bool GetPlayerDirection() { return _Left; }	//�÷��̾��¿����
	inline float GetShadowCenterX() { return _Center.x; }//�׸��ڼ���X
	inline float GetShadowCenterY() { return _Center.y; }//�׸��ڼ���Y
	inline POINTFLOAT GetShadowCenterPoint() { return _Center; }//�׸��ڼ�������Ʈ
	inline MYRECT GetShadowRect() { return _ShadowRc; }		//�÷��̾�׸��ڷ�Ʈ(����)
	inline MYRECT GetPlayerRect() { return _PlayerHitRc; } //�÷��̾��ǰݷ�Ʈ
	inline int GetAttackCount() { return _AttackCount; }//�޺�����ī��Ʈ��
	inline MYRECT GetAttackRC1() { return _AttackRc1; }//�޺���Ÿ1����Ʈ
	inline MYRECT GetAttackRC2() { return _AttackRc2; }//�޺���Ÿ2����Ʈ
	inline MYRECT GetAttackRC3() { return _AttackRc3; }//�޺���Ÿ3����Ʈ
	inline MYRECT GetAttackRCH() { return _AttackRcH; }//�㸮����ű��Ʈ
	inline MYRECT GetAttackRCDAP() { return _DAP; }//��Ʈ
	inline MYRECT GetAttackRCDash() { return _DashAtt; }//��Ʈ
	inline int GetPlayerLevel() { return _Level; }//�÷��̾��
	inline float GetPlayerMoney() { return _Money; }//�÷��̾������
	inline float GetPlayerHp() { return _Hp; }//�÷��̾�ü��
	inline float GetPlayerExp() { return _Exp; }//�÷��̾����ġ
	inline bool GetPlayerGuardState() { return _Guard; } //�����ߴ���



	inline void SetPlayerLevel(int level) { _Level = level; }//�÷��̾��
	inline void SetPlayerMoney(float money) { _Money = money; }//�÷��̾������
	inline void SetPlayerHp(float hp) { _Hp = hp; }//�÷��̾�ü��
	inline void SetPlayerExp(float exp) { _Exp = exp; }//�÷��̾����ġ
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
