#include "WallERight.h"

#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

WallERight::WallERight(const Point& iniPos, Maze* l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("walle.jpg", false);
}

void WallERight::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = iniPos.getX();
    int y = iniPos.getY();
    steps.push_back(Point(x,y));
    bool igual = false;
    char orientacao='L';
    while(!saiu && cont < maxSteps)
    {
        igual = false;
        int dx = 0;
        int dy = 0;
        switch(orientacao)
        {
            case 'L':
                if(maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y+1)))
                {
                    dx=1;
                    dy=0;
                }
                else if(maze->isEmpty(Point(x,y+1)))
                {
                    dx=0;
                    dy=1;
                    orientacao = 'S';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x,y-1)))
                {
                    dx=-1;
                    dy=0;
                    orientacao = 'O';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x,y-1)) && !maze->isEmpty(Point(x,y+1)))
                {
                    dx=0;
                    dy=-1;
                    orientacao = 'N';
                }
                break;
            case 'O':
                if(!maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x-1,y)))
                {
                    dx=-1;
                    dy=0;
                }
                else if(maze->isEmpty(Point(x,y-1)))
                {
                    dx=0;
                    dy=-1;
                    orientacao = 'N';
                }
                else if(!maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x,y-1)))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                else if(!maze->isEmpty(Point(x,y-1)) && !maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y+1)))
                {
                    dx=0;
                    dy=+1;
                    orientacao = 'S';
                }
                break;
            case 'N':
                if(!maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x,y-1)))
                {
                    dx=0;
                    dy=-1;
                }
                else if(maze->isEmpty(Point(x+1,y)))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                else if(!maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y-1)) && !maze->isEmpty(Point(x+1,y)))
                {
                    dx=0;
                    dy=1;
                    orientacao = 'S';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x-1,y)))
                {
                    dx=-1;
                    dy=0;
                    orientacao = 'O';
                }
                break;
            case 'S':
                if(!maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y+1)))
                {
                    dx=0;
                    dy=1;
                }
                else if(maze->isEmpty(Point(x-1,y)))
                {
                    dx=-1;
                    dy=0;
                    orientacao = 'O';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x-1,y)))
                {
                    dx=0;
                    dy=-1;
                    orientacao = 'N';
                }
                else if(!maze->isEmpty(Point(x,y+1)) && maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x-1,y)))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                break;
        }
        x += dx;
        y += dy;
        steps.push_back(Point(x, y));
        cont++;
        if(x >= maze->getWidth() || x < 0
                || y >= maze->getHeight() || y < 0)
            saiu = true;
    }
}

void WallERight::draw()
{
    float rx,ry;
    float deltax = GL::getDeltaX();
    float deltay = GL::getDeltaY();
    rx = pos.getX() * deltax;
    ry = pos.getY() * deltay;
    GL::enableTexture(roboTex->texid);
    GL::setColor(255,255,255);
    GL::drawRect(rx, ry, rx+deltax, ry+deltay);
    GL::disableTexture();
}


