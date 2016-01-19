#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
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
        //glRotatef((float) glfwGetTime() * 1.f, 0.f, 0.f, 1.f);
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
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
