#ifndef PHYSICS_H
#define PHYSICS_H

class physics
{
public:
    physics();
    virtual ~physics();
    bool checkExitToBorder(double positionX, double positionY);
private:

};

physics::physics()
{
}

bool physics::checkExitToBorder(double positionX, double positionY)
{
    bool result = false;

    if (positionX > 1.0 || positionX < -1.0)
    {
        result = true;
    }

    return result;
}

physics::~physics()
{
}

#endif
