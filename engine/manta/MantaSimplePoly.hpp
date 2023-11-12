#pragma once
// Simple Polygons for the Manta Raytracer


#include "glm.hpp"

#include "comet/CometSimplePoly.hpp"


namespace Manta
{

// Simple Polygon Classes

// Plane ----------------------------------------------------
// 
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


// Sphere ----------------------------------------------------
// 
class Sphere
{
public:

	Sphere() = delete;
	Sphere(glm::vec3 center, float32 radius, glm::vec3 colour);
	~Sphere();

	glm::vec3 GetCenter();
	float32 GetRadius();
	glm::vec3 GetColour();

private:

	glm::vec3 m_Center;
	float32 m_Radius;
	glm::vec3 m_Colour;

};





}