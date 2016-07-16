#ifndef LAYER_H
#define LAYER_H


class Layer : public AbstractLayer
{
public:
    Layer(int sizeX, int sizeY, int positionX=0, int positionY=0);
    int getSizeX() { return sizeX; }
    int getSizeY() { return sizeY; }
    uint getGridPoint(int x, int y);
    void setGridPoint(int x, int y, uint pixel);
    void changeSize(float multiplierX, float multiplierY);
private:
    vector<vector<uint>> grid;
    int sizeX;
    int sizeY;
    int positionX;
    int positionY;
};

#endif // LAYER_H
