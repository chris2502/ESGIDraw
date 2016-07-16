#ifndef COMPOSITELAYER_H
#define COMPOSITELAYER_H

#include<vector>
#include "abstractlayer.hpp"

class CompositeLayer : public AbstractLayer
{
public:
    CompositeLayer(std::vector<AbstractLayer *> layers, int positionX=0, int positionY=0);
    int getSizeX();
    int getSizeY();
    unsigned int getGridPoint(int x, int y);
    void setGridPoint(int x, int y, unsigned int pixel);
    void changeSize(float multiplierX, float multiplierY);
private:
    std::vector<AbstractLayer*> layers;
};

#endif // COMPOSITELAYER_H
