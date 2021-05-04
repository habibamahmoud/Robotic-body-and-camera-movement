#include <stdlib.h>
#include <GL/glut.h>


int moving, startx, starty;

static int elbow[] = { 0, 0 };
static int shoulder[] = { 0, 0 };
static int shoulder_Z[] = { 0, 0 };
static int finger_up[] = { 0, 0 };
static int finger_base[] = { 0, 0 };
static int legR[] ={0,0};
static int legL[] ={0,0};
static int knee[]={0 ,0};



GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);


    // START OF TRUNK
    glPushMatrix();
    glTranslatef(0.0, 0.25, 0.0);
    glScalef(1, 0.5, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    // END OF TRUNK

    // START OF STOMACH
    glPushMatrix();
    glTranslatef(0.0, 1.25, 0.0);
    glScalef(1, 1.5, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    // END OF STOMACH

    // START OF RIGHT LEG
    glPushMatrix();

    glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)legR[0], 0.0, 0.0, 1.0);
    glTranslatef(-0.1, -0.25, 0.0);

    glRotatef((GLfloat)legL[0], 1.0, 0.0, 0.0);
    glTranslatef(0.3, -0.5, 0.0);

    glPushMatrix();
    glScalef (0.4, 1.5, 0.5);
    glutWireCube(1.0);
    glPopMatrix();


    glTranslatef(0.0, -0.75, 0.0);
    glRotatef(GLfloat (knee[0]), 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glPushMatrix();
    glScalef (0.4, 1.0, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.0, -0.625, 0.0);
    glPushMatrix();
    glScalef (0.5, 0.25, 0.9);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    // END OF RIGHT LEG

    //START OF LEFT LEG
    glPushMatrix();

    glTranslatef(-0.1, 0.0, 0.0);
    glRotatef((GLfloat)legR[1], 0.0, 0.0, 1.0);
    glTranslatef(0.1, -0.25, 0.0);

    glRotatef((GLfloat)legL[1], 1.0, 0.0, 0.0);
    glTranslatef(-0.29, -0.5, 0.0);

    glPushMatrix();
    glScalef (0.4, 1.5, 0.5);
    glutWireCube(1.0);
    glPopMatrix();


    glTranslatef(0.0, -0.75, 0.0);
    glRotatef(GLfloat (knee[1]), 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glPushMatrix();
    glScalef (0.4, 1.0, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.0, -0.625, 0.0);
    glPushMatrix();
    glScalef (0.5, 0.25, 0.9);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    //END OF LEFT LEG
    


    // START OF HEAD
    glPushMatrix();
    glTranslatef(0.0, 2.5, 0.0);
    glutWireSphere(0.35, 15, 15);
    glPopMatrix();
    // END OF HEAD

    // START OF RIGHT ARM

    glPushMatrix();

    glTranslatef(0.88, 1.85, 0);

    glRotatef((GLfloat)shoulder_Z[0], 1.0, 0.0, 0.0);


    glTranslatef(-0.375, 0, 0);
    glRotatef(shoulder[0], 0.0, 0.0, 1.0);
    glTranslatef(0.375, 0, 0);

    
    glPushMatrix();
    glScalef(0.75, 0.3, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.75, 0, 0);

    glTranslatef(-0.375, 0, 0.0);
    glRotatef((GLfloat)elbow[0], 0.0, 0.0, 1.0);
    glTranslatef(0.375, 0, 0.0);
    glPushMatrix();
    glScalef(0.75, 0.3, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

    

    // START OF FINGER 1
    glPushMatrix();

    glTranslatef(0.45, 0.05, 0.1125);
    glTranslatef(-0.1, 0, 0);
    glRotatef(finger_base[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glRotatef(finger_up[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 1


    // START OF FINGER 2
    glPushMatrix();

    glTranslatef(0.45, 0.05, 0.0375);
    glTranslatef(-0.1, 0, 0);
    glRotatef(finger_base[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glRotatef(finger_up[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 2

    // START OF FINGER 3
    glPushMatrix();

    glTranslatef(0.45, 0.05, -0.0375);

    glTranslatef(-0.1, 0, 0);
    glRotatef(finger_base[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glRotatef(finger_up[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 3


    // START OF FINGER 4
    glPushMatrix();

    glTranslatef(0.45, 0.05, -0.1125);
    glTranslatef(-0.1, 0, 0);
    glRotatef(finger_base[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glRotatef(finger_up[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 4


    // START OF FINGER 5
    glPushMatrix();
    glTranslatef(0.475, -0.1, 0);
    glTranslatef(-0.1, 0, 0);
    glRotatef(-finger_base[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glRotatef(-finger_up[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 5

    glPopMatrix();
    // END OF RIGHT ARM


    // START OF LEFT ARM

    glPushMatrix();



    glTranslatef(-0.88, 1.85, 0);
    glRotatef((GLfloat)shoulder_Z[1], 1.0, 0.0, 0.0);
    glTranslatef(0.375, 0, 0);
    glRotatef(shoulder[1], 0.0, 0.0, 1.0);
    glTranslatef(-0.375, 0, 0);

    
    glPushMatrix();
    glScalef(0.75, 0.3, 0.3);
    glutWireCube(1.0);
    glPopMatrix();



    glTranslatef(-0.75, 0, 0);

    glTranslatef(0.375, 0, 0.0);
    glRotatef((GLfloat)elbow[1], 0.0, 0.0, 1.0);
    glTranslatef(-0.375, 0, 0.0);
    glPushMatrix();
    glScalef(0.75, 0.3, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

   

    // START OF FINGER 1
    glPushMatrix();

    glTranslatef(-0.475, 0.05, 0.1125);
    glTranslatef(0.1, 0, 0);
    glRotatef(finger_base[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(finger_up[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 1


    // START OF FINGER 2
    glPushMatrix();

    glTranslatef(-0.475, 0.05, 0.0375);
    glTranslatef(0.1, 0, 0);
    glRotatef(finger_base[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(finger_up[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 2

    // START OF FINGER 3
    glPushMatrix();

    glTranslatef(-0.475, 0.05, -0.0375);
    glTranslatef(0.1, 0, 0);
    glRotatef(finger_base[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(finger_up[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 3


    // START OF FINGER 4
    glPushMatrix();

    glTranslatef(-0.475, 0.05, -0.1125);
    glTranslatef(0.1, 0, 0);
    glRotatef(finger_base[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(finger_up[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 4


    // START OF FINGER 5
    glPushMatrix();

    glTranslatef(-0.475, -0.1, 0);
    glTranslatef(0.1, 0, 0);
    glRotatef(-finger_base[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(-finger_up[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 5

    glPopMatrix();
    // END OF LEFT ARM

    glPopMatrix();
    glutSwapBuffers();

}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    //LEGS MOVMENT
    case 'k':
    if(legL[1] >= -70){
        legL[1] = (legL[1]-5) %360;
        glutPostRedisplay();
    }
    break;
    case 'K':
    if(legL[1] <= 70){
        legL[1] = (legL[1]+5) %360;
        glutPostRedisplay();
    }
    break;
    case 'j':
    if(legR[1]>= -70){
        legR[1]  = (legR[1]-5) %360;
        glutPostRedisplay();
    }
    break;
    case 'J':
    if(legR[1]<= 2){
        legR[1]  = (legR[1]+5) %360;
        glutPostRedisplay();
    }
    break;


    case 'l':
    if(legL[0] >= -70){
        legL[0] = (legL[0]-5) %360;
        glutPostRedisplay();
    }
    break;
    case 'L':
    if(legL[0] <= 70){
        legL[0] = (legL[0]+5) %360;
        glutPostRedisplay();
    }
    break;
    case 'P':
    if(legR[0]>= -2){
        legR[0]  = (legR[0]-5) %360;
        glutPostRedisplay();
    }
    break;
    case 'p':
    if(legR[0]<= 70){
        legR[0]  = (legR[0]+5) %360;
        glutPostRedisplay();
    }
    break;
    //KNEE MOVMENTS
    case 'y':
    if(knee[0] <=70){
        knee[0] = (knee[0]+5) %360;
        glutPostRedisplay();
    }
    break;
    case 'Y':
    if(knee[0] >=-15){
        knee[0] = (knee[0]-5) %360;
        glutPostRedisplay();
    }
    break;
    case 't':
    if(knee[1] <=70){
        knee[1] = (knee[1]+5) %360;
        glutPostRedisplay();
    }
    break;
    case 'T':
    if(knee[1] >=-15){
        knee[1] = (knee[1]-5) %360;
        glutPostRedisplay();
    }
    break;

       // shoulder MOVEMENT
    case 's':
        if (shoulder[1] < 90) {
            shoulder[1] = (shoulder[1] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'S':
        if (shoulder[1] > -90) {
            shoulder[1] = (shoulder[1] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'D':
        if (shoulder[0] < 90) {
            shoulder[0] = (shoulder[0] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'd':
        if (shoulder[0] > -90) {
            shoulder[0] = (shoulder[0] - 5) % 360;
            glutPostRedisplay();
        }
        break;


        // ELBOWS MOVEMENT
    case 'e':
        if (elbow[1] < 130) {
            elbow[1] = (elbow[1] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'E':
        if (elbow[1] > -120) {
            elbow[1] = (elbow[1] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'R':
        if (elbow[0] < 130) {
            elbow[0] = (elbow[0] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'r':
        if (elbow[0] > -120) {
            elbow[0] = (elbow[0] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'z':
        if (shoulder_Z[0] < 90) {
            shoulder_Z[0] = (shoulder_Z[0] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'Z':
        if (shoulder_Z[0] > -90) {
            shoulder_Z[0] = (shoulder_Z[0] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'x':
        if (shoulder_Z[1] < 90) {
            shoulder_Z[1] = (shoulder_Z[1] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'X':
        if (shoulder_Z[1] > -90) {
            shoulder_Z[1] = (shoulder_Z[1] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    //finger_up movement
    case 'q':
        if (finger_base[1] < 20) {
            finger_base[1] = (finger_base[1] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'Q':
        if (finger_base[1] > -20) {
            finger_base[1] = (finger_base[1] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'w':
        if (finger_up[1] < 20) {
            finger_up[1] = (finger_up[1] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'W':
        if (finger_up[1] > -20) {
            finger_up[1] = (finger_up[1] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'i':
        if (finger_base[0] < 20) {
            finger_base[0] = (finger_base[0] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'I':
        if (finger_base[0] > -20) {
            finger_base[0] = (finger_base[0] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'o':
        if (finger_up[0] < 20) {
            finger_up[0] = (finger_up[0] + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'O':
        if (finger_up[0] > -20) {
            finger_up[0] = (finger_up[0] - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}


static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
