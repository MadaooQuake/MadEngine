#ifndef LEVEL0_H
#define LEVEL0_H

#include <GLFW/glfw3.h>

#include <set>

class level0
{
public:
    std::set<double> levelX;
    std::set<double> levelY;
    level0();
    virtual ~level0();
    void generateworld();
};

level0::level0()
{
}

void level0::generateworld()
{
//    glPushMatrix();
//    glRotatef((float) glfwGetTime() * 100.0f, 0.f, 0.f, 1.f);
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.0f, 0.0f, 1.0f); // Blue
//    glVertex2f(0.1f, -0.6f);
//    glVertex2f(0.7f, -0.6f);
//    glVertex2f(0.4f, -0.1f);
//    glEnd();
//    glPopMatrix();

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

level0::~level0()
{
}


#endif // LEVEL0_H_INCLUDED
