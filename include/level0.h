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
private:
    std::vector<double> staticElementsX;
    std::vector<double> staticElementsY;
};

level0::level0()
{
}

void level0::createStaticObjects() {
    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (0.55);
    staticElementsX.push_back (0.55);
    staticElementsX.push_back (-0.5);

    staticElementsX.push_back (-0.55);
    staticElementsX.push_back (-0.50);
    staticElementsX.push_back (-0.50);
    staticElementsX.push_back (-0.55);

    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (0.75);
    staticElementsX.push_back (0.75);
    staticElementsX.push_back (-0.5);

    staticElementsX.push_back (-0.2);
    staticElementsX.push_back (1.0);
    staticElementsX.push_back (1.0);
    staticElementsX.push_back (-0.2);

    staticElementsX.push_back (-0.5);
    staticElementsX.push_back (1.0);
    staticElementsX.push_back (1.0);
    staticElementsX.push_back (-0.5);

    staticElementsY.push_back (0.6);
    staticElementsY.push_back (0.6);
    staticElementsY.push_back (0.55);
    staticElementsY.push_back (0.55);

    staticElementsY.push_back (0.95);
    staticElementsY.push_back (0.95);
    staticElementsY.push_back (-1.0);
    staticElementsY.push_back (-1.0);

    staticElementsY.push_back (0.3);
    staticElementsY.push_back (0.3);
    staticElementsY.push_back (0.25);
    staticElementsY.push_back (0.25);

    staticElementsY.push_back (0.00);
    staticElementsY.push_back (0.00);
    staticElementsY.push_back (-0.05);
    staticElementsY.push_back (-0.05);

    staticElementsY.push_back (-0.4);
    staticElementsY.push_back (-0.4);
    staticElementsY.push_back (-0.45);
    staticElementsY.push_back (-0.45);
}

void level0::generateworld()
{
    createStaticObjects();
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

level0::~level0()
{
}


#endif // LEVEL0_H_INCLUDED
