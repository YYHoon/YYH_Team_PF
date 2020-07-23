#pragma once
#include "gameNode.h"

enum class OBSTACLE_TYPE
{
	Desk,
	Pillar,
	VendingMachine,
	Table,
	End
};

class ParentsObstacle : public gameNode
{
protected:
	OBSTACLE_TYPE _Type;
	string _Name;
	image* _Img;
	MYRECT _Collison;
	MYRECT _PhysicCollison;
	POINT_FLOAT _Center;
	bool _IsDestructible;
	bool _IsColPlayer;
	bool _IsColBoss;

public:
	virtual HRESULT init(float spawnCenterX, float spawnCenterY) = 0;
	virtual void update() {};
	virtual HRESULT init(float spawnCenterX, float spawnCenterY, bool isRight);
	
	virtual void DestroyedMesh(bool isHit) {};

	virtual void SetCenterXY(float x, float y) { _Center.x = x; _Center.y = y; }
	virtual void SetName(string name) { _Name = name; }
	virtual void SetType(OBSTACLE_TYPE type) { _Type = type; }
	virtual void SetCollision(MYRECT collision) { _Collison = collision; }

	virtual MYRECT GetCollision() { return _Collison; }
	virtual string GetName() { return _Name; }
	virtual OBSTACLE_TYPE GetType() { return _Type; }
	virtual POINT_FLOAT GetCenter() { return _Center; }
	virtual image* GetImg() { return _Img; }
	virtual MYRECT GetPhysicCollision() { return _PhysicCollison; }
};

