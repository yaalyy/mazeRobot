#ifndef STACK_H
#define STACK_H

#define pathSize 200    //the size of storage of path
extern int pathPointer;

struct MOVINGPATH    //store the history of path
{
    int x;
    int y;
};

void stackPush(struct MOVINGPATH*,int,int);
struct MOVINGPATH stackPop(struct MOVINGPATH*);

#endif