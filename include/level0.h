#ifndef LEVEL0_H
#define LEVEL0_H

#include <GLFW/glfw3.h>

#include <vector>

class level0
{
public:
    level0();
    virtual ~level0();
    void generateworld();
    void createStaticObjects();
    std::vector<double> getObjectFromX();
    std::vector<double> getObjectFromY();
    double getStartPositionX();
    double getStartPositionY();
private:
    std::vector<double> staticElementsX;
    std::vector<double> staticElementsY;
    double startPointX;
    double startPointY;
};

level0::level0()
{
}

void level0::createStaticObjects() {
    startPointX = -0.5f;
    staticElementsX.push_back (-0.5f);
    staticElementsX.push_back (0.55f);
    staticElementsX.push_back (0.55f);
    staticElementsX.push_back (-0.5f);

    staticElementsX.push_back (-0.55f);
    staticElementsX.push_back (-0.50f);
    staticElementsX.push_back (-0.50f);
    staticElementsX.push_back (-0.55f);

    staticElementsX.push_back (-0.5f);
    staticElementsX.push_back (0.75f);
    staticElementsX.push_back (0.75f);
    staticElementsX.push_back (-0.5f);

    staticElementsX.push_back (-0.2f);
    staticElementsX.push_back (1.0f);
    staticElementsX.push_back (1.0f);
    staticElementsX.push_back (-0.2f);

    staticElementsX.push_back (-0.5f);
    staticElementsX.push_back (1.0f);
    staticElementsX.push_back (1.0f);
    staticElementsX.push_back (-0.5f);

    startPointY = 0.6f;
    staticElementsY.push_back (0.6f);
    staticElementsY.push_back (0.6f);
    staticElementsY.push_back (0.55f);
    staticElementsY.push_back (0.55f);

    staticElementsY.push_back (0.95f);
    staticElementsY.push_back (0.95f);
    staticElementsY.push_back (-1.0f);
    staticElementsY.push_back (-1.0f);

    staticElementsY.push_back (0.3f);
    staticElementsY.push_back (0.3f);
    staticElementsY.push_back (0.25f);
    staticElementsY.push_back (0.25f);

    staticElementsY.push_back (0.00f);
    staticElementsY.push_back (0.00f);
    staticElementsY.push_back (-0.05f);
    staticElementsY.push_back (-0.05f);

    staticElementsY.push_back (-0.4f);
    staticElementsY.push_back (-0.4f);
    staticElementsY.push_back (-0.45f);
    staticElementsY.push_back (-0.45f);
}

void level0::generateworld()
{
    glBegin(GL_QUADS);
    glColor3f(0.37, 0.30, 0.22);
    // read vector
    for (unsigned i=0; i<staticElementsX.size(); i++)
    {
        glVertex2f(staticElementsX.at(i), staticElementsY.at(i));
    }

    glColor3f(0.75, 0.68, 0.59);

    glVertex2f(-0.5, -0.7);
    glVertex2f(1.0, -0.7);
    glVertex2f(1.0, -1.0);
    glVertex2f(-0.5, -1.0);
    glEnd();
}

std::vector<double> level0::getObjectFromX() {
    return staticElementsX;
}

std::vector<double> level0::getObjectFromY() {
    return staticElementsY;
}

double level0::getStartPositionX() {
    return startPointX;
}

double level0::getStartPositionY() {
    return startPointY;
}



level0::~level0()
{
}


#endif // LEVEL0_H_INCLUDED
