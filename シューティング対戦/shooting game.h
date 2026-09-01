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

enum { TITLE, PLAY, OVER };

/*色*/
const int RED = GetColor(255, 0, 0);
const int WHITE = GetColor(255, 255, 255);
const int BLACK = GetColor(0, 0, 0);
const int ORANGE = GetColor(255, 165, 0);

/*ボール設定*/
const int BALL_R = 10;

/*キャラ設定*/
const int HP = 100;
const int SPEED = 30;
const int FIGHTER_MAX = 2;
const int FIGHTER_KEY[] = { KEY_INPUT_X };
const int FIGHTER_SIZE = 30;
const int FIGHTER_WIDTH = 3;

/*関数宣言*/
void drawball();
void decreaseHP();
void drawText(int x, int y, const char* txt, int val, int siz, int col);

class Figter {

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
	int getCol;
	int gethp();
	void draw();
	void move(int key);

};
