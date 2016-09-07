#ifndef WALLERIGHT_H
#define WALLERIGHT_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"
#include "Point.h"

using namespace std;

class WallERight: public Robot {
	public:
        WallERight(const Point& iniPos, Maze*l, int maxSteps);	// Constructor
        void draw();
        void generateSteps();
        vector<Point> getSteps();
        bool jaPassou(int x,int y);
        void addCheckpoint(int x, int y);
    private:
        TEX* roboTex; // robot texture id
        vector<Point> checkpoint;
};


#endif // WALLERIGHT_H
