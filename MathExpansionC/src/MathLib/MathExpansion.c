#include "MathExpansion.h"

//NAN definition
#define PRVNAN (*(double*)((uint64_t[]){0x7FF8000000000000ULL}))
#define PRVPI (double)(3.14159265359) //define as macro to assign label to value

typedef enum errcode_e{
	NO_ERR = 0,				//no error
	DIVIDE_BY_ZERO,			//divide by zero error
	SQUAREROOT_NEGATIVE,	//square root of negative error
	ZERO_ROOT,				//zeroth root doesn't exist
	NOT_A_TRIANGLE			//values do not represent a triangle
}errcode_e;

static errcode_e glblErrCode = NO_ERR; //global error code

//Name: setError
//Description: Sets the global error code
//Inputs: Error Code enum
//Outputs: none
//Side Effects: Stores new error code in glblErrCode
static void setError(errcode_e val){
	glblErrCode = val;
}

//Name: clearError
//Description: Clears the global error code
//Inputs: Error Code enum
//Outputs: none
//Side Effects: Resets error code in glblErrCode
static void clearError(){
	glblErrCode = 0;
}

//Name: getError
//Description: Retrieves global error's value
//Inputs: none
//Outputs: The enum in glblErrCode
//Side Effects: n/a
static errcode_e getError(){
	return glblErrCode;
}

//Name: getErrorString
//Description: Returns global error's value as a C string
//Inputs: none
//Outputs: C string of the error
//Side Effects: n/a
static const char* getErrorString(){
	switch(getError()){
	case DIVIDE_BY_ZERO:
		return "DIVIDE BY ZERO";
		break;
	case SQUAREROOT_NEGATIVE:
		return "SQUARE ROOT OF NEGATIVE";
		break;
	case NOT_A_TRIANGLE:
		return "NOT A VALID TRIANGLE";
		break;
	case ZERO_ROOT:
		return "ZERO ROOTS DON'T EXIST";
		break;
	case NO_ERR:
		return "NO ERROR";
		break;
	default:
		return "NO ERROR";
		break;
	}
}

//Name: getPI
//Description: Returns PI macro as double
//Inputs: none
//Outputs: PI as double
//Side Effects: n/a
double getPI(){
	return PRVPI;
}

//Name: definePoint
//Description: Defines a point with X and Y coordinates
//Inputs: double x position, double y position
//Outputs: new point object
//Side Effects: n/a
point_t definePoint(double x, double y){
	point_t newpoint;
	newpoint.x = x;
	newpoint.y = y;
	return newpoint;
}

//Name: definePointAsPointer
//Description: Defines a pointer to a point object
//Inputs: double x position, double y position
//Outputs: new pointer to a point object
//Side Effects: n/a
point_t* definePointAsPointer(double x, double y){
	point_t* newpoint = (point_t*)malloc(sizeof(point_t));
	newpoint->x = x;
	newpoint->y = y;
	return newpoint;
}

//Name: defineTriangle
//Description: Defines a triangle with points A B and C
//Inputs: Three points (A, B, C)
//Outputs: New triangle object
//Side Effects: n/a
triangle_t defineTriangle(point_t A, point_t B, point_t C){
	triangle_t newtriangle;
	newtriangle.A = A;
	newtriangle.B = B;
	newtriangle.C = C;
	return newtriangle;
}

//Name: defineTriangleAsPointer
//Description: Defines a pointer to a triangle with points A B and C
//Inputs: Three points (A, B, C)
//Outputs: New pointer to new triangle object
//Side Effects: n/a
triangle_t* defineTriangleAsPointer(point_t A, point_t B, point_t C){
	triangle_t* newtriangle = (triangle_t*)malloc(sizeof(triangle_t));
	newtriangle->A = A;
	newtriangle->B = B;
	newtriangle->C = C;
	return newtriangle;
}


circle_t defineCircle(point_t newpoint, double radius){
	circle_t circle;
	circle.center = newpoint;
	circle.radius = absoluteVal(radius);
	return circle;
}

circle_t* defineCircleAsPointer(point_t newpoint, double radius){
	circle_t* circle = (circle_t*)malloc(sizeof(circle_t));
	circle->center = newpoint;
	circle->radius = absoluteVal(radius);
	return circle;
}

double calcCircleCircumference(circle_t circle){
	return 2*getPI()*circle.radius;
}

double calcCircleDiameter(circle_t circle){
	return 2*circle.radius;
}

double calcCircleArc(circle_t circle, double theta){
	return (theta/360.0)*calcCircleCircumference(circle);
}

double calcCircleArea(circle_t circle){
	return getPI()*square(circle.radius);
}

double calcFactorial(int n){
	double factor = 1;
	for (int i=1; i<=n; ++i){
		factor*=i;
	}
	return factor;
}

double sine(double theta){
	//Normalize using periodicity
	while (theta>getPI()){
		theta -= 2*getPI();
	}
	while (theta<getPI()){
		theta += 2*getPI();
	}

	//Perform taylor series approximation
	double ret = 0;
	for (int i=0; i<20; ++i){
		int sign = (i%2==0) ? 1 : -1;
		double term = sign * (powerNth(theta,2*i+1)/calcFactorial(2*i+1));
		ret += term;
	}
	return ret;
}

double cosine(double theta){
	//Normalize using periodicity
	while (theta>getPI()){
		theta -= 2*getPI();
	}
	while (theta<getPI()){
		theta += 2*getPI();
	}

	//Perform taylor series approximation
	double ret = 0;
	for (int i=0; i<20; ++i){
		int sign = (i%2==0) ? 1 : -1;
		double term = sign * (powerNth(theta,2*i)/calcFactorial(2*i));
		ret += term;
	}
	return ret;
}

double tangent(double theta){
	double rise = sine(theta);
	double run = cosine(theta);
	double ret = 0;
	if (run == 0){
		setError(DIVIDE_BY_ZERO);
		ret = PRVNAN;
	}
	else{
		ret = rise/run;
	}
	if (getError()!=NO_ERR)
		printf("Error: %s\n", getErrorString());
	clearError();
	return ret;
}

double cosecant(double theta){
	double SIN = sine(theta);
	if (SIN==0){
		setError(DIVIDE_BY_ZERO);
		SIN=PRVNAN;
	}
	else{
		SIN = 1/SIN;
	}
	if (getError()!=NO_ERR)
			printf("Error: %s\n", getErrorString());
	clearError();
	return SIN;
}

double secant(double theta){
	double COS = cosine(theta);
	if (COS==0){
		setError(DIVIDE_BY_ZERO);
		COS=PRVNAN;
	}
	else{
		COS = 1/COS;
	}
	if (getError()!=NO_ERR)
			printf("Error: %s\n", getErrorString());
	clearError();
	return COS;
}

double distanceFormula(point_t a, point_t b){
	//sqrt((x2-x1)^2 + (y2-y1)^2))
	return squareRoot(square(b.x-a.x)+square(b.y-a.y));
}

point_t midpointFormula(point_t a, point_t b){
	//(x1+x2)/2, (y1+y2)/2
	return definePoint((a.x+b.x)/2, (a.y+b.y)/2);
}

//Name: square
//Description: Squares a number
//Inputs: Double value to square
//Outputs: Double of squared value
//Side Effects: n/a
double square(double val){
	return powerNth(val, 2);
}

//Name: squareRoot
//Description: Square roots a number, reimplementation of nth function
//Inputs: Double value to square root
//Outputs: Double of square rooted value
//Side Effects: n/a
double squareRoot(double val){
	return NthRoot(val, 2.0);
}

double powerNth(double val, int nth){
	double ret = 1.0; //begin with value of 1
	if (nth < 0){		//set up reciprocal if negative
		val = 1/val;
		nth *= -1;
	}

//
	while (nth > 0){
		if (nth % 2 == 1){
			ret *= val;
		}
		val *= val;
		nth /= 2;
	}
	return ret;
}

//Name: NthRoot
//Description: Nth roots a number using newton iteration
//Inputs: Double value to square root, double exponent (nth)
//Outputs: Double of square rooted value
//Side Effects: n/a
double NthRoot(double val, double nth){
	double root;	//return value
	double err;		//maximum error
	double previous; //buffer for original root value
	double nthIsNegative = nth < 0; //find if nth is negative
	nth = absoluteVal(nth);			//get abs, return inverse if true
	if (val < 0 && ((int)nth%2==0)){	//throw error if even exponent is negative
		setError(SQUAREROOT_NEGATIVE);
		root = PRVNAN; //store this result if true
	}
	else{ //perform newton iteration for nth root
		root = val/nth;	//divide input by nth
		err = 0.000000001; //precision
		if (val == 0.0){ //
			return 0.0;
		}
		do{
			previous = root;
			//Implementation of Newton iteration
			//xk - f(xk)/f'(xk)
			root = (1.0 / nth) * ((nth-1)* root + val / powerNth(root, nth - 1));
		}while (absoluteVal(root - previous) > err);

		if (nthIsNegative){
			root = 1.0/root;
		}
	}
	if (getError()!=NO_ERR){ //If there is an error, print it out
		printf("Error: %s\n", getErrorString());
	}
	clearError(); //Reset the error code
	return root;
}

double absoluteVal(double val){
	if (val < 0){
		return val*-1.0;
	}
	return val;
}

double roundToNearest(double val){
	const double precision = 0.00001;
	double quotient = val/precision;
	int quotientRounded;
	double scale = 1.0/precision;


	if (val>=0){
		quotientRounded = (double)((int)(quotient+0.5));
	}
	else{
		quotientRounded = (double)((int)(quotient-0.5));
	}
	val = quotientRounded*precision;
	val = (double)((int)(val*scale+0.5));
	val = val/scale;

	return val;
}

