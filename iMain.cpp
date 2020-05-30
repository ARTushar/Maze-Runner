# include "iGraphics.h"
int mposx,  mposy;
int width = 1400;
int height =800;
int mazeWidth1 = 25;
int mazeWidth2 = 25;
int mazeHeight1 = 25;
int mazeHeight2 = 25;
int map1CoordinateX[15][33];
int map1CoordinateY[15][33];
int map2CoordinateX[25][25];
int map2CoordinateY[25][25];
int map3CoordinateX[22][30];
int map3CoordinateY[22][30];
int map4CoordinateX[29][29];
int map4CoordinateY[29][29];
int startX1 = 150, startX2 = 265, startX3 = 150, startX4 = 150;
int startY1 = 550, startY2 = 680, startY3 = 680, startY4 = 720;
int runner1X, runner1Y, runner2X, runner2Y, runner3X, runner3Y, runner4X, runner4Y;
int xbefore, ybefore;
int runningSpeed = 5;
int a1, a2, a3, a4, b1, b2, b3, b4;
bool musicOn = true;
bool moveright1 = true, moveright2 = true, moveright3 = true, moveright4 = true, moveup2 = true, moveup3 = true, moveup4 = true;
bool done1 = true, done2 = true, done3 = true, done4 = true;
int mapArray1[15][33] =
{
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int mapArray2[25][25]=
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }

};
int mapArray3[22][30]=
{
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },
	{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
int mapArray4[29][29]=
{
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
char startVideo[1000][20]
{
	{ "Video\\001.bmp" }, { "Video\\002.bmp" }, { "Video\\003.bmp" }, { "Video\\004.bmp" }, { "Video\\005.bmp" },
	{ "Video\\006.bmp" }, { "Video\\007.bmp" }, { "Video\\008.bmp" }, { "Video\\009.bmp" }, { "Video\\010.bmp" },
	{ "Video\\011.bmp" }, { "Video\\012.bmp" }, { "Video\\013.bmp" }, { "Video\\014.bmp" },
	{ "Video\\015.bmp" }, { "Video\\016.bmp" }, { "Video\\017.bmp" }, { "Video\\018.bmp" }, { "Video\\019.bmp" },
	{ "Video\\020.bmp" }, { "Video\\021.bmp" }, { "Video\\022.bmp" }, { "Video\\023.bmp" }, { "Video\\024.bmp" },
	{ "Video\\025.bmp" }, { "Video\\026.bmp" }, { "Video\\027.bmp" }, { "Video\\028.bmp" }, { "Video\\029.bmp" },
	{ "Video\\030.bmp" }, { "Video\\031.bmp" }, { "Video\\032.bmp" }, { "Video\\033.bmp" }, { "Video\\034.bmp" },
	{ "Video\\035.bmp" }, { "Video\\036.bmp" }, { "Video\\037.bmp" }, { "Video\\038.bmp" }, { "Video\\039.bmp" },
	{ "Video\\040.bmp" }, { "Video\\041.bmp" }, { "Video\\042.bmp" }, { "Video\\043.bmp" }, { "Video\\044.bmp" },
	{ "Video\\045.bmp" }, { "Video\\046.bmp" }, { "Video\\047.bmp" }, { "Video\\048.bmp" }, { "Video\\049.bmp" },
	{ "Video\\050.bmp" }, { "Video\\051.bmp" }, { "Video\\052.bmp" }, { "Video\\053.bmp" }, { "Video\\054.bmp" },
	{ "Video\\055.bmp" }, { "Video\\056.bmp" }, { "Video\\057.bmp" }, { "Video\\058.bmp" }, { "Video\\059.bmp" },
	{ "Video\\060.bmp" }, { "Video\\061.bmp" }, { "Video\\062.bmp" }, { "Video\\063.bmp" }, { "Video\\064.bmp" },
	{ "Video\\065.bmp" }, { "Video\\066.bmp" }, { "Video\\067.bmp" }, { "Video\\068.bmp" }, { "Video\\069.bmp" },
	{ "Video\\070.bmp" }, { "Video\\071.bmp" }, { "Video\\072.bmp" }, { "Video\\073.bmp" }, { "Video\\074.bmp" },
	{ "Video\\075.bmp" }, { "Video\\076.bmp" }, { "Video\\077.bmp" }, { "Video\\078.bmp" }, { "Video\\079.bmp" }, { "Video\\080.bmp" }, { "Video\\081.bmp" }, { "Video\\082.bmp" }, { "Video\\083.bmp" }, { "Video\\084.bmp" }, { "Video\\085.bmp" }, { "Video\\086.bmp" }, { "Video\\087.bmp" }, { "Video\\088.bmp" }, { "Video\\089.bmp" }, { "Video\\090.bmp" }, { "Video\\091.bmp" }, { "Video\\092.bmp" }, { "Video\\093.bmp" }, { "Video\\094.bmp" }, { "Video\\095.bmp" }, { "Video\\096.bmp" }, { "Video\\097.bmp" }, { "Video\\098.bmp" }, { "Video\\099.bmp" }, { "Video\\100.bmp" }, { "Video\\101.bmp" }, { "Video\\103.bmp" }, { "Video\\104.bmp" }, { "Video\\105.bmp" }, { "Video\\106.bmp" }, { "Video\\107.bmp" }, { "Video\\108.bmp" }, { "Video\\109.bmp" }, { "Video\\110.bmp" }, { "Video\\111.bmp" }, { "Video\\112.bmp" }, { "Video\\113.bmp" }, { "Video\\114.bmp" }, { "Video\\115.bmp" }, { "Video\\116.bmp" }, { "Video\\117.bmp" }, { "Video\\118.bmp" }, { "Video\\118.bmp" }, { "Video\\119.bmp" }, { "Video\\120.bmp" }, { "Video\\121.bmp" }, { "Video\\122.bmp" }, { "Video\\123.bmp" }, { "Video\\124.bmp" }, { "Video\\125.bmp" }, { "Video\\126.bmp" }, { "Video\\127.bmp" }, { "Video\\128.bmp" }, { "Video\\129.bmp" }, { "Video\\130.bmp" }, { "Video\\131.bmp" }, { "Video\\132.bmp" }, { "Video\\133.bmp" }, { "Video\\134.bmp" }, { "Video\\135.bmp" }, { "Video\\136.bmp" }, { "Video\\137.bmp" }, { "Video\\138.bmp" }, { "Video\\139.bmp" }, { "Video\\140.bmp" }, { "Video\\141.bmp" }, { "Video\\142.bmp" }, { "Video\\143.bmp" }, { "Video\\144.bmp" }, { "Video\\145.bmp" }, { "Video\\146.bmp" }, { "Video\\147.bmp" }, { "Video\\148.bmp" }, { "Video\\149.bmp" }, { "Video\\150.bmp" }, { "Video\\151.bmp" }, { "Video\\152.bmp" }, { "Video\\153.bmp" }, { "Video\\154.bmp" }, { "Video\\155.bmp" }, { "Video\\156.bmp" }, { "Video\\157.bmp" }, { "Video\\158.bmp" }, { "Video\\159.bmp" }, { "Video\\160.bmp" }, { "Video\\161.bmp" }, { "Video\\162.bmp" }, { "Video\\163.bmp" }, { "Video\\164.bmp" }, { "Video\\165.bmp" }, { "Video\\166.bmp" }, { "Video\\167.bmp" }, { "Video\\168.bmp" }, { "Video\\169.bmp" }, { "Video\\170.bmp" }, { "Video\\171.bmp" }, { "Video\\172.bmp" }, { "Video\\173.bmp" }, { "Video\\174.bmp" }, { "Video\\175.bmp" }, { "Video\\176.bmp" }, { "Video\\177.bmp" }, { "Video\\178.bmp" }, { "Video\\179.bmp" }, { "Video\\180.bmp" }, { "Video\\181.bmp" }, { "Video\\182.bmp" }, { "Video\\183.bmp" }, { "Video\\184.bmp" }, { "Video\\185.bmp" }, { "Video\\186.bmp" }, { "Video\\187.bmp" }, { "Video\\188.bmp" }, { "Video\\189.bmp" }, { "Video\\190.bmp" }, { "Video\\191.bmp" }, { "Video\\192.bmp" }, { "Video\\193.bmp" }, { "Video\\194.bmp" }, { "Video\\195.bmp" }, { "Video\\196.bmp" }, { "Video\\197.bmp" }, { "Video\\198.bmp" }, { "Video\\199.bmp" }, { "Video\\200.bmp" }, { "Video\\201.bmp" }, { "Video\\202.bmp" }, { "Video\\203.bmp" }, { "Video\\204.bmp" }, { "Video\\205.bmp" }, { "Video\\206.bmp" }, { "Video\\207.bmp" }, { "Video\\208.bmp" }, { "Video\\209.bmp" }, { "Video\\210.bmp" }, { "Video\\211.bmp" }, { "Video\\212.bmp" }, { "Video\\213.bmp" }, { "Video\\214.bmp" }, { "Video\\215.bmp" }, { "Video\\216.bmp" }, { "Video\\217.bmp" }, { "Video\\218.bmp" }, { "Video\\219.bmp" }, { "Video\\220.bmp" }, { "Video\\221.bmp" }, { "Video\\222.bmp" }, { "Video\\223.bmp" }, { "Video\\224.bmp" }, { "Video\\225.bmp" }, { "Video\\226.bmp" }, { "Video\\227.bmp" }, { "Video\\228.bmp" }, { "Video\\229.bmp" }, { "Video\\230.bmp" }, { "Video\\231.bmp" }, { "Video\\232.bmp" }, { "Video\\233.bmp" }, { "Video\\234.bmp" }, { "Video\\235.bmp" }, { "Video\\236.bmp" }, { "Video\\237.bmp" }, { "Video\\238.bmp" }, { "Video\\239.bmp" }, { "Video\\240.bmp" }, { "Video\\241.bmp" }, { "Video\\242.bmp" }, { "Video\\243.bmp" }, { "Video\\244.bmp" }, { "Video\\245.bmp" }, { "Video\\246.bmp" }, { "Video\\247.bmp" }, { "Video\\248.bmp" }, { "Video\\249.bmp" }, { "Video\\250.bmp" }, { "Video\\251.bmp" }, { "Video\\252.bmp" }, { "Video\\253.bmp" }, { "Video\\254.bmp" }, { "Video\\255.bmp" }, { "Video\\256.bmp" }, { "Video\\257.bmp" }, { "Video\\258.bmp" }, { "Video\\259.bmp" }, { "Video\\260.bmp" }, { "Video\\261.bmp" }, { "Video\\262.bmp" }, { "Video\\263.bmp" }, { "Video\\264.bmp" }, { "Video\\265.bmp" }, { "Video\\266.bmp" }, { "Video\\267.bmp" }, { "Video\\268.bmp" }, { "Video\\269.bmp" }, { "Video\\270.bmp" }, { "Video\\271.bmp" }, { "Video\\272.bmp" }, { "Video\\273.bmp" }, { "Video\\274.bmp" }, { "Video\\275.bmp" }, { "Video\\276.bmp" }, { "Video\\277.bmp" }, { "Video\\278.bmp" }, { "Video\\279.bmp" }, { "Video\\280.bmp" }, { "Video\\281.bmp" }, { "Video\\282.bmp" }, { "Video\\283.bmp" }, { "Video\\284.bmp" }, { "Video\\285.bmp" }, { "Video\\286.bmp" }, { "Video\\287.bmp" }, { "Video\\288.bmp" }, { "Video\\289.bmp" }, { "Video\\290.bmp" }, { "Video\\291.bmp" }, { "Video\\292.bmp" }, { "Video\\293.bmp" }, { "Video\\294.bmp" }, { "Video\\295.bmp" }, { "Video\\296.bmp" }, { "Video\\297.bmp" }, { "Video\\298.bmp" }, { "Video\\299.bmp" }, { "Video\\300.bmp" }, { "Video\\301.bmp" }, { "Video\\302.bmp" }, { "Video\\303.bmp" }, { "Video\\304.bmp" }, { "Video\\305.bmp" }, { "Video\\306.bmp" }, { "Video\\307.bmp" }, { "Video\\308.bmp" }, { "Video\\309.bmp" }, { "Video\\310.bmp" }, { "Video\\311.bmp" }, { "Video\\312.bmp" }, { "Video\\313.bmp" }, { "Video\\314.bmp" }, { "Video\\315.bmp" }, { "Video\\316.bmp" }, { "Video\\317.bmp" }, { "Video\\318.bmp" }, { "Video\\319.bmp" }, { "Video\\320.bmp" }, { "Video\\321.bmp" }, { "Video\\322.bmp" }, { "Video\\323.bmp" }, { "Video\\324.bmp" }, { "Video\\325.bmp" }, { "Video\\326.bmp" }, { "Video\\327.bmp" }, { "Video\\328.bmp" }, { "Video\\329.bmp" }, { "Video\\330.bmp" }, { "Video\\331.bmp" }, { "Video\\332.bmp" }, { "Video\\333.bmp" }, { "Video\\334.bmp" }, { "Video\\335.bmp" }, { "Video\\336.bmp" }, { "Video\\337.bmp" }, { "Video\\338.bmp" }, { "Video\\339.bmp" }, { "Video\\340.bmp" }, { "Video\\341.bmp" }, { "Video\\342.bmp" }, { "Video\\343.bmp" }, { "Video\\344.bmp" }, { "Video\\345.bmp" }, { "Video\\346.bmp" }, { "Video\\347.bmp" }, { "Video\\348.bmp" }, { "Video\\349.bmp" }, { "Video\\350.bmp" }, { "Video\\351.bmp" }, { "Video\\352.bmp" }, { "Video\\353.bmp" }, { "Video\\354.bmp" }, { "Video\\355.bmp" }, { "Video\\356.bmp" }, { "Video\\357.bmp" }, { "Video\\358.bmp" }, { "Video\\359.bmp" }, { "Video\\360.bmp" }, { "Video\\361.bmp" }, { "Video\\362.bmp" }, { "Video\\363.bmp" }, { "Video\\364.bmp" }, { "Video\\365.bmp" }, { "Video\\366.bmp" }, { "Video\\367.bmp" }, { "Video\\368.bmp" }, { "Video\\369.bmp" }, { "Video\\370.bmp" }, { "Video\\371.bmp" }, { "Video\\372.bmp" }, { "Video\\373.bmp" }, { "Video\\374.bmp" }, { "Video\\375.bmp" }, { "Video\\376.bmp" }, { "Video\\377.bmp" }, { "Video\\378.bmp" }, { "Video\\379.bmp" }
};
int no;
int gameState =-2;
int limitTime[4] = { 60, 95, 105, 160 };
char name[50];
char times[10];
char timen[10];
char bg1[4][20] = { "image\\bg111.bmp", "image\\bg131.bmp", "image\\bg161.bmp", "image\\bg171.bmp" };
char bg2[4][20] = { "image\\bg112.bmp", "image\\bg132.bmp", "image\\bg162.bmp", "image\\bg172.bmp" };
char bg3[4][20] = { "image\\bg113.bmp", "image\\bg133.bmp", "image\\bg163.bmp", "image\\bg173.bmp" };
char bg4[4][20] = { "image\\bg114.bmp", "image\\bg134.bmp", "image\\bg164.bmp", "image\\bg174.bmp" };
typedef struct 
{
	char arrowup[2][30];
	char arrowdown[2][30];
	char arrowright[2][30];
	char arrowleft[2][30];
} Arrow;
Arrow arrow = { { { "image\\arrowup.bmp" }, { "image\\black.bmp" } }, { { "image\\arrowdown.bmp" }, { "image\\black.bmp" } }, { { "image\\arrowright.bmp" }, { "image\\black.bmp" } }, { { "image\\arrowleft.bmp" }, { "image\\black.bmp" } } };
typedef struct
{
	char nameS[20];
	int score;
	char scoreS[10];
} Score;
Score highScore[5];
typedef struct
{
	int x;
	int y;
	int enemyX;
	int enemyY;
} enemyCoordinate;
enemyCoordinate enemy4[16];
enemyCoordinate enemy3[10];
enemyCoordinate enemy2[10];
enemyCoordinate enemy1[8];
int ar = 0;
int index = 0;
char score[5][10];
int s[5][1];
int prevState = 0;
int prevState2 = 0;
int startCoordnate[4][2][1];
int picnum = 3;
int count;
bool inc = true;
FILE *fstr;
char *data = "HghScore.txt";

void scoreboard1()
{
		int d = (times[1] - '0') * 60 +( times[5] - '0')*10+times[6]-'0';
	    s[0][0] = 100 + d;
		score[0][2] = s[0][0] % 10 + '0';
		score[0][1] = (s[0][0] / 10) % 10 + '0';
		score[0][0] = (s[0][0] / 100) % 10 + '0';
		score[0][3] = '\0';

}
void scoreboard2()
{
	
		int d = (times[1] - '0') * 60 + (times[5] - '0') * 10 + times[6] - '0';
		s[1][0] = 150 + d*2;
		score[1][2] = s[1][0] % 10 + '0';
		score[1][1] = (s[1][0] / 10) % 10 + '0';
		score[1][0] = (s[1][0] / 100) % 10 + '0';
		score[1][3] = '\0';
}
void scoreboard3()
{
	
		int d = (times[1] - '0') * 60 + (times[5] - '0') * 10 + times[6] - '0';
		s[2][0] = 200 + d*3;
		score[2][2] = s[2][0] % 10 + '0';
		score[2][1] = (s[2][0] / 10) % 10 + '0';
		score[2][0] = (s[2][0] / 100) % 10 + '0';
		score[2][3] = '\0';

}
void scoreboard4()
{
		int d = (times[1] - '0') * 60 + (times[5] - '0') * 10 + times[6] - '0';
		s[3][0] = 250 + d*4;
		score[3][2] = s[3][0] % 10 + '0';
		score[3][1] = (s[3][0] / 10) % 10 + '0';
		score[3][0] = (s[3][0] / 100) % 10 + '0';
		score[3][3] = '\0';
	
}
void totalScore()
{
	s[4][0] = s[0][0] + s[1][0] + s[2][0] + s[3][0];
	printf("\n%d\n", s[4][0]);
	score[4][2] = s[4][0] % 10 + '0';
	score[4][1] = (s[4][0] / 10) % 10 + '0';
	score[4][0] = (s[4][0] / 100) % 10 + '0';
	score[4][3] = '\0';
}
void timeneed()
{
	int d = (times[1] - '0') * 60 + (times[5] - '0') * 10 + times[6] - '0';
	int t;
	if (prevState==1)
		t = limitTime[0] - d;
	else if (prevState==2)
		t = limitTime[1] - d;
	else if (prevState == 3)
		t = limitTime[2] - d;
	else if (prevState == 4)
		t = limitTime[3] - d;
	timen[0] = ' ';
	timen[2] = ' ';
	timen[3] = ':';
	timen[4] = ' ';
	
	 if(t<60){
		timen[1] = '0';
		timen[5] = '0' + t / 10;
		timen[6] = '0' + t % 10;
		timen[7] = '\0';
	}
	else if (t < 120)
	{
		timen[1] = '1';
		timen[5] = '0' + (t-60) / 10;
		timen[6] = '0' +(t-60) % 10;
		timen[7] = '\0';
	}
	else if (t < 180)
	{
		timen[1] = '2';
		timen[5] = '0' + (t - 120) / 10;
		timen[6] = '0' + (t - 120) % 10;
		timen[7] = '\0';
	}
}
void restart()
{
	runner1X = startCoordnate[0][0][0];
	runner1Y = startCoordnate[0][1][0];
	runner2X = startCoordnate[1][0][0];
	runner2Y = startCoordnate[1][1][0];
	runner3X = startCoordnate[2][0][0];
	runner3Y = startCoordnate[2][1][0];
	runner4X = startCoordnate[3][0][0];
	runner4Y = startCoordnate[3][1][0];
}
void clearScore()
{
	s[0][0] = 0;
	s[1][0] = 0;
	s[2][0] = 0;
	s[3][0] = 0;
	s[4][0] = 0;
}
void clearname()
{
	name[0] =0;
	index = 0;
}
void sortS(Score a[], int n)
{

	int i, j;
	for (i = 0; i<n-1; i++)
		for (j = i + 1; j < n; j++){
			if (a[j].score > a[i].score){
				Score temp;
				strcpy_s(temp.nameS, a[i].nameS);
				temp.score = a[i].score;
				strcpy_s(temp.scoreS, a[i].scoreS);

				strcpy_s(a[i].nameS, a[j].nameS);
				a[i].score = a[j].score;
				strcpy_s(a[i].scoreS, a[j].scoreS);

				strcpy_s(a[j].nameS, temp.nameS);
				a[j].score = temp.score;
				strcpy_s(a[j].scoreS, temp.scoreS);
			}
		}
}
void saveScore()
{
	if (count < 5){
		strcpy_s(highScore[count].nameS, name);
		highScore[count].score = s[4][0];
		strcpy_s(highScore[count].scoreS, score[4]);
		if (inc)
		count++;
		sortS(highScore, count);
	}
	else
	{
		sortS(highScore, 5);
		if (s[4][0]>highScore[4].score){
			strcpy_s(highScore[4].nameS, name);
			highScore[4].score = s[4][0];
			strcpy_s(highScore[4].scoreS, score[4]);
			count = 5;
			sortS(highScore, 5);
		}
	}
	
}
void drawMaze1(){
	int counter,newCounter;
	for (counter = 0; counter < 15; counter++){
		for (newCounter = 0; newCounter < 33; newCounter++){
			if (mapArray1[counter][newCounter] == 1){
				iShowBMP2(map1CoordinateX[counter][newCounter], map1CoordinateY[counter][newCounter], "Image\\bricks6.bmp",0);
			}
		}
	}
}
void drawMaze2(){
	int counter, newCounter;
	for (counter = 0; counter < 25; counter++){
		for (newCounter = 0; newCounter < 25; newCounter++){
			if (mapArray2[counter][newCounter] == 1){
				iShowBMP2(map2CoordinateX[counter][newCounter], map2CoordinateY[counter][newCounter], "Image\\bricks6.bmp",0);
			}
		}
	}
}
void drawMaze3()
{
	int counter, newCounter;
	for (counter = 0; counter < 22; counter++){
		for (newCounter = 0; newCounter < 30; newCounter++){
			if (mapArray3[counter][newCounter] == 1){
				iShowBMP2(map3CoordinateX[counter][newCounter], map3CoordinateY[counter][newCounter], "Image\\bricks6.bmp", 0);
			}
		}
	}
}
void drawMaze4()
{
	int counter, newCounter;
	for (counter = 0; counter < 29; counter++){
		for (newCounter = 0; newCounter < 29; newCounter++){
			if (mapArray4[counter][newCounter] == 1){
				iShowBMP2(map4CoordinateX[counter][newCounter], map4CoordinateY[counter][newCounter], "Image\\bricks6.bmp", 0);
			}
		}
	}
}
void assignCoordinate1()
{
	int i, j;
	int dx = startX1, dy = startY1;
	for (i = 0; i < 15; i++){
		for (j = 0; j < 33; j++){
			map1CoordinateX[i][j] = dx;
			map1CoordinateY[i][j] = dy;
			dx += mazeWidth1;
		}
		dx = startX1;
		dy -= mazeHeight1;
	}
}
void assignCoordinate2()
{
	int dx = startX2, dy = startY2, i, j;
	for (i = 0; i < 25; i++){
		for (j = 0; j < 25; j++){
			map2CoordinateX[i][j] = dx;
			map2CoordinateY[i][j] = dy;
			dx += mazeWidth2;
		}
		dx = startX2;
		dy -= mazeHeight2;
	}
}
void assignCoordinate3()
{
	int dx = startX3, dy = startY3, i, j;
	for (i = 0; i < 22; i++){
		for (j = 0; j < 30; j++){
			map3CoordinateX[i][j] = dx;
			map3CoordinateY[i][j] = dy;
			dx += mazeWidth2;
		}
		dx = startX3;
		dy -= mazeHeight2;
	}
}
void assignCoordinate4()
{
	int dx = startX4, dy = startY4, i,j;
	for (i = 0; i < 29; i++){
		for (j = 0; j < 29; j++){
			map4CoordinateX[i][j] = dx;
			map4CoordinateY[i][j] = dy;
			dx += mazeWidth2;
		}
		dx = startX3;
		dy -= mazeHeight2;
	}
}
void assignEnemyCoordinate()
{
	enemy4[0].x = map4CoordinateX[27][21], enemy4[0].y = map4CoordinateY[27][21], enemy4[0].enemyX = enemy4[0].x, enemy4[0].enemyY = enemy4[0].y;
	enemy4[1].x = map4CoordinateX[19][15], enemy4[1].y = map4CoordinateY[19][15], enemy4[1].enemyX = enemy4[1].x, enemy4[1].enemyY = enemy4[1].y;
	enemy4[2].x = map4CoordinateX[23][17], enemy4[2].y = map4CoordinateY[23][17], enemy4[2].enemyX = enemy4[2].x, enemy4[2].enemyY = enemy4[2].y;
	enemy4[3].x = map4CoordinateX[23][9], enemy4[3].y = map4CoordinateY[23][9], enemy4[3].enemyX = enemy4[3].x, enemy4[3].enemyY = enemy4[3].y;
	enemy4[4].x = map4CoordinateX[27][11], enemy4[4].y = map4CoordinateY[27][11], enemy4[4].enemyX = enemy4[4].x, enemy4[4].enemyY = enemy4[4].y;
	enemy4[5].x = map4CoordinateX[13][7], enemy4[5].y = map4CoordinateY[13][7], enemy4[5].enemyX = enemy4[5].x, enemy4[5].enemyY = enemy4[5].y;
	enemy4[6].x = map4CoordinateX[5][11], enemy4[6].y = map4CoordinateY[5][11], enemy4[6].enemyX = enemy4[6].x, enemy4[6].enemyY = enemy4[6].y;
	enemy4[7].x = map4CoordinateX[9][17], enemy4[7].y = map4CoordinateY[9][17], enemy4[7].enemyX = enemy4[7].x, enemy4[7].enemyY = enemy4[7].y;
	enemy4[8].x = map4CoordinateX[13][11], enemy4[8].y = map4CoordinateY[13][11], enemy4[8].enemyX = enemy4[8].x, enemy4[8].enemyY = enemy4[8].y;
	enemy4[9].x = map4CoordinateX[13][15], enemy4[9].y = map4CoordinateY[13][15], enemy4[9].enemyX = enemy4[9].x, enemy4[9].enemyY = enemy4[9].y;
	enemy4[10].x = map4CoordinateX[22][25], enemy4[10].y = map4CoordinateY[22][25], enemy4[10].enemyX = enemy4[10].x, enemy4[10].enemyY = enemy4[10].y;
	enemy4[11].x = map4CoordinateX[13][23], enemy4[11].y = map4CoordinateY[13][23], enemy4[11].enemyX = enemy4[11].x, enemy4[11].enemyY = enemy4[11].y;
	enemy4[12].x = map4CoordinateX[3][23], enemy4[12].y = map4CoordinateY[3][23], enemy4[12].enemyX = enemy4[12].x, enemy4[12].enemyY = enemy4[12].y;
	enemy4[13].x = map4CoordinateX[5][19], enemy4[13].y = map4CoordinateY[5][19], enemy4[13].enemyX = enemy4[13].x, enemy4[13].enemyY = enemy4[13].y;
	enemy4[14].x = map4CoordinateX[1][11], enemy4[14].y = map4CoordinateY[1][11], enemy4[14].enemyX = enemy4[14].x, enemy4[14].enemyY = enemy4[14].y;
	enemy4[15].x = map4CoordinateX[2][1], enemy4[15].y = map4CoordinateY[2][1], enemy4[15].enemyX = enemy4[15].x, enemy4[15].enemyY = enemy4[15].y;


	enemy3[0].x = map3CoordinateX[19][19], enemy3[0].y = map3CoordinateY[19][19], enemy3[0].enemyX = enemy3[0].x, enemy3[0].enemyY = enemy3[0].y;
	enemy3[1].x = map3CoordinateX[20][16], enemy3[1].y = map3CoordinateY[20][16], enemy3[1].enemyX = enemy3[1].x, enemy3[1].enemyY = enemy3[1].y;
	enemy3[2].x = map3CoordinateX[20][4], enemy3[2].y = map3CoordinateY[20][4], enemy3[2].enemyX = enemy3[2].x, enemy3[2].enemyY = enemy3[2].y;
	enemy3[3].x = map3CoordinateX[15][6], enemy3[3].y = map3CoordinateY[15][6], enemy3[3].enemyX = enemy3[3].x, enemy3[3].enemyY = enemy3[3].y;
	enemy3[4].x = map3CoordinateX[10][11], enemy3[4].y = map3CoordinateY[10][11], enemy3[4].enemyX = enemy3[4].x, enemy3[4].enemyY = enemy3[4].y;
	enemy3[5].x = map3CoordinateX[15][13], enemy3[5].y = map3CoordinateY[15][13], enemy3[5].enemyX = enemy3[5].x, enemy3[5].enemyY = enemy3[5].y;
	enemy3[6].x = map3CoordinateX[10][26], enemy3[6].y = map3CoordinateY[10][26], enemy3[6].enemyX = enemy3[6].x, enemy3[6].enemyY = enemy3[6].y;
	enemy3[7].x = map3CoordinateX[4][11], enemy3[7].y = map3CoordinateY[4][11], enemy3[7].enemyX = enemy3[7].x, enemy3[7].enemyY = enemy3[7].y;
	enemy3[8].x = map3CoordinateX[1][4], enemy3[8].y = map3CoordinateY[1][4], enemy3[8].enemyX = enemy3[8].x, enemy3[8].enemyY = enemy3[8].y;
	enemy3[9].x = map3CoordinateX[1][1], enemy3[9].y = map3CoordinateY[1][1], enemy3[9].enemyX = enemy3[9].x, enemy3[9].enemyY = enemy3[9].y;


	enemy2[0].x = map2CoordinateX[23][15], enemy2[0].y = map2CoordinateY[23][15], enemy2[0].enemyX = enemy2[0].x, enemy2[0].enemyY = enemy2[0].y;
	enemy2[1].x = map2CoordinateX[19][11], enemy2[1].y = map2CoordinateY[19][11], enemy2[1].enemyX = enemy2[1].x, enemy2[1].enemyY = enemy2[1].y;
	enemy2[2].x = map2CoordinateX[15][5], enemy2[2].y = map2CoordinateY[15][5], enemy2[2].enemyX = enemy2[2].x, enemy2[2].enemyY = enemy2[2].y;
	enemy2[3].x = map2CoordinateX[1][11], enemy2[3].y = map2CoordinateY[1][11], enemy2[3].enemyX = enemy2[3].x, enemy2[3].enemyY = enemy2[3].y;
	enemy2[4].x = map2CoordinateX[9][13], enemy2[4].y = map2CoordinateY[9][13], enemy2[4].enemyX = enemy2[4].x, enemy2[4].enemyY = enemy2[4].y;
	enemy2[5].x = map2CoordinateX[9][21], enemy2[5].y = map2CoordinateY[9][21], enemy2[5].enemyX = enemy2[5].x, enemy2[5].enemyY = enemy2[5].y;
	enemy2[6].x = map2CoordinateX[7][23], enemy2[6].y = map2CoordinateY[7][23], enemy2[6].enemyX = enemy2[6].x, enemy2[6].enemyY = enemy2[6].y;
	enemy2[7].x = map2CoordinateX[1][19], enemy2[7].y = map2CoordinateY[1][19], enemy2[7].enemyX = enemy2[7].x, enemy2[7].enemyY = enemy2[7].y;
	enemy2[8].x = map2CoordinateX[3][23], enemy2[8].y = map2CoordinateY[3][23], enemy2[8].enemyX = enemy2[8].x, enemy2[8].enemyY = enemy2[8].y;


	enemy1[0].x = map1CoordinateX[13][21], enemy1[0].y = map1CoordinateY[13][21], enemy1[0].enemyX = enemy1[0].x, enemy1[0].enemyY = enemy1[0].y;
	enemy1[1].x = map1CoordinateX[9][24], enemy1[1].y = map1CoordinateY[9][24], enemy1[1].enemyX = enemy1[1].x, enemy1[1].enemyY = enemy1[1].y;
	enemy1[2].x = map1CoordinateX[13][8], enemy1[2].y = map1CoordinateY[13][8], enemy1[2].enemyX = enemy1[2].x, enemy1[2].enemyY = enemy1[2].y;
	enemy1[3].x = map1CoordinateX[9][12], enemy1[3].y = map1CoordinateY[9][12], enemy1[3].enemyX = enemy1[3].x, enemy1[3].enemyY = enemy1[3].y;
	enemy1[4].x = map1CoordinateX[9][3], enemy1[4].y = map1CoordinateY[9][3], enemy1[4].enemyX = enemy1[4].x, enemy1[4].enemyY = enemy1[4].y;
	enemy1[5].x = map1CoordinateX[3][22], enemy1[5].y = map1CoordinateY[3][22], enemy1[5].enemyX = enemy1[5].x, enemy1[5].enemyY = enemy1[5].y;
	enemy1[6].x = map1CoordinateX[3][26], enemy1[6].y = map1CoordinateY[3][26], enemy1[6].enemyX = enemy1[6].x, enemy1[6].enemyY = enemy1[6].y;
	enemy1[7].x = map1CoordinateX[1][26], enemy1[7].y = map1CoordinateY[1][26], enemy1[7].enemyX = enemy1[7].x, enemy1[7].enemyY = enemy1[7].y;


}
void savePosition()
{
	runner1X = map1CoordinateX[14][32] + 5;
	startCoordnate[0][0][0] = runner1X;
	runner1Y = map1CoordinateY[13][32] + 5;
	startCoordnate[0][1][0] = runner1Y;
	runner2X = map2CoordinateX[24][24] + 5;
	startCoordnate[1][0][0] = runner2X;
	runner2Y = map2CoordinateY[23][24] + 5;
	startCoordnate[1][1][0] = runner2Y;
	runner3X = map3CoordinateX[18][26] + 5;
	startCoordnate[2][0][0] = runner3X;
	runner3Y = map3CoordinateY[17][26] + 5;
	startCoordnate[2][1][0] = runner3Y;
	runner4X = map4CoordinateX[27][27] + 10;
	startCoordnate[3][0][0] = runner4X;
	runner4Y = map4CoordinateY[27][27] + 5;
	startCoordnate[3][1][0] = runner4Y;
}
void restartEnemy()
{
	moveright1 = true;
	moveright2 = true;
	moveright3 = true;
	moveright4 = true;
	moveup2 = true;
	moveup3 = true;
	moveup4 = true;
	done1 = true;
	done2 = true;
	done3 = true;
	done4 = true;
	
	for (int i = 0; i < 16; i++)
	{
		enemy4[i].x = enemy4[i].enemyX, enemy4[i].y = enemy4[i].enemyY;
	}
	for (int i = 0; i < 10; i++)
	{
		enemy3[i].x = enemy3[i].enemyX, enemy3[i].y = enemy3[i].enemyY;
	}
	for (int i = 0; i < 9; i++)
	{
		enemy2[i].x = enemy2[i].enemyX, enemy2[i].y = enemy2[i].enemyY;
	}
	for (int i = 0; i < 8; i++)
	{
		enemy1[i].x = enemy1[i].enemyX, enemy1[i].y = enemy1[i].enemyY;
	}
}
void readfile(Score high[])
{
	int i,n;
	fscanf(fstr, " %d", &count);
	n = count;
	for (i = 0; i < n; i++)
	{
		fscanf(fstr, " %[^\n]", high[i].nameS);
		fscanf(fstr, " %d", &high[i].score);
		fscanf(fstr, " %s", high[i].scoreS);
	}
}
void writefile(Score high[])
{
	int i,n;
	n = count;
	fprintf(fstr, "%d\n", count);
	for (i = 0; i < n; i++)
	{
		fprintf(fstr, "%s\n", high[i].nameS);
		fprintf(fstr, "%d\n", high[i].score);
		fprintf(fstr, "%s\n", high[i].scoreS);
	}
}
void iDraw()
{
	iClear();
	if (gameState == -2){
		iShowBMP(0, 0, startVideo[no]);
		if (no ==  378)
			gameState = -1;
	}

	else if (gameState==-1){
		clearScore();
		clearname();
		restartEnemy();
		inc = true;
		iShowBMP(0, 0, "image\\bg2.bmp");
	
		iShowBMP(520, 453, "image\\button.bmp");
		iShowBMP(520, 383, "image\\button.bmp");
		iShowBMP(520, 313, "image\\button.bmp");
		iShowBMP(520, 248, "image\\button.bmp");
		iShowBMP(520, 180, "image\\button.bmp");
		iShowBMP(1200, 60, "image\\button.bmp");
			

	}
	else if (gameState == 5)
	{
		iShowBMP(0,0, "image\\name5.bmp");
		iSetColor(255, 255, 128);
		iText(490, 470, name, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(gameState==1){
		iShowBMP(0,0, bg1[picnum]);
		drawMaze1();
		iShowBMP2(1110, 500, "image\\name2.bmp",0);
		iShowBMP2(1110, 400, "image\\time.bmp",0);
		iSetColor(255, 255, 128);
		iText(1225, 510, name,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1300, 415, times, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 128);
		iFilledCircle(runner1X, runner1Y, 5);
		if (mapArray1[((startY1 - runner1Y) / (mazeHeight1)+1)][(runner1X - startX1) / mazeWidth1+1] == 0  )
			iShowBMP2(runner1X+5, runner1Y-5, arrow.arrowright[ar], 0);
		if (mapArray1[((startY1 - runner1Y) / (mazeHeight1)+1)][(runner1X - startX1) / mazeWidth1 - 1] == 0)
			iShowBMP2(runner1X - 25, runner1Y - 5, arrow.arrowleft[ar], 0);
		if (mapArray1[((startY1 - runner1Y) / (mazeHeight1))][(runner1X - startX1) / mazeWidth1 ] == 0)
			iShowBMP2(runner1X - 7, runner1Y + 5, arrow.arrowup[ar], 0);
		if (mapArray1[((startY1 - runner1Y) / (mazeHeight1)+2)][(runner1X - startX1) / mazeWidth1] == 0)
			iShowBMP2(runner1X - 6, runner1Y - 25, arrow.arrowdown[ar], 0);

		for (int i = 0; i < 8; i++)
		{
			if (i == 1)
				continue;
			iShowBMP(enemy1[i].x, enemy1[i].y, "image\\bricks6.bmp");
			if (runner1X >= enemy1[i].x && runner1X <= enemy1[i].x + 25 && runner1Y >= enemy1[i].y && runner1Y <= enemy1[i].y + 25)
			{
				if (musicOn){
					PlaySound(0, 0, 0);
					PlaySound("music\\fail.wav", NULL, SND_ASYNC);
				}
				gameState = 18;
			}
		}
	}
	else if (gameState == 6)
	{
		iShowBMP(0, 0, "image\\level1done.bmp");
		scoreboard1();
		timeneed();
		iSetColor(255, 255, 128);
		iText(615, 445, timen,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(615, 360, score[0], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == 2){
		iShowBMP(0, 0, bg2[picnum]);
		drawMaze2();
		iShowBMP2(1110, 500, "image\\name2.bmp", 0);
		iShowBMP2(1110, 400, "image\\time.bmp", 0);
		iSetColor(255, 255, 128);
		iText(1225, 510, name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1300, 415, times, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 128);

		iFilledCircle(runner2X, runner2Y, 5);
		if (mapArray2[((startY2 - runner2Y) / (mazeHeight2)+1)][(runner2X - startX2) / mazeWidth2 + 1] == 0)
			iShowBMP2(runner2X + 5, runner2Y - 5, arrow.arrowright[ar], 0);
		if (mapArray2[((startY2 - runner2Y) / (mazeHeight2)+1)][(runner2X - startX2) / mazeWidth2 - 1] == 0)
			iShowBMP2(runner2X - 25, runner2Y - 5, arrow.arrowleft[ar], 0);
		if (mapArray2[((startY2 - runner2Y) / (mazeHeight2))][(runner2X - startX2) / mazeWidth2] == 0)
			iShowBMP2(runner2X - 7, runner2Y + 5, arrow.arrowup[ar], 0);
		if (mapArray2[((startY2 - runner2Y) / (mazeHeight2)+2)][(runner2X - startX2) / mazeWidth2] == 0)
			iShowBMP2(runner2X - 6, runner2Y - 25, arrow.arrowdown[ar], 0);

		for (int i = 0; i < 9; i++)
		{
			if (i == 2 || i == 4)
				continue;
			iShowBMP(enemy2[i].x, enemy2[i].y, "image\\bricks6.bmp");
			if (runner2X >= enemy2[i].x && runner2X <= enemy2[i].x + 25 && runner2Y >= enemy2[i].y && runner2Y <= enemy2[i].y + 25)
			{
				if (musicOn){
					PlaySound(0, 0, 0);
					PlaySound("music\\fail.wav", NULL, SND_ASYNC);
				}
				gameState = 18;
			}
		}
	}
	else if (gameState == 7)
	{
		iShowBMP(0, 0, "image\\level2done.bmp");
		scoreboard2();
		timeneed();
		iSetColor(255, 255, 128);
		iText(615, 445, timen, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(615, 360, score[1], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == 3)
	{
		iShowBMP(0, 0, bg3[picnum]);
		drawMaze3();
		iShowBMP2(1110, 500, "image\\name2.bmp", 0);
		iShowBMP2(1110, 400, "image\\time.bmp", 0);
		iSetColor(255, 255, 128);
		iText(1225, 510, name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1300, 415, times, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 128);
		iFilledCircle(runner3X, runner3Y, 5);
		if (mapArray3[((startY3 - runner3Y) / (mazeHeight2)+1)][(runner3X - startX3) / mazeWidth2 + 1] == 0)
			iShowBMP2(runner3X + 5, runner3Y - 5, arrow.arrowright[ar], 0);
		if (mapArray3[((startY3 - runner3Y) / (mazeHeight2)+1)][(runner3X - startX3) / mazeWidth2 - 1] == 0)
			iShowBMP2(runner3X - 25, runner3Y - 5, arrow.arrowleft[ar], 0);
		if (mapArray3[((startY3 - runner3Y) / (mazeHeight2))][(runner3X - startX3) / mazeWidth2] == 0)
			iShowBMP2(runner3X - 7, runner3Y + 5, arrow.arrowup[ar], 0);
		if (mapArray3[((startY3 - runner3Y) / (mazeHeight2)+2)][(runner3X - startX3) / mazeWidth2] == 0)
			iShowBMP2(runner3X - 6, runner3Y - 25, arrow.arrowdown[ar], 0);
		for (int i = 0; i < 10; i++)
		{
			if (i == 2 || i==4)
				continue;
			iShowBMP(enemy3[i].x, enemy3[i].y, "image\\bricks6.bmp");
			if (runner3X >= enemy3[i].x && runner3X <= enemy3[i].x + 25 && runner3Y >= enemy3[i].y && runner3Y <= enemy3[i].y + 25)
			{
				if (musicOn){
					PlaySound(0, 0, 0);
					PlaySound("music\\fail.wav", NULL, SND_ASYNC);
				}
				gameState = 18;
			}
		}
	}
	else if (gameState == 8)
	{

		iShowBMP(0, 0, "image\\level3done.bmp");
		scoreboard3();
		timeneed();
		iSetColor(255, 255, 128);
		iText(615, 445, timen, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(615, 360, score[2], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == 4)
	{
		iShowBMP(0, 0, bg4[picnum]);
		drawMaze4();
		iShowBMP2(1110, 500, "image\\name2.bmp", 0);
		iShowBMP2(1110, 400, "image\\time.bmp", 0);
		iSetColor(255, 255, 128);
		iText(1225, 510, name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1300, 415, times, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 128);
		iFilledCircle(runner4X, runner4Y, 5);
		if (mapArray4[((startY4 - runner4Y) / (mazeHeight2)+1)][(runner4X - startX4) / mazeWidth2 + 1] == 0)
			iShowBMP2(runner4X + 5, runner4Y - 5, arrow.arrowright[ar], 0);
		if (mapArray4[((startY4 - runner4Y) / (mazeHeight2)+1)][(runner4X - startX4) / mazeWidth2 - 1] == 0)
			iShowBMP2(runner4X - 25, runner4Y - 5, arrow.arrowleft[ar], 0);
		if (mapArray4[((startY4 - runner4Y) / (mazeHeight2))][(runner4X - startX4) / mazeWidth2] == 0)
			iShowBMP2(runner4X - 7, runner4Y + 5, arrow.arrowup[ar], 0);
		if (mapArray4[((startY4 - runner4Y) / (mazeHeight2)+2)][(runner4X - startX4) / mazeWidth2] == 0)
			iShowBMP2(runner4X - 6, runner4Y - 25, arrow.arrowdown[ar], 0);

		for (int i = 0; i < 16; i++)
		{
			if (i == 1 || i == 7)
				continue;
			iShowBMP(enemy4[i].x, enemy4[i].y, "image\\bricks6.bmp");
			if (runner4X >= enemy4[i].x && runner4X <= enemy4[i].x + 25 && runner4Y >= enemy4[i].y && runner4Y <= enemy4[i].y + 25)
			{
				if (musicOn){
					PlaySound(0, 0, 0);
					PlaySound("music\\fail.wav", NULL, SND_ASYNC);
				}
				gameState = 18;
			}
		}
	}
	else if (gameState == 10)
	{
		iShowBMP(0, 0, "image\\level4done.bmp");
		scoreboard4();
		timeneed();
		iSetColor(255, 255, 128);
		iText(615, 445, timen, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(615, 360, score[3], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	else if (gameState==13)
	{
		iShowBMP(0, 0, "image\\leveldone.bmp");
		iSetColor(255, 255, 128);
		iText(750, 328, score[4],GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == 9)
	{
		iShowBMP(0, 0, "image\\continue.bmp");
		iShowBMP(570, 505, "image\\button.bmp");
		iShowBMP(570, 425, "image\\button.bmp");
		iShowBMP(570, 340, "image\\button.bmp");
	}
	else if (gameState == 14)
	{
		iShowBMP(0, 0, "image\\gameover.bmp");
		if (inc == true){
			totalScore();
			saveScore();
			fstr = fopen(data, "w");
			if (fstr != 0){
				writefile(highScore);
				fclose(fstr);
			}
		}
		inc = false;
		iSetColor(255, 255, 128);
		iText(740, 380, score[4], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == 16)
	{
		iShowBMP(0, 0, "image\\highscore.bmp");
		int i,a,b;
		a = 300, b = 490;
		iSetColor(255, 255, 128);
		for (i = 0; i < count; i++)
		{
			iText(a, b, highScore[i].nameS, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(a + 770, b, highScore[i].scoreS, GLUT_BITMAP_TIMES_ROMAN_24);
			b -= 80;
		}

	}
	else if (gameState == 11)
	{
		iShowBMP(0, 0, "image\\settings.bmp");
		iShowBMP(390, 510, "image\\button.bmp");
		iShowBMP(390, 410, "image\\button.bmp");
		iShowBMP(390, 320, "image\\button.bmp");
		if (musicOn)
			iShowBMP2(670, 515, "image\\click.bmp", 0);
		else
			iShowBMP2(670, 400, "image\\click.bmp", 0);

	}
	else if (gameState == 15)
	{
		iShowBMP(0, 0, "image\\selectbg.bmp");

		iShowBMP(300, 400, "image\\changebg1.bmp");
		iShowBMP(800, 400, "image\\changebg2.bmp");
		iShowBMP(300, 100, "image\\changebg3.bmp");
		iShowBMP(800, 100, "image\\changebg4.bmp");

		if (picnum == 0)
			iShowBMP2(350, 450, "image\\click.bmp",0);
		else if (picnum == 1)
			iShowBMP2(850, 450, "image\\click.bmp",0);
		else if (picnum == 2)
			iShowBMP2(350, 150, "image\\click.bmp", 0);
		else if (picnum == 3)
			iShowBMP2(850, 150, "image\\click.bmp", 0);
	}
	else if (gameState == 12)
	{
		iShowBMP(0, 0, "image\\credits.bmp");
	}
	else if (gameState == 17)
	{
		iShowBMP(0, 0, "image\\quit.bmp");
	}
	else if (gameState == 18)
	{
		iShowBMP(0, 0, "image\\collision.bmp");
		totalScore();
		if (inc){
			saveScore();
			fstr = fopen(data, "w");
			writefile(highScore);
			fclose(fstr);
		}
		inc = false;
		iSetColor(255, 255, 128);
		iText(690, 345, score[4], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == 19)
	{
		iShowBMP(0, 0, "image\\rules.bmp");
	}
	
}


void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{

	if (gameState == -1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 520 && mx <= 550 && my <= 483 && my >= 453)
				gameState = 5;
			else if (mx > 520 && mx < 550 && my>383 && my < 413)
				gameState = 16;
			else if (mx > 520 && mx < 550 && my>313 && my < 343)
				gameState = 11, prevState=-1;
			else if (mx > 520 && mx < 550 && my>248 && my < 278)
				gameState = 12;
			else if (mx > 520 && mx < 550 && my>180 && my < 210)
				gameState = 17, prevState = -1;
			else if (mx > 1200 && mx < 1230 && my>60 && my < 90)
				gameState = 19;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
	if (gameState == 9)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx > 570 && mx < 600 && my>505 && my < 535){
				gameState = prevState;
				if (musicOn){
					PlaySound("music\\bg.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			else if (mx > 570 && mx < 600 && my>425 && my < 455)
				gameState = 11,prevState2=9;
			else if (mx > 570 && mx < 600 && my>340 && my < 370){
				restart();
				gameState = -1,prevState=0;
				if (musicOn){
					PlaySound("music\\main.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}

	}
	if (gameState == 12)
	{
		if (mx > 1165 && mx < 1280 && my> 150 && my < 180)
			gameState = -1;
	}
	if (gameState == 11)
	{
		if (mx > 1205 && mx < 1315 && my>100 && my < 120){
			if (prevState == -1)
				gameState = prevState;
			else
				gameState = prevState2;
		}
		else if (mx > 390 && mx < 420 && my>410 && my < 440)
		{
			PlaySound(0, 0, 0);
			musicOn = false;
		}
		else if (mx > 390 && mx < 420 && my>510 && my < 540)
		{
			musicOn = true;
			if (prevState == -1)
				PlaySound("music\\main.wav", NULL, SND_LOOP | SND_ASYNC);
			else 
				PlaySound("music\\start.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		else if (mx > 390 && mx < 420 && my>320 && my < 350)
			gameState = 15;
	}
	
	if (gameState == 15)
	{
		if (mx > 350 && mx < 630 && my>450 && my < 610)
			picnum = 0;
		else if (mx > 850 && mx < 1130 && my>450 && my < 610)
				picnum = 1;

		else if (mx > 350 && mx < 630 && my>150 && my < 310)
			picnum = 2;
		else if (mx > 850 && mx < 1130 && my>150 && my < 310)
			picnum = 3;
		else if (mx > 1140 && mx < 1300 && my>120 && my < 140)
			gameState = 11;
	}
	if (gameState == 16)
	{
		if (mx > 1240 && mx < 1360 && my>65 && my < 95)
			gameState = -1;
	}
	if (gameState == 17)
	{
		if (mx > 585 && mx < 650 && my>375 && my < 400)
			exit(0);
		else if (mx > 850 && mx < 905 && my>375 && my < 400)
			gameState = prevState;
	}
	if (gameState == 19)
	{
		if (mx > 1180 && mx < 1310 && my>95 && my < 120){
			gameState = -1;
		}
	}


}

void iPassiveMouseMove(int mx,int my)
{
	

 mposx = mx;
 mposy = my;
 if(mx== 2){}        
 else if(my== 2){} 
}

void iKeyboard(unsigned char key)
{
	if (gameState == 5){
		
		if (key != '\b' && key != '\r')
		{
			name[index] = key;
			index++;
			name[index] = 0;
		}
		else if (key == '\b')
		{
			if (index < 0)
				index = 0;
			else
				index--;

			if (index<0)
				name[0] = 0;
			else
				name[index] = 0;
		}
		else{
			gameState = 1,prevState=-1;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\bg.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}


	else if (gameState == 6)
	{
		if (key == '\r'){
			gameState = 2;
			prevState = 1;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\bg.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	else if (gameState == 7)
	{
		if (key == '\r'){
			gameState = 3;
			prevState = 2;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\bg.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	else if (gameState == 8)
	{
		if (key == '\r'){
			gameState = 4;
			prevState = 3;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\bg.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	else if (gameState == 10)
	{
		if (key == '\r'){
			gameState = 13;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\win.wav", NULL, SND_ASYNC);
			}
		}
	}
	else if (gameState == 1)
	{
		if (key == 27){
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\start.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			gameState = 9;
			prevState = 1;
		}
	}
	else if (gameState == 2)
	{
		
		if (key == 27){
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\start.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			gameState = 9;
			prevState = 2;
		}
	}
	else if (gameState == 3)
	{
		if (key == 27){
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\start.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			gameState = 9;
			prevState = 3;
		}
	}
	else if (gameState == 4)
	{
		if (key == 27){
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\start.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			gameState = 9;
			prevState = 4;
		}
	}
	else if (gameState == 13 || gameState == 14 || gameState==18)
	{
		if (gameState == 13)
		{
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\win.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		if (key == '\r'){
			gameState = -1;
			if (musicOn){
				PlaySound("music\\main.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			restart();
		}
		
	}

}

void iSpecialKeyboard(unsigned char key)
{
	
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (gameState == 1){

		xbefore = runner1X, ybefore = runner1Y;

		if (key == GLUT_KEY_RIGHT )
		{
			runner1X += runningSpeed;
			
		}
		if (key == GLUT_KEY_LEFT )
		{
			runner1X -= runningSpeed;
		}
		if (key == GLUT_KEY_UP )
		{
			runner1Y += runningSpeed;
		}
		if (key == GLUT_KEY_DOWN )
		{
			runner1Y -= runningSpeed;
		}
		if (runner1Y > map1CoordinateY[0][0] && runner1X>=map1CoordinateX[0][2])
			runner1Y = map1CoordinateY[0][0];
		if (mapArray1[((startY1 - runner1Y) / (mazeHeight1)+1)][(runner1X - startX1) / mazeWidth1] == 1)
		{
			runner1X = xbefore;
			runner1Y = ybefore;
		}
		if (runner1X >= startX1 && runner1Y >= startY1 + 30){
			gameState = 6;
			prevState = 1;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\wow.wav", NULL, SND_ASYNC);
			}
		}
	}
	else if (gameState == 2){
		xbefore = runner2X, ybefore = runner2Y;

		if (key == GLUT_KEY_RIGHT)
		{
			runner2X += runningSpeed;
		}
		if (key == GLUT_KEY_LEFT)
		{
			runner2X -= runningSpeed;
		}
		if (key == GLUT_KEY_UP)
		{
			runner2Y += runningSpeed;
		}
		if (key == GLUT_KEY_DOWN)
		{
			runner2Y -= runningSpeed;
		}
		
		
		if (runner2Y > map2CoordinateY[0][0])
			runner2Y =  map2CoordinateY[0][0];
		if (mapArray2[((startY2 - runner2Y) / (mazeHeight2)+1)][(runner2X - startX2) / mazeWidth2] == 1){
		
			runner2X = xbefore;
			runner2Y = ybefore;
		}
		
		if (runner2X >= map2CoordinateX[3][24] + 20 && runner2Y >= map2CoordinateY[3][24]){
			gameState = 7;
			prevState = 2;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\wow.wav", NULL, SND_ASYNC);
			}
		}

	}
	else if (gameState == 3)
	{
		xbefore = runner3X, ybefore = runner3Y;

		if (key == GLUT_KEY_RIGHT)
		{
			runner3X += runningSpeed;
		}
		if (key == GLUT_KEY_LEFT)
		{
			runner3X -= runningSpeed;
		}
		if (key == GLUT_KEY_UP)
		{
			runner3Y += runningSpeed;
		}
		if (key == GLUT_KEY_DOWN)
		{
			runner3Y -= runningSpeed;
		}
		
		if (runner3Y > map3CoordinateY[0][0] && runner3X >= map3CoordinateX[0][2])
			runner3Y = map3CoordinateY[0][0];
		if (mapArray3[((startY3 - runner3Y) / (mazeHeight2)+1)][(runner3X - startX3) / mazeWidth2] == 1){

			runner3X = xbefore;
			runner3Y = ybefore;
		}

		if (runner3X >= map3CoordinateX[0][1] && runner3Y >= map3CoordinateY[0][0] + 25){
			gameState = 8;
			prevState = 3;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\wow.wav", NULL, SND_ASYNC);
			}
		}
	}
	else if (gameState == 4)
	{
		xbefore = runner4X, ybefore = runner4Y;

		if (key == GLUT_KEY_RIGHT)
		{
			runner4X += runningSpeed;
		}
		if (key == GLUT_KEY_LEFT)
		{
			runner4X -= runningSpeed;
		}
		if (key == GLUT_KEY_UP)
		{
			runner4Y += runningSpeed;
		}
		if (key == GLUT_KEY_DOWN)
		{
			runner4Y -= runningSpeed;
		}
		if (runner4Y > map4CoordinateY[0][0] && runner4X >= map4CoordinateX[0][2])
			runner4Y = map4CoordinateY[0][0];
		if (mapArray4[((startY4 - runner4Y) / (mazeHeight2)+1)][(runner4X - startX4) / mazeWidth2] == 1){

			runner4X = xbefore;
			runner4Y = ybefore;
		}

		if (runner4X >= map4CoordinateX[0][1] && runner4Y >= map4CoordinateY[0][0] + 30){
			scoreboard4();
			if (inc == true){
				totalScore();
				saveScore();
				fstr = fopen(data, "w");
				if (fstr != 0){
					writefile(highScore);
					fclose(fstr);
				}
			}
			inc = false;
			gameState = 10;
			prevState = 4;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\wow.wav", NULL, SND_ASYNC);
			}
		}
	}
		
		

}
void change()
{
	no++;
}
void time()
{

	if (gameState == 1){
		static int sec = 0, min = 1;
		if (prevState == -1){
			sec = 0, min = 1;
			prevState = 5;
		}
		if (sec < 0){
			min -= 1;
			sec = 59;
		}
		if (sec < 10) {
			times[5] = '0';
			times[6] = '0' + sec;
			times[7] = 0;
		}
		else {
			times[5] = '0' + (sec) / 10;
			times[6] = '0' + (sec) % 10;
			times[7] = '\0';
		}
		if (min < 9){
			times[0] = ' ';
			times[1] = '0' + min;
		}
		else
		{
			times[0] = '0' + (min) / 10;
			times[1] = '0' + (min) % 10;
		}
		sec--;
		if (times[1] == '0' && times[5] == '0' && times[6] == '0')
		{
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\fail.wav", NULL, SND_ASYNC);
			}
			gameState = 14;
		}
	}
	
	else if (gameState == 2)
	{
		static int sec2 = 35, min2 = 1;
		if (prevState == 1){
			sec2 = 35, min2 = 1;
			prevState = 5;
		}
		if (sec2 < 0){
			min2 -= 1;
			sec2= 59;
		}
		if (sec2 < 10) {
			times[5] = '0';
			times[6] = '0' + sec2;
			times[7] = 0;
		}
		else {
			times[5] = '0' + (sec2) / 10;
			times[6] = '0' + (sec2) % 10;
			times[7] = '\0';
		}
		if (min2 < 9){
			times[0] = ' ';
			times[1] = '0' + min2;
		}
		else
		{
			times[0] = '0' + (min2) / 10;
			times[1] = '0' + (min2) % 10;
		}
		sec2--;
		if (times[1] == '0' && times[5] == '0' && times[6] == '0')
		{
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\fail.wav", NULL, SND_ASYNC);
			}
			gameState = 14;
		}
	}
	else if (gameState == 3)
	{
		static int sec3 = 45, min3 = 1;
		if (prevState == 2){
			sec3 = 45, min3 = 1;
			prevState = 5;
		}
		if (sec3 < 0){
			min3 -= 1;
			sec3 = 59;
		}
		if (sec3 < 10) {
			times[5] = '0';
			times[6] = '0' + sec3;
			times[7] = 0;
		}
		else {
			times[5] = '0' + (sec3) / 10;
			times[6] = '0' + (sec3) % 10;
			times[7] = '\0';
		}
		if (min3 < 9){
			times[0] = ' ';
			times[1] = '0' + min3;
		}
		else
		{
			times[0] = '0' + (min3) / 10;
			times[1] = '0' + (min3) % 10;
		}
		sec3--;
		if (times[1] == '0' && times[5] == '0' && times[6] == '0')
		{
			gameState = 14;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\fail.wav", NULL, SND_ASYNC);
			}

		}
	}
	else if (gameState == 4)
	{
		static int sec4 = 40, min4 = 2;
		if (prevState == 3){
			sec4 = 40, min4 = 2;
			prevState = 5;
		}
		if (sec4 < 0){
			min4 -= 1;
			sec4 = 59;
		}
		if (sec4 < 10) {
			times[5] = '0' ;
			times[6] = '0' + sec4;
			times[7] = 0;
		}
		else {
			times[5] = '0' + (sec4) / 10;
			times[6] = '0' + (sec4) % 10;
			times[7] = '\0';
		}
		if (min4 < 9){
			times[0] = ' ';
			times[1] = '0' + min4;
		}
		else
		{
			times[0] = '0' + (min4) / 10;
			times[1] = '0' + (min4) % 10;
		}
		sec4--;
		if (times[1] == '0' && times[5] == '0' && times[6] == '0')
		{
			gameState = 14;
			if (musicOn){
				PlaySound(0, 0, 0);
				PlaySound("music\\fail.wav", NULL, SND_ASYNC);
			}

		}
	}
}
void arrowblink()
{
	if (gameState == 1 || gameState == 2 || gameState == 3 || gameState == 4)
	{
		static int i = 0;
		if (i % 2 == 0)
			ar = 1;
		else
			ar = 0;
		i++;
	}

}
void enemy()
{
	if (gameState == 4)
	{
		if (done4){
			a1 = 27, b1 = 27;
			done4 = false;
		}
		for (int j = 0; j < 16; j++)
		{
			if (j != 3 && j != 7 && j != 8 && j != 10 && j != 11 && j != 15)
			{
				if (moveright4 == true)
					enemy4[j].x += 1;
				else
					enemy4[j].x -= 1;
				if (enemy4[j].x == enemy4[j].enemyX + 25)
					moveright4 = false;
				else if (enemy4[j].x == enemy4[j].enemyX - a1)
					moveright4 = true, a1 += 2;
				printf("%d %d\n", enemy4[1].enemyX, enemy4[1].x);
			}

			else
			{
				if (moveup4 == true)
					enemy4[j].y += 1;
				else
					enemy4[j].y -= 1;
				if (enemy4[j].y == enemy4[j].enemyY + 25)
					moveup4 = false;
				else if (enemy4[j].y == enemy4[j].enemyY - b1)
					moveup4 = true, b1+=2;
			}
		}
	}
	if (gameState == 3)
	{
		if (done3){
			a2 = 27, b2 = 27;
			done3 = false;
		}
		for (int j = 0; j < 10; j++)
		{
			if (j != 0 && j != 4 && j != 5 && j != 6 && j != 7 && j != 9)
			{
				if (moveright3 == true)
					enemy3[j].x += 1;
				else
					enemy3[j].x -= 1;
				if (enemy3[j].x == enemy3[j].enemyX + 25)
					moveright3 = false;
				if (enemy3[j].x == enemy3[j].enemyX - a2)
					moveright3 = true, a2 += 2;
				printf("%d %d\n", enemy3[1].enemyX, enemy3[1].x);
			}
			else
			{
				if (moveup3 == true)
					enemy3[j].y += 1;
				else
					enemy3[j].y -= 1;
				if (enemy3[j].y == enemy3[j].enemyY + 25)
					moveup3 = false;
				if (enemy3[j].y == enemy3[j].enemyY - b2)
					moveup3 = true, b2 += 2;
			}
		}
	}
	if (gameState == 2)
	{
		if (done2){
			a3 = 27, b3 = 27;
			done2 = false;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j != 1 && j != 4 && j!=6)
			{
				if (moveright2 == true)
					enemy2[j].x += 1;
				else
					enemy2[j].x -= 1;
				if (enemy2[j].x == enemy2[j].enemyX + 25)
					moveright2 = false;
				if (enemy2[j].x == enemy2[j].enemyX - a3)
					moveright2 = true, a3 += 2;
				printf("%d %d\n", enemy2[0].enemyX, enemy2[0].x);

			}
			else
			{
				if (moveup2 == true)
					enemy2[j].y += 1;
				else
					enemy2[j].y -= 1;
				if (enemy2[j].y == enemy2[j].enemyY + 25)
					moveup2 = false;
				if (enemy2[j].y == enemy2[j].enemyY - b3)
					moveup2 = true, b3 += 2;
			}
		}
	}
	if (gameState == 1)
	{
		if (done1){
			a4 = 27;
			done1 = false;
		}
		for (int j = 0; j < 8; j++)
		{
			
				if (moveright1 == true)
					enemy1[j].x += 1;
				else
					enemy1[j].x -= 1;
				if (enemy1[j].x == enemy1[j].enemyX + 25)
					moveright1 = false;
				if (enemy1[j].x == enemy1[j].enemyX - a4)
					moveright1 = true, a4 += 2;
				printf("%d %d\n", enemy1[0].enemyX, enemy1[0].x);
		}
	}
	
}

int main()
{
	iSetTimer(1000, time);
	iSetTimer(1, enemy);
	iSetTimer(20, change);
	iSetTimer(1000, arrowblink);

	times[2] = ' ';
	times[3] = ':';
	times[4] = ' ';

	assignCoordinate1();
	assignCoordinate2();
	assignCoordinate3();
	assignCoordinate4();
	assignEnemyCoordinate();

	savePosition();

	fstr = fopen(data, "r");
	if (fstr != 0){
		readfile(highScore);
		fclose(fstr);
	}

	if (gameState==-2)
	{
		PlaySound("music\\main.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	iInitialize(width, height, "MAZE RUNNER");
	return 0;
}
