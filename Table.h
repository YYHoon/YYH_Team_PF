#pragma once

#include "ParentsObstacle.h"

class Table : public ParentsObstacle
{
public:
	HRESULT init(float spawnCenterX, float spawnCenterY)override;
};

