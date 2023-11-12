
// Simple Polygons for the Manta Raytracer


#include "glm.hpp"

#include "MantaSimplePoly.hpp"
#include "comet/CometSimplePoly.hpp"



namespace Manta
{

// Simple Polygon Classes

// Sphere ----------------------------------------------------
//
//  
Sphere::Sphere(glm::vec3 colour)
	: m_Colour(colour)
{

}

Sphere::~Sphere()
{
	// empty
}

glm::vec3 Sphere::GetColour()
{
	return m_Colour;
}







}