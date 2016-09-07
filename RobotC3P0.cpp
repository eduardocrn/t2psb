#include "RobotC3P0.h"

#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

RobotC3P0::RobotC3P0(const Point& iniPos, Maze* l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("c3p0.jpg", false);
}

void RobotC3P0::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = iniPos.getX();
    int y = iniPos.getY();
    steps.push_back(Point(x,y));

    while(!saiu && cont < maxSteps)
    {
        int dx, dy;
        do {
           if(maze->isEmpty(Point(x+1,y)))
           {
                dx=1;
                dy=0;
           }
           else if(maze->isEmpty(Point(x,y+1)))
           {
                dx=0;
                dy=1;
            }
           else if(maze->isEmpty(Point(x-1,y)))
           {
                dx=-1;
                dy=0;
           }
           else
           {
            dx=0;
            dy=-1;
            }
        }
        while(!maze->isEmpty(Point(x+dx, y+dy)));
        x += dx;
        y += dy;
        steps.push_back(Point(x, y));
        cont++;
        if(x >= maze->getWidth() || x < 0
                || y >= maze->getHeight() || y < 0)
            saiu = true;
    }
}

void RobotC3P0::draw()
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


