#include "Config.h"

#include "classes/Entities.h"
#include "classes/Map.h"
#include "classes/Tile.h"
#include "classes/Item.h"
#include "classes/Structs.h"
#include "EventHandler.h"

#include "EntityHandler.h"
namespace Overtone {
	bool InvalidTile() {
		for (int i = 0; i < vfq; i++) {
			if (floorChars[i] == MC.nextTile) {
				return false;
			}
		}
		return true;
	}

	//Is Interactive Tile
	bool IIT() {
		if (MC.nextTile == '=') {
			return true;
		}
		else if (InvalidTile()) {
			FeatureTile& newTile = MC.thisInteractive;
			const Map& currentWorld = lucidMap[cW];
			for (size_t i = 0; i < currentWorld.mapFloor[cF].floorZone[cZ].zoneInt.size(); i++) {
				const FeatureTile& currentTile = currentWorld.mapFloor[cF].floorZone[cZ].zoneInt[i];
				if (newTile.tilePos.X == currentTile.tilePos.X && newTile.tilePos.Y == currentTile.tilePos.Y) {
					newTile.typeID.charID = currentTile.typeID.charID;
					newTile.typeID.intID = currentTile.typeID.intID;
					return true;
				}
			}
			newTile.tilePos.X = 0;
			newTile.tilePos.Y = 0;
			return false;
		}
		return false;
	}

	void IDChecker(FeatureTile& FT) {
		switch (FT.typeID.charID) {
		case 'i': case 'I':
			//items.GlyphChecker(ID.intID);
			break;
		case 't': case 'T':
			interactiveTiles.InteractionHandler(FT);
			break;
		case 'e': case 'E':
			//EntityGlyphChecker(ID.intID);
			break;
		}
	}

	void ZonePass() {

	}

	void InteractionHandler() {
		const Overtone::Map& currentWorld = lucidMap[cW];
		if (MC.currentWorldInt.size() < currentWorld.mapFloor.size()) {
			MC.currentWorldInt.resize(currentWorld.mapFloor.size());
		}

		if (MC.currentWorldInt[cF].floorZone.size() < currentWorld.mapFloor[cF].floorZone.size()) {
			MC.currentWorldInt[cF].floorZone.resize(currentWorld.mapFloor[cF].floorZone.size());
		}
		const size_t cS = MC.currentWorldInt[cF].floorZone[cZ].usedInt.size() + (size_t)1;
		MC.currentWorldInt[cF].floorZone[cZ].usedInt.resize(cS);

		IDChecker(MC.thisInteractive);

		MC.currentWorldInt[cF].floorZone[cZ].interacted = true;
		MC.nextTile = MC.currentTile;
		MC.currentWorldInt[cF].floorZone[cZ].usedInt[cS - 1].tilePos.X = MC.thisInteractive.tilePos.X;
		MC.currentWorldInt[cF].floorZone[cZ].usedInt[cS - 1].tilePos.Y = MC.thisInteractive.tilePos.Y;
		MC.currentWorldInt[cF].floorZone[cZ].usedInt[cS - 1].typeID.charID = MC.thisInteractive.typeID.charID;
		MC.currentWorldInt[cF].floorZone[cZ].usedInt[cS - 1].typeID.intID = MC.thisInteractive.typeID.intID;
	}
}