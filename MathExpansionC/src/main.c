
#include "MathLib/MathExpansion.h"
#include <stdio.h>
#include <math.h>

int main(void) {
	printf("%.2lf\n", ceilingVal(3.14));
	printf("%.2lf\n", floorVal(3.14));
	printf("%.2lf\n", absoluteVal(-3.14));
	return EXIT_SUCCESS;
}
