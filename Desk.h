#pragma once
#include "ParentsObstacle.h"
class Desk : public ParentsObstacle
{
public:
	HRESULT init(float spawnCenterX, float spawnCenterY)override;
};