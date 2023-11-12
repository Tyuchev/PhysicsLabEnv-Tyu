// Manta Raytracer to demonstrate the Comet Physics Engine


#include "glm.hpp"

#include "comet/CometSimplePoly.hpp"


namespace Manta
{

struct HitResult
{
    glm::vec3 hitPoint;
    glm::vec3 hitNormal;
    //Maybe only send back a 'collider', instead of the onject itself - avoids inheritance
    //const Object* object = nullptr;
    float t = FLT_MAX;
};








void ExecuteRaytracer();


}