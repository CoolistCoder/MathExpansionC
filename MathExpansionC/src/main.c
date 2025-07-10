
#include "MathLib/MathExpansion.h"
#include <stdio.h>

int main(void) {
	point_t newpoint = definePoint(32, 64);
	printf("%.2lf, %.2lf\n", newpoint.x, newpoint.y);

	return EXIT_SUCCESS;
}
