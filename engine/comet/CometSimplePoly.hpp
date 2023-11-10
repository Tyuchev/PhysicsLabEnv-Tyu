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
	Plane(float32 x, float32 y, float32 z, float32 constant);
	~Plane();

	glm::vec3 GetPoint();
	glm::vec3 FindNormal();

private:

	float32 m_XCoefficent, m_YCoefficient, m_ZCoefficient, m_Constant;


};

}
