#include"shooting game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetWindowText("シューティングゲーム");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) {
	
		return -1;

	}

	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	int scene = TITLE;
	int timer = 0;

	Fighter fighter[FIGHTER_MAX];

	fighter[0].init(BSIZE * 1.5, BSIZE * 1.5, 8, GREEN);
	fighter[1].init(BSIZE * 1.5, BSIZE * 1.5, 8, BLUE);

	while (ProcessMessage() == 0) {
	
		++timer;
		ClearDrawScreen();

		switch (scene) {
		
		case TITLE:

			drawText(WIDTH / 2, HEIGHT * 0.33, "SHOOTING GAME", 0, 100, EMERALDGREEN);

			if (timer % 30 < 15) {

				drawText(WIDTH / 2, HEIGHT * 0.66, "Press[G]to start.", 0, 50, GOLD);

			}

				if (CheckHitKey(KEY_INPUT_G)) {
				
					fighter[0].init(BSIZE * 1.5, BSIZE * 1.5, 8, GREEN);
					fighter[1].init(BSIZE * (COL - 1.5), BSIZE * (ROW - 1.5), 8, MAGENTA);

					scene = PLAY;

				}

				break;

		case PLAY:

			for (int i = 0; i < FIGHTER_MAX; ++i) {
			
				fighter[i].move(FIGHTER_KEY[i]);
			
			}

			if (fighter[0].gethp() <= 0 || fighter[1].gethp() <= 0) {
			
				scene = OVER;
				timer = 0;
			
			}

			break;

		case OVER:

			if (fighter[0].gethp() > fighter[1].gethp()) {
			
				drawText(WIDTH / 2, HEIGHT / 2, "あなたの勝利！", 0, 100, fighter[0].getCol());
			
			}
			else if (fighter[0].gethp() < fighter[1].gethp()) {
			
				drawText(WIDTH / 2, HEIGHT / 2, "あなたの負け", 0, 100, fighter[1].getCol());
			
			}
			else {
			
				drawText(WIDTH / 2, HEIGHT / 2, "引き分け", 0, 100, LILAC);
			
			}

			if (timer > FRAME_RATE * 7) {
			
				scene = TITLE;
			
			}

			break;
		
		}

		for (int i = 0; i < FIGHTER_MAX; ++i) {
		
			fighter[i].draw();

			int x = BSIZE * 3 + (WIDTH - BSIZE * 6) * i, y = BSIZE * 0.5;

			drawText(x, y, "PLAYER_HP %d", fighter[i].gethp(), 60, fighter[i].getCol());
		
		}

		ScreenFlip();
		WaitTimer(FRAME_RATE);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {

			break;

		}
	
	}

	DxLib_End();
	return 0;

}

void drawText(int x, int y, const char* txt, int val, int siz, int col) {

	SetFontSize(BSIZE * siz / 100);
	int strWidth = GetDrawStringWidth(txt, strlen(txt));
	x = x - strWidth / 2;
	y = y - BSIZE * siz / 100 / 2;

	DrawFormatString(x + 1, y + 2, BLACK, txt, val);
	DrawFormatString(x, y, col, txt, val);

}

void Fighter::init(int x, int y, int lr, int col) {

	this->x = x;
	this->y = y;
	this->lr = lr;
	this->color = col;
	this->angle = 0;
	this->speed = 0;
	this->hp = 100;

}

int Fighter::getCol() {

	return color;

}

int Fighter::gethp() {

	return hp;

}

void Fighter::draw() {

	int px[3], py[3];

	for (int i = 0; i < 3; ++i) {
	
		px[i] = x + (int)(FIGHTER_SIZE * cos(M_PI * (angle + 120 * i) / 180));
		py[i] = y + (int)(FIGHTER_SIZE * sin(M_PI * (angle + 120 * i) / 180));
	
	}

	for (int i = 0; i < 3; ++i) {
	
		DrawLine(px[i], py[i], px[(i + 1) % 3], py[(i + 1) % 3], color, FIGHTER_WIDTH);
	
	}

	DrawLine(x, y, px[0], py[0], WHITE, FIGHTER_WIDTH);

}

void Fighter::move(int key) {

	if (CheckHitKey(key)) {
	
		if (speed < SPEED) {
		
			++speed;
		
		}
	
	}

	else {
	
		angle = angle + lr;
		speed = speed * 0.9;
	
	}

	int px = x + speed * cos(M_PI * angle / 180);
	int py = y + speed * sin(M_PI * angle / 180);

}