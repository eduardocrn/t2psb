#ifndef ROBOTR2D2_H
#define ROBOTR2D2_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class RobotR2D2: public Robot {
	public:
        RobotR2D2(const Point& iniPos, Maze*l, int maxSteps);	// Constructor
        void draw();
        void generateSteps();
        vector<Point> getSteps();
    private:
        TEX* roboTex; // robot texture id
};

#endif
