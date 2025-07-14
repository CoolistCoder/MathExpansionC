
#include "MathLib/MathExpansion.h"
#include <stdio.h>

int main(void) {
	point_t *a, *b;
	a = definePointAsPointer(0, 0);
	b = definePointAsPointer(8, 6);

	printf("%.2lf", distanceFormula(*a, *b));

	return EXIT_SUCCESS;
}
