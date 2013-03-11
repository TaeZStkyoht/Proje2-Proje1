/* TaeZ-Stkyoht */
/*****************
Oðuzhan TÜRK
040080232
*****************/

#include<stdio.h>
#include<GL/glut.h>
#include "SOIL.h"


GLint LoadGLTexture(const char *filename, GLUquadric *sphere){

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricTexture(sphere, GL_TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);

    GLuint _texture;
    _texture = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture 
	(
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT 
     );
    if(!_texture) printf("SOIL loading error: '%s'\n", SOIL_last_result());
    return _texture;
}

GLfloat	lPos[]={0, 0, 0, 1};
GLfloat sLight[]={1, 1, 1, 1};
GLfloat wLight[]={0.15, 0.15, 0.15, 1};

void Render(){ // Texture'lar görüntülemeyi yavaþlattýðý için frame sayýsýnda azalma olabilir
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
	static GLuint shapeQuality=256;
	static GLUquadric *planet;
	static GLuint unitRoundSpeed=4;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	// Gezegenlerin hýzlarý farklý. Bir süre sonra oluþan kombinasyondan anlaþýlabilir.

	/* Sun */
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("sun.jpg", planet));
	glLightfv(GL_LIGHT0, GL_POSITION, lPos);
	glTranslatef(0, 0, -300);
	glColor3f(1, 1, 1);
	glRotatef(rSun*unitRoundSpeed, 0, 1, 0);
	gluSphere(planet, 2.1*unitRadius, shapeQuality, shapeQuality);
	glLightfv(GL_LIGHT0, GL_POSITION, lPos);
	rSun+=3;
	if(rSun>360)
		rSun=0;
	glDisable(GL_TEXTURE_2D);


	/* Mercury */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("mercury.jpg", planet));
	glRotatef(rMercury, 0, 1, 0);
	glColor3f(1, 1, 1);
	glTranslatef(30, 0, 0);
	glRotatef(rMercury*unitRoundSpeed, 0, 1, 0);
	rMercury+=8;
	if(rMercury>360)
		rMercury=0;
	gluSphere(planet, 0.61*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	/* Venus */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("venus.jpg", planet));
	glRotatef(rVenus, 0, 1, 0);
	glColor3f(1, 1, 1);
	glTranslatef(45, 0, 0);
	glRotatef(rVenus*unitRoundSpeed, 0, 1, 0);
	rVenus+=4;
	if(rVenus>360)
		rVenus=0;
	gluSphere(planet, 1.7*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	/* Earth */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("earth.jpg", planet));
	glRotatef(rEarth, 0, 1, 0);
	glColor3f(1, 1, 1);
	glTranslatef(95, 0, 0);
	glRotatef(rEarth*unitRoundSpeed, 0, 1, 0);
	rEarth+=3;
	if(rEarth>360)
		rEarth=0;
	gluSphere(planet, 1.8*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	
	/* Moon */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("moon.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rMoon, 0, 1, 0);
	glTranslatef(3*unitRadius, 0, 0);
	glRotatef(rMoon*unitRoundSpeed, 0, 1, 0);
	rMoon+=12;
	if(rMoon>360)
		rMoon=0;
	gluSphere(planet, 0.5*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();


	/* Mars */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("mars.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rMars, 0, 1, 0);
	glTranslatef(140, 0, 0);
	glRotatef(rMars*unitRoundSpeed, 0, 1, 0);
	rMars+=3;
	if(rMars>360)
		rMars=0;
	gluSphere(planet, 1.65*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);

	/* Phobos */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("phobos.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rPhobos, 0, 1, 0);
	glTranslatef(2.5*unitRadius, 0, 0);
	glRotatef(rPhobos*unitRoundSpeed, 0, 1, 0);
	rPhobos+=15;
	if(rPhobos>360)
		rPhobos=0;
	gluSphere(planet, 0.9*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	/* Deimos */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("deimos.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rDeimos, 0, 1, 0);
	glTranslatef(4*unitRadius, 0, 0);
	glRotatef(rDeimos*unitRoundSpeed, 0, 1, 0);
	rDeimos+=10;
	if(rDeimos>360)
		rDeimos=0;
	gluSphere(planet, 0.5*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();


	/* Jupiter */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("jupiter.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rJupiter, 0, 1, 0);
	glTranslatef(200, 0, 0);
	glRotatef(rJupiter*unitRoundSpeed, 0, 1, 0);
	rJupiter+=3;
	if(rJupiter>360)
		rJupiter=0;
	gluSphere(planet, 3.7*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	/* Saturn */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("saturn.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rSaturn, 0, 1, 0);
	glTranslatef(230, 0, 0);
	glRotatef(rSaturn*unitRoundSpeed, 0, 1, 0);
	rSaturn+=2;
	if(rSaturn>360)
		rSaturn=0;
	gluSphere(planet, 3.1*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	/* Uranus */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("uranus.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rUranus, 0, 1, 0);
	glTranslatef(250, 0, 0);
	glRotatef(rUranus*unitRoundSpeed, 0, 1, 0);
	rUranus+=1;
	if(rUranus>360)
		rUranus=0;
	gluSphere(planet, 1.26*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	/* Neptune */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("neptune.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rNeptune, 0, 1, 0);
	glTranslatef(270, 0, 0);
	glRotatef(rNeptune*unitRoundSpeed, 0, 1, 0);
	rNeptune+=3;
	if(rNeptune>360)
		rNeptune=0;
	gluSphere(planet, 1.23*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	/* Pluto */
	glPushMatrix();
	planet=gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, LoadGLTexture("pluto.jpg", planet));
	glColor3f(1, 1, 1);
	glRotatef(rPluto, 0, 1, 0);
	glTranslatef(290, 0, 0);
	glRotatef(rPluto*unitRoundSpeed, 0, 1, 0);
	rPluto+=1;
	if(rPluto>360)
		rPluto=0;
	gluSphere(planet, 0.66*unitRadius, shapeQuality, shapeQuality);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPopMatrix();

	glutSwapBuffers();
}

void Timer(int value){
    glutPostRedisplay();
    glutTimerFunc(250, Timer, 1);
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
    glutTimerFunc(250, Timer, 1);
	Init();
	glutMainLoop();
	return 0;
}
