#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "include/pinko.h"

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void)
{
    double position = 0.0f;
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

        glPushMatrix();
        glRotatef((float) glfwGetTime() * 100.0f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex2f(0.1f, -0.6f);
        glVertex2f(0.7f, -0.6f);
        glVertex2f(0.4f, -0.1f);
        glEnd();
        glPopMatrix();

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

        // Now draw the triangle


//        glPushMatrix();
//        //glRotatef((float) glfwGetTime() * 100.0f, 10.f, 0.f, 1.f);
//        glTranslatef((float) glfwGetTime() * 0.5f, 0.f, 0.f);
//        glBegin(GL_TRIANGLES);
//        glVertex2f(-0.1f, 0.6f);
//        glVertex2f(-0.7f, 0.6f);
//        glVertex2f(-0.4f, 0.1f);
//        glEnd();
//        glPopMatrix();

        //another item :D
        glTranslatef(position, 0.f, 0.f);
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
        std::cout << "prawo";
        break;
    case 263:
        std::cout << "lewo";
        break;
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, GL_TRUE);
        break;
    default:
        break;
    }
}
