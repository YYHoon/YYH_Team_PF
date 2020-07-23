#pragma once
#include "gameNode.h"

enum class ITEM_TYPE
{
	Money,
	Apple,
	End
};

class Item : public gameNode
{
protected:
	string _Name;
	ITEM_TYPE _Type;
	image* _Img;
	MYRECT _Collision;
	POINT_FLOAT _Center;

public:
	virtual HRESULT init() = 0;
	void update();
	void release();
	void render();

	virtual string GetName() { return _Name; }
	virtual ITEM_TYPE GetType() { return _Type; }
	virtual image* GetImage() { return _Img; }
	virtual MYRECT GetCollision() { return _Collision; }
	virtual POINT_FLOAT GetCenter() { return _Center; }

	virtual void SetName(string name) { _Name = name; }
	virtual void SetType(ITEM_TYPE type) { _Type = type; }
	virtual void SetImg(image* img) { _Img = img; }
	virtual void SetCollisionCenter(POINT_FLOAT center, float width, float height) { _Collision.centerSet(center.x, center.y, width, height); }
	virtual void SetCenter(POINT_FLOAT center) { _Center = center; }

public:
	virtual void SpawnItem();
	virtual void ItemCollisionCheck() {}
};

