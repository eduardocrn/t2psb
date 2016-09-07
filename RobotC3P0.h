#ifndef ROBOTC3P0_H
#define ROBOTC3P0_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class RobotC3P0: public Robot {
	public:
        RobotC3P0(const Point& iniPos, Maze*l, int maxSteps);	// Constructor
        void draw();
        void generateSteps();
        vector<Point> getSteps();
    private:
        TEX* roboTex; // robot texture id
};

#endif
