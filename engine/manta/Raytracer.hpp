#pragma once
// Manta Raytracer to demonstrate the Comet Physics Engine


#include "glm.hpp"
#include <iostream>
#include <chrono>
#include <vector>

#include "MantaSimplePoly.hpp"
#include "comet/CometSimplePoly.hpp"
#include "core/random.h"


namespace Manta
{

struct HitResult
{
    glm::vec3 hitPoint;
    glm::vec3 hitNormal;
    //Maybe only send back a 'collider', instead of the onject itself - avoids inheritance
    //const Object* object = nullptr;
    float hitDistance = FLT_MAX;
};

class MantaRaytracer
{
public:
 
    MantaRaytracer(int w, int h, std::vector<glm::vec3>& frameBuffer, int rpp, int bounces);
    ~MantaRaytracer();

    void SetupRaytracer();
    void EngageRaytracer();

    // Trace Path & return intersection combined colours

    glm::vec3 TracePath(Comet::Ray& ray, unsigned int bouncesRemaining, float random);

    std::vector<glm::vec3>& m_FrameBuffer;


private:

    
    int m_NumberOfObjects; // * 3
    int m_ImageWidth;
    int m_ImageHeight;
    int m_RaysPerPixel;
    int m_MaxBounces;

    std::vector<Sphere> objectHolder;

    

};




}