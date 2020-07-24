#include "stdafx.h"
#include "DialogueImage.h"

DialogueImage::DialogueImage()
{

}

DialogueImage::~DialogueImage()
{

}

HRESULT DialogueImage::init()
{
	IMAGEMANAGER->addImage("UI_Portrait_face_Kyoko01_03", "Image/UI/face/UI_Portrait_face_Kyoko01_03.bmp", 324, 609, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Kyoko02_01", "Image/UI/face/UI_Portrait_face_Kyoko02_01.bmp", 387, 600, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Kyoko02_03", "Image/UI/face/UI_Portrait_face_Kyoko02_03.bmp", 387, 600, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Kyoko03_02", "Image/UI/face/UI_Portrait_face_Kyoko03_02.bmp", 357, 594, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Kyoko04_02", "Image/UI/face/UI_Portrait_face_Kyoko04_02.bmp", 316, 568, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misako01_03", "Image/UI/face/UI_Portrait_face_Misako01_03.bmp", 251, 546, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misako02_01", "Image/UI/face/UI_Portrait_face_Misako02_01.bmp", 350, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misako02_02", "Image/UI/face/UI_Portrait_face_Misako02_02.bmp", 350, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misako02_04", "Image/UI/face/UI_Portrait_face_Misako02_04.bmp", 350, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misako04_01", "Image/UI/face/UI_Portrait_face_Misako04_01.bmp", 300, 540, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misako04_02", "Image/UI/face/UI_Portrait_face_Misako04_02.bmp", 300, 540, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misuzu01_01", "Image/UI/face/UI_Portrait_face_Misuzu01_01.bmp", 570, 680, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misuzu01_02", "Image/UI/face/UI_Portrait_face_Misuzu01_02.bmp", 570, 680, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misuzu01_03", "Image/UI/face/UI_Portrait_face_Misuzu01_03.bmp", 570, 680, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misuzu02_01", "Image/UI/face/UI_Portrait_face_Misuzu02_01.bmp", 529, 700, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misuzu02_02", "Image/UI/face/UI_Portrait_face_Misuzu02_02.bmp", 529, 700, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI_Portrait_face_Misuzu02_03", "Image/UI/face/UI_Portrait_face_Misuzu02_03.bmp", 529, 700, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Kyoko_Dialogue", "Image/UI/CharacterName/Kyoko_Dialogue.bmp", 135, 39, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Misako_Dialogue", "Image/UI/CharacterName/Misako_Dialogue.bmp", 155, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Misuzu_Dialogue", "Image/UI/CharacterName/Misuzu_Dialogue.bmp", 149, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Principal_Dialogue", "Image/UI/CharacterName/Principal_Dialogue.bmp", 195, 42, true, RGB(255, 0, 255));

	return S_OK;
}
