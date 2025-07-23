
#include "MathLib/MathExpansion.h"
#include <stdio.h>
#include <math.h>

int main(void) {
	cylinder_t newcylinder = defineCylinder(defineCircle(definePoint(0, 0), 5), 3);

	printf("%.3lf", calcCylinderVolume(newcylinder));

	return EXIT_SUCCESS;
}
