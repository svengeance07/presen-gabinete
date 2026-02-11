#include "Config.h"
#include "Renderer.h"
#include "MapHandler.h"
#include "EventHandler.h"
#include "KeyCheck.h"
#include "AIConsoleControl.h"

using Overtone::programIsRunning;

int main()
{
	//Init
	InitWorlds();
	SetupConsoleWindow();

	//Main Loop
	while (programIsRunning) {
		EventHandler();
		Renderer();
		KeyCheck();
	}
}