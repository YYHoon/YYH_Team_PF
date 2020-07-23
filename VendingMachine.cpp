#include "stdafx.h"
#include "VendingMachine.h"

HRESULT VendingMachine::init(float spawnCenterX, float spawnCenterY)
{
	_Type = OBSTACLE_TYPE::VendingMachine;
	_Name = "VendingMachine";
	_Img = IMAGEMANAGER->findImage("VendingMachine");
	_Center.x = spawnCenterX;
	_Center.y = spawnCenterY;
	_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
	_IsDestructible = true;

	return S_OK;
}

void VendingMachine::DestroyedMesh(bool isHit)
{
	if (isHit)
	{
		_Img = IMAGEMANAGER->findImage("VendingMachineDestroyed");
	}
}
