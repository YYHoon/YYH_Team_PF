#include "stdafx.h"
#include "BossProgressBar.h"


BossProgressBar::BossProgressBar()
{
}


BossProgressBar::~BossProgressBar()
{
}

HRESULT BossProgressBar::init(float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("MisuzuHealthTop", "Image/UI/RCG_Misuzu_meter_fill.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("MisuzuHealthBottom", "Image/UI/RCG_bossmeterBG_frame.bmp", width, height, true, RGB(255, 0, 255));

	//뒤에 깔리는 게이지의 가로크기를 기준으로 삼는다
	_width = _progressBarBottom->getWidth();

	return S_OK;
}

void BossProgressBar::release()
{
}

void BossProgressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y,
		_progressBarTop->getWidth(),
		_progressBarBottom->getHeight());
}

void BossProgressBar::render()
{
	IMAGEMANAGER->render("MisuzuHealthBottom", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("MisuzuHealthTop", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_width, _progressBarBottom->getHeight());

}

void BossProgressBar::setGauge(float currentGauge, float maxGauge)
{
	//백분율 구하는 공식이에여!
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}
