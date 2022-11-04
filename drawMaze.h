#ifndef _DRAW_MAZE_H_
#define _DRAW_MAZE_H_

extern const int mazeSize;

struct MAZESQUARE       //each square of square is a struct, including data such as colour, coordinates and so on.
{
	int isExit;
	int xCoordinate, yCoordinate;
	int isWall;
	int isEntrance;

	
};    
void modifyMaze(int,int ,int ,int, int);  
void drawSquare(int ,int );
void drawWall(int ,int );
void drawExit(int,int);
void drawMaze();
void loadMazeData();  

#endif
