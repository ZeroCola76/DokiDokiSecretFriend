#pragma once
#include "WInApp.h"

//인트로, 크레딧, 다이얼로그 1~3, 엔딩 클래스 만들어야 함

class DialogText
{
public:
	WCHAR* intro;
	WCHAR* stage1;
	WCHAR* stage2;
	WCHAR* stage3;
	WCHAR* ending;


};

class TitleSrc
{
public:
	HBITMAP backGround;
	HBITMAP start;
	HBITMAP credit;
	HBITMAP exit;

};

class CreditSrc
{
public:
	HBITMAP credit;
};

class DialogSrc
{
public:
	HBITMAP boy;
	HBITMAP boy_s;
	HBITMAP girl_s;
	HBITMAP girl_b;
	HBITMAP girl;
	HBITMAP dialog;
	HBITMAP txtBtn;

};

class IntroSrc
{
public:
	HBITMAP intro1;
	HBITMAP intro2;
	HBITMAP intro3;
	HBITMAP intro4;
	HBITMAP intro5;
	HBITMAP intro6;
	HBITMAP intro7;
	HBITMAP intro8;
	HBITMAP intro9;
};


class Stage1Src
{
public:
	HBITMAP backGround;
	HBITMAP afterBackGround;
	HBITMAP leftArrow;
	HBITMAP rightArrow;
	HBITMAP UpArrow;
	HBITMAP downArrow;
	HBITMAP noteCircle;
	HBITMAP	popupBox;
	HBITMAP result;
	HBITMAP A;
	HBITMAP B;
	HBITMAP C;
	HBITMAP Check;
	HBITMAP afterCheck;
};

class Dialog1Src
{
public:
	HBITMAP dialog1_1;
	HBITMAP dialog1_2;
	HBITMAP dialog1_3;
	HBITMAP dialog1_4;
	HBITMAP dialog1_5;
	HBITMAP dialog1_6;
	HBITMAP dialog1_7;
	HBITMAP dialog1_8;
	HBITMAP dialog1_9;
	HBITMAP dialog1_10;
	HBITMAP dialog1_11;
	HBITMAP dialog1_12;
	HBITMAP dialog1_13;
	HBITMAP dialog1_14;
	HBITMAP dialog1_15;
};

class Dialog2Src
{
public:
	HBITMAP dialog2_1;
	HBITMAP dialog2_2;
	HBITMAP dialog2_3;
	HBITMAP dialog2_4;
	HBITMAP dialog2_5;
	HBITMAP dialog2_6;
	HBITMAP dialog2_7;
	HBITMAP dialog2_8;
	HBITMAP dialog2_9;
	HBITMAP dialog2_10;
};

class Stage2Src
{
public:
	//배경
	HBITMAP backGround;

	//팝업창
	HBITMAP popUp0;
	HBITMAP popUp0_a;
	HBITMAP popUp1;
	HBITMAP popUp1_a;
	HBITMAP popUp2;
	HBITMAP popUp2_a;
	HBITMAP popUp3;
	HBITMAP popUp3_a;
	HBITMAP popUp4;
	HBITMAP popUp4_a;

	//UI
	HBITMAP findUI0;
	HBITMAP findUI1;
	HBITMAP findUI2;
	HBITMAP findUI3;
	HBITMAP findUI4;


	HBITMAP remainUI0;
	HBITMAP remainUI1;
	HBITMAP remainUI2;
	HBITMAP remainUI3;
	HBITMAP remainUI4;

	//대사
	HBITMAP window1;
	HBITMAP window2;

	HBITMAP board1;
	HBITMAP board2;

	HBITMAP note1;
	HBITMAP note2;

	HBITMAP desk1;
	HBITMAP desk2;

	HBITMAP titleBack;
};

class Dialog3Src
{
public:
	HBITMAP dialog3_1;
	HBITMAP dialog3_2;
	HBITMAP dialog3_3;
	HBITMAP dialog3_4;
	HBITMAP dialog3_5;
	HBITMAP dialog3_6;
	HBITMAP dialog3_7;
	HBITMAP dialog3_8;

};

class Stage3Src
{
public:
	HBITMAP backGround;

	HBITMAP quiz1;
	HBITMAP quiz2;
	HBITMAP quiz3;

	HBITMAP quizRabbit;
	HBITMAP rabbit1;
	HBITMAP rabbit2;
	HBITMAP rabbit3;
	HBITMAP rabbit4;
	HBITMAP rabbit5;
	HBITMAP rabbit6;
	HBITMAP rabbit7;

	HBITMAP quizAirplane;
	HBITMAP airplane1;
	HBITMAP airplane2;
	HBITMAP airplane3;
	HBITMAP airplane4;
	HBITMAP airplane5;
	HBITMAP airplane6;
	HBITMAP airplane7;

	HBITMAP quizTree;
	HBITMAP tree1;
	HBITMAP tree2;
	HBITMAP tree3;
	HBITMAP tree4;
	HBITMAP tree5;
	HBITMAP tree6;
	HBITMAP tree7;

	HBITMAP startUI;
	HBITMAP startUI_a;
	HBITMAP nextUI;

};

class EndSrc
{
public:
	HBITMAP end1;
	HBITMAP end2;
	HBITMAP end3;
	HBITMAP end4;
	HBITMAP end5;
	HBITMAP end6;
	HBITMAP end7;
	HBITMAP end8;
	HBITMAP end9;
	HBITMAP end10;
	HBITMAP end11;
	HBITMAP end12;
	HBITMAP end13;
	HBITMAP end14;
	HBITMAP end15;
	HBITMAP end16;
	HBITMAP end17;
	HBITMAP end18;
	HBITMAP end19;
	HBITMAP end20;
	HBITMAP end21;
	HBITMAP end22;
	HBITMAP end23;
	HBITMAP end24;

	HBITMAP ending;
};
