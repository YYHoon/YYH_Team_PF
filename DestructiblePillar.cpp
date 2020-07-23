#include "stdafx.h"
#include "DestructiblePillar.h"

HRESULT DestructiblePillar::init(float spawnCenterX, float spawnCenterY)
{
	_Type = OBSTACLE_TYPE::Pillar;
	_Name = "DestructiblPillar";
	_Img = IMAGEMANAGER->findImage("Pillar");
	_Center.x = spawnCenterX;
	_Center.y = spawnCenterY;
	_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
	_PhysicCollison.centerSet(_Center.x, _Center.y + 360, _Img->getWidth(), _Img->getHeight() / 6);
	_IsDestructible = true;
	return S_OK;
}

HRESULT DestructiblePillar::init(float spawnCenterX, float spawnCenterY, bool isRight)
{
	if (isRight)
	{
		_Type = OBSTACLE_TYPE::Pillar;
		_Name = "RightDestructiblPillar";
		_Img = IMAGEMANAGER->findImage("RightDestructiblePillar");
		_Center.x = spawnCenterX;
		_Center.y = spawnCenterY;
		_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
		_PhysicCollison.centerSet(_Center.x, _Center.y + 360, _Img->getWidth(), _Img->getHeight() / 6);
		_IsDestructible = true;
		return S_OK;
	}
	else
	{
		_Type = OBSTACLE_TYPE::Pillar;
		_Name = "LeftDestructiblePillar";
		_Img = IMAGEMANAGER->findImage("LeftDestructiblePillar");
		_Center.x = spawnCenterX;
		_Center.y = spawnCenterY;
		_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
		_PhysicCollison.centerSet(_Center.x, _Center.y + 360, _Img->getWidth(), _Img->getHeight() / 6);
		_IsDestructible = true;
		return S_OK;
	}
}
