#include "stdafx.h"
#include "Table.h"

HRESULT Table::init(float spawnCenterX, float spawnCenterY)
{
	int RndNum = RND->getFromIntTo(1, 4);
	
	_Type = OBSTACLE_TYPE::Table;
	_Name = "Table";
	switch (RndNum)
	{
	case 1:
		_Img = IMAGEMANAGER->findImage("Table1");
		break;
	case 2:
		_Img = IMAGEMANAGER->findImage("Table2");
		break;
	case 3:
		_Img = IMAGEMANAGER->findImage("Table3");
		break;
	case 4:
		_Img = IMAGEMANAGER->findImage("Table4");
	}
	_Center.x = spawnCenterX;
	_Center.y = spawnCenterY;
	_Collison.centerSet(_Center.x, _Center.y, _Img->getWidth(), _Img->getHeight());
	_IsDestructible = false;


	return S_OK;
}
