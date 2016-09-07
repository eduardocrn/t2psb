#include "TestMaze.h"
#include "RobotB9.h"//
#include "RobotC3P0.h"
#include "RobotR2D2.h"
#include "RobotWallE.h"
#include "WallERight.h"
#include "GL.h"

using namespace std;

int main()
{
    GL::init();
    // Load the test maze
    Maze* lab = new TestMaze();
    lab->loadMaze("maze2.txt");
    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << " , " << posIni.getY() << endl;
    Robot* robo;
    int op = lab->getRobot();
    switch(op)
    {
        case 0: robo = new RobotB9(posIni,lab,2000); break;// 200 passos no maximo

        case 1: robo = new RobotC3P0(posIni,lab,2000); break;

        case 2: robo = new RobotR2D2(posIni,lab,2000); break;

        case 3: robo = new WallERight(posIni,lab,2000); break;
                        //Robo abaixo utiliza ideia de pilha
                       //new RobotWallE(posIni,lab,2000); break;
    }
    GL::setMazeRobot(lab, robo);

	GL::loop();
}
