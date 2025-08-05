#include "MathExpansion.h"

//NAN definition
#define PRVNAN (*(double*)((uint64_t[]){0x7FF8000000000000ULL}))
#define PRVPI (double)(3.14159265359) //define as macro to assign label to value
#define PRVEULER (double)(2.718281828459045);

typedef enum errcode_e{
	NO_ERR = 0,				//no error
	DIVIDE_BY_ZERO,			//divide by zero error
	SQUAREROOT_NEGATIVE,	//square root of negative error
	ZERO_ROOT,				//zeroth root doesn't exist
	NOT_A_TRIANGLE,			//values do not represent a triangle
	CANNOT_BE_NEGATIVE		//value cannot be negative
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
	case CANNOT_BE_NEGATIVE:
		return "THE VALUE PROVIDED CAN'T BE NEGATIVE";
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

//Name: getEuler
//Description: Returns Euler macro as double
//Inputs: none
//Outputs: Euler as double
//Side Effects: n/a
double getEuler(){
	return PRVEULER;
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

//Name: definePoint
//Description: Defines a point with X Y Z coordinates
//Inputs: double x position, double y position, double Z position
//Outputs: new point3d object
//Side Effects: n/a
point3d_t definePoint3d(double x, double y, double z){
	point3d_t newpoint;
	newpoint.x = x;
	newpoint.y = y;
	newpoint.z = z;
	return newpoint;
}

//Name: definePointAsPointer
//Description: Defines a pointer to a point3d object
//Inputs: double x position, double y position, double Z position
//Outputs: new pointer to a point3d object
//Side Effects: n/a
point3d_t* definePoint3dAsPointer(double x, double y, double z){
	point3d_t* newpoint = (point3d_t*)malloc(sizeof(point3d_t));
	newpoint->x = x;
	newpoint->y = y;
	newpoint->z = z;
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

rect_t defineRect(point_t corner, double width, double height){
	rect_t rect;
	rect.corner = corner;
	rect.width = width;
	rect.height = height;
	return rect;
}

rect_t* defineRectAsPointer(point_t corner, double width, double height){
	rect_t* rect = (rect_t*)malloc(sizeof(rect_t));
	rect->corner = corner;
	rect->width = width;
	rect->height = height;
	return rect;
}

rect_t defineSquare(point_t corner, double size){
	rect_t rect = defineRect(corner, size, size);
	return rect;
}

rect_t* defineSquareAsPointer(point_t corner, double size){
	rect_t* rect = defineRectAsPointer(corner, size, size);
	return rect;
}

rect3d_t defineRect3d(point3d_t corner, double width, double height, double depth){
	rect3d_t rect;
	rect.corner = corner;
	rect.width = width;
	rect.height = height;
	rect.depth = depth;
	return rect;
}

rect3d_t* defineRect3dAsPointer(point3d_t corner, double width, double height, double depth){
	rect3d_t* rect = (rect3d_t*)malloc(sizeof(rect3d_t));
	rect->corner = corner;
	rect->width = width;
	rect->height = height;
	rect->depth = depth;
	return rect;
}

rect3d_t defineCube(point3d_t corner, double size){
	rect3d_t rect = defineRect3d(corner, size, size, size);
	return rect;
}

rect3d_t* defineCubeAsPointer(point3d_t corner, double size){
	rect3d_t* rect = defineRect3dAsPointer(corner, size, size, size);
	return rect;
}

//Name: defineCircle
//Description: Defines a circle with point center and radius r
//Inputs: point newpoint (center), double radius (r)
//Outputs: New circle object
//Side Effects: n/a
circle_t defineCircle(point_t newpoint, double radius){
	circle_t circle;
	circle.center = newpoint;
	circle.radius = absoluteVal(radius);
	return circle;
}

//Name: defineCircleAsPointer
//Description: Defines a pointer to a circle with point center and radius r
//Inputs: point newpoint (center), double radius (r)
//Outputs: New pointer to circle object
//Side Effects: n/a
circle_t* defineCircleAsPointer(point_t newpoint, double radius){
	circle_t* circle = (circle_t*)malloc(sizeof(circle_t));
	circle->center = newpoint;
	circle->radius = absoluteVal(radius);
	return circle;
}

//Name: calcCircleCircumference
//Description: Calculates the circumference of a circle
//Inputs: Any circle object
//Outputs: double of circle's circumference
//Side Effects: n/a
double calcCircleCircumference(circle_t circle){
	return 2*getPI()*circle.radius;
}

//Name: calcCircleDiameter
//Description: Calculates the diameter of a circle
//Inputs: Any circle object
//Outputs: double of circle's diameter
//Side Effects: n/a
double calcCircleDiameter(circle_t circle){
	return 2*circle.radius;
}

//Name: calcCircleArc
//Description: Calculates the arc of a circle
//Inputs: Any circle object
//Outputs: double of circle's arc
//Side Effects: n/a
double calcCircleArc(circle_t circle, double theta){
	return (theta/360.0)*calcCircleCircumference(circle);
}

//Name: calcCircleArea
//Description: Calculates the area of a circle
//Inputs: Any circle object
//Outputs: double of circle's area
//Side Effects: n/a
double calcCircleArea(circle_t circle){
	return getPI()*square(circle.radius);
}

//Name: calcFactorial
//Description: Calculates the factorial of a whole number
//Inputs: An integer (n)
//Outputs: The factorial up to n
//Side Effects: n/a
double calcFactorial(int n){
	double factor = 1;
	for (int i=1; i<=n; ++i){
		factor*=i;
	}
	return factor;
}

cylinder_t defineCylinder(circle_t circle, double height){
	cylinder_t cylinder;
	cylinder.circle = circle;
	cylinder.height = absoluteVal(height);
	return cylinder;
}

cylinder_t* defineCylinderAsPointer(circle_t circle, double height){
	cylinder_t* cylinder = (cylinder_t*)malloc(sizeof(cylinder_t));;
	cylinder->circle = circle;
	cylinder->height = absoluteVal(height);
	return cylinder;
}

double calcCylinderVolume(cylinder_t cylinder){
	return (calcCircleArea(cylinder.circle)*cylinder.height);
}

double calcSphereVolume(circle_t circle){
	return (4.0/3.0)*getPI()*powerNth(circle.radius, 3);
}

double calcSphereSurfaceArea(circle_t circle){
	return 4*getPI()*square(circle.radius);
}


ellipse_t defineEllipse(point_t center, double xAxis, double yAxis){
	ellipse_t ellipse;
	ellipse.center = center;
	ellipse.xAxis = absoluteVal(xAxis);
	ellipse.yAxis = absoluteVal(yAxis);
	return ellipse;
}

//Name: sine
//Description: Calculates an approximation of sine
//Inputs: double theta value
//Outputs: double closest approximation to sine
//Side Effects: n/a
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

//Name: cosine
//Description: Calculates an approximation of cosine
//Inputs: double theta value
//Outputs: double closest approximation to cosine
//Side Effects: n/a
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

//Name: tangent
//Description: Calculates an approximation of tangent
//Inputs: double theta value
//Outputs: double The approximation of tangent
//Side Effects: n/a
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

//Name: cosecant
//Description: Calculates an approximation of cosecant
//Inputs: double theta value
//Outputs: double The approximation of cosecant
//Side Effects: n/a
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

//Name: secant
//Description: Calculates an approximation of secant
//Inputs: double theta value
//Outputs: double The approximation of secant
//Side Effects: n/a
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

double cotangent(double theta){
	double TAN = tangent(theta);
	if (TAN==0){
		setError(DIVIDE_BY_ZERO);
		TAN=PRVNAN;
	}
	else{
		TAN = 1/TAN;
	}
	if (getError()!=NO_ERR)
			printf("Error: %s\n", getErrorString());
	clearError();
	return TAN;
}

double radiansToDegrees(double theta){
	return theta*(180.0f/getPI());
}

//TODO needs to be rewritten
double calcLN(double val){
    if (val <= 0) {
        return PRVNAN;  //undefined log
    }

    // approximate to 0 if close to 1
    if (val == 1) return 0;

    double result = 0.0;

    // normalize into the range of [1,2) for accuracy
    int exponent = 0;
    while (val >= 2.0) {
        val /= 2.0;
        exponent++;
        result += 0.693147181; // round up log(2)
    }
    while (val < 1.0) {
        val *= 2.0;
        exponent--;
        result -= 0.693147181; // round down log(2)
    }

    //set up for approximation
    double fraction = (val - 1) / (val + 1);
    double square = fraction * fraction;
    double approximation = fraction;
    double term = fraction;

    //Apply ln taylor series for approximation
    for (int i = 3; i <= 21; i += 2) {
        term *= square;
        approximation += term / i;
    }

    result += 2 * approximation;

    return result;
}

double calcLog(double val){
	return calcLN(val)/calcLN(10);
}

//Name: distanceFormula
//Description: calculates the distance between two points
//Inputs: Two points a and b
//Outputs: double of distance between both points
//Side Effects: n/a
double distanceFormula(point_t a, point_t b){
	//sqrt((x2-x1)^2 + (y2-y1)^2))
	return squareRoot(square(b.x-a.x)+square(b.y-a.y));
}

//Name: midpointFormula
//Description: calculates the midpoint between two points
//Inputs: Two points a and b
//Outputs: point midpoint between both points
//Side Effects: n/a
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

static double powerInt(double val, int nth){
	double ret = 1.0;
	if (nth < 0){
		nth = -nth;
		nth = 1.0/val;
	}
	for (int i=0; i<nth; ++i){
		ret *= val;
	}
	return ret;
}

static double computeFrac(double exp){
	long double res = 1.0;
	long double term = 1.0;
	for (int i=0; i<=50; ++i){
		term *= exp / i;
		res += term;
	}
	return res;
}

//TODO this needs to be fixed
static double powerFrac(double val, double nth){
	if (val == 0){
		return 0;
	}
	if (nth <= 0){
		return PRVNAN;
	}

	double lnBase = calcLN(val);
	if (lnBase == -1){
		return -1;
	}

	double result = computeFrac(nth*lnBase);
	return result;
}

//Name: powerNth
//Description: retrieves the nth power of a number
//Inputs: Double value, int nth power
//Outputs: double value to the nth power
//Side Effects: n/a
double powerNth(double val, double nth){
	if (nth == (int) nth){
		return powerInt(val, (int)nth);
	}
	else{
		return powerInt(val, (int)nth);
		//return powerFrac(val, nth);
	}
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

//Name: absoluteVal
//Description: Absolute value of a number
//Inputs: double value
//Outputs: Absolute value of the value passed in
//Side Effects: n/a
double absoluteVal(double val){
	if (val < 0){
		return val*-1.0;
	}
	return val;
}

double floorVal(double val){
	if (val==(int)(val)){
		return val;
	}

	if (val<0){
		return (int)(val-1);
	}

	return (int)(val);
}

double ceilingVal(double val){
	if (val==(int)(val)){
		return val;
	}

	if (val>0){
		return (int)(val+1);
	}

	return (int)(val);
}

//Name: roundToNearestPrecision
//Description: Value to round based on precision
//Inputs: double value, double precision
//Outputs: double nearest value to the value passed in
//Side Effects: n/a
double roundToNearestPrecision(double val, double precision){
	double quotient = val/precision;
	int quotientRounded;
	double scale = 1.0/precision;


	if (val>=0){
		quotientRounded = (double)((int)(quotient+0.6));
	}
	else{
		quotientRounded = (double)((int)(quotient-0.4));
	}
	val = quotientRounded*precision;
	val = (double)((int)(val*scale+0.5));
	val = val/scale;

	return val;
}

//Name: roundToNearest
//Description: Value to round based on precision enum
//Inputs: double value, prec_e precision
//Outputs: double nearest value to the value passed in
//Side Effects: n/a
double roundToNearest(double val, prec_e precision){
	return roundToNearestPrecision(val, getRoundPlace(precision));
}

//Name: getRoundPlace
//Description: Converts the prec_e enum to a decimal
//Inputs: precision enum
//Outputs: double corresponding to decimal place
//Side Effects: n/a
double getRoundPlace(prec_e precision){
	const double tenth = 0.1;
	const double hundredth = 0.01;
	const double thousandth = 0.001;
	const double tenthousandth = 0.0001;
	const double hundredthousandth = 0.00001;
	const double millionth = 0.000001;

	switch(precision){
	case TENTH:
		return tenth;
		break;
	case HUNDREDTH:
		return hundredth;
		break;
	case THOUSANDTH:
		return thousandth;
		break;
	case TENTHOUSANDTH:
		return tenthousandth;
		break;
	case HUNDREDTHOUSANDTH:
		return hundredthousandth;
		break;
	case MILLIONTH:
		return millionth;
		break;
	}
	return tenth;
}
