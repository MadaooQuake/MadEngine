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
    void generateworld();
    void createStaticObjects();
    std::vector<double> getObjectFromX();
    std::vector<double> getObjectFromY();
    double getStartPositionX();
    double getStartPositionY();
private:
    std::map<double, std::vector<double> > staticObjects;
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
    startPointY = 0.6f;

    staticElementsX.push_back (-0.5f);
    staticElementsX.push_back (0.55f);
    staticObjects[0.6f] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (0.55f);
    staticElementsX.push_back (-0.5f);
    staticObjects[0.55f] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.55f);
    staticElementsX.push_back (-0.50f);
    staticObjects[0.95f] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (-0.50f);
    staticElementsX.push_back (-0.55f);
    staticObjects[-1.0f] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.5f);
    staticElementsX.push_back (0.75f);
    staticObjects[0.3f] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (0.75f);
    staticElementsX.push_back (-0.5f);
    staticObjects[0.25f] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.2f);
    staticElementsX.push_back (1.0f);
    staticObjects[0.0f] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (1.0f);
    staticElementsX.push_back (-0.2f);
    staticObjects[-0.05f] = staticElementsX;

    staticElementsX.clear();
    staticElementsX.push_back (-0.5f);
    staticElementsX.push_back (1.0f);
    staticObjects[-0.4f] = staticElementsX;
    staticElementsX.clear();
    staticElementsX.push_back (1.0f);
    staticElementsX.push_back (-0.5f);
    staticObjects[-0.45f] = staticElementsX;
}

void level0::generateworld()
{
    glBegin(GL_QUADS);
    glColor3f(0.37, 0.30, 0.22);
    for( std::map<double, std::vector<double> >::iterator it = staticObjects.begin();
    it != staticObjects.end(); ++it)
    {
        //draw time ;)
        std::vector<double> xValue = (*it).second;
        double yValue = (*it).first;
        std::cout << yValue << " : " << xValue[0] << xValue[1] << std::endl;
        glVertex2f(xValue[0], yValue);
        glVertex2f(xValue[1], yValue);
        it++;
        xValue.clear();
        yValue = (*it).first;
        xValue = (*it).second;
        glVertex2f(xValue[0], yValue);
        glVertex2f(xValue[1], yValue);

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
