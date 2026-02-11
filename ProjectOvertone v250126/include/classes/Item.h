#pragma once
#include "utils/ArrayHandler.h"

namespace Overtone {

	class Item {
	private:
		const char types[5] = { ' ', ',', '*', '?'};

	public:
		char GlyphChecker(int ID) {
			return types[ID];
		}

	};
}
inline Overtone::Item items;