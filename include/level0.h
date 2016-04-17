#ifndef LEVEL0_H
#define LEVEL0_H

#include <GLFW/glfw3.h>
#include <map>
#include <vector>

class level0
{
public:
    level0();
    virtual ~level0();
    void generateWorld();
    void createStaticObjects();
    std::vector<double> getObjectFromX();
    std::vector<double> getObjectFromY();
    double getStartPositionX();
    double getStartPositionY();
    std::map<double, std::vector<double> > getStaticObjects();
private:
    std::map<double, std::vector<double> > staticObjects;
    std::vector<double> staticElementsX;
    double startPointX;
    double startPointY;
};

level0::level0()
{
}

// get from db to collision
void level0::createStaticObjects() {
    startPointX = -0.5;
    startPointY = 0.6;

    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (0.55);
    staticObjects[0.6] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (0.55);
    staticElementsX.push_back (-0.5);
    staticObjects[0.55] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.55);
    staticElementsX.push_back (-0.5);
    staticObjects[0.95] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (-0.55);
    staticObjects[-1.0] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (0.75);
    staticObjects[0.3] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (0.75);
    staticElementsX.push_back (-0.5);
    staticObjects[0.25] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.2);
    staticElementsX.push_back (1.0);
    staticObjects[0.0] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (1.0);
    staticElementsX.push_back (-0.2);
    staticObjects[-0.05] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (1.0);
    staticObjects[-0.4] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (1.0);
    staticElementsX.push_back (-0.5);
    staticObjects[-0.45] = staticElementsX;
}

void level0::generateWorld()
{
    // get from db
    glBegin(GL_QUADS);
    glColor3f(0.37, 0.30, 0.22);
    glVertex2f(-0.5, 0.6);
    glVertex2f(0.55, 0.6);
    glVertex2f(0.55, 0.55);
    glVertex2f(-0.5, 0.55);

    glVertex2f(-0.55, 0.95);
    glVertex2f(-0.50, 0.95);
    glVertex2f(-0.50, -1.0);
    glVertex2f(-0.55, -1.0);

    glVertex2f(-0.5, 0.3);
    glVertex2f(0.75, 0.3);
    glVertex2f(0.75, 0.25);
    glVertex2f(-0.5, 0.25);

    glVertex2f(-0.2, 0.00);
    glVertex2f(1.0, 0.00);
    glVertex2f(1.0, -0.05);
    glVertex2f(-0.2, -0.05);

    glVertex2f(-0.5, -0.4);
    glVertex2f(1.0, -0.4);
    glVertex2f(1.0, -0.45);
    glVertex2f(-0.5, -0.45);

    glColor3f(0.75, 0.68, 0.59);

    glVertex2f(-0.5, -0.7);
    glVertex2f(1.0, -0.7);
    glVertex2f(1.0, -1.0);
    glVertex2f(-0.5, -1.0);
    glEnd();
}

double level0::getStartPositionX() {
    return startPointX;
}

double level0::getStartPositionY() {
    return startPointY;
}

std::map<double, std::vector<double> > level0::getStaticObjects() {
    return staticObjects;
}



level0::~level0()
{
}


#endif // LEVEL0_H_INCLUDED
