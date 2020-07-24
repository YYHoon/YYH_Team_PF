#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);

	imginit(); // 모든 이미지를 여기다 넣도록
	soundinit(); // 사운드도 따로 뺐습니다.

	p = new Player;
	p->SetAddressBoss(b);
	p->PlayerImageAniStting();
	p->Init();
	//b = new Boss;
	//b->SetPlayerAddressLink(p);
	//b->init();
	_SM = new StageManager;
	_SM->init();
	//_pixel = new pixelCollsion;
	//_pixel->init();
	//_en = new EnemySchoolGirl;
	//_en->Init(PointFloatMake(500,500));
	

	//SCENEMANAGER->addScene("LoadingScene", new LoadingScene);					//1
	//SCENEMANAGER->addScene("VideoScene", new VideoScene);						//2
	//SCENEMANAGER->addScene("IntroMenuScene", new IntroMenuScene);				//3
	//SCENEMANAGER->addScene("SelectMenuScene", new SelectMenuScene);				//4
	//SCENEMANAGER->addScene("CharacterSelectScene", new CharacterSelectScene);	//5
	//
	//SCENEMANAGER->changeScene("LoadingScene");

	_InGameUI = new InGameUI;
	_InGameUI->init();


	return S_OK;
}

//메모리 해제
void playGround::release()
{
	
}

//연산
void playGround::update()
{
	gameNode::update();
	//p->Update();
	//b->update();
	//_SM->update();
	//_pixel->update();
	//_en->Update();
	_InGameUI->update();

	//SCENEMANAGER->update();
}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================
	//_SM->render();
	//p->Render();
	//b->render();
	//_pixel->render();
	//_en->Render();
	_InGameUI->render();
	//SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::imginit()
{
	// UI
	{
		IMAGEMANAGER->addImage("MenuBackGround", "Image/UI/menuBackGround.bmp", WINSIZEX, WINSIZEY, false, BLACK);
		IMAGEMANAGER->addImage("MenuFrontGround", "Image/UI/MenuFront.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);
		IMAGEMANAGER->addImage("KyokoIntro", "Image/UI/fx_battle_portraits_kyoko.bmp", 512, 771, true, MAGENTA);
		IMAGEMANAGER->addImage("MisakoIntro", "Image/UI/fx_battle_portraits_misako.bmp", 443, 761, true, MAGENTA);
		IMAGEMANAGER->addImage("Intro_UI_START", "Image/UI/UI_START.bmp", 151, 56, true, MAGENTA);
		IMAGEMANAGER->addImage("Intro_UI_QUIT", "Image/UI/UI_QUIT.bmp", 136, 54, true, MAGENTA);
		IMAGEMANAGER->addImage("Intro_UI_ARROW", "Image/UI/UI_title_arrow.bmp", 53, 61, true, MAGENTA);
		IMAGEMANAGER->addImage("Intro_UI_LOGO", "Image/UI/UI_TITLE_LOGO.bmp", 573, 317, true, MAGENTA);
		IMAGEMANAGER->addImage("SelectManuBackGround", "Image/UI/UI_FILE_SELECT.bmp", 1600, 900, false, BLACK);
		IMAGEMANAGER->addImage("UI_FILE_A", "Image/UI/UI_FILE_A.bmp", 608, 248, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_B", "Image/UI/UI_FILE_B.bmp", 608, 248, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_C", "Image/UI/UI_FILE_C.bmp", 608, 248, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_MENU", "Image/UI/UI_FILE_SELECT_MENU.bmp", 797, 878, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_FG", "Image/UI/UI_FILE_SELECT_FG.bmp", 351, 128, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_BG_Blue", "Image/UI/UI_FILE_SELECT_BG_Blue.bmp", 1585, 885, false, BLACK);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_BG_Pink", "Image/UI/UI_FILE_SELECT_BG_Pink.bmp", 1600, 900, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_BG_Yellow", "Image/UI/UI_FILE_SELECT_BG_Yellow.bmp", 797, 829, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_FG_Character", "Image/UI/UI_FILE_SELECT_FG_Character.bmp", 790, 900, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FE_Character_Select", "Image/UI/UI_FE_Character_Select.bmp", 1600, 900, false, BLACK);
		IMAGEMANAGER->addImage("UI_SELECT_Character_Text", "Image/UI/UI_SELECT_Character_Text.bmp", 334, 68, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_SELECT_Character", "Image/UI/UI_SELECT_Character.bmp", 432, 759, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FILE_SELECT_Character_Shadow", "Image/UI/UI_FILE_SELECT_Character_Shadow.bmp", 260, 759, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_RCG_HUD_portrait_Kyoko_default", "Image/UI/UI_RCG_HUD_portrait_Kyoko_default.bmp", 124, 142, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_HUD_player_BG", "Image/UI/UI_HUD_player_BG.bmp", 342, 76, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_HUD_Nplayer_BG", "Image/UI/UI_HUD_Nplayer_BG.bmp", 341, 46, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_HUD_player_Digit", "Image/UI/UI_HUD_player_Digit.bmp", 22, 21, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_FrontEnd_FileSelect_002_LETTERBOX", "Image/UI/UI_FrontEnd_FileSelect_002_LETTERBOX.bmp", 1600, 900, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_BOSS_Dialog_Alpha", "Image/UI/UI_BOSS_Dialog_Alpha.bmp", 1600, 900, true, MAGENTA);
		IMAGEMANAGER->addImage("fx_battle_portraits_misuzu", "Image/UI/fx_battle_portraits_misuzu.bmp", 570, 841, true, MAGENTA);
		IMAGEMANAGER->addImage("fx_vs_L_CORNER_PINK", "Image/UI/fx_vs_L_CORNER_PINK.bmp", 508, 515, true, MAGENTA);
		IMAGEMANAGER->addImage("fx_vs_R_CORNER_PINK", "Image/UI/fx_vs_R_CORNER_PINK.bmp", 508, 515, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_Battle_Intro", "Image/UI/UI_Battle_Intro.bmp", 1600, 390, true, MAGENTA);
		IMAGEMANAGER->addImage("RCG_bossmeterBG_frame", "Image/UI/RCG_bossmeterBG_frame.bmp", 749, 101, true, MAGENTA);
		IMAGEMANAGER->addImage("RCG_bossmeter_frame", "Image/UI/RCG_bossmeter_frame.bmp", 749, 101, true, MAGENTA);
		IMAGEMANAGER->addImage("RCG_Misuzu_meter_fill", "Image/UI/RCG_Misuzu_meter_fill.bmp", 572, 43, true, MAGENTA);
		IMAGEMANAGER->addImage("MISUZU_NAME_HP_BAR", "Image/UI/MISUZU_NAME_HP_BAR.bmp", 155, 42, true, MAGENTA);
		IMAGEMANAGER->addImage("UI_Screen_Lock_Chain", "Image/UI/UI_Screen_Lock_Chain.bmp", 1600, 900, true, MAGENTA);
	}

	//StageManager
	IMAGEMANAGER->addImage("Stage1_Start", "image/Stage_BG/Stage1_Start.bmp", 2016, 672, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_1", "image/Stage_BG/Stage1_1.bmp", 2400, 1064, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2.bmp", 2860, 1040, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1_Boss", "image/Stage_BG/Stage1_Boss.bmp", 2769, 1280, false, RGB(255, 0, 255));
	//Pixel
	IMAGEMANAGER->addImage("Stage1_Start_Pixel", "image/Stage_BG/Stage1_Start_Pixel.bmp", 2016, 672, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_1_Pixel", "image/Stage_BG/Stage1_1_Pixel.bmp", 2400, 1064, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2_Pixel.bmp", 2860, 1040, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_Boss_Pixel", "image/Stage_BG/Stage1_Boss_Pixel.bmp", 2769, 1280, false, RGB(0, 0, 0));

	//Obstacle
	IMAGEMANAGER->addImage("Pillar", "image/Obstacle/Pillar.bmp", 207, 864, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("LeftDestructiblePillar", "image/Obstacle/LeftDetsructiblePillar.bmp", 207, 893, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("RightDestructiblePillar", "image/Obstacle/RightDestructiblePillar.bmp", 207, 893, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Desk", "image/Obstacle/desk.bmp", 168, 159, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("VendingMachine", "image/Obstacle/VendingMachine.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("VendingMachineDestroyed", "image/Obstacle/VendingMachineDestroyed.bmp", 300, 296, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Table1", "image/Obstacle/cafeteria_table1.bmp", 283, 130, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Table2", "image/Obstacle/cafeteria_table2.bmp", 317, 130, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Table3", "image/Obstacle/cafeteria_table3.bmp", 267, 130, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Table4", "image/Obstacle/cafeteria_table4.bmp", 278, 130, true, RGB(255, 0, 255));

	//Item
	IMAGEMANAGER->addFrameImage("MoneyFallen", "image/Item/Money_Fallen.bmp", 78, 25, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MoneyLand", "image/Item/Money_Land.bmp", 23, 11, true, RGB(255, 0, 255));
}

void playGround::soundinit()
{
	//UI
	SOUNDMANAGER->addSound("IntroMusic", "Sounds/RCG_Intro_Song.wav", true, true);
	SOUNDMANAGER->addSound("MenuMusic", "Sounds/RCG_menu01.wav", true, true);
	SOUNDMANAGER->addSound("MemuConfirm", "Sounds/menu_confirm.wav", false, false);
	SOUNDMANAGER->addSound("MemuBack", "Sounds/menu_back.wav", false, false);
	SOUNDMANAGER->addSound("MemuCursor", "Sounds/menu_cursor.wav", false, false);
}
