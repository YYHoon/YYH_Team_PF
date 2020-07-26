#pragma once
#include "Enemy.h"
class SchoolGirl : public Enemy
{
public:
	HRESULT init(float centerX, float centerY, bool isRight)override;
	void ImgInit()override;

	void update()override;

	static void RIdle(void* obj);
	static void LIdle(void* obj);

	void Move()override;
	void BeShot()override;
	void AnimReSet()override;
	void UpdateCollison()override;
};

