
#include "MathLib/MathExpansion.h"
#include <stdio.h>

int main(void) {
	point_t a, b;
	b.x = 6;
	a.x = 0;
	b.y = 8;
	a.y = 0;
	printf("%.2lf", distanceFormula(a, b));

	return EXIT_SUCCESS;
}
