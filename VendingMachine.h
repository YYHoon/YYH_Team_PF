#pragma once
#include "ParentsObstacle.h"
class VendingMachine : public ParentsObstacle
{
	HRESULT init(float spawnCenterX, float spawnCenterY)override;
	void DestroyedMesh(bool isHit)override;
};

