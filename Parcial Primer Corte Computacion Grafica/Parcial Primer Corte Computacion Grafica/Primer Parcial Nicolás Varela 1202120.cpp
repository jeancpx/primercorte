
#include <stdlib.h> // se declara la libreria stdlib.h ya que me generaba un error 
#include <GL/glut.h> 
#include<iostream>
#include <math.h>

int x = 1700, y = 1700; // Tamaño de la ventana 
void pintaPixel(float x, float y, float r, float g, float b){ // se toman los parametros como float debido a que es una formula matematica a graficar 
	glPointSize(5);// grosor del pixel
	glColor3f(r,g,b);
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
	glutSwapBuffers();
}

void funcion() {
	float v;// variable tipo float para aplicar la funcion matematica 
	for (float i =-3.5 ; i <=12.5 ; i+=0.003) {// rango aproximado de la funcion en el que va recorriendo cada 0.003 pixeles para que la grafica sea mas gruesa y se vea mejor
		v = (3.5*(i)+12.5)*70;// la funcion matematica se multiplica por 70 para que se logre observar mejor 
		pintaPixel(i*70, v, 1, 0, 0);// a los valores en X se multiplica por 70 para que se logre observar mejor 
	}
}
void plano() {
	for (int i = -x / 2; i < x / 2; i++) {//For para el eje x 
		pintaPixel(i, 0, 1, 1, 1);
	}
	for (int i = -x / 2; i < x / 2; i++) {//For para el eje y 
		pintaPixel(0, i, 1, 1, 1);
	}
	funcion();
}
void coordenadas() {
	int x = 0, y = 0;//se toma como x=0,y=0 el punto de origen 
	plano();
	pintaPixel(x, y, 0, 0, 0);
}
int main(int argc, char*argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(x, y);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Grafica Comportamiento");
	gluOrtho2D(-x / 2, x / 2, -y / 2, y / 2);//Distribucion de la ventana para cada uno de los cuadrantes del plano cartesiano 
	glutDisplayFunc(coordenadas);//se llama a la funcion coordenadas que a su vez esta llama a la funcion plano y el plano llama a la funcion matematica a graficar 
	glutMainLoop();
	return 0;
}
