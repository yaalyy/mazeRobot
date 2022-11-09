#include "stack.h"
#include<stdio.h>


int pathPointer = -1;
struct MOVINGPATH movingPath[pathSize];


void stackPush(struct MOVINGPATH* path,int x, int y)
{
    pathPointer++;
    path[pathPointer].x = x;
    path[pathPointer].y = y;
}

struct MOVINGPATH stackPop(struct MOVINGPATH* path)
{
    if (pathPointer==-1) {
        printf("empty stack\n");
        return path[pathPointer];
    }
    else
    {
        pathPointer--;
        return path[pathPointer+1];
    }
    
}