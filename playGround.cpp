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
	CAMERAMANAGER->setConfig(0, 0, WINSIZEX, WINSIZEY, 0, 0, 0, 0);
	imginit(); // 모든 이미지를 여기다 넣도록
	soundinit(); // 사운드도 따로 뺐습니다.


	_SM = new StageManager;
	_SM->init();

	

	SCENEMANAGER->addScene("LoadingScene", new LoadingScene);					//1
	SCENEMANAGER->addScene("VideoScene", new VideoScene);						//2
	SCENEMANAGER->addScene("IntroMenuScene", new IntroMenuScene);				//3
	SCENEMANAGER->addScene("SelectMenuScene", new SelectMenuScene);			//4
	SCENEMANAGER->addScene("CharacterSelectScene", new CharacterSelectScene);	//5

	SCENEMANAGER->changeScene("LoadingScene");
	

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
	
	//_SM->update();
	SCENEMANAGER->update();
	if(SCENEMANAGER->GetNowScene()=="Stage1_Start" || SCENEMANAGER->GetNowScene() == "Stage1_1" 
		|| SCENEMANAGER->GetNowScene() == "Stage1_2" || SCENEMANAGER->GetNowScene() == "Stage1_Boss")
		_SM->update();
	KEYANIMANAGER->update();

}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//=================================================
//	_SM->render();
	SCENEMANAGER->render();
	if (SCENEMANAGER->GetNowScene() == "Stage1_Start" || SCENEMANAGER->GetNowScene() == "Stage1_1"
		|| SCENEMANAGER->GetNowScene() == "Stage1_2" || SCENEMANAGER->GetNowScene() == "Stage1_Boss")
		_SM->render();
	TIMEMANAGER->render(getMemDC());
	//ZORDER->ZOrderRender();
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
	//Player
	{
		IMAGEMANAGER->addFrameImage("PlayerBattleStart", "Player/Kyoko_BattleStart.bmp", 2964, 420, 26, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerIdle", "Player/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerWalk", "Player/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerRun", "Player/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerAttack1", "Player/Kyoko_ComboAttack1.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerAttack2", "Player/Kyoko_ComboAttack2.bmp", 1869, 402, 7, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerAttack3", "Player/Kyoko_ComboAttack3.bmp", 2970, 462, 9, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerHit", "Player/Kyoko_Hit.bmp", 246, 348, 2, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerDown", "Player/Kyoko_Down.bmp", 4896, 366, 24, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerGuard", "Player/Kyoko_Guard.bmp", 351, 378, 3, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerDiveAttack", "Player/Kyoko_Dive.bmp", 5040, 360, 21, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerGameOver", "Player/Kyoko_GameOver.bmp", 6240, 282, 26, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerHKick", "Player/Kyoko_HurricaneKick.bmp", 2997, 657, 9, 3, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerStandUp", "Player/Kyoko_StandUp.bmp", 3315, 330, 17, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerStomp", "Player/Kyoko_Stomp.bmp", 1290, 420, 10, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerStnned", "Player/Kyoko_Stunned.bmp", 384, 384, 4, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerDap", "Player/Kyoko_Ultimate.bmp", 3675, 384, 25, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addFrameImage("PlayerJump", "Player/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("PlayerShadow", "Player/KyoKo_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));
		//이펙트
		EFFECTMANAGER->addEffect("Playeroang", "Player/eff/Kyoko_Down.bmp", 1800, 100, 180, 100, 1, 0.5f, 1);
		EFFECTMANAGER->addEffect("PlayerLDAP", "Player/eff/LDAP.bmp", 768, 111, 192, 111, 1, 0.2f, 1);
		EFFECTMANAGER->addEffect("PlayerRDAP", "Player/eff/RDAP.bmp", 768, 111, 192, 111, 1, 0.2f, 1);
		EFFECTMANAGER->addEffect("PlayerWind", "Player/eff/KyoKo_Wind.bmp", 633, 200, 127, 200, 1, 0.3f, 1);
		EFFECTMANAGER->addEffect("PlayerAWind", "Player/eff/KyoKo_AWind.bmp", 633, 200, 127, 200, 1, 0.3f, 1);
		EFFECTMANAGER->addEffect("PlayerBungea", "Player/eff/Bungea.bmp", 1020, 600, 170, 600, 1, 0.3f, 1);
		EFFECTMANAGER->addEffect("PlayerAttEff", "Player/eff/Effect_Hit2.bmp", 1800, 200, 200, 200, 1, 0.3f, 1);
		//효과음
		SOUNDMANAGER->addSound("PlayerAtt1", "Player/sound/Att1.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerAtt2", "Player/sound/Att2.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerAtt3", "Player/sound/Att3.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerHit1", "Player/sound/Hit1.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerHit2", "Player/sound/Hit2.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerHit3", "Player/sound/Hit3.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerDap", "Player/sound/Dap.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerHkick", "Player/sound/Hkick.WAV", false, false);
		SOUNDMANAGER->addSound("PlayerDashAtt", "Player/sound/DashAtt.WAV", false, false);
	}

	//StageManager
	IMAGEMANAGER->addImage("Stage1_Start", "image/Stage_BG/Stage1_Start.bmp", 2016, 672, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_1", "image/Stage_BG/Stage1_1.bmp", 2400, 1064, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_2", "image/Stage_BG/Stage1_2.bmp", 2860, 1040, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1_Boss", "image/Stage_BG/Stage1_Boss.bmp", 2769, 1280, false, RGB(255, 0, 255));
	//Pixel
	IMAGEMANAGER->addImage("Stage1_Start_Pixel", "image/Stage_BG/Stage1_Start_Pixel.bmp", 2016, 772, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_1_Pixel", "image/Stage_BG/Stage1_1_Pixel.bmp", 2400, 1064, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Stage1_2_Pixel", "image/Stage_BG/Stage1_2_Pixel.bmp", 2860, 1040, false, RGB(0, 0, 0));
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
	// Boss
	IMAGEMANAGER->addImage("redDC", "image/Boss/redDC.bmp", 5000, 1000, false, NULL);
	IMAGEMANAGER->addFrameImage("WALK", "image/Boss/walk.bmp", 0, 0, 1557, 526, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ATTACK", "image/Boss/attack.bmp", 0, 0, 2430, 582, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SLAP", "image/Boss/slap.bmp", 0, 0, 4634, 520, 14, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SLAPRED", "image/Boss/slap_red.bmp", 0, 0, 4634, 520, 14, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PUNCH", "image/Boss/punch.bmp", 0, 0, 10935, 700, 27, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PUNCHRED", "image/Boss/punch_red.bmp", 0, 0, 10935, 700, 27, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("HIT", "image/Boss/hit.bmp", 0, 0, 2295, 528, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("KNOCK", "image/Boss/knock.bmp", 0, 0, 2340, 520, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SIT", "image/Boss/sit.bmp", 0, 0, 876, 392, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("WAKE", "image/Boss/wake.bmp", 0, 0, 4731, 538, 19, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("TAUNT", "image/Boss/taunt.bmp", 0, 0, 4899, 668, 23, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("TAUNTRED", "image/Boss/taunt_red.bmp", 0, 0, 4899, 668, 23, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ROAR", "image/Boss/roar.bmp", 0, 0, 2520, 520, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("IDLE_RUSH", "image/Boss/idle_rush.bmp", 0, 0, 1040, 508, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RUSH", "image/Boss/rush.bmp", 0, 0, 1752, 498, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RUSHTURN", "image/Boss/rushturn.bmp", 0, 0, 540, 496, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JUMP", "image/Boss/jump.bmp", 0, 0, 1368, 594, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("UP", "image/Boss/up.bmp", 0, 0, 912, 594, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("DOWN", "image/Boss/down.bmp", 0, 0, 684, 570, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LANDHIT", "image/Boss/landhit.bmp", 0, 0, 2052, 570, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("DEAD", "image/Boss/dead.bmp", 0, 0, 2772, 566, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("CRY", "image/Boss/cry.bmp", 0, 0, 1232, 566, 4, 2, true, RGB(255, 0, 255));
	// Enemy
	IMAGEMANAGER->addImage("Enemy_Shadow", "image/enemy/Enemy_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));
	//여학생 걷기
	IMAGEMANAGER->addFrameImage("SgWalk", "image/enemy/sg/sg_walk.bmp", 0, 0, 1296, 372, 12, 2, true, RGB(255, 0, 255));
	//여학생 달리기
	IMAGEMANAGER->addFrameImage("SgRun", "image/enemy/sg/sg_run.bmp", 0, 0, 1470, 330, 10, 2, true, RGB(255, 0, 255));
	//여학생 다운 및 기상
	IMAGEMANAGER->addFrameImage("SgKnockdown", "image/enemy/sg/sg_knockdown.bmp", 0, 0, 2925, 1080, 13, 6, true, RGB(255, 0, 255));
	//여학생 일반공격
	IMAGEMANAGER->addFrameImage("SgJab", "image/enemy/sg/sg_jab.bmp", 0, 0, 1239, 354, 7, 2, true, RGB(255, 0, 255));
	//여학생 기본
	IMAGEMANAGER->addFrameImage("SgIdle", "image/enemy/sg/sg_idle.bmp", 0, 0, 1170, 354, 10, 2, true, RGB(255, 0, 255));
	//여학생 피격모션
	IMAGEMANAGER->addFrameImage("SgGethit", "image/enemy/sg/sg_gethit.bmp", 0, 0, 1431, 360, 9, 2, true, RGB(255, 0, 255));
}

void playGround::soundinit()
{
	//UI
	SOUNDMANAGER->addSound("IntroMusic", "Sounds/RCG_Intro_Song.wav", true, true);
	SOUNDMANAGER->addSound("MenuMusic", "Sounds/RCG_menu01.wav", true, true);
	SOUNDMANAGER->addSound("MemuConfirm", "Sounds/menu_confirm.wav", false, false);
	SOUNDMANAGER->addSound("MemuBack", "Sounds/menu_back.wav", false, false);
	SOUNDMANAGER->addSound("MemuCursor", "Sounds/menu_cursor.wav", false, false);
	SOUNDMANAGER->addSound("Stage_1", "Sounds/RCG_Dollar_Signs.wav", true, true);
	SOUNDMANAGER->addSound("Stage_2", "Sounds/RCG_The_Burbs.wav", true, true);
	SOUNDMANAGER->addSound("Stage_Boss", "Sounds/RCG_boss_misuzu.wav", true, true);
	//BOSS
	SOUNDMANAGER->addSound("ATTACKSOUND", "Sounds/Boss/boss_misuzu_elbow_bonk.wav", false, false);
	SOUNDMANAGER->addSound("JUMPSOUND", "Sounds/Boss/boss_misuzu_meteor_drop_jump2.wav", false, false);
	SOUNDMANAGER->addSound("LANDHITSOUND", "Sounds/Boss/boss_misuzu_meteor_drop_impact.wav", false, false);
	SOUNDMANAGER->addSound("RUSHSOUND", "Sounds/Boss/boss_misuzu_shoulder_tackle_footstep.wav", false, true);
	SOUNDMANAGER->addSound("SLAPSOUND", "Sounds/Boss/boss_misuzu_slap.wav", false, false);
	SOUNDMANAGER->addSound("PUNCHSOUND", "Sounds/Boss/boss_misuzu_windup_punch.wav", false, false);
	SOUNDMANAGER->addSound("HITSOUND1", "Sounds/Boss/vo_misuzu_gethit_01.wav", false, false);
	SOUNDMANAGER->addSound("HITSOUND2", "Sounds/Boss/vo_misuzu_gethit_02.wav", false, false);
	SOUNDMANAGER->addSound("HITSOUND3", "Sounds/Boss/vo_misuzu_gethit_03.wav", false, false);
	SOUNDMANAGER->addSound("HITSOUND4", "Sounds/Boss/vo_misuzu_gethit_heavy_01.wav", false, false);
	SOUNDMANAGER->addSound("TAUNTSOUND", "Sounds/Boss/vo_misuzu_laugh_02.wav", false, false);
}
