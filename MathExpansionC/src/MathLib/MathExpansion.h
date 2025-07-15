/*
 * MathExpansion.h
 *
 *  Created on: Jul 9, 2025
 *      Author: User
 */

#ifndef MATHLIB_MATHEXPANSION_H_
#define MATHLIB_MATHEXPANSION_H_
#include <stdlib.h>
#include <stdio.h>
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

//definition of a circle with Point and Radius
typedef struct circle_t{
	point_t center;
	double radius;
}circle_t;

//getters
double getPI();

point_t definePoint(double, double);
point_t* definePointAsPointer(double, double);

triangle_t defineTriangle(point_t, point_t, point_t);
triangle_t* defineTriangleAsPointer(point_t, point_t, point_t);

circle_t defineCircle(point_t newpoint, double radius);
circle_t* defineCircleAsPointer(point_t newpoint, double radius);
double calcCircumference(circle_t);
double calcDiameter(circle_t);

//formulas
double distanceFormula(point_t a, point_t b);

//utils
double square(double val);
double squareRoot(double val);
double powerNth(double val, int nth);
double NthRoot(double val, double nth);
double absoluteVal(double val);


#endif /* MATHLIB_MATHEXPANSION_H_ */
