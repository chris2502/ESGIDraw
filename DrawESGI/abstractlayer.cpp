#include "abstractlayer.hpp"

AbstractLayer::AbstractLayer(int positionX, int positionY)
{
    this->positionX = positionX;
    this->positionY = positionY;
}

void AbstractLayer::changePosition(int diffX, int diffY)
{
    positionX += diffX;
    positionY += diffY;
}
