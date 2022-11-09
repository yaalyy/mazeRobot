#include "robot.h"
#include "drawMaze.h"
#include "setting.h"
#include "graphics.h"
#include<stdio.h>

struct ROBOT robot;
extern struct MAZESQUARE mazeSquare[mazeSize][mazeSize];


void resetRobot()   //reset the coordinates of robot to the entrance coordinates
{
    robot.direction = 1;   //the default direction of robot is UP
    robot.xCoordinate = robot.xEntrance;
    robot.yCoordinate = robot.yEntrance;
}
void drawRobot()
{
    setColour(green);
    int x[3] = {robot.x_vertex,robot.x1_base,robot.x2_base};
    int y[3] = {robot.y_vertex,robot.y1_base,robot.y2_base};
    fillPolygon(3,x,y);

}
void updateAngleCoordinate()     //update coordinates of three vertexes
{   
    int direction = robot.direction;
    switch(direction)
    {
        case 1:
            robot.x_vertex = robot.xCoordinate;
            robot.y_vertex = robot.yCoordinate - 0.5*squareWidth;
            robot.x1_base = robot.xCoordinate - 0.5*squareWidth;
            robot.y1_base = robot.yCoordinate + 0.5*squareWidth;
            robot.x2_base = robot.xCoordinate + 0.5*squareWidth;
            robot.y2_base = robot.yCoordinate + 0.5*squareWidth;
            break;
        case 2:
            robot.x_vertex = robot.xCoordinate - 0.5*squareWidth;
            robot.y_vertex = robot.yCoordinate;
            robot.x1_base = robot.xCoordinate + 0.5*squareWidth;
            robot.y1_base = robot.yCoordinate + 0.5*squareWidth;
            robot.x2_base = robot.xCoordinate + 0.5*squareWidth;
            robot.y2_base = robot.yCoordinate - 0.5*squareWidth;
            break;
        case 3: 
            robot.x_vertex = robot.xCoordinate;
            robot.y_vertex = robot.yCoordinate + 0.5*squareWidth;
            robot.x1_base = robot.xCoordinate + 0.5*squareWidth;
            robot.y1_base = robot.yCoordinate - 0.5*squareWidth;
            robot.x2_base = robot.xCoordinate - 0.5*squareWidth;
            robot.y2_base = robot.yCoordinate - 0.5*squareWidth;
            break;
        case 4: 
            robot.x_vertex = robot.xCoordinate + 0.5*squareWidth;
            robot.y_vertex = robot.yCoordinate;
            robot.x1_base = robot.xCoordinate - 0.5*squareWidth;
            robot.y1_base = robot.yCoordinate - 0.5*squareWidth;
            robot.x2_base = robot.xCoordinate - 0.5*squareWidth;
            robot.y2_base = robot.yCoordinate + 0.5*squareWidth;
            break;
    }
}

void scanMaze()  //scan the maze to get the coordinates of entrance and exit

{
    int i,j;
    int xCoordinate,yCoordinate;
    int foundEntrance = 0;
    int foundExit = 0;
    for (i=0;i<mazeSize;i++)
    {
        for(j=0;j<mazeSize;j++)
        {
            if (mazeSquare[j][i].isEntrance == 1)
            {
                foundEntrance = 1;
                robot.xEntrance = mazeSquare[j][i].xCentre;   //set entrance coordinates
                robot.yEntrance = mazeSquare[j][i].yCentre;
                continue;
            }
            if (mazeSquare[j][i].isExit == 1)
            {
                foundExit = 1;
                robot.xExit = mazeSquare[j][i].xCentre;   //set exit coordinates
                robot.yExit = mazeSquare[j][i].yCentre;
                continue;
            }
        }
    }
    if (foundEntrance == 1)
    {
        printf("Entrance detected\n"); 

    }
    else
    {
        printf("Entrance not detected\n");

    }

    if (foundExit == 1)
    {
        printf("Exit detected\n");
    }
    else
    {
        printf("Exit not detected\n");
    }
   


}

void forward()
{
    sleep(sleepTime);
    int direction = robot.direction;
    switch(direction)
    {
        case 1: 
            robot.yCoordinate = robot.yCoordinate - squareWidth;
            break;
        case 2: 
            robot.xCoordinate = robot.xCoordinate - squareWidth;
            break;
        case 3: 
            robot.yCoordinate = robot.yCoordinate + squareWidth;
            break;
        case 4: 
            robot.xCoordinate = robot.xCoordinate + squareWidth;
            
    }
    clear();
    updateAngleCoordinate();
    drawRobot();
    
}

void left()
{
    sleep(sleepTime);
    int direction = robot.direction;
    switch(direction)
    {
        case 1: 
            robot.direction = 2;
            break;
        case 2: 
            robot.direction = 3;
            break;
        case 3: 
            robot.direction = 4;
            break;
        case 4: 
            robot.direction = 1;
            
    }
    clear();
    updateAngleCoordinate();
    drawRobot();

}

void right()
{
    sleep(sleepTime);
    int direction = robot.direction;
    switch(direction)
    {
        case 1: 
            robot.direction = 4;
            break;
        case 2: 
            robot.direction = 1;
            break;
        case 3: 
            robot.direction = 2;
            break;
        case 4: 
            robot.direction = 3;
            
    }
    clear();
    updateAngleCoordinate();
    drawRobot();
}

int atMarker()
{
    if ((robot.xCoordinate == robot.xExit)&&(robot.yCoordinate == robot.yExit))
    {
        robot.atExit = 1;
        printf("The bot has reached the exit\n");
        return 1;
    }
    return 0;
    

}

int canMoveForward()
{
    int i;
    struct MAZESQUARE *mazePointer;
    mazePointer = &mazeSquare[0][0];
    int nextXCoordinate,nextYCoordinate;
    int direction = robot.direction;
    switch(direction)
    {
        case 1: 
            nextXCoordinate = robot.xCoordinate;
            nextYCoordinate = robot.yCoordinate - squareWidth;
            break;
        case 2: 
            nextXCoordinate = robot.xCoordinate - squareWidth;
            nextYCoordinate = robot.yCoordinate;
            break;
        case 3: 
            nextXCoordinate = robot.xCoordinate;
            nextYCoordinate = robot.yCoordinate + squareWidth;
            break;
        case 4: 
            nextXCoordinate = robot.xCoordinate + squareWidth;
            nextYCoordinate = robot.yCoordinate;
            
    }
    for(i=0;i<mazeSize*mazeSize;i++)
    {
        if((mazePointer->xCentre == nextXCoordinate)&&(mazePointer->yCentre == nextYCoordinate))
        {
            if(mazePointer->isWall == 1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        mazePointer++;
    }
    return 0;
}

void manuallyControl()   //here set commands to manually control the robot
{
    forward();
    right();
    forward();
    forward();
    forward();
    forward();
    forward();
    forward();
    forward();
    forward();
    left();
    forward();
    forward();
    forward();
    forward();
    forward();
    forward();
    left();
    forward();
    forward();
    right();
    forward();
    forward();
    right();
    forward();
    forward();
    left();
    forward();
    atMarker();
}

void setDirection()   //Help robot find the correct direction to enter the maze, 
//so it does not accidentally leave the maze
{
    struct CoordinateGroup
    {
        int x;
        int y;
        int isInside;
    };

    struct CoordinateGroup coGroup[5];  //represent coordinates around the robot in 4 distinct directions.
    
    coGroup[1].x = robot.xCoordinate;
    coGroup[1].y = robot.yCoordinate - squareWidth;
    coGroup[1].isInside = 0;
    coGroup[2].x = robot.xCoordinate - squareWidth;
    coGroup[2].y = robot.yCoordinate;
    coGroup[2].isInside = 0;
    coGroup[3].x = robot.xCoordinate;
    coGroup[3].y = robot.yCoordinate + squareWidth;
    coGroup[3].isInside = 0;
    coGroup[4].x = robot.xCoordinate + squareWidth;
    coGroup[4].y = robot.yCoordinate + squareWidth;
    coGroup[4].isInside = 0;

    int emptySpace; //the direction of leaving maze, so the opposite direction should be entrying the maze.
    int correctDirection;
    int i,j;
    struct MAZESQUARE *mazePointer;
    mazePointer = &mazeSquare[0][0];
    for(i=0;i<mazeSize*mazeSize;i++)
    {
        for(j=1;j<5;j++)
        {
            if((coGroup[j].x == mazePointer->xCentre)&&(coGroup[j].y == mazePointer->yCentre))
            {
                coGroup[j].isInside = 1;
            }
        }
    }

    for(i=1;i<5;i++)
    {
        if (coGroup[i].isInside == 0)
        {
            emptySpace = i;
            break;
        }
    }

    correctDirection = emptySpace + 2;
    if(correctDirection > 4)
    {
        correctDirection = correctDirection - 4;
    }

    robot.direction = correctDirection;

    sleep(sleepTime);
    

}

void autoSearch()
{
    
}

