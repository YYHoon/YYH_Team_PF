#pragma once
#include "gameNode.h"

#define LOADINGMAX 2000

class progressBar;

class LoadingScene : public gameNode
{
private:
	progressBar* _loadingBar;
	image* _background;

	int _x, _y;
	int _count;

public:
	LoadingScene();
	~LoadingScene();

	int _currentCount;

	HRESULT init();
	void release();
	void update();
	void render();


};

static DWORD CALLBACK threadfunction(LPVOID lpParameter);