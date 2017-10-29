/*
*	Autor1: Alonso Issac Morales Gutiérrez	A01371668
*	Autor2: Gabriela Aguilar Lugo			A01373890
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*	Main.cpp
*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Camera _camera;
Transform _transform;
Transform _transform2;

void Initialize()
{
	// Creando toda la memoria que el programa va a utilizar.
	// Creación del atributo de posiciones de los vértices.
	// Lista de vec2
	// Claramente en el CPU y RAM
	std::vector<glm::vec3> positions;
	positions.push_back(glm::vec3(3.0f, 0, 3.0f));  
	positions.push_back(glm::vec3(3.0f, 0, -3.0f)); 
	positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); 
	positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); 

	positions.push_back(glm::vec3(-3.0f, 0, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0, 3.0f));
	positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f));
		
	positions.push_back(glm::vec3(-3.0f, 0, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 0, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f));

	positions.push_back(glm::vec3(3.0f, 0, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 0, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f));

	positions.push_back(glm::vec3(3.0f, 0, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0, -3.0f));

	positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f));

	
	// Arreglo de colores en el cpu
	//Paleta de colores http://prideout.net/archive/colors.php#Floats

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));

	colors.push_back(glm::vec3(0.502f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.502f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.502f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.502f, 0.0f, 0.0f));

	colors.push_back(glm::vec3(0.482f, 0.408f, 0.933f));
	colors.push_back(glm::vec3(0.482f, 0.408f, 0.933f));
	colors.push_back(glm::vec3(0.482f, 0.408f, 0.933f));
	colors.push_back(glm::vec3(0.482f, 0.408f, 0.933f));

	colors.push_back(glm::vec3(1.0f, 0.843f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.843f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.843f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.843f, 0.0f));
	
	std::vector<glm::vec3> normales;
	
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));

	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));

	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 
		4, 5, 6, 4, 6, 7, 
		8, 9, 10, 8, 10, 11, 
		12, 13, 14, 12, 14, 15, 
		16, 17, 18, 16, 18, 19, 
		20, 21, 22, 20, 23, 21 };

	_mesh.CreateMesh(positions.size());
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normales, GL_STATIC_DRAW, 2);
	_mesh.SetIndice(indices, GL_STATIC_DRAW);

	_shaderProgram.CreateProgram();
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.AttachShader("Light.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Light.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.LinkProgram();

	_transform.SetPosition(0.0f, 0.0f, 0.0f);
	_transform.SetScale(0.3f, 0.3f, 0.3f);

	_transform2.SetPosition(0.0f, -2.0f, 0.0f);
	_transform2.SetScale(8.0f, 0.01f, 8.0f);

	_camera.SetPosition(0.0f,0.0f,10.0f);
}

void GameLoop()
{
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	_transform.Rotate(0.01f, 0.01f, 0.01f, false);

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_shaderProgram.SetUniformVector("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformVector("LightPosition", glm::vec3(0.0f, 0.0f, 5.0f));
	_shaderProgram.SetUniformVector("CameraPosition", _camera.GetPosition());
	_mesh.Draw(GL_TRIANGLES);

	_shaderProgram.SetUniformMatrix("modelMatrix", _transform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();
	
	// Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	// Solicitando una versión específica de OpenGL.
	glutInitContextVersion(4, 0);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicación
	// gráfica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un título.
	glutCreateWindow("Proyecto Final pt1: Luminosidad");
	// Asociamos una función de render.
	//Esta función se mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librería se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f,1.0f,0.5f,1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configuración inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}