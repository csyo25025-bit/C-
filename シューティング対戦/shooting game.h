#pragma once

#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>
#include"DxLib.h"

using namespace std;


const int FRAME_RATE = 30;
const int FRAME_TITLE = 1000 / FRAME_RATE;

const int COL = 15;
const int ROW = 9;
const int WIDTH = 960;
const int HEIGHT = 640;

const int BSIZE = 80;

enum { TITLE, PLAY, OVER };

/*色*/
const int RED = GetColor(255, 0, 0);
const int WHITE = GetColor(255, 255, 255);
const int BLACK = GetColor(0, 0, 0);
const int ORANGE = GetColor(255, 165, 0);
const int BLUE = GetColor(0, 0, 255);
const int GREEN = GetColor(0, 255, 0);
const int EMERALDGREEN = GetColor(32, 192, 96);
const int GOLD = GetColor(224, 192, 0);
const int MAGENTA = GetColor(255, 0, 224);
const int LILAC = GetColor(192, 128, 192);

/*ボール設定*/
const int BALL_R = 10;
const int BULLET_SPEED = 10;
const int BULLET_MAX = 10;

/*キャラ設定*/
const int PLAYER_HP = 100;
const int SPEED = 30;
const int FIGHTER_MAX = 2;
const int FIGHTER_KEY[] = { KEY_INPUT_X };
const int FIGHTER_SIZE = 30;
const int FIGHTER_WIDTH = 3;

/*敵設定*/
const int ENEMY_SPEED = 5;
int obj_x = WIDTH / 2, obj_y = HEIGHT / 2;
int obj_vx = ENEMY_SPEED, obj_vy = ENEMY_SPEED;
const int ENEMY_HP = 100;

/*関数宣言*/
void drawText(int x, int y, const char* txt, int val, int siz, int col);

struct Bullet {

public:

	double x, y;
	double vx, vy;
	bool active;

};

class Fighter {

private:

	int x;
	int y;
	int lr;
	int angle;
	int speed;
	int color;
	int hp;

public:

	void init(int x, int y, int lr, int col);
	int getCol();
	int gethp();
	void draw();
	void move(int key);
	void enemymove();
	void shoot(Bullet& b);

};