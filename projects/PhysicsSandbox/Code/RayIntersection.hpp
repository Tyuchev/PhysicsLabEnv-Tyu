// Ray Intersection Assignment


#include "config.h"
#include <vector>
#include <cstring>
#include <chrono>
#include "imgui.h"
#include "render/renderdevice.h"
#include "render/shaderresource.h"
#include "render/textureresource.h"
#include "render/model.h"
#include "render/cameramanager.h"
#include "render/lightserver.h"
#include "render/debugrender.h"
#include "core/random.h"
#include "render/input/inputserver.h"
#include "core/cvar.h"
#include "core/app.h"
#include "render/window.h"

#include "comet/CometSimplePoly.hpp"
#include "manta/Raytracer.hpp"
#include "manta/MantaSimplePoly.hpp"


void RayIntersectionAssignment();