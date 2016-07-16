#ifndef COMPOSITELAYER_H
#define COMPOSITELAYER_H


class CompositeLayer : public AbstractLayer
{
public:
    CompositeLayer(vector<AbstractLayer*> layers, int positionX=0, int positionY=0);
    int getSizeX();
    int getSizeY();
    uint getGridPoint(int x, int y);
    void setGridPoint(int x, int y, uint pixel);
    void changeSize(float multiplierX, float multiplierY);
private:
    vector<AbstractLayer*> layers;
};

#endif // COMPOSITELAYER_H
