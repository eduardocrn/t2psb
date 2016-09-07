#include "RobotWallE.h"
//#include "Point.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>


using namespace std;

RobotWallE::RobotWallE(const Point& iniPos, Maze* l, int maxSteps)
    : Robot(iniPos, l, maxSteps)
{
    srand(time(NULL));
    roboTex = LoadTexture("walle.jpg", false);
}

void RobotWallE::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = iniPos.getX();
    int y = iniPos.getY();
    steps.push_back(Point(x,y));
    bool igual = false;
    char orientacao='N';
    checkpoint.push_back(Point(x,y));
    bool volta = false;
    while(!saiu && cont < maxSteps)
    {
        int dx = 0;
        int dy = 0;

        if(volta)
        {
            x = checkpoint.back().getX();
            y = checkpoint.back().getY();

            steps.push_back(Point(x,y));

            if(maze->isEmpty(Point(x+1,y)) && !jaPassou(x+1,y))
            {
                orientacao = 'L';
                volta = false;
            }
            else if(maze->isEmpty(Point(x-1,y)) && !jaPassou(x-1,y))
            {
                orientacao = 'O';
                volta = false;
            }
            else if(maze->isEmpty(Point(x,y+1)) && !jaPassou(x,y+1))
            {
                orientacao = 'S';
                volta = false;
            }
            else if(maze->isEmpty(Point(x,y-1)) && !jaPassou(x,y-1))
            {
                orientacao = 'N';
                volta = false;
            }
            else
            {
                checkpoint.pop_back();
            }
        }
    if(!volta)
    switch(orientacao)
        {
            case 'L':
                if(maze->isEmpty(Point(x+1,y)) && !jaPassou(x+1,y))
                {
                    dx=1;
                    dy=0;
                }
                else if(maze->isEmpty(Point(x,y-1)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x+1,y)) && !jaPassou(x,y-1))
                {
                    dx=0;
                    dy=-1;
                    orientacao = 'N';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x,y+1)) && !jaPassou(x,y+1))
                {
                    dx=0;
                    dy=1;
                    orientacao = 'S';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x,y+1)) && !jaPassou(x,y+1))
                {
                    dx=0;
                    dy=1;
                    orientacao = 'S';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x,y-1)))
                {
                    volta=true;
                }
                break;
            case 'O':
                if(maze->isEmpty(Point(x-1,y)) && !jaPassou(x-1,y))
                {
                    dx=-1;
                    dy=0;
                }
                else if(maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y-1)) && !jaPassou(x,y+1))
                {
                    dx=0;
                    dy=1;
                    orientacao = 'S';
                }

                else if(!maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y-1)) && !jaPassou(x,y-1))
                {
                    dx=0;
                    dy=-1;
                    orientacao = 'N';
                }
                else if(maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x-1,y)) && !jaPassou(x,y-1))
                {
                    dx=0;
                    dy=-1;
                    orientacao = 'N';
                }
                else if(!maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x,y-1)))
                {
                    volta = true;
                }
                break;
            case 'N':
                if(maze->isEmpty(Point(x,y-1)) && !jaPassou(x,y-1))
                {
                    dx=0;
                    dy=-1;
                }
                else if(maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y-1)) && !maze->isEmpty(Point(x+1,y)) && !jaPassou(x-1,y))
                {
                    dx=-1;
                    dy=0;
                    orientacao = 'O';
                }

                else if(!maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x+1,y)) && !jaPassou(x+1,y))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                else if(maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y-1)) && !jaPassou(x+1,y))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                else if(!maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y-1)) && !maze->isEmpty(Point(x+1,y)))
                {
                   volta = true;
                }
                break;
            case 'S':
                if(maze->isEmpty(Point(x,y+1)) && !jaPassou(x,y+1))
                {
                    dx=0;
                    dy=1;
                }
                else if(maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x-1,y)) && !jaPassou(x+1,y))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                else if(!maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x-1,y)) && !jaPassou(x-1,y))
                {
                    dx=-1;
                    dy=0;
                    orientacao = 'O';
                }
                else if(maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x-1,y)) && !maze->isEmpty(Point(x,y+1)) && !jaPassou(x+1,y))
                {
                    dx=1;
                    dy=0;
                    orientacao = 'L';
                }
                else if(!maze->isEmpty(Point(x+1,y)) && !maze->isEmpty(Point(x,y+1)) && !maze->isEmpty(Point(x-1,y)))
                {
                    volta = true;
                }
                break;
        }
        x += dx;
        y += dy;
        addCheckpoint(x,y);
        if(!volta)
        {
            steps.push_back(Point(x, y));
            cont++;
        }
        if(x >= maze->getWidth() || x < 0
                || y >= maze->getHeight() || y < 0)
            saiu = true;
    }
}

//Verifica se robo ja passou pela posicao
bool RobotWallE::jaPassou(int x, int y)
{
    bool passou = false;
    for(int i=0; i<steps.size(); i++)
    {
        if(steps[i].getX()==x && steps[i].getY()==y)
            passou = true;
    }
    return passou;
}

//Armazena os pontos onde há mais de uma opcao de caminho
void RobotWallE::addCheckpoint(int x, int y)
{
    if( !jaPassou(x,y) && ((maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x,y+1)))
            || (maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y-1)))
            || (maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y+1)))
            || (maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y+1)) && maze->isEmpty(Point(x,y-1)))
            || (maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x,y+1)) && maze->isEmpty(Point(x+1,y)))
            || (maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x,y+1)) && maze->isEmpty(Point(x,y-1)))
            || (maze->isEmpty(Point(x,y-1)) && maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x+1,y)))
            || (maze->isEmpty(Point(x+1,y)) && maze->isEmpty(Point(x-1,y)) && maze->isEmpty(Point(x,y+1)))))
                checkpoint.push_back(Point(x,y));

}
void RobotWallE::draw()
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
