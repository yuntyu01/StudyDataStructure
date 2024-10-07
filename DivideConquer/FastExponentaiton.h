#include <stdio.h>
#include <stdint.h>

typedef uint64_t ULONG;

ULONG Power(int Base, int Exponent) {
	if (Exponent == 1)
		return Base;
	else if (Base == 0)
		return 1;

	if (Exponent % 2 == 0)
	{
		ULONG NewBase = Power(Base, Exponent / 2);
		return NewBase * NewBase;
	}
	else {
		ULONG NewBase = Power(Base, (Exponent - 1) / 2);
		return (NewBase * NewBase) * Base;
	}
}