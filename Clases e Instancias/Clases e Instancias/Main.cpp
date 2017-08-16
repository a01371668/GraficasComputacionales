/*
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
*/

//Se va a la carpeta de video, evalua la tarjea de video y obtiene todo el API más reciente de openGL
#include <GL/glew.h>
//Se ocupa de manejar ventanas (openGL no maneja ventanas)
#include <GL/freeglut.h>
using namespace std;

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f); 

	glEnd();
	glutSwapBuffers();

}

int main(int argc, char* argv[]) {
	//Inicializar freeglut
	//Freeglut se encarga de crear una ventana donde podemos dibujar
	glutInit(&argc, argv);

	//Inicializar el contexto de OpenGL. EL contexto se refiere a las capacidades que va a tener nuestra aplicación gráfica.
	//En este caso estamos trabajando con el pipeline clásico.
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	//freeglut nos permite controlar eventos que ocurren en la ventana. Un evento que nos interesa es cuando alguien cierra la ventana.
	//En este caso, estamos dejando de renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
	//Configuramos el framebuffer. En este caso estamos solicitando un buffer true color RGBA,
	//un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//Iniciar las dimensiones de la ventana en pixeles
	glutInitWindowSize(400, 400);

	//Creamos la ventana y le damos un título.
	glutCreateWindow("Hello Wordl GL");
	
	//Asociamos una función de render. Ésta función se mandará a llamar para dibujar un frame
	glutDisplayFunc(GameLoop);

	//Inicializar GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra tarjeta de video.
	glewInit();

	//Configuracion de OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;

	/*
	//Crear objeto circle
	std::cout << "Circulo" << std::endl;
	Circle circulo(2.0,"green");
	std::cout << circulo.GetRadius() << std::endl;

	//Crear objeto rectangle
	std::cout << "\nRectangulo" << std::endl;
	Rectangle rectangulo(5.0, 3.0);
	std::cout << rectangulo.GetHeight() << std::endl;
	std::cout << rectangulo.GetWidth() << std::endl;
	std::cout << rectangulo.GetArea() << std::endl;
	std::cout << rectangulo.GetPerimeter() << std::endl;

	//Objeto Employee
	std::cout << "\nEmployee" << std::endl;
	Employee empleado(1, "Alonso", "Morales", 100);
	//std::cout << empleado.Print << std::endl;
	std::cout << empleado.GetAnualSalary() << std::endl;
	*/
	
	//Evitar que se cierre la pantalla output
	//std:: cin.get()
}