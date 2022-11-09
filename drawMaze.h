#ifndef DRAW_MAZE_H_
#define DRAW_MAZE_H_



struct MAZESQUARE       //each square of square is a struct, including data such as colour, coordinates and so on.
{
	int isExit;
	int xCoordinate, yCoordinate;
	int isWall;
	int isEntrance;
	int xCentre, yCentre;   //the coordinate of centre of the square
	int isVisited;

	
};    
void modifyMaze(int,int ,int ,int, int);  
void drawSquare(int ,int );
void drawWall(int ,int );
void drawExit(int,int);
void drawMaze();
void loadMazeData();  
int findXIndex(int);
int findYIndex(int);

#endif
