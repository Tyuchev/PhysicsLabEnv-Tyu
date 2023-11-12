
// Simple Polygons for the Manta Raytracer

#include "config.h"
#include "glm.hpp"

#include "MantaSimplePoly.hpp"
#include "comet/CometSimplePoly.hpp"



namespace Manta
{

// Simple Polygon Classes

// Plane ----------------------------------------------------
// 
	Plane::Plane(glm::vec3 point, glm::vec3 normal, glm::vec3 colour)
		: m_Point(point), m_Normal(normal), m_Colour(colour)
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

	glm::vec3 Plane::GetColour()
	{
		return m_Colour;
	}


// Sphere ----------------------------------------------------
//  
Sphere::Sphere(glm::vec3 center, float32 radius, glm::vec3 colour)
	: m_Center(center), m_Radius(radius), m_Colour(colour)
{

}

Sphere::~Sphere()
{
	// empty
}


glm::vec3 Sphere::GetCenter()
{
	return m_Center;
}

float32 Sphere::GetRadius()
{
	return m_Radius;
}

glm::vec3 Sphere::GetColour()
{
	return m_Colour;
}




}