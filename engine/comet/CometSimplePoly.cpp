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
Plane::Plane(float32 x, float32 y, float32 z, float32 constant)
	: m_XCoefficent(x), m_YCoefficient(y), m_ZCoefficient(z), m_Constant(constant)
{
}


Plane::~Plane()
{
	// empty
}

glm::vec3 GetPoint()
{



}


glm::vec3 FindNormal()
{



}


}
