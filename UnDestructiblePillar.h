#pragma once
#include "ParentsObstacle.h"

class UnDestructiblePillar : public ParentsObstacle
{
public:
	HRESULT init(float spawnCenterX, float spawnCenterY)override;
};

