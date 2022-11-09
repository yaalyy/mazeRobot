#ifndef STACK_H
#define STACK_H

#define pathSize 200
extern int pathPointer;

struct MOVINGPATH
{
    int x;
    int y;
};

void stackPush(struct MOVINGPATH*,int,int);
struct MOVINGPATH stackPop(struct MOVINGPATH*);

#endif