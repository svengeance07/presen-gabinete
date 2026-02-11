#pragma once
#include "utils/ArrayHandler.h"

#include "Text.h"
#include "Navigation.h"

#include "Screens.h"

namespace Overtone {

	class Screen {
	private:
		//Private Variables
		Text screenText;
		Navigation screenNav;

	public:
		//Public Variables
		char screen[HEIGHT][WIDTH];

	private:
		//Private Functions
		void BagScreenNav(int k) {
			switch (k) {
			case 'z':
				switch (screenNav.opc) {
					//Use Med
				case 5:
					
					break;
				}
				break;
			case 'x':
				cW = lW;
				inNewZone = true;
				break;
			}
		}

		void ScreenCommands(int k) {
			switch (cW) {
			case -3:
				BagScreenNav(k);
				break;
			}
		}

	public:
		//Public Functions
		void ScreenFiller(const char screenFiller[HEIGHT][WIDTH]) {
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					screen[i][j] = screenFiller[i][j];
				}
			}
		}

		void ScreenCoordFiller(const int x, const int y, const char glyph) {
			screen[y][x] = glyph;
		}

		void ScreenTextBufferFiller(const char title[WIDTH], const charMatrix& text) {
			screenText.TextBufferFiller(title, text);
			isTextOnScreen = true;
		}

		void ScreenTextFiller() {
			screenText.InitTextSetup(screen);
			screenText.TextGen(screen);
		}

		void ScreenGen(string& frame) {
			for (int i = 0; i < HEIGHT; i++) {
				Utils::String_1x18_Filler(screen[i], frame);
			}
			std::cout << frame;
		}

		void ScreenKeyChecks(int k, int sK) {
			if (k == 0 || k == 224) {
				screenNav.Nav(sK);
			}
			else {
				ScreenCommands(k);
			}

		}

		void ScreenNav() {
			ScreenCoordFiller(7, screenNav.opc, screenNav.glyph);
			if (screenNav.oldOpc != screenNav.opc) {
				ScreenCoordFiller(7, screenNav.oldOpc, '+');
			}
		}

		//Constructors
		Screen() : screenText(true), screenNav(5, 13, 4) {
			Utils::Char_18x18_ArrayFiller(emptyScreen, screen);
		}

	};
}
inline Overtone::Screen screen;
