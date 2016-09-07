#include "TestMaze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cmath>

using std::stringstream;

TestMaze :: TestMaze() {
}

// Should load the maze from a text file
// Here is just creates boundaries with an exit at the bottom

void TestMaze :: loadMaze(string arquivo) {
    ifstream arqentrada;
    arqentrada.open(arquivo.c_str(),ios::in);
    string aux;
	string labirinto;
	stringstream dimensao;
	stringstream robo;
	stringstream posicao;
    getline(arqentrada,aux);
    dimensao << aux;
    dimensao >> aux >> dimy >> dimx;
    getline(arqentrada,aux);
    posicao << aux;
    int posx;
    int posy;
    posicao >> aux >> posy >> posx;
    posIni = Point(posx,posy);
	getline(arqentrada,aux);
	robo << aux;
	robo >> aux >> robot;
    for(int i = 0; i <= dimx;i++){
        getline(arqentrada,labirinto);
        for(int j=0; j<dimx;j++){
            lab[i][j] = labirinto[j];
        }
    }
    arqentrada.close();
}

// Returns true if the x,y pos is empty
bool TestMaze :: isEmpty(const Point& pos) const {
    if(pos.getX()<0 || pos.getX()>=dimx
                    || pos.getY()<0 || pos.getY()>=dimy) return true;
    return (lab[pos.getY()][pos.getX()]==' ');
}

// Return the maze dimensions
int TestMaze :: getWidth() { return dimx; }
int TestMaze :: getHeight() { return dimy; }

int TestMaze::getRobot() { return robot; }

Point TestMaze::getIniPos() { return posIni; }
