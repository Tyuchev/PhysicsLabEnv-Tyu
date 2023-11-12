// Manta Raytracer to demonstrate the Comet Physics Engine


#include "config.h"
#include "glm.hpp"
#include <iostream>
#include <chrono>
#include <vector>

#include "Raytracer.hpp"
#include "MantaSimplePoly.hpp"
#include "comet/CometSimplePoly.hpp"
#include "core/random.h"

namespace Manta
{

MantaRaytracer::MantaRaytracer(int w, int h, std::vector<glm::vec3>& frameBuffer, int rpp, int bounces)
    : m_ImageWidth(w), m_ImageHeight(h), m_FrameBuffer(frameBuffer), m_RaysPerPixel(rpp),m_MaxBounces(bounces),
    m_NumberOfObjects(10) // * 3
{

}

MantaRaytracer::~MantaRaytracer()
{

}


void MantaRaytracer::SetupRaytracer()
{
    RandomGen randomGen;

    // Setting up test scene

    std::vector<Sphere> SphereHolder;
    SphereHolder.reserve(m_NumberOfObjects * 3);

    for (int it = 0; it < m_NumberOfObjects; it++) // num Spheres * 3 
    {
        {
            float r = randomGen.RandomFloat();
            float g = randomGen.RandomFloat();
            float b = randomGen.RandomFloat();

            const double span = 10.0f;
            Sphere sphere{ glm::vec3{randomGen.RandomFloatNTP() * span, randomGen.RandomFloat() * span + 0.2f, randomGen.RandomFloatNTP() * span}, 
                10.0f, 
                glm::vec3{r, g, b} };
            SphereHolder.push_back(sphere);
        }
        {

            float r = randomGen.RandomFloat();
            float g = randomGen.RandomFloat();
            float b = randomGen.RandomFloat();

            const double span = 30.0f;
            Sphere sphere{ glm::vec3{randomGen.RandomFloatNTP() * span, randomGen.RandomFloat() * span + 0.2f, randomGen.RandomFloatNTP() * span},
                10.0f,
                glm::vec3{r, g, b} };
            SphereHolder.push_back(sphere);
        }
        {

            float r = randomGen.RandomFloat();
            float g = randomGen.RandomFloat();
            float b = randomGen.RandomFloat();

            const double span = 25.0f;
            Sphere sphere{ glm::vec3{ randomGen.RandomFloatNTP() * span, randomGen.RandomFloat() * span + 0.2f, randomGen.RandomFloatNTP() * span},
                10.0f,
                glm::vec3{r, g, b} };
            SphereHolder.push_back(sphere);
        }
    }


	return;
}}