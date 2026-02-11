#include "Config.h"

#include "classes/Screen.h"
#include "classes/Entities.h"
#include "classes/Map.h"

#include "MapHandler.h"

#include "Texts.h"

using Overtone::isTextOnScreen;

void ScreenHandler() {
	if (isTextOnScreen) {
		screen.ScreenTextFiller();
	}
	else {
		//Negative worlds represent different type of menus
		if (Overtone::cW < 0) {
			switch (Overtone::cW) {
			case -1:
				screen.ScreenFiller(mainMenuScreen);
				break;
			case -3:
				screen.ScreenFiller(bagScreen);
				screen.ScreenNav();
				break;
			}
		}
		else {
			MapHandler();
		}
	}
}

void ScreenBuilder() {
	string screenFrame;
	
	ScreenHandler();

	screen.ScreenGen(screenFrame);
}