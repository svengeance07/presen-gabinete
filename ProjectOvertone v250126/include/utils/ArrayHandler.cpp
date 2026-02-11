#include "ArrayHandler.h"
#include "Config.h"

namespace Overtone {
	namespace Utils {
		void String_to_Char_1x18_MatrixFiller(const charMatrix& filler, string& emptyString, int i) {
			for (int j = 0; j < WIDTH; j++) {
				char c = filler[i][j];
				emptyString += c;
				emptyString += ' ';
			}
			emptyString += '\n';
		}

		void String_1x18_Filler(const char filler[WIDTH], string& emptyString) {
			for (int i = 0; i < WIDTH; i++) {
				emptyString += filler[i];
				emptyString += ' ';
			}
			emptyString += '\n';
		}

		void Char_18x18_ArrayFiller(const char filler[HEIGHT][WIDTH], char emptyArray[HEIGHT][WIDTH]) {
			for (int i = 0; i < HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					emptyArray[i][j] = filler[i][j];
				}
			}
		}
		void Char_3x18_ArrayFiller(const char filler[M_HEIGHT][WIDTH], char emptyArray[M_HEIGHT][WIDTH]) {
			for (int i = 0; i < M_HEIGHT; i++) {
				for (int j = 0; j < WIDTH; j++) {
					emptyArray[i][j] = filler[i][j];
				}
			}
		}
		void Char_1x18_ArrayFiller(const char filler[WIDTH], char emptyArray[WIDTH]) {
			for (int i = 0; i < WIDTH; i++) {
				emptyArray[i] = filler[i];
			}
		}

		void Char_Xx18_MatrixFiller(const charMatrix& filler, charMatrix& emptyArray) {
			emptyArray.resize(filler.size());

			for (size_t i = 0; i < filler.size(); i++) {
				emptyArray[i].resize(WIDTH);
				for (int j = 0; j < WIDTH; j++) {
					emptyArray[i][j] = filler[i][j];
				}
			}
			emptyArray.shrink_to_fit();
		}
	}
}