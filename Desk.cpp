#include "stdafx.h"
#include "Desk.h"

HRESULT Desk::init(float spawnCenterX, float spawnCenterY)
{
	_Type = OBSTACLE_TYPE::Desk;
	_Name = "Desk";
	_Img = IMAGEMANAGER->findImage("Desk");
	_Center.x = spawnCenterX;
	_Center.y = spawnCenterY;
	_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
	_IsDestructible = false;
	return S_OK;
}
