#include "stdafx.h"
#include "Dialogue.h"
#include "InGameUI.h"
#include "DialogueImage.h"

HRESULT Dialogue::init()
{


	return S_OK;
}

void Dialogue::release()
{
}

void Dialogue::update()
{
    //string filePath = "dialogue/";
    //string fileName;

    //switch (_Stage)
    //{
    //    case StageChapter::STAGE1:
    //    {
    //        fileName = filePath + "Stage1Dialogue.txt";
    //       break;
    //    }
    //    case StageChapter::STAGE2:
    //    {
    //        fileName = filePath + "Stage2Dialogue.txt";
    //        break;
    //    }
    //    case StageChapter::BOSS_BEFORE:
    //    {
    //        fileName = filePath + "boss_start.txt";
    //        break;
    //    }
    //    case StageChapter::BOSS_AFTER:
    //    {
    //        fileName = filePath + "boss_finish.txt";
    //        break;
    //    }
    //}

    //ifstream readMsg;
    //readMsg.open(fileName);

    //if (readMsg.is_open())
    //{
    //    while (!readMsg.eof())
    //    {
    //        string str;
    //        int atPos;

    //        getline(readMsg, str);
    //        atPos = str.find('@', 0);

    //        DialogueImage characterImg;
    //        ZeroMemory(&characterImg, sizeof(characterImg));

    //        characterImg.portrait = IMAGEMANAGER->findImage(str.substr(0, atPos));
    //        string keyName = findNameImg(str, "kyoko") ? "kyokoName" : findNameImg(str, "misako") ? "misakoName" : "misuzuName";
    //        characterImg.name = IMAGEMANAGER->findImage(keyName);

    //        if (str.find("misuzu") == string::npos)
    //        {
    //           
    //        }
    //        else
    //        {

    //        }

    //        string characterMsg(str.substr(atPos + 1, str.length()));
    //        int enterCh = characterMsg.find("/");
    //        if (enterCh != string::npos)
    //        {
    //            characterMsg.replace(enterCh, 1, "\n");
    //        }

    //        _qCharacterImg.push(characterImg);
    //        _qCharacterMsg.push(characterMsg);
    //    }
    //}
    //readMsg.close();
}

void Dialogue::render()
{
}
