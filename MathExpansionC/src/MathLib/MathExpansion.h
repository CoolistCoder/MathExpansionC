/*
 * MathExpansion.h
 *
 *  Created on: Jul 9, 2025
 *      Author: User
 */

#ifndef MATHLIB_MATHEXPANSION_H_
#define MATHLIB_MATHEXPANSION_H_
#include <stdlib.h>

//definition of a point with x and y coordinates
typedef struct point_t{
	double x, y;
}point_t;

point_t definePoint(double, double);
point_t* definePointAsPointer(double, double);

#endif /* MATHLIB_MATHEXPANSION_H_ */
