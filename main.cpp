#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>
#include <set>

#include "include/pinko.h"
#include "include/level0.h"
#include "include/physics.h"

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

pinko MyPinko;

int main(void)
{
    level0 level;
    physics physic;
    double position = 0.0f, positionY = 0.0f;
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Pinko v1.0.0", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        level.generateworld();

        //another item :D
        position += MyPinko.getMove();
        positionY -= physic.getGravityFactor();
        glPushMatrix();
        if (physic.checkExitToBorderX(position) == true)
        {
            position -= MyPinko.getMove();
        }

        if (physic.checkExitToBorderY(positionY) == true)
        {
            positionY += physic.getGravityFactor();
        }

        glTranslatef((float) position, positionY, 0.f);
        MyPinko.generatePinko();
        glPopMatrix();
        MyPinko.cleanMove();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch(key) {
    case 262:
        MyPinko.goForward();
        break;
    case 263:
        MyPinko.goBack();
        break;
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, GL_TRUE);
        break;
    default:
        break;
    }
}
