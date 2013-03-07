/* TaeZ-Stkyoht */
/*****************
Oðuzhan TÜRK
040080232
*****************/

#include <GL/glut.h>


GLfloat	lPos[]={0, 0, 0, 1};
GLfloat sLight[]={0.95, 0.95, 0.95, 1};
GLfloat wLight[]={0.25, 0.25, 0.25, 1};


void Render(){
	static GLfloat rSun=0;
	static GLfloat rMercury=0;
	static GLfloat rVenus=0;
	static GLfloat rEarth=0;
	static GLfloat rMoon=0;
	static GLfloat rMars=0;
	static GLfloat rPhobos=0;
	static GLfloat rDeimos=0;
	static GLfloat rJupiter=0;
	static GLfloat rSaturn=0;
	static GLfloat rUranus=0;
	static GLfloat rNeptune=0;
	static GLfloat rPluto=0;
	static GLfloat unitRadius=8;
	static GLuint shapeQuality=10;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	/* Sun */
	glLightfv(GL_LIGHT0, GL_POSITION, lPos);
	glTranslatef(0, 0, -300);
	glColor3ub(255, 255, 0);
	glRotatef(rSun, 0, 1, 0);
	glutSolidSphere(2.1*unitRadius, shapeQuality, shapeQuality);
	glLightfv(GL_LIGHT0, GL_POSITION, lPos);
	rSun+=3;
	if(rSun>360)
		rSun=0;


	/* Mercury */
	glPushMatrix();
	glRotatef(rMercury, 0, 1, 0);
	glColor3ub(180, 180, 180);
	glTranslatef(30, 0, 0);
	glRotatef(rMercury, 0, 1, 0);
	glutSolidSphere(0.61*unitRadius, shapeQuality, shapeQuality);
	rMercury+=8;
	if(rMercury>360)
		rMercury=0;
	glPopMatrix();


	/* Venus */
	glPushMatrix();
	glRotatef(rVenus, 0, 1, 0);
	glColor3ub(255, 100, 100);
	glTranslatef(45, 0, 0);
	glRotatef(rVenus, 0, 1, 0);
	glutSolidSphere(1.7*unitRadius, shapeQuality, shapeQuality);
	rVenus+=4;
	if(rVenus>360)
		rVenus=0;
	glPopMatrix();


	/* Earth */
	glPushMatrix();
	glRotatef(rEarth, 0, 1, 0);
	glColor3ub(0, 0, 255);
	glTranslatef(95, 0, 0);
	glRotatef(rEarth, 0, 1, 0);
	glutSolidSphere(1.8*unitRadius, shapeQuality, shapeQuality);
	rEarth+=3;
	if(rEarth>360)
		rEarth=0;
	
	/* Moon */
	glPushMatrix();
	glColor3ub(200, 200, 200);
	glRotatef(rMoon, 0, 1, 0);
	glTranslatef(3*unitRadius, 0, 0);
	glRotatef(rMoon, 0, 1, 0);
	glutSolidSphere(0.5*unitRadius, shapeQuality, shapeQuality);
	rMoon+=12;
	if(rMoon>360)
		rMoon=0;
	glPopMatrix();
	glPopMatrix();


	/* Mars */
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(rMars, 0, 1, 0);
	glTranslatef(140, 0, 0);
	glRotatef(rMars, 0, 1, 0);
	rMars+=3;
	if(rMars>360)
		rMars=0;
	glutSolidSphere(1.65*unitRadius, shapeQuality, shapeQuality);

	/* Phobos */
	glPushMatrix();
	glColor3ub(150, 120, 100);
	glRotatef(rPhobos, 0, 1, 0);
	glTranslatef(2.5*unitRadius, 0, 0);
	glRotatef(rPhobos, 0, 1, 0);
	rPhobos+=15;
	if(rPhobos>360)
		rPhobos=0;
	glutSolidSphere(0.9*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();

	/* Deimos */
	glPushMatrix();
	glColor3ub(190, 175, 255);
	glRotatef(rDeimos, 0, 1, 0);
	glTranslatef(4*unitRadius, 0, 0);
	glRotatef(rDeimos, 0, 1, 0);
	rDeimos+=10;
	if(rDeimos>360)
		rDeimos=0;
	glutSolidSphere(0.5*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();
	glPopMatrix();


	/* Jupiter */
	glPushMatrix();
	glColor3ub(200, 50, 0);
	glRotatef(rJupiter, 0, 1, 0);
	glTranslatef(200, 0, 0);
	glRotatef(rJupiter, 0, 1, 0);
	rJupiter+=3;
	if(rJupiter>360)
		rJupiter=0;
	glutSolidSphere(3.7*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();


	/* Saturn */
	glPushMatrix();
	glColor3ub(150, 120, 0);
	glRotatef(rSaturn, 0, 1, 0);
	glTranslatef(230, 0, 0);
	glRotatef(rSaturn, 0, 1, 0);
	rSaturn+=2;
	if(rSaturn>360)
		rSaturn=0;
	glutSolidSphere(3.1*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();


	/* Uranus */
	glPushMatrix();
	glColor3ub(0, 200, 255);
	glRotatef(rUranus, 0, 1, 0);
	glTranslatef(250, 0, 0);
	glRotatef(rUranus, 0, 1, 0);
	rUranus+=1;
	if(rUranus>360)
		rUranus=0;
	glutSolidSphere(1.26*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();


	/* Neptune */
	glPushMatrix();
	glColor3ub(0, 100, 255);
	glRotatef(rNeptune, 0, 1, 0);
	glTranslatef(270, 0, 0);
	glRotatef(rNeptune, 0, 1, 0);
	rNeptune+=3;
	if(rNeptune>360)
		rNeptune=0;
	glutSolidSphere(1.23*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();


	/* Pluto */
	glPushMatrix();
	glColor3ub(200, 200, 200);
	glRotatef(rPluto, 0, 1, 0);
	glTranslatef(290, 0, 0);
	glRotatef(rPluto, 0, 1, 0);
	rPluto+=1;
	if(rPluto>360)
		rPluto=0;
	glutSolidSphere(0.66*unitRadius, shapeQuality, shapeQuality);
	glPopMatrix();


	glPopMatrix();

	glutSwapBuffers();
}

void Timer(int value){
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 1);
}

void Reshape(int width, int height){
	GLfloat fAspect;
	if(height==0) height=1;
    glViewport(0, 0, width, height);
	fAspect = (GLfloat)width/(GLfloat)height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85, fAspect, 1, 700);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Init(){
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, wLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lPos);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glClearColor(0, 0, 0, 1);
}

void Keyboard(unsigned char key, int x, int y){
   switch(key){
      case 27:
         exit(0);
         break;
   }
}


int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Solar System");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Render);
	glutKeyboardFunc(Keyboard);
    glutTimerFunc(100, Timer, 1);
	Init();
	glutMainLoop();
	return 0;
}
