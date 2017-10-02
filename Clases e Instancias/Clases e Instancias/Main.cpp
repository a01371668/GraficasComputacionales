/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*	Main.cpp
*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Mesh.h"
#include "ShaderProgram.h"
#include <iostream>
#include <vector>

Mesh _mesh;
ShaderProgram _shaderProgram;

void Initialize()
{
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, 1.0f));
	positions.push_back(glm::vec2(-1.0f, 1.0f));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));

	_mesh.CreateMesh(4);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("iResolution", 400.0f, 400.0f);
	_shaderProgram.Deactivate();
}

// Esta función se mandará a llamar para dibujar un frame.
void GameLoop()
{
	// Siempre es recomendable borrar la información anterior del framebuffer.
	// En este caso estamos borrando la información de color,
	// y la información de profundidad.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_shaderProgram.Activate();

	_mesh.Draw(GL_TRIANGLE_FAN);

	_shaderProgram.Deactivate();

	// Cambiar el buffer actual.
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	// Inicialización de Freeglut.
	// Freeglut se encarga de crear una ventana
	// En donde vamos a poder dibujar
	glutInit(&argc, argv);
	// Freeglut es el encargado de solicitar un contexto
	// de OpenGL. El contexto se refiere a las capacidades
	// que va a tener nuestra aplicación gráfica.
	glutInitContextVersion(4, 0);
	// Tenemos que informar que queremos trabajar únicamente con
	// el pipeline programable
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la venta.
	// Un evento que nos interesa es cuando alguien cierra la venta.
	// En este caso simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando
	// un buffer true color RGBA, un buffer de profundidad y un segundo buffer
	// para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	// Le damos un nombre a la ventana y la creamos.
	glutCreateWindow("Hello World GL");
	// Asociamos una funcion de render. Esta función se
	// mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);

	// Inicializar GLEW. Esta librería se encarga
	// de obtener el API de OpenGL de nuestra tarjeta
	// de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configuramos OpenGL. Este es el color
	// por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	Initialize();

	// Iniciar la aplicación. El main se pausará en esta
	// línea hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	// Terminar.
	return 0;
}
