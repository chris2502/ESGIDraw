#ifndef LAYER_H
#define LAYER_H

#include<vector>
#include "abstractlayer.hpp"

class Layer : public AbstractLayer
{
public:
    Layer(int sizeX, int sizeY, int positionX=0, int positionY=0);
    int getSizeX() { return sizeX; }
    int getSizeY() { return sizeY; }
    unsigned int getGridPoint(int x, int y);
    void setGridPoint(int x, int y, unsigned int pixel);
    void changeSize(float multiplierX, float multiplierY);
private:
    std::vector<std::vector<unsigned int>> grid;
    int sizeX;
    int sizeY;
    int positionX;
    int positionY;
};

#endif // LAYER_H
