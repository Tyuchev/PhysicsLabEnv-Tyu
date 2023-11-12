// Simple Polygons for the Manta Raytracer


#include "glm.hpp"

#include "comet/CometSimplePoly.hpp"


namespace Manta
{

// Simple Polygon Classes

// Sphere ----------------------------------------------------
// 

class Sphere
{
public:

	class Sphere() = delete;
	class Sphere(glm::vec3 colour);
	~Sphere();

	glm::vec3 GetColour();

private:

	glm::vec3 m_Colour;

};





}