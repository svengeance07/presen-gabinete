#pragma once

namespace Overtone {
	struct XY {
		int X, Y;
		XY() { X = 0, Y = 0; }
		XY(int x, int y) { X = x, Y = y; }
	};

	struct ObjectID {
		char charID;
		int intID;

		ObjectID() {
			charID = 'I';
			intID = 1;
		}
		ObjectID(char CHARID, int INTID) {
			charID = CHARID;
			intID = INTID;
		}
	};

	struct FeatureTile {
		XY tilePos;
		ObjectID typeID;
		FeatureTile() = default;
		FeatureTile(int x, int y, char charID, int intID) : tilePos(x, y), typeID(charID, intID){}
	};

	//Entities
	struct CurrentZoneChk {
		bool interacted = false;
		std::vector<FeatureTile> usedInt;

		CurrentZoneChk() {
			usedInt.clear();
		}
	};
	struct CurrentFloorChk {
		std::vector<CurrentZoneChk> floorZone;
		int zones;

		CurrentFloorChk() {
			zones = 1;
			floorZone.reserve(zones);
		}
		CurrentFloorChk(int zoneQuantity) {
			zones = zoneQuantity;
			floorZone.reserve(zones);
		}
	};

	struct Stats {
		int maxFhp, fhp,
			maxMhp, mhp,
			atk;
		float cri;

		Stats() {
			maxFhp = 0;
			fhp = maxFhp;
			maxMhp = 0;
			mhp = maxMhp;
			atk = 0;
			cri = 0.0;
		}

		Stats(int MAXFHP, int MAXMHP, int ATK, float CRI) :
			maxFhp(MAXFHP),
			fhp(maxFhp),
			maxMhp(MAXMHP),
			mhp(maxMhp),
			atk(ATK),
			cri(CRI) 
		{ }
	};
}