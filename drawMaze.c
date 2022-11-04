#include "drawMaze.h"
#include "graphics.h"
#include "setting.h"
#include<stdio.h>



const int mazeSize = 11;  //the size of maze is 11x11, which can be modified



struct MAZESQUARE mazeSquare[mazeSize][mazeSize]; //the size of maze is mazeSize x mazeSize


void modifyMaze(int x,int y,int isExit,int isWall, int isEntrance)   //a procedure to quickly modify a square in the maze
{
	mazeSquare[x][y].xCoordinate = x;
	mazeSquare[x][y].yCoordinate = y;
	mazeSquare[x][y].isExit = isExit;
	mazeSquare[x][y].isWall = isWall;
	mazeSquare[x][y].isEntrance = isEntrance;
}

void drawSquare(int x,int y)    //draw a empty square that robot can walk through.
{
	setColour(lightgray);
	drawRect(x,y,squareWidth,squareWidth);
	setColour(white);
	fillRect(x+1,y+1,squareWidth-1,squareWidth-1);
}

void drawWall(int x,int y)
{
	setColour(lightgray);
	drawRect(x,y,squareWidth,squareWidth);
	setColour(black);
	fillRect(x,y,squareWidth,squareWidth);
}

void drawExit(int x,int y)
{
	setColour(lightgray);
	drawRect(x,y,squareWidth,squareWidth);
	fillRect(x,y,squareWidth,squareWidth);
}
void drawMaze()   //draw whole maze
{
	int i,j;  //this is an index for loop
	int x=(width - mazeSize*squareWidth)/2,y=(height - mazeSize*squareWidth)/2;
	for(i = 0;i<mazeSize;i++)
	{
		for(j=0;j<mazeSize;j++)
		{
			if ((mazeSquare[j][i].isWall == 1)&&(mazeSquare[j][i].isExit == 0))
			{
				drawWall(x,y);

			}
			else if ((mazeSquare[j][i].isExit == 1)&&(mazeSquare[j][i].isWall == 0))
			{
				drawExit(x,y);
			}
			else if ((mazeSquare[j][i].isExit == 0)&&(mazeSquare[j][i].isWall == 0))
			{
				drawSquare(x,y);
			}
			x = x + squareWidth;
		}
		y = y + squareWidth;
		x= (width - mazeSize*squareWidth)/2;
		
	}
	

}

void loadMazeData()    //maze data are stored in a file called "maze.txt"
{
	const char *fileName = "maze.txt";
	FILE *file;
	file = fopen(fileName,"r");
	if (file == NULL)    //check if the file exists or not
	{
		printf("File not found\n");
		
	}
	else
	{
		printf("File found\n");
		int maze[mazeSize][mazeSize];
		int i,j;
		for(i=0;i<mazeSize;i++)
		{
			for(j=0;j<mazeSize;j++)
			{
				fscanf(file,"%d",&maze[j][i]);
			}
		}

		for(i=0;i<mazeSize;i++)
		{
			for(j=0;j<mazeSize;j++)
			{
				switch (maze[j][i])   //0 means a wall, 1 means a road, 2 means an entrance, 3 means an exit
				{
					case 0 : 
						modifyMaze(j,i,0,1,0);
						break;
					case 1 : 
						modifyMaze(j,i,0,0,0);
						break;
					case 2 :
						modifyMaze(j,i,0,0,1);
						break;
					case 3 : 
						modifyMaze(j,i,1,0,0);
						break;
					default: printf("Found error data\n");
				}
			}
		}

	}

	fclose(file);
}