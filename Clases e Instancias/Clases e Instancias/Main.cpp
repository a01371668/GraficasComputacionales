/*
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
*/

#include <GL/glew.h> //Se va a la carpeta de video, evalua la tarjea de video y obtiene todo el API más reciente de openGL
#include <GL/freeglut.h> //Se ocupa de manejar ventanas (openGL no maneja ventanas)
#include <string>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "InputFile.h"

GLuint vao; //Identificador del manager al que vamos a asociar todos los VBO's
GLuint shaderProgram; //Identificador del manager de los shaders (shaderProgram)


void Initialize() {
	//Creando toda la memoria que el programa va a utilizar.
	std::vector <glm::vec2> positions; //almacenar atributo de posiciones de los vértices (es una lista de vec2); std::vector(lista ligada)
	//Esto es en CPU y RAM
	positions.push_back(glm::vec2(0.5f, 0.5f));
	positions.push_back(glm::vec2(0.5f, -0.5f));
	positions.push_back(glm::vec2(-0.5f, 0.5f));
	positions.push_back(glm::vec2(-0.5f, -0.5f));

	std::vector <glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));

	glGenVertexArrays(1, &vao); //Queremos generar 1 manager
	glBindVertexArray(vao); //Utilizar el vao. A partir de este momento, todos los VBO's creados y configurados se van a asociar a este manager

	GLuint positionsVBO; //Indentificador del Vertex Buffer Object de posiciones.
	glGenBuffers(1, &positionsVBO); //Creación del VBO de posiciones
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //Activamos el buffer para poder utilizarlo
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(),
		positions.data(), GL_STATIC_DRAW); //Creamos la memoria y la inicializamos con los datos del atributo de posiciones
	glEnableVertexAttribArray(0); //Activamos el atributo en la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //Configuramos los datos del atributo en la tarjeta de video
	glBindBuffer(GL_ARRAY_BUFFER, 0); //Ya no vamos a utilizar este VBO en éste momento.

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0); //Desactivamos el manager

	//Leemos archivos de texto vertex y fragment shaders
	InputFile ifile;

	//Cargamos VERTEX SHADER
	ifile.Read("Default.vert");	//Leemos archivo default.vert donde está el código del vertex shader
	std::string vertexSource = ifile.GetContents(); //Obtenemos codigo fuente y lo guardamos en un string
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER); //Creamos un shader de tipo vertex y guardamos su identificador en una variable.

	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str(); //Obtener los datos en el formato correcto, es un cast

	glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr); //Le estamos dando el codigo fuente a OpenGL para que se lo asigne al shader
	glCompileShader(vertexShaderHandle); //Compilamos el shader en busca de errores. Se asume que no hay error en la compilación

	ifile.Read("Default.frag");
	std::string fragmentSource = ifile.GetContents();
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
	glCompileShader(fragmentShaderHandle);

	shaderProgram = glCreateProgram(); //Creamos identificador para el manager de los shaders
	glAttachShader(shaderProgram, vertexShaderHandle); //Adjuntamos el vertexShader al manager (van a trabajar juntos)
	glAttachShader(shaderProgram, fragmentShaderHandle); //Adjuntamos el fragmentShader al manager (van a trabajar juntos)
	glBindAttribLocation(shaderProgram, 0, "VertexPosition"); //Agregamos un buffer con indice 0(posiciones) a la variable VertexPosition
	glBindAttribLocation(shaderProgram, 1, "VertexColor"); //Agregamos un buffer con indice 1(colores) a la variable VertexColor
	glLinkProgram(shaderProgram); //Ejecutamos el proceso de linker(asegurarnos que el vertex y fragment son compatibles)
}

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpiamos el buffer de color y el buffer de profundidad. Siempre hacerlo al inicio del frame
	
	glUseProgram(shaderProgram); //Activamos el vertex shader y fragment shader utilizando el manager.
	glBindVertexArray(vao); //Activamos el manager, en este momento se activan todos los VBO's asociados automáticamente.
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); //Funcion de dibujado sin indices
	glBindVertexArray(0); //Terminamos de utilizar el manager
	glUseProgram(0); //Desactivamos el manager
	
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	//Inicializar freeglut
	//Freeglut se encarga de crear una ventana donde podemos dibujar
	glutInit(&argc, argv);

	//Solicitando una version especifica de OpenGL
	glutInitContextVersion(4, 0);

	//Inicializar el contexto de OpenGL. EL contexto se refiere a las capacidades que va a tener nuestra aplicación gráfica.
	//En este caso estamos trabajando con el pipeline clásico.
	glutInitContextProfile(GLUT_CORE_PROFILE);

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
	std::cout << glGetString(GL_VERSION) << std::endl;

	Initialize(); //Configuración inicial de nuestro programa.
	
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
}