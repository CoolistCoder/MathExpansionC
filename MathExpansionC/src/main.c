
#include "MathLib/MathExpansion.h"
#include <stdio.h>
//#include <math.h> //we don't need this!

int main(void) {
	rect_t sqr = defineSquare(definePoint(0, 0), 64);

	printf("Square at %.2lf, %.2lf\n", sqr.center.x, sqr.center.y);
	printf("Width = %.2lf\n", sqr.width);
	printf("Height = %.2lf\n", sqr.height);

	return EXIT_SUCCESS;
}
