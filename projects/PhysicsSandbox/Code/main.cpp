// main.cpp

#include "config.h"
#include "SandboxApp.hpp"


int main(int argc, const char** argv)
{
	SandboxApp app;
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	app.Exit();

}