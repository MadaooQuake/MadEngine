#ifndef PHYSICS_H
#define PHYSICS_H
#include <algorithm>
#include <math.h>

class physics
{
public:
    std::vector<double> elementsX;
    std::vector<double> elementsY;
    double gravityFactor = 0.012f;
    physics();
    virtual ~physics();
    bool checkExitToBorderX(double positionX);
    bool checkExitToBorderY(double positionY);
    void putStaticElements(std::vector<double> tmpElementsX, std::vector<double> tmpElementsY);
    bool checkStaticObjectsOnPositionX(double positionX, double positionY, double startPositionX);
    bool checkStaticObjectsOnPositionY(double positionX, double positionY, double startPositionX, double startPositionY);
    bool findInX(double positionX);
    double getGravityFactor();
private:

};

physics::physics()
{
}

bool physics::checkExitToBorderX(double positionX)
{
    bool result = false;
    if (positionX > 1.2 || positionX < -0.95)
    {
        result = true;
    }

    return result;
}

bool physics::checkExitToBorderY(double positionY)
{
    bool result = false;
    if(positionY <= -1.6f || positionY >= 1.0f)
    {
        result = true;
    }

    return result;
}

void physics::putStaticElements(std::vector<double> tmpElementsX, std::vector<double> tmpElementsY)
{
    elementsX = tmpElementsX;
    elementsY = tmpElementsY;
}


bool physics::checkStaticObjectsOnPositionX(double positionX, double positionY, double startPositionX)
{
    double positionPinkoInX = (startPositionX + positionX);
    return false;
}

bool physics::checkStaticObjectsOnPositionY(double positionX, double positionY, double startPositionX, double startPositionY)
{
    bool result = false;
    double positionPinkoInY = (startPositionY - positionY) - gravityFactor;

    if(std::find(elementsY.begin(), elementsY.end(), positionPinkoInY) != elementsY.end()
       && findInX(startPositionX + positionX) == true) {
        result = true;
    }
    return result;
}

bool physics::findInX(double positionX)
{

    bool result = false;
    for (int i = 0; i < elementsX.size();)
    {
        std::cout << result << std::endl;
        if (elementsX[i] >= positionX || positionX <= elementsX[i+=1])
        {
            result = true;
            break;
        }
        i +=2;
    }
    return result;
}

double physics::getGravityFactor()
{
    return gravityFactor;
}

physics::~physics()
{
}

#endif
