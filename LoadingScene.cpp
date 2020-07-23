#include "stdafx.h"
#include "LoadingScene.h"
#include "progressBar.h"


LoadingScene::LoadingScene()
	: _background(nullptr), _loadingBar(nullptr),
	_currentCount(NULL)
{
}


LoadingScene::~LoadingScene()
{
}

HRESULT LoadingScene::init()
{
	_background = IMAGEMANAGER->addFrameImage("Loading", "Image/UI/Loading.bmp", 1600, 3600, 1, 4, false, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 10, WINSIZEX, 10);
	_loadingBar->setGauge(0, 0);

	_x = _y = _count = 0;

	//쓰레드를 사용하려면
	CreateThread(
		NULL,				//스레드의 보안속성(자식윈도우가 존재할때) 핸들로 자식인지 부모인지 파악
		NULL,				//스레드의 스택크기(NULL로 두면 메인쓰레드 크기와 동일)
		threadfunction,		//스레드 사용할 함수 명
		this,				//스레드의 매개변수(this로 하면 본 클래스)
		NULL,				//스레드의 특성(NULL로 두면 바로 실행)
		NULL				//스레드의 생성 후 스레드의 ID를 넘겨준다 보통은 NULL로 둠
	);


	return S_OK;
}

void LoadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void LoadingScene::update()
{
	_loadingBar->update();
	_loadingBar->setGauge(_currentCount, LOADINGMAX);

	if (_currentCount == LOADINGMAX)
	{
		SCENEMANAGER->changeScene("VideoScene");
	}
	
	_count++;

	if (_count % 20 == 0)
	{
		_y++;
		if (_y > 3) _y = 0;
	}

}

void LoadingScene::render()
{
	_background->frameRender(getMemDC(), 0, 0, _x, _y);
	_loadingBar->render();
}

DWORD CALLBACK threadfunction(LPVOID lpParameter)
{
	LoadingScene* loadingHelper = (LoadingScene*)lpParameter;

	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		SOUNDMANAGER->play("IntroMusic", 0.3f);

		//슬립 안걸면 넘 빠름...
		Sleep(1);

		loadingHelper->_currentCount++;
	}
	
	return 0;
}
