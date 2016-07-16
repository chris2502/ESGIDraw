#include "compositelayer.hpp"

CompositeLayer::CompositeLayer(vector<AbstractLayer*> layers, int positionX, int positionY):
    AbstractLayer(positionX, positionY)
{
    this->layers = layers;
}


int CompositeLayer::getSizeX() {
    int result = 0;
    for (AbstractLayer * layer : layers) {
        for(int i = 0 ; i < layer.getSizeX() ; i++) {
            if(i + layer.getPositionX() > result) {
                result = i + layer.getPositionX();
            }
        }
    }
    return result;
}

int CompositeLayer::getSizeY() {
    int result = 0;
    for (AbstractLayer * layer : layers) {
        for(int i = 0 ; i < layer.getSizeY() ; i++) {
            if(i + layer.getPositionY() > result) {
                result = i + layer.getPositionY();
            }
        }
    }
    return result;
}

uint CompositeLayer::getGridPoint(int x, int y) {
    uint result=0;
    for(AbstractLayer * layer : layers) {
        if(layer->getPositionX() + layer->getSizeX() >= x &&
                layer->getPositionX() <= x &&
                layer->getPositionY() + layer.getSizeY() >= y &&
                layer->getPositionY() <= y)
        {
            result = layer->getGridPoint(x - layer->getPositionX(),
                                         y - layer->getPositionY());
            break;
        }
    }
    return result;
}

void CompositeLayer::setGridPoint(int x, int y, uint pixel) {
    for(AbstractLayer * layer : layers) {
        if(layer->getPositionX() + layer->getSizeX() >= x &&
                layer->getPositionX() <= x &&
                layer->getPositionY() + layer.getSizeY() >= y &&
                layer->getPositionY() <= y)
        {
            layer->setGridPoint(x - layer->getPositionX(), y - layer->getPositionY(), pixel);
            break;
        }
    }
}

void CompositeLayer::changeSize(float multiplierX, float multiplierY) {
    // Not Yet Implemented
}
