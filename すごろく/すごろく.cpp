#include<iostream>
#include<vector>
#include"DxLib.h"

using namespace std;

/*ゲーム内カウント*/
const int FRAME_RATE = 30;
const int FRAME_TIME = 1000 / FRAME_RATE;

/*画面設定*/
const int WIDTH = 960;
const int HEIGHT = 640;

const int BSIZE = 80;

enum {TITLE,PLAY,DICE,MOVE,RESULT};

/*色設定*/
struct Color {
	
	int RED;
	int GREEN;
	int BLUE;
	int WHITE;
	int BLACK;
	int MAGENTA;
	int EMERALDGREEN;
	int GOLD;
	int LIGHTGREEN;

	void Init() {
	
		RED = GetColor(255, 0, 0);
		GREEN = GetColor(0, 255, 255);
		BLUE = GetColor(0, 0, 255);
		WHITE = GetColor(255, 255, 255);
		BLACK = GetColor(0, 0, 0);
		MAGENTA = GetColor(255, 0, 224);
		EMERALDGREEN = GetColor(32, 192, 96);
		GOLD = GetColor(244, 192, 0);
		LIGHTGREEN = GetColor(128, 255, 128);
	
	}

};

Color colors;

/*関数設定*/
void drawText(int x, int y, const char* txt, int val, int siz, int col) {

	SetFontSize(BSIZE * siz / 100);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	
	x = x - strWidth / 2;
	y = y - BSIZE * siz / 100 / 2;

	DrawFormatString(x + 1, y + 2, colors.BLACK, txt, val);
	DrawFormatString(x, y, col, txt, val);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetWindowText("すごろく");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) {
	
		return -1;
	
	}

	int img[1] = {

		LoadGraph("BACK/TITLE_BACK.jpg")

	};

	colors.Init();

	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	int scene = TITLE;
	int timer = 0;

	while (ProcessMessage() == 0) {
	
		++timer;
		ClearDrawScreen();



		switch (scene) {
		
		case TITLE:
			
			DrawGraph(0, 0, img[0], FALSE);
			drawText(WIDTH / 2, HEIGHT * 0.33, "すごろく", 0, 100, colors.LIGHTGREEN);
			
			if (timer % 30 < 15) {
			
				drawText(WIDTH / 2, HEIGHT * 0.66, "「SPACE」キーを押してゲームスタート", 0, 50, colors.GOLD);
			
			}

			if (CheckHitKey(KEY_INPUT_SPACE)) {
			
				scene = PLAY;
			
			}

			break;

		}
	
		ScreenFlip();
		WaitTimer(FRAME_TIME);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {

			break;

		}
		
	}

	DxLib_End();
	return 0;

}