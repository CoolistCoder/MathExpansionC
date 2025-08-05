
#include "MathLib/MathExpansion.h"
#include <stdio.h>
//#include <math.h> //we don't need this!

int main(void) {
	rect3d_t cbe = defineCube(definePoint3d(0, 0, 0), 64);

	printf("Cube at %.2lf, %.2lf, %.2lf\n", cbe.corner.x, cbe.corner.y, cbe.corner.z);
	printf("Width = %.2lf\n", cbe.width);
	printf("Height = %.2lf\n", cbe.height);
	printf("Height = %.2lf\n", cbe.depth);

	rect3d_t rtp = defineRect3d(definePoint3d(0, 0, 0), 23, 43, 54);

	printf("Cube at %.2lf, %.2lf, %.2lf\n", rtp.corner.x, rtp.corner.y, rtp.corner.z);
	printf("Width = %.2lf\n", rtp.width);
	printf("Height = %.2lf\n", rtp.height);
	printf("Height = %.2lf\n", rtp.depth);

	return EXIT_SUCCESS;
}
