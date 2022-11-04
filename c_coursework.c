#include "graphics.h"
#include<stdlib.h>
#include "setting.h"
#include "drawMaze.h"

int main(int argc, char **argv)
{
	loadMazeData();
	setWindowSize(width,height);
	background();
	drawMaze();

	return 0;
}

