// CometSimplePoly.cpp

#include "config.h"
#include "core/idpool.h"
#include "render/gltf.h"
#include "render/debugrender.h"
#include "core/random.h"
#include "core/cvar.h"
#include <string>
#include <iostream>

#include "CometSimplePoly.hpp"


namespace Comet
{

// Simple Polygon Classes

// Plane ----------------------------------------------------
// 
Plane::Plane(glm::vec3 point, glm::vec3 normal)
	: m_Point(point), m_Normal(normal)
{
}


Plane::~Plane()
{
	// empty
}

glm::vec3 Plane::GetPoint()
{
	return m_Point;
}


glm::vec3 Plane::GetNormal()
{
	return m_Normal;
}


// Ray ----------------------------------------------------
// 

Ray::Ray(glm::vec3 start, glm::vec3 direction)
	: m_Start(start), m_Direction(direction)
{

}

Ray::~Ray() 
{
	// empty
}

glm::vec3 Ray::GetStart()
{
	return m_Start;
}

glm::vec3 Ray::GetDirection()
{
	return m_Direction;
}

glm::vec3 Ray::Intersect(Plane plane, bool& isCollision)
{
	glm::vec3 hitPosition{0.0, 0.0, 0.0};

	float32 dotProduct = glm::dot(m_Direction, plane.GetNormal());

	// DOESNT HANDLE COLLISIONS BEHIND THE CAMERA
	// if vectors point in the same direction, they will not intersect
	if (dotProduct >= 0)
	{
		isCollision = false;
		return hitPosition;
	}

	glm::vec3 rayStartToKnownPoint = plane.GetPoint() - m_Start;
	float32 normalDotSpan = glm::dot(rayStartToKnownPoint, plane.GetNormal());

	float32 normalDotRayDirection = glm::dot(m_Direction, plane.GetNormal());

	// Otherwise known as 't'
	float32 distanceCoefficient = normalDotSpan / normalDotRayDirection;

	glm::vec3 interceptPoint = m_Start + (m_Direction * distanceCoefficient);
	isCollision = true;

	return hitPosition;
}




}
