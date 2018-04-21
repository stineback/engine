#include <GLUT/glut.h>
#include <Vector3.h>

#define window_width  640
#define window_height 480

GLfloat rtri = 90;
GLfloat rquad = 10;

const Vector3<GLfloat> RED(1.0f,0.0f,0.0f);
const Vector3<GLfloat> GREEN(0.0f,1.0f,0.0f);
const Vector3<GLfloat> BLUE(0.0f,0.0f,1.0f);
const Vector3<GLfloat> YELLOW(1.0f,1.0f,0.0f);
const Vector3<GLfloat> VIOLET(1.0f,0.0f,1.0f);

void setColor(Vector3<GLfloat> color){
	glColor3f(color.getX(), color.getY(), color.getZ());
}

// Main loop
void main_loop_function() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer

	glLoadIdentity(); // Reset The View
	glTranslatef(-1.5f,0.0f,-6.0f);
	glRotatef(rtri,0.0f,1.0f,0.0f);
	glBegin(GL_TRIANGLES);

	// front triangle
	setColor(RED);
	glVertex3f(0.0f, 1.0f, 0.0f);
	setColor(GREEN);
	glVertex3f(-1.0f,-1.0f, 1.0f);
	setColor(BLUE);
	glVertex3f( 1.0f,-1.0f, 1.0f);

	// right triangle
	setColor(RED);
	glVertex3f( 0.0f, 1.0f, 0.0f);
	setColor(BLUE);
	glVertex3f(1.0f,-1.0f, 1.0f);
	setColor(GREEN);
	glVertex3f(1.0f,-1.0f, -1.0f);

	// back triangle
	setColor(RED);
	glVertex3f( 0.0f, 1.0f, 0.0f);
	setColor(GREEN);
	glVertex3f(1.0f,-1.0f, -1.0f);
	setColor(BLUE);
	glVertex3f(-1.0f,-1.0f, -1.0f);

	// left triangle
	setColor(RED);
	glVertex3f( 0.0f, 1.0f, 0.0f);
	setColor(BLUE);
	glVertex3f(-1.0f,-1.0f, -1.0f);
	setColor(GREEN);
	glVertex3f(-1.0f,-1.0f, 1.0f);

	glEnd();

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);
	glRotatef(rquad,1.0f,0.0f,0.0f);
	glBegin(GL_QUADS);

	// top of cube
	setColor(GREEN);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f( -1.0f, 1.0f, -1.0f);
	glVertex3f( -1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f,1.0f, 1.0f);


	// bottom of cube
	setColor(Vector3<GLfloat>(1.0f,0.5f,0.0f));
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f( -1.0f, - 1.0f, -1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);

	// front of cube
	setColor(RED);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f( -1.0f, 1.0f, 1.0f);
	glVertex3f( -1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f,-1.0f, 1.0f);

	// back of cube
	setColor(YELLOW);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f( -1.0f, -1.0f, -1.0f);
	glVertex3f( -1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f,1.0f, -1.0f);

	// left side of cube
	setColor(BLUE);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f( -1.0f, 1.0f, -1.0f);
	glVertex3f( -1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);

	// right side of cube
	setColor(VIOLET);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glVertex3f( 1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f,-1.0f, -1.0f);

	glEnd();
    glutSwapBuffers();

    rtri +=0.2f;
    rquad -=1.5f;
}

void future(){
	  // Z angle
	    static float angle;
	    // Clear color (screen)
	    // And depth (used internally to block obstructed objects)
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    // Load identity matrix
	    glLoadIdentity();
	    // Multiply in translation matrix
	    glTranslatef(0, 0, -10);
	    // Multiply in rotation matrix
	    glRotatef(angle, 0, 0, 1);
	    // Render colored quad
	    glBegin( GL_QUADS);
	    glColor3ub(255, 000, 000);
	    glVertex2f(-1, 1);
	    glColor3ub(000, 255, 000);
	    glVertex2f(1, 1);
	    glColor3ub(000, 000, 255);
	    glVertex2f(1, -1);
	    glColor3ub(255, 255, 000);
	    glVertex2f(-1, -1);
	    glEnd();
	    // Swap buffers (color buffers, makes previous render visible)
	    glutSwapBuffers();
	    // Increase angle to rotate
	    angle += 0.25;
}

// Initialze OpenGL perspective matrix
void GL_Setup(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode( GL_PROJECTION);
    glEnable( GL_DEPTH_TEST);
    gluPerspective(45, (float) width / height, .1, 100);
    glMatrixMode( GL_MODELVIEW);
}

// Initialize GLUT and start main loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(window_width, window_height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Learning openGL");
    glutDisplayFunc(main_loop_function);
    glutIdleFunc(main_loop_function);
    GL_Setup(window_width, window_height);
    glutMainLoop();
    return 0;
}
