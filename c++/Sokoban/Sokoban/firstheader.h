// 공통적으로 사용되는 enum 자료형이나 define들을 모아놓는 헤더파일
#pragma once
#include <iostream>
#include <conio.h>

#define MAX_HEIGHT 10
#define MAX_WIDTH 10

extern int map[MAX_HEIGHT][MAX_WIDTH];

enum MAPTYPE
{
	EMPTY = 0,
	WALL,
	PLAYER,
	HOLE,
	BOX,
	HOLEWITHBOX,
	HOLEWITHPLAYER,
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

struct Position
{
	int x;
	int y;
};