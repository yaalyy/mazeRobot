#include "graphics.h"
#include "setting.h"
#include "drawMaze.h"
#include "robot.h"
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char **argv)
{
	loadMazeData();
	setWindowSize(width,height);
	background();
	drawMaze();

	foreground();
	scanMaze();
	resetRobot();
	updateAngleCoordinate();
	drawRobot();

	setDirection();
	updateAngleCoordinate();
	drawRobot();

	autoSearch(); 

	return 0;
}

