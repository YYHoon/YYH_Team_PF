#pragma once
#include "gameNode.h"

class pixelCollsion : public gameNode
{
private:
	image* _hill;	//언덕 이미지
	image* _ball;	//볼 이미지
	RECT _rc;		//볼이 사용할 렉트
	float _x, _y;	//볼의 중점좌표
	RECT _rc2;
	RECT _L; // 탐색렉트
	RECT _R;
	RECT _T;
	RECT _B;
	float speed;
	float jumpPower;
	float gravity;
	int _probeT;	//Y축 탐사
	int _probeB;	//X축 탐사
	int _probeL;	//L축 탐사
	int _probeR;	//R축 탐사
	bool collision; // 픽셀끼리 충돌했을때
public:
	pixelCollsion();
	~pixelCollsion();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	bool PixelCollisionTest(string Imgname, float getPixelX, float getPixelY, int SetColorR, int SetColorG, int SetColorB);
	void jump();
	void probeRectMake(float PlayerX, float playerY, float RectTop, float RectBottom, float RectLeft, float RectRight);
};

