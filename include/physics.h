#ifndef PHYSICS_H
#define PHYSICS_H

class physics
{
public:
    double gravityFactor = 0.012f;
    physics();
    virtual ~physics();
    bool checkExitToBorderX(double positionX);
    bool checkExitToBorderY(double positionY);
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

double physics::getGravityFactor()
{
    return gravityFactor;
}

physics::~physics()
{
}

#endif
