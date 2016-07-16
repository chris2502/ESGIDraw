#ifndef ABSTRACTLAYER_H
#define ABSTRACTLAYER_H


class AbstractLayer
{
public:
    AbstractLayer(int positionX=0, int positionY=0);
    virtual int getSizeX() = 0;
    virtual int getSizeY() = 0;
    int getPositionX() { return positionX; }
    int getPositionY() { return positionY; }
    virtual unsigned int getGridPoint(int x, int y) = 0;
    virtual void setGridPoint(int x, int y, unsigned int pixel) = 0;
    virtual void changeSize(float multiplierX, float multiplierY) = 0;
    void changePosition(int diffX, int diffY);
private:
    int positionX;          // Position dans le calque parent
    int positionY;          // Position dans le calque parent
};

#endif // ABSTRACTLAYER_H
