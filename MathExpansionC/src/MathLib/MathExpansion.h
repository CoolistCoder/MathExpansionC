/*
 * MathExpansion.h
 *
 *  Created on: Jul 9, 2025
 *      Author: User
 */

#ifndef MATHLIB_MATHEXPANSION_H_
#define MATHLIB_MATHEXPANSION_H_
#include <stdlib.h>
#include <stdint.h>

//definition of a point with x and y coordinates
typedef struct point_t{
	double x, y;
}point_t;

//definition of a triangle with points A, B, and C
typedef struct triangle_t{
	point_t A;
	point_t B;
	point_t C;
}triangle_t;

point_t definePoint(double, double);
point_t* definePointAsPointer(double, double);

triangle_t defineTriangle(point_t, point_t, point_t);
triangle_t* defineTriangleAsPointer(point_t, point_t, point_t);


//utils
double squareRoot(double val);


#endif /* MATHLIB_MATHEXPANSION_H_ */
