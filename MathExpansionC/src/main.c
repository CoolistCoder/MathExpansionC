
#include "MathLib/MathExpansion.h"
#include <stdio.h>
#include <math.h>

int main(void) {
	printf("%.2lf\n", calcSphereVolume(defineCircle(definePoint(0, 0), 25)));
	return EXIT_SUCCESS;
}
