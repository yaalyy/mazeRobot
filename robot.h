#ifndef ROBOT_H
#define ROBOT_H

struct ROBOT    //Robot is shown as a isosceles triangle
{
    int xCoordinate, yCoordinate;    //coordinates of centre of triangle
    int atExit;    //boolean to check if the robot reaches the exit
    int direction;   //1 = up, 2 = left, 3 = down, 4 = right
    int x_vertex, y_vertex; //coordinates of vertex angle
    int x1_base,y1_base;   //coordinates of base angles
    int x2_base,y2_base;
    int xEntrance, yEntrance; //coordinates of entrance
    int xExit, yExit;  //coordinates of exit

};

void resetRobot();
void drawRobot();
void updateAngleCoordinate();
void scanMaze();
void forward();
void left();
void right();
int atMarker();
int canMoveForward();
void manuallyControl();
void setDirection();
void autoSearch();



#endif