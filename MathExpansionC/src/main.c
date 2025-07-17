
#include "MathLib/MathExpansion.h"
#include <stdio.h>

int main(void) {
	circle_t circle = defineCircle(definePoint(0, 0), 5);
	point_t pointEast = definePoint(0, 5);
	point_t pointSouth = definePoint(5, 0);


	printf("%.10lf", distanceFormula(circle.center, midpointFormula(pointEast, pointSouth)));

	return EXIT_SUCCESS;
}
