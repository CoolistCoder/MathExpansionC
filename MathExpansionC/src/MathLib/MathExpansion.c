#include "MathExpansion.h"

#define PRVNAN (*(double*)((uint64_t[]){0x7FF8000000000000ULL}))

typedef enum errcode_e{
	NO_ERR = 0,
	DIVIDE_BY_ZERO,
	SQUAREROOT_NEGATIVE,
	NOT_A_TRIANGLE
}errcode_e;

static errcode_e glblErrCode = NO_ERR;

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
	case NO_ERR:
		return "NO ERROR";
		break;
	default:
		return "NO ERROR";
		break;
	}
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

//Name: squareRoot
//Description: Square roots a number using babylonian method
//Inputs: Double value to square root
//Outputs: Double of squared value
//Side Effects: n/a
double squareRoot(double val){
	double root;
	double err;
	if (val < 0){
		setError(SQUAREROOT_NEGATIVE);
		root = PRVNAN;
	}
	else{
		root = val/2.0;
		err = 0.000000001;
		while ((root * root - val) > err || (val - root * root) > err){
			root = (root + val / root) / 2.0;
		}
	}
	if (getError()!=NO_ERR){
		printf("Error: %s\n", getErrorString());
	}
	clearError();
	return root;
}




