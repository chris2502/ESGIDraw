#include "layer.hpp"

Layer::Layer(int sizeX, int sizeY, int positionX, int positionY):
    AbstractLayer(positionX, positionY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}


uint Layer::getGridPoint(int x, int y) {
    return grid[x][y];
}

void Layer::setGridPoint(int x, int y, uint pixel) {
    grid[x][y] = pixel;
}

void Layer::changeSize(float multiplierX, float multiplierY) {
    // Not Yet Implemented
}
