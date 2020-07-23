#include "stdafx.h"
#include "pixelCollsion.h"


pixelCollsion::pixelCollsion()
{
}


pixelCollsion::~pixelCollsion()
{
}

HRESULT pixelCollsion::init()
{
	_hill = IMAGEMANAGER->findImage("Stage1_Start_Pixel");
	//_ball = IMAGEMANAGER->addImage("ball", "Image/UI_title_arrow.bmp", 53, 61, true, RGB(255, 0, 255));
	_ball = IMAGEMANAGER->addImage("ball", "Image/UI_title_arrow2.bmp",30, 30, true, RGB(255, 0, 255));
	_x = WINSIZEX / 2 - 150;
	_y = WINSIZEY / 2 + 80;
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
	_T = RectMakeCenter(_x, _rc.top - 10, 5, 5);
	_B = RectMakeCenter(_x, _rc.bottom + 10, 5, 5);
	_L = RectMakeCenter(_rc.left - 10, _y, 5, 5);
	_R = RectMakeCenter(_rc.right + 10, _y, 5, 5);
	jumpPower = 0;
	gravity = 0;

	collision = false;
	speed = 2;
	return S_OK;
}

void pixelCollsion::release()
{
}

void pixelCollsion::update()
{ 

	_y -= jumpPower;
	jumpPower -= gravity;


	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= speed;
		probeRectMake(_x,_y,_rc.top,_rc.bottom,_rc.left,_rc.right);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += speed;
		probeRectMake(_x, _y, _rc.top, _rc.bottom, _rc.left, _rc.right);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= speed;
		probeRectMake(_x, _y, _rc.top, _rc.bottom, _rc.left, _rc.right);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += speed;
		probeRectMake(_x, _y, _rc.top, _rc.bottom, _rc.left, _rc.right);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		
		jump();
	}





	for (int i = 0; i < 1; ++i)
	{

		if (PixelCollisionTest("Stage1_Start_Pixel", _T.left, _T.top, 255, 0, 0))
		{
			_y += speed; 
			cout << " 11" << endl;
		}
		if (PixelCollisionTest("Stage1_Start_Pixel", _L.left, _L.top, 255, 0, 0))
		{
			_x += speed;
			cout << " 22" << endl;
		}
		if (PixelCollisionTest("Stage1_Start_Pixel", _B.left, _B.bottom, 255, 0, 0))
		{
			_y -= speed;
			cout << " 33" << endl;
		}
		if (PixelCollisionTest("Stage1_Start_Pixel", _R.right, _R.bottom, 255, 0, 0))
		{
			_x -= speed;
			cout << " 44" << endl;
		}
	}



	//for (int i = 0; i < 1; ++i)
	//{
	//	if (PixelCollisionTest("Stage1_Start_Pixel", _B.left, _B.bottom, 255, 255, 0))
	//	{
	//		_y -= speed;
	//		cout << " 33" << endl;
	//	}
	//}
	probeRectMake(_x, _y, _rc.top, _rc.bottom, _rc.left, _rc.right);
	//탐사축도 업데이트 함수에 넣어서 계속해서 갱신해준다
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
}
void pixelCollsion::render()
{
	IMAGEMANAGER->findImage("Stage1_Start_Pixel")->render(getMemDC(), 0, 0);
	Rectangle(getMemDC(), _rc);
//	_ball->render(getMemDC(), _rc.left, _rc.top);
	Rectangle(getMemDC(), _T);
	Rectangle(getMemDC(), _B);
	Rectangle(getMemDC(), _L);
	Rectangle(getMemDC(), _R);
}

bool pixelCollsion::PixelCollisionTest(string Imgname,float getPixelX,float getPixelY,int SetColorR,int SetColorG,int SetColorB)
{
	COLORREF color = GetPixel(IMAGEMANAGER->findImage(Imgname)->getMemDC(), getPixelX, getPixelY);
	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);
	if(r == SetColorR && g == SetColorG && b == SetColorB)
	{
		return true;
	}
	return false;
}

void pixelCollsion::jump()
{

}

void pixelCollsion::probeRectMake(float PlayerX,float playerY,float RectTop,float RectBottom,float RectLeft,float RectRight)
{


	_T = RectMakeCenter(PlayerX, RectTop - 10, 5, 5);
	_B = RectMakeCenter(PlayerX, RectBottom + 10, 5, 5);
	_L = RectMakeCenter(RectLeft - 10, playerY, 5, 5);
	_R = RectMakeCenter(RectRight + 10, playerY, 5, 5);



}
