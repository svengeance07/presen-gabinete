#pragma once
#include "utils/ArrayHandler.h"

#include "classes/Screen.h"
#include "classes/Structs.h"
#include "Player.h"

namespace Overtone {
	class Entity {
	public:
		XY pos;
		int tic = 0;
		char glyph = '&';
		bool alive = true;

		void Dialogue() {

		}
		//Constructor
		Entity() = default;
	};

	class Player : public Entity {
	public:
		Stats stats;
		XY oldPos;
		char lastTile, currentTile, nextTile;
		bool isFighting, canInteract, interacted;
		std::vector<CurrentFloorChk> currentWorldInt;
		FeatureTile thisInteractive;

	private:

	public:
		//Constructor
		Player() : stats(100, 100, 10, 0.10f) {
			glyph = '@';
			isFighting = false;
			interacted = false;
			canInteract = false;
			lastTile = glyph;
			currentTile = glyph;
			nextTile = glyph;
			currentWorldInt.clear();
		}
	private:
		bool OutOfScreen() {
			if (pos.X == WIDTH - 1 || pos.X == 0 || pos.Y == HEIGHT - 1 || pos.Y == 0) return true;
			else return false;
		}

		bool PosFixer() {
			if (OutOfScreen() || InvalidTile()) {
				pos.X = oldPos.X;
				pos.Y = oldPos.Y;
				return false;
			}
			else return true;
			
		}
		void Movement(int k, Screen& thisScreen) {
			tic += 1;
			oldPos.Y = pos.Y;
			oldPos.X = pos.X;
			switch (k) {
			case 72:
				pos.Y -= 1;
				break;
			case 75:
				pos.X -= 1;
				break;
			case 77:
				pos.X += 1;
				break;
			case 80:
				pos.Y += 1;
				break;
			}
			thisInteractive.tilePos.X = pos.X;
			thisInteractive.tilePos.Y = pos.Y;
			nextTile = thisScreen.screen[thisInteractive.tilePos.Y][thisInteractive.tilePos.X];
			canInteract = IIT();
			if (PosFixer()) {
				lastTile = currentTile;
				currentTile = nextTile;
			}
		}
		void Commands(int k) {
			tic += 1;
			switch (k) {
			case 'z':
				if (canInteract) {
					interacted = true;
					if (nextTile != '=') {
						InteractionHandler();
					}
				}
				break;
			case 'x':
				lW = cW;
				cW = -3;
				break;
			case 'c':
				lW = cW;
				cW = -2;
				break;
			}
		}

	public:

		void KeyChecks(int k, int sK, Screen& thisScreen) {
			if (k == 0 || k == 224) {
				Movement(sK, thisScreen);
			}
			else {
				Commands(k);
			}
		}

		void Draw(Screen& thisScreen) {
			thisScreen.ScreenCoordFiller(oldPos.X, oldPos.Y, lastTile);
			thisScreen.ScreenCoordFiller(pos.X, pos.Y, glyph);
		}
	};

	class Enemy : public Entity {
	private:
		Stats stats;
	public:
		//Constructor
		Enemy() { glyph = 'i'; }

	};

	class Boss : public Enemy {
	private:
		Stats stats;
	public:
		Boss() { glyph = 'B'; }
	};

	class NPC : public Entity{
		NPC() { glyph = '&'; }
	};
}
inline Overtone::Player MC;
















