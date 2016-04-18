#ifndef PHYSICS_H
#define PHYSICS_H
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>

class physics
{
public:
    double gravityFactor = 0.005f;
    physics();
    virtual ~physics();
    bool checkExitToBorderX(double positionX);
    bool checkExitToBorderY(double positionY);
    void putStaticElements(std::map<double, std::vector<double> > staticObjects_);
    bool checkStaticObjectsOnPositionX(double positionX, double positionY, std::vector<double> pinkoPosition);
    bool checkStaticObjectsOnPositionY(double positionX, double positionY, std::vector<double> pinkoPosition, double startPositionY);
    bool findInX(double positionX, std::vector<double> elementsX, std::vector<double> pinkoPosition);
    bool findInY(double positionX, std::vector<double> elementsX, std::vector<double> pinkoPosition);
    double getGravityFactor();
private:
    std::map<double, std::vector<double> > staticObjects;
};

physics::physics()
{
}

bool physics::checkExitToBorderX(double positionX)
{
    bool result = false;
    if (positionX > 1.2f || positionX < -0.95f)
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

void physics::putStaticElements(std::map<double, std::vector<double> > staticObjects_)
{
    staticObjects = staticObjects_;
}

bool physics::checkStaticObjectsOnPositionY(double positionX, double positionY, std::vector<double> pinkoPosition, double startPositionY)
{
    bool result = false;
    double positionPinkoInY = 0.0f;

    positionPinkoInY = positionY + startPositionY - (8*gravityFactor);
    positionPinkoInY = roundl(positionPinkoInY * 1000) / 1000;

    if (staticObjects.find(positionPinkoInY) != staticObjects.end())
    {
        result = findInX(positionX, staticObjects[positionPinkoInY], pinkoPosition);
    }
    // search conflits from y

    return result;
}

bool physics::findInX(double positionX, std::vector<double> elementsX, std::vector<double> pinkoPosition)
{
    bool result = false;
    double positionX1 = pinkoPosition[0] + positionX;
    double positionX2 = pinkoPosition[1] + positionX;
    if(positionX1 < elementsX[0] && positionX2 > elementsX[1])
    {
        result = true;
    }

    return result;
}

bool physics::findInY(double positionX, std::vector<double> elementsX, std::vector<double> pinkoPosition)
{
    // now i must add loop
    bool result = false;

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
