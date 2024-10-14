#include "BruteForce.h"

int BruteForce(char* Text, int TextSize, int Strat, char* Patten, int PatternSize)
{
	int i = 0;
	int j = 0;

	for (i = Strat; i <= TextSize - PatternSize; i++) {
		for (j = 0; j < PatternSize; j++) {
			if (Text[i + j] != Patten[j])
				break;
		}
		if (j > PatternSize)
			return i;
	}

	return -1;
}