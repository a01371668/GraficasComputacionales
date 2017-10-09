#pragma once

#include <glm/glm.hpp>
#include "Transform.h"


class Camera {
public:
	Camera();
	
	glm::mat4 GetViewProjection();
	glm::mat4 GetViewMatrix(); //Matriz de vista
	glm::mat4 GetProjectionMatrix(); //Matriz de proyeccion
	glm::vec3 GetPosition();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);

	void MoveForward(float delta, bool world = false);
	void MoveUp(float delta, bool world = false);
	void MoveRight(float delta, bool world = false);

	void Yaw(float degrees); //Rota la c�mara en el eje Y
	void Roll(float degrees); //Rota la c�mara en el eje Z
	void Pitch(float degrees); //Rota la c�mara en el eje X
	void Rotate(float x, float y, float z, bool world = false);

	void SetPerspective(float nearPlane, float farPlane, float fieldOfView, float aspectRatio);
	void SetOrthographic(float size, float aspectRatio);

private:
	Transform _transform;
	
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
};