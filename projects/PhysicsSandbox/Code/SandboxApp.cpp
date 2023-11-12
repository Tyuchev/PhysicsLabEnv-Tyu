//------------------------------------------------------------------------------
// SandboxApp.cc
// (C) 2022 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include <cstring>
#include "imgui.h"
#include "render/renderdevice.h"
#include "render/shaderresource.h"
#include <vector>
#include "render/textureresource.h"
#include "render/model.h"
#include "render/cameramanager.h"
#include "render/lightserver.h"
#include "render/debugrender.h"
#include "core/random.h"
#include "render/input/inputserver.h"
#include "core/cvar.h"
#include <chrono>

#include "SandboxApp.hpp"
#include "RayIntersection.hpp"
#include "manta/Raytracer.hpp"
#include "manta/MantaSimplePoly.hpp"


SandboxApp::SandboxApp()
    : m_Window(nullptr)
{
    // empty
}

SandboxApp::~SandboxApp()
{
    // empty
}

bool SandboxApp::Open()
{
    App::Open();
    this->m_Window = new Display::Window;
    this->m_Window->SetSize(1280, 760);

    if (this->m_Window->Open())
    {
        glClearColor(0.5f, 0.9f, 0.3f, 1.0f);

        Render::RenderDevice::Init();

        // set ui rendering function
        this->m_Window->SetUiRender([this]()
            {
                this->RenderUI();
            });

        return true;

    }
    return false;
}

void SandboxApp::Run()
{
    std::chrono::high_resolution_clock wallClock{};

    int w;
    int h;

    // Needs deleting? RAII?
    this->m_Window->GetSize(w, h);
    glm::mat4 projection = glm::perspective(glm::radians(90.0f), float(w) / float(h), 0.01f, 1000.f);
    Render::Camera* MainCam = Render::CameraManager::GetCamera(CAMERA_MAIN);
    MainCam->projection = projection;

    // number of accumulated frames
    int frameIndex = 0;

    std::vector<glm::vec3> framebuffer;
    framebuffer.resize(w * h);

    std::vector<glm::vec3> framebufferCopy;
    framebufferCopy.resize(w * h);

    // User Input
    Input::Keyboard* UserKeyboard = Input::GetDefaultKeyboard();
    Input::Mouse* UserMouse = Input::GetDefaultMouse();

    int RPP = 1;
    int BOUNCES = 5;

    Manta::MantaRaytracer MantaRay{w, h, framebuffer, RPP, BOUNCES};
    MantaRay.SetupRaytracer();

    // Num of Rays per frame
    float numberMegaRays = framebuffer.size() * (5 * 0.000001f);
    float megaRaysPerSec = 0.0f;


    // Create time points for render loop
    std::chrono::high_resolution_clock::time_point renderBegin;
    std::chrono::high_resolution_clock::time_point renderEnd;
    double renderTimer{ 0.0 };

    // Min time step
    double dt = 0.01667f;


    // Simulation loop
    while (this->m_Window->IsOpen())
    {
        auto timeStart = std::chrono::steady_clock::now();

        glClear(GL_COLOR_BUFFER_BIT);
        this->m_Window->Update();

        renderBegin = wallClock.now();
        // Create decision tree? Execute correct assignment.
        RayIntersectionAssignment();

        frameIndex++;

        // Get the average distribution of all samples
        // CHANGE FRAMEBUFFERS - FROM FLOATS TO SOMETHING SMALLER???
        // Currently floats - 4 bytes - 32 bits.. What do we need?
        // Maybe use int8 = 8bits = up to the num 256? A quarter of float 32's size?? Do we need the precision of floats?
        // otherwise maybe int16 = up to the num 65536
        {
            size_t p = 0;
            for (glm::vec3 const& pixel : framebuffer)
            {
                framebufferCopy[p] = pixel;
                framebufferCopy[p].r /= frameIndex;
                framebufferCopy[p].g /= frameIndex;
                framebufferCopy[p].b /= frameIndex;
                p++;
            }
        } // with float 32's this buffer seems to be AT LEAST 4mb - Well over cache 1 & likely ovedr cache 2!!

        m_Window->Blit((float*)&framebufferCopy[0], w, h);

        // transfer new frame to m_Window
        this->m_Window->SwapBuffers();

        // Timers & Debug info
        renderEnd = wallClock.now();
        renderTimer = (std::chrono::duration_cast<std::chrono::microseconds>(renderEnd - renderBegin)).count() * 0.000001;

        auto timeEnd = std::chrono::steady_clock::now();
        dt = std::min(0.04, std::chrono::duration<double>(timeEnd - timeStart).count());

        // MraysPerSec
        megaRaysPerSec = numberMegaRays * (1.0f / renderTimer);

        std::cout << "Render Time: " << renderTimer << " seconds" << std::endl;
        std::cout << "Mrays/sec: " << megaRaysPerSec << "\n" << std::endl;

        if (UserKeyboard->pressed[Input::Key::Code::Escape])
            this->Exit();
    }

}


void SandboxApp::Exit()
{
    this->m_Window->Close();
}


void SandboxApp::RenderUI()
{
    if (this->m_Window->IsOpen())
    {
        //ImGui::Begin("Debug");
        //Core::CVar* r_draw_light_spheres = Core::CVarGet("r_draw_light_spheres");
        //int drawLightSpheres = Core::CVarReadInt(r_draw_light_spheres);
        //if (ImGui::Checkbox("Draw Light Spheres", (bool*)&drawLightSpheres))
        //    Core::CVarWriteInt(r_draw_light_spheres, drawLightSpheres);

        //Core::CVar* r_draw_light_sphere_id = Core::CVarGet("r_draw_light_sphere_id");
        //int lightSphereId = Core::CVarReadInt(r_draw_light_sphere_id);
        //if (ImGui::InputInt("LightSphereId", (int*)&lightSphereId))
        //    Core::CVarWriteInt(r_draw_light_sphere_id, lightSphereId);

        //ImGui::End();

        Debug::DispatchDebugTextDrawing();
    }
}
