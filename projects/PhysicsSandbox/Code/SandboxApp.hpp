#pragma once


#include "core/app.h"
#include "render/window.h"

#include "SandboxApp.hpp"
#include "manta/Raytracer.hpp"
#include "manta/MantaSimplePoly.hpp"


class SandboxApp : public Core::App
{

public:
	SandboxApp();
	~SandboxApp();

	bool Open();
	void Run();
	void Exit();

private:

	void RenderUI();

	Display::Window* m_Window;

};