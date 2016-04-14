#ifndef PHYSICS_H
#define PHYSICS_H
#include <algorithm>
#include <math.h>
#include <map>

class physics
{
public:
    double gravityFactor = 0.012f;
    physics();
    virtual ~physics();
    bool checkExitToBorderX(double positionX);
    bool checkExitToBorderY(double positionY);
    void putStaticElements(std::map<double, std::vector<double> > staticObjects_);
    bool checkStaticObjectsOnPositionX(double positionX, double positionY, double startPositionX);
    bool checkStaticObjectsOnPositionY(double positionX, double positionY, double startPositionX, double startPositionY);
    bool findInX(double positionX);
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

void physics::putStaticElements(std::map<double, std::vector<double> > staticObjects_)
{
    staticObjects = staticObjects_;
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

    return result;
}

bool physics::findInX(double positionX)
{

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
