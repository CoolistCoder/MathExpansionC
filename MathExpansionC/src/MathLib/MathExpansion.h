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

//Versions
#ifndef MATHEX_VER_ALPHA
#define MATHEX_VER_ALPHA 0
#endif

//definition of point precision for round functions
typedef enum prec_e{
	TENTH,
	HUNDREDTH,
	THOUSANDTH,
	TENTHOUSANDTH,
	HUNDREDTHOUSANDTH,
	MILLIONTH
}prec_e;

//definition of a point with x and y coordinates
typedef struct point_t{
	double x, y;
}point_t;

//definition of a point with x y z coordinates
typedef struct point3d_t{
	double x, y, z;
}point3d_t;


//definition of a triangle with points A, B, and C
typedef struct triangle_t{
	point_t A;
	point_t B;
	point_t C;
}triangle_t;

//definition of a rectangle with a bottom left corner point and width and height
typedef struct rect_t{
	point_t corner;
	double width, height;
}rect_t;

//definition of a 3D rectangle with a bottom left corner point and width and height
typedef struct rect3d_t{
	point3d_t corner;
	double width, height, depth;
}rect3d_t;

//definition of a circle with Point and Radius
typedef struct circle_t{
	point_t center;
	double radius;
}circle_t;

//definition of an ellipse
typedef struct ellipse_t{
	point_t center;
	double xAxis;
	double yAxis;
}ellipse_t;

//definition of a cylinder with circle and height
typedef struct cylinder_t{
	circle_t circle;
	double height;
}cylinder_t;

//getters
double getPI();
double getEuler();

//definition functions
point_t definePoint(double, double);
point_t* definePointAsPointer(double, double);
point3d_t definePoint3d(double, double, double);
point3d_t* definePoint3dAsPointer(double, double, double);

triangle_t defineTriangle(point_t, point_t, point_t);
triangle_t* defineTriangleAsPointer(point_t, point_t, point_t);

rect_t defineRect(point_t, double, double);
rect_t* defineRectAsPointer(point_t, double, double);
rect_t defineSquare(point_t, double);
rect_t* defineSquareAsPointer(point_t, double);

rect3d_t defineRect3d(point3d_t, double, double, double);
rect3d_t* defineRect3dAsPointer(point3d_t, double, double, double);
rect3d_t defineCube(point3d_t, double);
rect3d_t* defineCubeAsPointer(point3d_t, double);

circle_t defineCircle(point_t newpoint, double radius);
circle_t* defineCircleAsPointer(point_t newpoint, double radius);

cylinder_t defineCylinder(circle_t, double);
cylinder_t* defineCylinderAsPointer(circle_t, double);

ellipse_t defineEllipse(point_t, double, double);


//Calculation functions
double calcCircleCircumference(circle_t);
double calcCircleDiameter(circle_t);
double calcCircleArc(circle_t, double theta);
double calcCircleArea(circle_t);

double calcCylinderVolume(cylinder_t);

double calcSphereVolume(circle_t);
double calcSphereSurfaceArea(circle_t);

double calcFactorial(int n);
double sine(double theta);
double cosine(double theta);
double tangent(double theta);
double cosecant(double theta);
double secant(double theta);
double cotangent(double theta);
double radiansToDegrees(double theta);

double calcLN(double x);
double calcLog(double val);


//formulas
double distanceFormula(point_t a, point_t b);
point_t midpointFormula(point_t a, point_t b);


//utils
double square(double val);
double squareRoot(double val);
double powerNth(double val, double nth);
double NthRoot(double val, double nth);
double absoluteVal(double val);
double floorVal(double val);
double ceilingVal(double val);
double roundToNearestPrecision(double val, double precision);
double roundToNearest(double val, prec_e precision);
double getRoundPlace(prec_e precision);


#endif /* MATHLIB_MATHEXPANSION_H_ */
