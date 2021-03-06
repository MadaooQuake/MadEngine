#ifndef PINKO_H
#define PINKO_H
#include <GLFW/glfw3.h>
#include <vector>

class pinko
{
    public:
        double move = 0.0f;
        pinko();
        void generatePinko();
        void goForward();
        void goBack();
        void cleanMove();
        double getMove();
        std::vector<double> getPinkoPosition();
        virtual ~pinko();
    protected:
        std::vector<double> pinkoPosition;
    private:
};

pinko::pinko()
{
    //ctor
}

void pinko::generatePinko()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.32f, 0.62f);
    glVertex2f(-0.34f, 0.62f);
    glVertex2f(-0.36f, 0.62f);
    glVertex2f(-0.36f, 0.62f);
    glVertex2f(-0.36f, 0.6f);
    glVertex2f(-0.38f, 0.6f);
    glVertex2f(-0.38f, 0.62f);
    glVertex2f(-0.38f, 0.64f);
    glVertex2f(-0.34f, 0.68f);
    glVertex2f(-0.24f, 0.68f);
    glVertex2f(-0.2f, 0.64f);
    glVertex2f(-0.2f, 0.62f);
    glVertex2f(-0.26f, 0.62f);
    glVertex2f(-0.26f, 0.6f);
    glVertex2f(-0.28f, 0.6f);
    glVertex2f(-0.28f, 0.62f);
    glVertex2f(-0.34f, 0.62f);
    glEnd();
}

void pinko::goForward()
{
    move = 0.02f;
}

void pinko::goBack()
{
    move = -0.02f;
}

void pinko::cleanMove()
{
    move = 0.0f;
}

double pinko::getMove()
{
    return move;
}

std::vector<double> pinko::getPinkoPosition()
{
    pinkoPosition.push_back(-0.36);
    pinkoPosition.push_back(-0.26);
    return pinkoPosition;
}

pinko::~pinko()
{
    //dtor
}

#endif // PINKO_H
