#pragma once
#include "Config.h"
#include "utils/ArrayHandler.h"
#include "classes/Structs.h"
#include "classes/Menu.h"
#include "Texts.h"

namespace Overtone {
	class Tile {
	private:
		const char types[4] = { ' ', ':', ';', '%'};
		int tic = 0;

	public:
		char GlyphChecker(int ID) {
			return types[ID];
		}

		void InteractionHandler(FeatureTile& FT) {
			switch (FT.typeID.intID) {
			case 1:
				FT.typeID.intID = 2;
				menu.MenuTextBufferFiller(interactionTitle, doorInteraction);
				break;
			case 3:
				break;
			}
		}
	};
}
inline Overtone::Tile interactiveTiles;