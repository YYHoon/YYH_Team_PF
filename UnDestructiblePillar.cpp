#include "stdafx.h"
#include "UnDestructiblePillar.h"

HRESULT UnDestructiblePillar::init(float spawnCenterX, float spawnCenterY)
{
	_Type = OBSTACLE_TYPE::Pillar;
	_Name = "UnDestructiblPillar";
	_Img = IMAGEMANAGER->findImage("Pillar");
	_Center.x = spawnCenterX;
	_Center.y = spawnCenterY;
	_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
	_IsDestructible = false;
	return S_OK;
}
