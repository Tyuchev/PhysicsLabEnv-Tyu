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
#include "render/physics.h"
#include <chrono>

#include "SandboxApp.hpp"



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
    int w;
    int h;

    // Needs deleting? RAII?
    this->m_Window->GetSize(w, h);
    glm::mat4 projection = glm::perspective(glm::radians(90.0f), float(w) / float(h), 0.01f, 1000.f);
    Render::Camera* MainCam = Render::CameraManager::GetCamera(CAMERA_MAIN);
    MainCam->projection = projection;

    // User Input
    Input::Keyboard* UserKeyboard = Input::GetDefaultKeyboard();
    Input::Mouse* UserMouse = Input::GetDefaultMouse();

    // Min time step
    double dt = 0.01667f;

    // Simulation loop
    while (this->m_Window->IsOpen())
    {
        auto timeStart = std::chrono::steady_clock::now();
        
        glClear(GL_COLOR_BUFFER_BIT);
        this->m_Window->Update();


        // Execute the entire rendering pipeline
        //Render::RenderDevice::Render(this->m_Window, dt);

        // transfer new frame to m_Window
        this->m_Window->SwapBuffers();

        auto timeEnd = std::chrono::steady_clock::now();
        dt = std::min(0.04, std::chrono::duration<double>(timeEnd - timeStart).count());

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
