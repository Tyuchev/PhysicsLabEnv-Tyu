#pragma once
// CometSimplePoly.hpp


#include "config.h"
#include "core/idpool.h"
#include "render/gltf.h"
#include "render/debugrender.h"
#include "core/random.h"
#include "core/cvar.h"
#include <string>
#include <iostream>

#include "glm.hpp"


namespace Comet
{


class Plane
{
public:

	Plane() = delete;
	Plane(glm::vec3 point, glm::vec3 normal, glm::vec3 colour);
	~Plane();

	glm::vec3 GetPoint();
	glm::vec3 GetNormal();
	glm::vec3 GetColour();

private:

	glm::vec3 m_Point;
	glm::vec3 m_Normal;
	glm::vec3 m_Colour;

};


class Ray
{
public:

	Ray() = delete;
	Ray(glm::vec3 start, glm::vec3 direction);
	~Ray();

	glm::vec3 Intersect(Plane plane, bool &isCollision);

private:

	glm::vec3 m_Start;
	glm::vec3 m_Direction;


};





}
