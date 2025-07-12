#include "MathExpansion.h"

#define PRVNAN (*(double*)((uint64_t[]){0x7FF8000000000000ULL}))

typedef enum errcode_e{
	NO_ERR = 0,
	DIVIDE_BY_ZERO,
	SQUAREROOT_NEGATIVE,
	NOT_A_TRIANGLE
}errcode_e;

static errcode_e glblErrCode = 0;

static void setError(errcode_e val){
	glblErrCode = val;
}

static void clearError(){
	glblErrCode = 0;
}

static errcode_e getError(){
	return glblErrCode;
}

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

point_t definePoint(double x, double y){
	point_t newpoint;
	newpoint.x = x;
	newpoint.y = y;
	return newpoint;
}

point_t* definePointAsPointer(double x, double y){
	point_t* newpoint = (point_t*)malloc(sizeof(point_t));
	newpoint->x = x;
	newpoint->y = y;
	return newpoint;
}

triangle_t defineTriangle(point_t A, point_t B, point_t C){
	triangle_t newtriangle;
	newtriangle.A = A;
	newtriangle.B = B;
	newtriangle.C = C;
	return newtriangle;
}

triangle_t* defineTriangleAsPointer(point_t A, point_t B, point_t C){
	triangle_t* newtriangle = (triangle_t*)malloc(sizeof(triangle_t));
	newtriangle->A = A;
	newtriangle->B = B;
	newtriangle->C = C;
	return newtriangle;
}



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




