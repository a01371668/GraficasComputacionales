/*
*	Autor1: Francisco Geada	Rodriguez	A01168958	
*	Autor2: Alonso Morales Gutiérrez	A01371668
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
#include "Texture2D.h"
#include <IL/il.h>
#include "DepthBuffer.h"

//Mesh que dibuja la palma de la mano
Mesh _mesh;
//Mesh que dibuja cada una de las falanges
Mesh _mesh1;
//Shader program que dibuja las geometrías de la escena
ShaderProgram _shaderProgram;
//Shader que hace el render de profundidad
ShaderProgram _shaderProgramDepth;
//Geometría de la palma de la mano
Transform _transform;
//Geometría del suelo
Transform _transform1;
//Geometría de cada una de las falanges de la mano
//Falanges inferiores
Transform _falangeTransform;
Transform _falangeTransform1;
Transform _falangeTransform2;
Transform _falangeTransform3;
//Falanges superiores
Transform _falangeTransform4;
Transform _falangeTransform5;
Transform _falangeTransform6;
Transform _falangeTransform7;
//Cámara para la escena
Camera _camera;
//Camara que proyecta la luz, se usa para el render de profundidad
Camera _cameraLuz;
//Textura de caja de madera
Texture2D _texture;
//Textura de red para el suelo
Texture2D _texture1;
//Buffer de profundidad
DepthBuffer _depthBuffer;
//Parámetros para medir el movimiento de la mano
float limit = 0.0f;
float openClose = 0.3f;

void Initialize() {
	//Vector de posiciones para la palma de la mano
	std::vector<glm::vec3> positions;
	//Vector de posiciones para las falanges
	std::vector<glm::vec3> positions1;
	//Normales de las geometrías
	std::vector<glm::vec3> normals;
	//índices para dibujar con el mesh
	std::vector<unsigned int> indices;
	//Vector de texturas
	std::vector<glm::vec2> texturas;
	//Texturas
	_texture.LoadTexture("caja.jpg");
	_texture1.LoadTexture("red.jpg");

	//Posiciones para la palma
	positions.push_back(glm::vec3(-2.0f, -4.0f, 0.250f));
	positions.push_back(glm::vec3(2.0f, 4.0f, 0.250f));
	positions.push_back(glm::vec3(-2.0f, 4.0f, 0.250f));
	positions.push_back(glm::vec3(2.0f, -4.0f, 0.250f));
	positions.push_back(glm::vec3(-2.0f, 4.0f, 0.250f));
	positions.push_back(glm::vec3(-2.0f, -4.0f, -0.250f));
	positions.push_back(glm::vec3(-2.0f, -4.0f, 0.250f));
	positions.push_back(glm::vec3(-2.0f, 4.0f, -0.250f));
	positions.push_back(glm::vec3(-2.0f, 4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, 4.0f, -0.250f));
	positions.push_back(glm::vec3(-2.0f, -4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, -4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, -4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, 4.0f, 0.250f));
	positions.push_back(glm::vec3(2.0f, -4.0f, 0.250f));
	positions.push_back(glm::vec3(2.0f, 4.0f, -0.250f));
	positions.push_back(glm::vec3(-2.0f, 4.0f, -0.250f));
	positions.push_back(glm::vec3(-2.0f, 4.0f, 0.250f));
	positions.push_back(glm::vec3(2.0f, 4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, 4.0f, 0.50f));
	positions.push_back(glm::vec3(-2.0f, -4.0f, 0.250f));
	positions.push_back(glm::vec3(-2.0f, -4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, -4.0f, -0.250f));
	positions.push_back(glm::vec3(2.0f, -4.0f, 0.250f));

	//Posiciones para las falanges
	positions1.push_back(glm::vec3(-0.50f, -1, 0.250f));
	positions1.push_back(glm::vec3(0.50f, 1, 0.250f));
	positions1.push_back(glm::vec3(-0.50f, 1, 0.250f));
	positions1.push_back(glm::vec3(0.50f, -1, 0.250f));
	positions1.push_back(glm::vec3(-0.50f, 1, 0.250f));
	positions1.push_back(glm::vec3(-0.50f, -1, -0.250f));
	positions1.push_back(glm::vec3(-0.50f, -1, 0.250f));
	positions1.push_back(glm::vec3(-0.50f, 1, -0.250f));
	positions1.push_back(glm::vec3(-0.5f, 1.0f, -0.250f));
	positions1.push_back(glm::vec3(0.50f, 1, -0.250f));
	positions1.push_back(glm::vec3(-0.5f, -1, -0.250f));
	positions1.push_back(glm::vec3(0.50f, -1, -0.250f));
	positions1.push_back(glm::vec3(0.50f, -1, -0.250f));
	positions1.push_back(glm::vec3(0.50f, 1, 0.250f));
	positions1.push_back(glm::vec3(0.50f, -1, 0.250f));
	positions1.push_back(glm::vec3(0.5f, 1, -0.250f));
	positions1.push_back(glm::vec3(-0.50f, 1, -0.250f));
	positions1.push_back(glm::vec3(-0.50f, 1, 0.250f));
	positions1.push_back(glm::vec3(0.50f, 1, -0.250f));
	positions1.push_back(glm::vec3(0.50f, 1, 0.250f));
	positions1.push_back(glm::vec3(-0.50f, -1, 0.250f));
	positions1.push_back(glm::vec3(-0.50f, -1, -0.250f));
	positions1.push_back(glm::vec3(0.50f, -1, -0.250f));
	positions1.push_back(glm::vec3(0.50f, -1, 0.250f));

	//Normales
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	//Vector para dibujar texturas en los vértices adecuados
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));

	//Los índices son ingresados en el orden en el que se dibujarán
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(0);
	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(5);
	indices.push_back(4);
	indices.push_back(8);
	indices.push_back(9);
	indices.push_back(10);
	indices.push_back(10);
	indices.push_back(9);
	indices.push_back(11);
	indices.push_back(12);
	indices.push_back(13);
	indices.push_back(14);
	indices.push_back(15);
	indices.push_back(13);
	indices.push_back(12);
	indices.push_back(16);
	indices.push_back(17);
	indices.push_back(18);
	indices.push_back(18);
	indices.push_back(17);
	indices.push_back(19);
	indices.push_back(20);
	indices.push_back(21);
	indices.push_back(22);
	indices.push_back(22);
	indices.push_back(23);
	indices.push_back(20);

	//Vector de colores (que se sigue necesitando aunque esté vacío)
	std::vector<glm::vec3> colors;

	//Creamos el buffer de profundidad con la resolución adecuada
	_depthBuffer.Create(2048);

	//Inicializamos el mesh que dibujará el suelo y la palma de la mano
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(texturas, GL_STATIC_DRAW, 3);

	//Inicializamos el mesh que dibujará las falanges
	_mesh1.SetIndices(indices, GL_STATIC_DRAW);
	_mesh1.CreateMesh(24);
	_mesh1.SetPositionAttribute(positions1, GL_STATIC_DRAW, 0);
	_mesh1.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh1.SetIndices(indices, GL_STATIC_DRAW);
	_mesh1.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh1.SetTexCoordAttribute(texturas, GL_STATIC_DRAW, 3);

	//Creamos el programa que manejará el shader para las geometrías de la escena
	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Shadow.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Shadow.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");

	//Creamos el programa que manejará los shaders de profundidad
	_shaderProgramDepth.CreateProgram();
	_shaderProgramDepth.AttachShader("Depth.frag", GL_FRAGMENT_SHADER);
	_shaderProgramDepth.AttachShader("Depth.vert", GL_VERTEX_SHADER);
	_shaderProgramDepth.SetAttribute(0, "VertexPosition");

	//Atamos los programas de shader
	_shaderProgram.LinkProgram();
	_shaderProgramDepth.LinkProgram();

	//Posicionamos las cámaras
	_camera.MoveForward(25.0f);
	_cameraLuz.SetOrthigraphic(45.0f, 1);
	_cameraLuz.SetPosition(10, 37, 0);
	_cameraLuz.Pitch(-90);

	//Manejamos las transformacíones
	_transform.MoveUp(-5, true);
	_transform1.SetScale(150, 0.5, 150);
	_transform1.MoveUp(-10, true);
	_falangeTransform.MoveUp(5.6f, true);
	_falangeTransform.MoveRight(-1.7, true);
	_falangeTransform1.MoveUp(5.6f, true);
	_falangeTransform2.MoveUp(5.6f, true);
	_falangeTransform2.MoveRight(1.9, true);
	_falangeTransform3.MoveUp(-2.8f, true);
	_falangeTransform3.MoveRight(-3.1f, true);
	_falangeTransform3.Rotate(0, 0, 80, true);
	_falangeTransform4.MoveUp(2.8f, true);
	_falangeTransform5.MoveUp(2.8f, true);
	_falangeTransform6.MoveUp(2.8f, true);
	_falangeTransform7.MoveUp(2.8f, true);
	_transform.Rotate(-73.0f, 0.00f, 0.0f, true);

}

void GameLoop() {
	//Atamos el buffer de profundidad
	_depthBuffer.Bind();

	//Limpiamos la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//La mano rota
	_transform.Rotate(0.0f, 0.15f, 0.0f, true);

	//Establecemos los límites del movimiento de la mano
	if (limit >= 128.0f || limit < 0.0f) {
		openClose *= -1;
	}

	limit += openClose;

	//Establecemos las posiciones por cuadro de las falanges inferiores
	_falangeTransform.MoveForward(openClose / 50, false);
	_falangeTransform.Rotate(openClose, 0, 0.0f, false);
	_falangeTransform1.MoveForward(openClose*0.76 / 50, false);
	_falangeTransform1.Rotate(openClose*0.76, 0, 0.0f, false);
	_falangeTransform2.MoveForward(openClose*0.66 / 50, false);
	_falangeTransform2.Rotate(openClose*0.66, 0, 0.0f, false);
	_falangeTransform3.MoveForward(openClose*0.82 / 50, false);
	_falangeTransform3.Rotate(openClose*0.82, 0, 0.0f, false);
	//Establecemos las posiciones por cuadro de las falanges superiores
	_falangeTransform4.MoveForward(openClose / 50, false);
	_falangeTransform4.Rotate(openClose, 0, 0.0f, false);
	_falangeTransform5.MoveForward(openClose*0.76 / 50, false);
	_falangeTransform5.Rotate(openClose*0.76, 0, 0.0f, false);
	_falangeTransform6.MoveForward(openClose*0.66 / 50, false);
	_falangeTransform6.Rotate(openClose*0.66, 0, 0.0f, false);
	_falangeTransform7.MoveForward(openClose*0.82 / 50, false);
	_falangeTransform7.Rotate(openClose*0.82, 0, 0.0f, false);

	//Hacemos el render de profundidad para...
	_shaderProgramDepth.Activate();
	//...la palma de la mano,...
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	//...el suelo,...
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()* _transform1.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	//...las falanges inferiores y...
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform1.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform2.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform3.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	//...las falanges superiores...
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform.GetModelMatrix()*_falangeTransform4.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform1.GetModelMatrix()*_falangeTransform5.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform2.GetModelMatrix()*_falangeTransform6.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);
	_shaderProgramDepth.SetUniformMatrix("mvpMatrix", _cameraLuz.GetViewProjection()*_transform.GetModelMatrix()*_falangeTransform3.GetModelMatrix()*_falangeTransform7.GetModelMatrix());
	_mesh1.Draw(GL_TRIANGLES);

	//Quitamos el buffer de profundidad al terminar
	_depthBuffer.Unbind();
	_shaderProgramDepth.Deactivate();

	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

	//Limpiamos la pantalla para el siguiente render
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Activamos el shader para las geometrías
	_shaderProgram.Activate();

	//Pasamos las uniformes de la luz y la cámara al shader
	_shaderProgram.SetUniformf("luzX", 0);
	_shaderProgram.SetUniformf("luzY", 5);
	_shaderProgram.SetUniformf("luzZ", 0);
	_shaderProgram.SetUniformf("camaraX", _camera.GetPosition()[0]);
	_shaderProgram.SetUniformf("camaraY", _camera.GetPosition()[1]);
	_shaderProgram.SetUniformf("camaraZ", _camera.GetPosition()[2]);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("ShadowMap", 1);

	//Dibujamos la palma de la mano
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	//Dibujamos las falanges inferiores
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	//Dibujamos las falanges superiores
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform.GetModelMatrix()*_falangeTransform4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform.GetModelMatrix()*_falangeTransform4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform1.GetModelMatrix()*_falangeTransform5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform1.GetModelMatrix()*_falangeTransform5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform2.GetModelMatrix()*_falangeTransform6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform2.GetModelMatrix()*_falangeTransform6.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_falangeTransform3.GetModelMatrix()*_falangeTransform7.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix()*_falangeTransform3.GetModelMatrix()*_falangeTransform7.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh1.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	//Dibujamos el suelo
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _cameraLuz.GetViewProjection());
	glActiveTexture(GL_TEXTURE0);
	_texture1.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.BindDepthMap();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_texture1.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depthBuffer.UnbindDepthMap();

	//Desactivamos el shader
	_shaderProgram.Deactivate();

	glutSwapBuffers();
}

void Idle() {
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height) {
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Hello World GL");
	glutDisplayFunc(GameLoop);
	glutReshapeFunc(ReshapeWindow);
	glutIdleFunc(Idle);

	glewInit();
	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	Initialize();

	glutMainLoop();

	return 0;
}