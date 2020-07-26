#include "stdafx.h"
#include "Enemy.h"

void Enemy::update()
{
	
}

void Enemy::release()
{
}

void Enemy::render()
{

	CAMERAMANAGER->render(getMemDC(), _ShadowImg, _ShadowCollision.left, _ShadowCollision.top);
}

void Enemy::Move()
{
	

}


void Enemy::BeShot()
{
}
