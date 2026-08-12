#include"DxLib.h"

using namespace std;

const unsigned int WIDTH = 960, HEIGHT = 640;
const unsigned int WHITE = 0xffffff;
const unsigned int BLUE = 0x0000ff;
const unsigned int RED = 0xff0000;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetWindowText("ゲーム開発のアルゴリズム");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) {

		return -1;

	}

	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	//赤い円の設定
	int rx = 0, ry = 0;
	const int RADIUS_R = 50;
	
	//青い円の設定
	int bx = WIDTH / 2, by = HEIGHT / 2;
	const int RADIUS_BX = 150;
	const int RADIUS_BY = 80;

	while (true) {

		ClearDrawScreen();

		int mouse_x, mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		rx = mouse_x;
		ry = mouse_y;

		unsigned int col = RED;

		double dx = rx - bx;
		double dy = ry - by;

		double scale_y = (double)RADIUS_BX / RADIUS_BY;
		double scaled_dy = dy * scale_y;

		double dist_sq = (dx * dx) + (scaled_dy * scaled_dy);

		double combined_radius = RADIUS_R + RADIUS_BX;

		if (dist_sq<=combined_radius*combined_radius) {

			col = WHITE;

		}

		DrawCircle(rx, ry, RADIUS_R, col, TRUE);
		DrawOval(bx, by, RADIUS_BX, RADIUS_BY, BLUE, TRUE);

		ScreenFlip();
		WaitTimer(33);

		if (ProcessMessage() == -1) {

			break;

		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {

			break;

		}

	}

	DxLib_End();
	return 0;

}