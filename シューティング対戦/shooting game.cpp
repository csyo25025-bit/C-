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
	int play_time = 0;
	int time;

	Fighter fighter[FIGHTER_MAX];
	Bullet bullet;

	bullet.active = false;

	fighter[0].init(BSIZE * 1.5, BSIZE * 1.5, 8, GREEN);
	fighter[1].init(BSIZE * 1.5, BSIZE * 1.5, 8, BLUE);

	while (ProcessMessage() == 0) {
	
		++timer;
		ClearDrawScreen();

		switch (scene) {

		case TITLE:

			drawText(WIDTH / 2, HEIGHT * 0.33, "SHOOTING GAME", 0, 100, EMERALDGREEN);

			if (timer % 30 < 15) {

				drawText(WIDTH / 2, HEIGHT * 0.66, "Press[SPACE]to start.", 0, 50, GOLD);

			}

			if (CheckHitKey(KEY_INPUT_SPACE)) {

				fighter[0].init(BSIZE * 1.5, BSIZE * 1.5, 8, GREEN);
				fighter[1].init(BSIZE * (COL - 1.5), BSIZE * (ROW - 1.5), 8, MAGENTA);

				bullet.active = false;

				play_time = 0;
				scene = PLAY;

			}

			break;

		case PLAY:

			++play_time;
			time = limittime - play_time / 30;

			drawText(WIDTH / 2, EDGE, "TIME:%d", time, 50, GOLD);

			for (int i = 0; i < FIGHTER_MAX; ++i) {
			
				if (i == 0) {

					fighter[i].move(FIGHTER_KEY[i]);

				}

				else if (i == 1) {

					fighter[i].enemymove();

				}

			}

			if (fighter[1].gethp() <= 0 || time <= 0)  {

				scene = OVER;
				timer = 0;

			}

			if (bullet.active) {

				bullet.x += bullet.vx;
				bullet.y += bullet.vy;

				int dx = fighter[1].getx() - bullet.x;
				int dy = fighter[1].gety() - bullet.y;

				if (dx * dx + dy * dy < (FIGHTER_SIZE + BALL_R) * (FIGHTER_SIZE + BALL_R)) {
				
					fighter[1].damage(10);
					bullet.active = false;
				
				}

				if (bullet.x<0 || bullet.x>WIDTH || bullet.y<0 || bullet.y>HEIGHT)  {

					bullet.active = false;

				}

			}

			if (CheckHitKey(KEY_INPUT_Z) == 1 && !bullet.active) {

				fighter[0].shoot(bullet);

			}

			break;

		case OVER:

			if (fighter[1].gethp() <= 0)  {
			
				drawText(WIDTH / 2, HEIGHT / 2, "あなたの勝利！", 0, 100, fighter[0].getCol());
			
			}
			
			else if (time <= 0)  {
			
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

		}

			int x = BSIZE * 3 + (WIDTH - BSIZE * 6) , y = BSIZE * 0.5;


			if (fighter[1].gethp() <= PLAYER_HP / 3) {

				drawText(x, y, "ENEMY_HP %d", fighter[1].gethp(), 60, RED);

			}

			else {

				drawText(x, y, "ENEMY_HP %d", fighter[1].gethp(), 60, fighter[1].getCol());

			}
		

		if (bullet.active) {

			DrawCircle((int)bullet.x, (int)bullet.y, BALL_R, WHITE, TRUE);

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
	this->speed = 0;
	this->hp = 100;

}

int Fighter::getCol() {

	return color;

}

int Fighter::gethp() {

	return hp;

}

int Fighter::getx() {

	return x;

}

int Fighter::gety() {

	return y;

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
	
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && CheckHitKey(KEY_INPUT_UP) == 1) {
		
		x += 10; 
		y -= 10;
		angle = 315;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1) {
	
		x += 10;
		y += 10;
		angle = 45;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && CheckHitKey(KEY_INPUT_UP) == 1) {
	
		x -= 10;
		y -= 10; 
		angle = 225;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1) {
	
		x -= 10; 
		y += 10;
		angle = 135;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
	
		x += 10; 
		angle = 0;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
	
		x -= 10;
		angle = 180;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_UP) == 1) {
	
		y -= 10;
		angle = 270;
	
	}
	
	else if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
	
		y += 10;
		angle = 90;
	
	}

	if (x < 0) { 
		
		x = WIDTH;
	
	}
	
	if (x > WIDTH) {
		
		x = 0;
	
	}
	
	if (y < EDGE - 1)  {
		
		y = HEIGHT;
	
	}
	
	if (y > HEIGHT) { 
		
		y = EDGE - 1;
	
	}

}

void Fighter::enemymove() {

	x += obj_vx;
	y += obj_vy;

	if (x < 0) {
	
		obj_vx = ENEMY_SPEED;

	}

	if (x > WIDTH) {
	
		obj_vx = -ENEMY_SPEED;
	
	}

	if (y < EDGE - 1)  {
	
		obj_vy = ENEMY_SPEED;
	
	}

	if (y > HEIGHT )  {
	
		obj_vy = -ENEMY_SPEED;
	
	}
	
}

void Fighter::shoot(Bullet& b) {

	b.x = x;
	b.y = y;

	b.vx = BULLET_SPEED * cos(M_PI * angle / 180.0);
	b.vy = BULLET_SPEED * sin(M_PI * angle / 180.0);

	b.active = true;

}

void Fighter::damage(int val) {

	hp = hp - val;

}