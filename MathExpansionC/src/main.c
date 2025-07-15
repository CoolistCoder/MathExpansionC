
#include "MathLib/MathExpansion.h"
#include <stdio.h>

int main(void) {
	circle_t circle = defineCircle(definePoint(0, 0), 5);
	printf("%.10lf", calcCircumference(circle));

	return EXIT_SUCCESS;
}
