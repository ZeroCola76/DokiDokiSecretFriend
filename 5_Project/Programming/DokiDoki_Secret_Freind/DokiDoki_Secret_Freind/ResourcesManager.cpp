#define _CRT_SECURE_NO_WARNINGS

#include "ResourcesManager.h"

//#include <iostream>
#include <fstream>
#include <locale>

#include <string>

using namespace std;

void ResourcesManager::Init()
{
	pathMgr.Init();
	LoadAllResources();
}

HBITMAP ResourcesManager::LoadHBITMAP(int _scene, const char* _path)
{
	char* dest;
	dest = pathMgr.GetResourcePath(_scene);
	strcat_s(dest, MAX_PATH, "Bitmap\\");


	strcat_s(dest, MAX_PATH, _path);
	char dest2[MAX_PATH];
	memset(dest2, 0, MAX_PATH);
	for (int i = 0; i < MAX_PATH; i++)
	{
		dest2[i] = dest[i];
	}

	return (HBITMAP)LoadImageA(NULL, dest2, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void ResourcesManager::LoadAllResources()
{
	LoadTitleResources();
	LoadCreditResources();

	LoadStage1Resources();
	LoadStage2Resources();
	LoadStage3Resources();

	LoadDialogResources();
	LoadDialog1Resources();
	LoadDialog2Resources();
	LoadDialog3Resources();

	LoadIntroResources();
	LoadEndResources();
}

void ResourcesManager::LoadTitleResources()
{
	title.backGround = LoadHBITMAP(P_TITLE, "title.bmp");
	title.start = LoadHBITMAP(P_TITLE, "title_start2.bmp");
	title.credit = LoadHBITMAP(P_TITLE, "title_credit2.bmp");
	title.exit = LoadHBITMAP(P_TITLE, "title_exit2.bmp");
}

void ResourcesManager::LoadCreditResources()
{
	credit.credit = LoadHBITMAP(P_CREDIT, "credit_SpaceToExit.bmp");
}

void ResourcesManager::LoadStage1Resources()
{
	stage1.backGround = LoadHBITMAP(P_STAGE1, "stage1_start.bmp");
	stage1.afterBackGround = LoadHBITMAP(P_STAGE1, "stage1_after.bmp");
	stage1.downArrow = LoadHBITMAP(P_STAGE1, "stage1_rhythm_DOWN.bmp");
	stage1.UpArrow = LoadHBITMAP(P_STAGE1, "stage1_rhythm_UP.bmp");
	stage1.leftArrow = LoadHBITMAP(P_STAGE1, "stage1_rhythm_LEFT.bmp");
	stage1.rightArrow = LoadHBITMAP(P_STAGE1, "stage1_rhythm_RIGHT.bmp");
	stage1.noteCircle = LoadHBITMAP(P_STAGE1, "Line_Judgement.bmp");
	stage1.popupBox = LoadHBITMAP(P_STAGE1, "stage1_Start_UI.bmp");
	stage1.result = LoadHBITMAP(P_STAGE1, "Stage1_clear_UI_NoGreatbmp.bmp");
	stage1.A = LoadHBITMAP(P_STAGE1, "A.bmp");
	stage1.B = LoadHBITMAP(P_STAGE1, "B.bmp");
	stage1.C = LoadHBITMAP(P_STAGE1, "C.bmp");
	stage1.Check = LoadHBITMAP(P_STAGE1, "stage1_Start_UI_a.bmp");
	stage1.afterCheck = LoadHBITMAP(P_STAGE1, "Stage1_clear_UI_NoGreatbmp_a.bmp");
}

void ResourcesManager::LoadStage2Resources()
{
	//배경
	stage2.backGround = LoadHBITMAP(P_STAGE2, "stage2.bmp");
	
	//팝업창
	stage2.popUp0 = LoadHBITMAP(P_STAGE2, "popUp0.bmp");
	stage2.popUp0_a = LoadHBITMAP(P_STAGE2, "popUp0_a.bmp");
	stage2.popUp1 = LoadHBITMAP(P_STAGE2, "popUp1.bmp");
	stage2.popUp1_a = LoadHBITMAP(P_STAGE2, "popUp1_a.bmp");
	stage2.popUp2 = LoadHBITMAP(P_STAGE2, "popUp2.bmp");
	stage2.popUp2_a = LoadHBITMAP(P_STAGE2, "popUp2_a.bmp");
	stage2.popUp3 = LoadHBITMAP(P_STAGE2, "popUp3.bmp");
	stage2.popUp3_a = LoadHBITMAP(P_STAGE2, "popUp3_a.bmp");
	stage2.popUp4 = LoadHBITMAP(P_STAGE2, "popUp4.bmp");
	stage2.popUp4_a = LoadHBITMAP(P_STAGE2, "popUp4_a.bmp");

	//UI
	stage2.findUI0 = LoadHBITMAP(P_STAGE2, "findUI_0.bmp");
	stage2.findUI1 = LoadHBITMAP(P_STAGE2, "findUI_1.bmp");
	stage2.findUI2 = LoadHBITMAP(P_STAGE2, "findUI_2.bmp");
	stage2.findUI3 = LoadHBITMAP(P_STAGE2, "findUI_3.bmp");
	stage2.findUI4 = LoadHBITMAP(P_STAGE2, "findUI_4.bmp");


	stage2.remainUI0 = LoadHBITMAP(P_STAGE2, "remainUI_0.bmp");
	stage2.remainUI1 = LoadHBITMAP(P_STAGE2, "remainUI_1.bmp");
	stage2.remainUI2 = LoadHBITMAP(P_STAGE2, "remainUI_2.bmp");
	stage2.remainUI3 = LoadHBITMAP(P_STAGE2, "remainUI_3.bmp");
	stage2.remainUI4 = LoadHBITMAP(P_STAGE2, "remainUI_4.bmp");

	//대화
	stage2.window1 = LoadHBITMAP(P_STAGE2, "window1.bmp");
	stage2.window2 = LoadHBITMAP(P_STAGE2, "window2.bmp");

	stage2.board1 = LoadHBITMAP(P_STAGE2, "board1.bmp");
	stage2.board2 = LoadHBITMAP(P_STAGE2, "board2.bmp");

	stage2.note1 = LoadHBITMAP(P_STAGE2, "note1.bmp");
	stage2.note2 = LoadHBITMAP(P_STAGE2, "note2.bmp");

	stage2.desk1 = LoadHBITMAP(P_STAGE2, "desk1.bmp");
	stage2.desk2 = LoadHBITMAP(P_STAGE2, "desk2.bmp");
		
}

void ResourcesManager::LoadStage3Resources()
{
	stage3.backGround = LoadHBITMAP(P_STAGE3, "stage3.bmp");
	stage3.quiz1 = LoadHBITMAP(P_STAGE3, "Dumi\\quiz1.bmp");
	stage3.quiz2 = LoadHBITMAP(P_STAGE3, "Dumi\\quiz2.bmp");
	stage3.quiz3 = LoadHBITMAP(P_STAGE3, "Dumi\\quiz3.bmp");

	stage3.quizRabbit = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit.bmp");
	stage3.rabbit1 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_1.bmp");
	stage3.rabbit2 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_2.bmp");
	stage3.rabbit3 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_3.bmp");
	stage3.rabbit4 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_4.bmp");
	stage3.rabbit5 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_5.bmp");
	stage3.rabbit6 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_6.bmp");
	stage3.rabbit7 = LoadHBITMAP(P_STAGE3, "Rabbit\\Piece_Rabbit_7.bmp");

	stage3.quizAirplane = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane.bmp");
	stage3.airplane1 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_1.bmp");
	stage3.airplane2 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_2.bmp");
	stage3.airplane3 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_3.bmp");
	stage3.airplane4 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_4.bmp");
	stage3.airplane5 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_5.bmp");
	stage3.airplane6 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_6.bmp");
	stage3.airplane7 = LoadHBITMAP(P_STAGE3, "Airplane\\Piece_Airplane_7.bmp");

	stage3.quizTree = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree.bmp");
	stage3.tree1 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_1.bmp");
	stage3.tree2 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_2.bmp");
	stage3.tree3 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_3.bmp");
	stage3.tree4 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_4.bmp");
	stage3.tree5 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_5.bmp");
	stage3.tree6 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_6.bmp");
	stage3.tree7 = LoadHBITMAP(P_STAGE3, "Tree\\Piece_Tree_7.bmp");

	stage3.startUI = LoadHBITMAP(P_STAGE3, "stage3_UI.bmp");
	stage3.startUI_a = LoadHBITMAP(P_STAGE3, "stage3_UI_a.bmp");
	stage3.nextUI = LoadHBITMAP(P_STAGE3, "stage3_spacebar_UI.bmp");;
}

void ResourcesManager::LoadDialogResources()
{
	dialog.boy = LoadHBITMAP(P_DIALOG, "cha_boy_1.bmp");
	dialog.boy_s = LoadHBITMAP(P_DIALOG, "cha_boy_s.bmp");
	dialog.girl = LoadHBITMAP(P_DIALOG, "cha_girl_5.bmp");
	dialog.girl_s = LoadHBITMAP(P_DIALOG, "cha_girl_s.bmp");
	dialog.girl_b = LoadHBITMAP(P_DIALOG, "cha_girl_b.bmp");
	dialog.dialog = LoadHBITMAP(P_DIALOG, "text_box.bmp");
	dialog.txtBtn = LoadHBITMAP(P_DIALOG, "text_button.bmp");

	text.intro = LoadTextResources("Intro.txt");
	text.stage1 = LoadTextResources("Stage1.txt");
	text.stage2 = LoadTextResources("Stage2.txt");
	text.stage3 = LoadTextResources("Stage3.txt");
	text.ending = LoadTextResources("Ending.txt");



}

void ResourcesManager::LoadDialog1Resources()
{
	dialog1.dialog1_1 = LoadHBITMAP(P_DIALOG1, "dialog1_1.bmp");
	dialog1.dialog1_2 = LoadHBITMAP(P_DIALOG1, "dialog1_2.bmp");
	dialog1.dialog1_3 = LoadHBITMAP(P_DIALOG1, "dialog1_3.bmp");
	dialog1.dialog1_4 = LoadHBITMAP(P_DIALOG1, "dialog1_4.bmp");
	dialog1.dialog1_5 = LoadHBITMAP(P_DIALOG1, "dialog1_5.bmp");
	dialog1.dialog1_6 = LoadHBITMAP(P_DIALOG1, "dialog1_6.bmp");
	dialog1.dialog1_7 = LoadHBITMAP(P_DIALOG1, "dialog1_7.bmp");
	dialog1.dialog1_8 = LoadHBITMAP(P_DIALOG1, "dialog1_8.bmp");
	dialog1.dialog1_9 = LoadHBITMAP(P_DIALOG1, "dialog1_9.bmp");
	dialog1.dialog1_10 = LoadHBITMAP(P_DIALOG1, "dialog1_10.bmp");
	dialog1.dialog1_11 = LoadHBITMAP(P_DIALOG1, "dialog1_11.bmp");
	dialog1.dialog1_12 = LoadHBITMAP(P_DIALOG1, "dialog1_12.bmp");
	dialog1.dialog1_13 = LoadHBITMAP(P_DIALOG1, "dialog1_13.bmp");
	dialog1.dialog1_14 = LoadHBITMAP(P_DIALOG1, "dialog1_14.bmp");
	dialog1.dialog1_15 = LoadHBITMAP(P_DIALOG1, "dialog1_15.bmp");

}

void ResourcesManager::LoadDialog2Resources()
{
	dialog2.dialog2_1 = LoadHBITMAP(P_DIALOG2, "dialog2_1.bmp");
	dialog2.dialog2_2 = LoadHBITMAP(P_DIALOG2, "dialog2_2.bmp");
	dialog2.dialog2_3 = LoadHBITMAP(P_DIALOG2, "dialog2_3.bmp");
	dialog2.dialog2_4 = LoadHBITMAP(P_DIALOG2, "dialog2_4.bmp");
	dialog2.dialog2_5 = LoadHBITMAP(P_DIALOG2, "dialog2_5.bmp");
	dialog2.dialog2_6 = LoadHBITMAP(P_DIALOG2, "dialog2_6.bmp");
	dialog2.dialog2_7 = LoadHBITMAP(P_DIALOG2, "dialog2_7.bmp");
	dialog2.dialog2_8 = LoadHBITMAP(P_DIALOG2, "dialog2_8.bmp");
	dialog2.dialog2_9 = LoadHBITMAP(P_DIALOG2, "dialog2_9.bmp");
	dialog2.dialog2_10 = LoadHBITMAP(P_DIALOG2, "dialog2_10.bmp");


}

void ResourcesManager::LoadDialog3Resources()
{
	dialog3.dialog3_1 = LoadHBITMAP(P_DIALOG3, "dialog3_1.bmp");
	dialog3.dialog3_2 = LoadHBITMAP(P_DIALOG3, "dialog3_2.bmp");
	dialog3.dialog3_3 = LoadHBITMAP(P_DIALOG3, "dialog3_3.bmp");
	dialog3.dialog3_4 = LoadHBITMAP(P_DIALOG3, "dialog3_4.bmp");
	dialog3.dialog3_5 = LoadHBITMAP(P_DIALOG3, "dialog3_5.bmp");
	dialog3.dialog3_6 = LoadHBITMAP(P_DIALOG3, "dialog3_6.bmp");
	dialog3.dialog3_7 = LoadHBITMAP(P_DIALOG3, "dialog3_7.bmp");
	dialog3.dialog3_8 = LoadHBITMAP(P_DIALOG3, "dialog3_8.bmp");
}

void ResourcesManager::LoadIntroResources()
{
	intro.intro1 = LoadHBITMAP(P_INTRO, "intro1.bmp");
	intro.intro2 = LoadHBITMAP(P_INTRO, "intro2.bmp");
	intro.intro3 = LoadHBITMAP(P_INTRO, "intro3.bmp");
	intro.intro4 = LoadHBITMAP(P_INTRO, "intro4.bmp");
	intro.intro5 = LoadHBITMAP(P_INTRO, "intro5.bmp");
	intro.intro6 = LoadHBITMAP(P_INTRO, "intro6.bmp");
	intro.intro7 = LoadHBITMAP(P_INTRO, "intro7.bmp");
	intro.intro8 = LoadHBITMAP(P_INTRO, "intro8.bmp");
	intro.intro9 = LoadHBITMAP(P_INTRO, "intro9.bmp");

}

void ResourcesManager::LoadEndResources()
{
	end.end1 = LoadHBITMAP(P_END, "end1.bmp");
	end.end2 = LoadHBITMAP(P_END, "end2.bmp");
	end.end3 = LoadHBITMAP(P_END, "end3.bmp");
	end.end4 = LoadHBITMAP(P_END, "end4.bmp");
	end.end5 = LoadHBITMAP(P_END, "end5.bmp");
	end.end6 = LoadHBITMAP(P_END, "end6.bmp");
	end.end7 = LoadHBITMAP(P_END, "end7.bmp");
	end.end8 = LoadHBITMAP(P_END, "end8.bmp");
	end.end9 = LoadHBITMAP(P_END, "end9.bmp");
	end.end10 = LoadHBITMAP(P_END, "end10.bmp");
	end.end11 = LoadHBITMAP(P_END, "end11.bmp");
	end.end12 = LoadHBITMAP(P_END, "end12.bmp");
	end.end13 = LoadHBITMAP(P_END, "end13.bmp");
	end.end14 = LoadHBITMAP(P_END, "end14.bmp");
	end.end15 = LoadHBITMAP(P_END, "end15.bmp");
	end.end16 = LoadHBITMAP(P_END, "end16.bmp");
	end.end17 = LoadHBITMAP(P_END, "end17.bmp");
	end.end18 = LoadHBITMAP(P_END, "end18.bmp");
	end.end19 = LoadHBITMAP(P_END, "end19.bmp");
	end.end20 = LoadHBITMAP(P_END, "end20.bmp");
	end.end21 = LoadHBITMAP(P_END, "end21.bmp");
	end.end22 = LoadHBITMAP(P_END, "end22.bmp");
	end.end23 = LoadHBITMAP(P_END, "end23.bmp");
	end.end24 = LoadHBITMAP(P_END, "end24.bmp");

	end.ending = LoadHBITMAP(P_END, "ending.bmp");
}

WCHAR* ResourcesManager::LoadTextResources(const char* _path)
{



	char* dest;
	dest = pathMgr.GetResourcePath(P_TEXT);
	strcat_s(dest, MAX_PATH, _path);

	char path[MAX_PATH];
	memset(path, '\0', MAX_PATH);
	for (int i = 0; i < MAX_PATH; i++)
	{
		path[i] = dest[i];
	}


	std::locale::global(std::locale(".UTF-8"));
	//std::locale::global(std::locale("korean"));

	WCHAR* Src;


	wifstream in;
	in.open(path);

	// 위치 지정자를 파일 끝으로 옮긴다.
	in.seekg(0, std::ios::end);
	// 그리고 그 위치를 읽는다. (파일의 크기)
	int size = in.tellg();
	// 그 크기의 문자열을 할당한다.
	Src = new WCHAR[size];

	memset(Src, L'\0', size);
	// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
	in.seekg(0, std::ios::beg);
	// 파일 전체 내용을 읽어서 문자열에 저장한다.
	in.read(Src, size);

	return Src;
}
