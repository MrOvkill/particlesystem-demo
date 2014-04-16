#include <GLFW/glfw3.h>
#include "SimpleParticleEngine.hpp"
#include "Particle.hpp"
#include "Util.hpp"
#include <GL/glu.h>

#define PARTICLE_AMT 500

int main(void) {
    trillek::util::Util::Seed();
    trillek::particle::SimpleParticleEngine engine;
    engine.Init(PARTICLE_AMT, 0, 0, -500);
    
    engine.lifeMin = 5;
    engine.lifeMax = 10;
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Grant Particle Test", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.f, (800.f/800.f), 0.0001f, 1000.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0, 0, 0, 1);
    glBlendFunc(GL_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        engine.Update();
        
        for(int i = 0; i < PARTICLE_AMT; i++)
        {
            float r = trillek::util::Util::RandFloat(0.f, 1.f);
            float g = trillek::util::Util::RandFloat(0.f, 1.f);
            float b = trillek::util::Util::RandFloat(0.f, 1.f);
            
            glPushMatrix();
            
            glTranslatef(engine.particles[i].x, engine.particles[i].y, engine.particles[i].z);
            glColor3f(r, g, b);
            glBegin(GL_QUADS);
            glVertex3f(-1.5, 1.5, 0);
            glVertex3f(1.5, 1.5, 0);
            glVertex3f(1.5, -1.5, 0);
            glVertex3f(-1.5, -1.5, 0);
            glEnd();
            
            glPopMatrix();
        }
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
