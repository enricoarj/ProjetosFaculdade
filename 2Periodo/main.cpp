#ifdef _APPLE_
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

float alpha = 0;
float beta = 0;
float delta = 0.6;

typedef struct
{
    float x;
    float y;
    float z;
} coordenadas;

coordenadas esfera = {0.0f, -10.0f, 0.0f};
float deslocesferax = 0.0f;
float deslocesferay = 0.1f;

int chute = 0;
int gols = 0;
int chutesFora = 0;
GLfloat limiteY = 9;

GLfloat escala = 1;
GLfloat angulo = 5;
GLfloat moverx = 5;
GLfloat movery = 5;
int trabalhoNome = 0;

//
void init()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);
}

//Codigo que possibilita o placar
void renderText(float x, float y, void *font, const char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    while (*string)
    {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

void projetoNome(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1920,0,1080);

    glLineWidth(4);
    glColor3f(0,0,0);
    glScalef(escala,escala,0);
    glRotatef(angulo, 0, 1, 0);
    glTranslatef(moverx,movery,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//Nome
    glBegin(GL_LINES);
//R
    glVertex2f(900, 250);
    glVertex2f(750, 525);
    glVertex2f(750, 700);
    glVertex2f(750, 250);
    glVertex2f(750, 525);
    glVertex2f(900, 700);
    glVertex2f(900, 700);
    glVertex2f(750, 700);
//I
    glVertex2f(1100, 700);
    glVertex2f(950, 700);
    glVertex2f(950, 250);
    glVertex2f(1100, 250);
    glVertex2f(1025, 700);
    glVertex2f(1025, 250);

//K
    glVertex2f(1150, 250);
    glVertex2f(1150, 700);

    glVertex2f(1300, 700);
    glVertex2f(1150, 525);

    glVertex2f(1150, 525);
    glVertex2f(1300, 525);

    glVertex2f(1300, 525);
    glVertex2f(1300, 250);
//U
    glVertex2f(1350, 700);
    glVertex2f(1350, 250);
    glVertex2f(1500, 250);
    glVertex2f(1500, 700);
    glVertex2f(1350, 250);
    glVertex2f(1500, 250);

    glEnd();
    glFlush();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.234,0.4321,0.12412,0);

// Traves do Gol
    glBegin(GL_LINES);
    glVertex2f(-3,8);
    glVertex2f(3,8);

    glVertex2f(-2.8,7.8);
    glVertex2f(2.8,7.8);

    glVertex2f(-3,3);
    glVertex2f(-3,8);

    glVertex2f(3,3);
    glVertex2f(3,8);

    glVertex2f(-2.8,3);
    glVertex2f(-2.8,7.8);

    glVertex2f(2.8,3);
    glVertex2f(2.8,7.8);

    glVertex2f(-10,3);
    glVertex2f(10,3);

    glEnd();


//Placar
    char placar[100];
    sprintf(placar, "Gols= %d, Chutes errados= %d", gols, chutesFora);

    renderText(-9, 8, GLUT_BITMAP_HELVETICA_18, placar);

// esfera
    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);
    glColor3f(0.8124, 0.9123, 0.9123);
    glPushMatrix();

    glTranslatef(esfera.x, esfera.y, esfera.z);
    glutWireSphere(1, 20, 20);
    glPopMatrix();

    glLoadIdentity();

//Parte que entra no trabalho do nome
    if(trabalhoNome == 1)
    {
        projetoNome();
    }
    glutSwapBuffers();
}

void moveBola(int value)
{
    if (chute)
    {
        esfera.x += deslocesferax;
        esfera.y += deslocesferay;

        if (esfera.y >= limiteY)
        {
            if (esfera.x <= 3 && esfera.x >= -3)
            {
                gols++;
                printf("GOL!\n");
            }
            else
            {
                chutesFora++;
                printf("POR POUCO!\n");
            }
            esfera.x = 0;
            esfera.y = -10;
            chute = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(5, moveBola, 0);
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r')
    {
        gols = 0;
        chutesFora = 0;
    }
    if (key == ' ')
    {
        chute = 1;
    }
    if (key == 27)
    {
        exit(0);
    }
    if (key == 'c')
    {
        trabalhoNome = 1;
    }
    if(key == 'q')
    {
        angulo--;
    }
    if(key == 'e')
    {
        angulo++;
    }
    if(key == '+')
    {
        escala=escala+0.5;
    }
    if(key == '-')
    {
        if(escala>0.5)
        {
            escala=escala-0.5;
        }
    }
    if(key == 'a')
    {
        moverx--;
    }
    if(key == 'd')
    {
        moverx++;
    }
    if(key == 'w')
    {
        movery++;
    }
    if(key == 's')
    {
        movery--;
    }
    glutPostRedisplay();
}

void listeningSpKey (GLint tecla, GLint x, GLint y)
{
    switch(tecla)
    {
    case GLUT_KEY_UP:
        esfera.y++;
        break;
    case GLUT_KEY_DOWN:
        esfera.y--;
        break;
    case GLUT_KEY_LEFT:
        esfera.x--;
        break;
    case GLUT_KEY_RIGHT:
        esfera.x++;
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Futebas");
    init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glutDisplayFunc(display);
    glutTimerFunc(5, moveBola, 0);
    glutMainLoop();
    return 0;
}
