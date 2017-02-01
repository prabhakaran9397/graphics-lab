#include <cmath>
#define PI 3.14159265

int y(int a)
{
	return getmaxy()-a;
}

void flipAxis(int fpoints[], int points[], int n)
{
	for(int i=0; i<2*n; i+=2) {
		fpoints[i]		= points[i];
		fpoints[i+1]	= y(points[i+1]);
	}
}

void combine(int a[3][3], int b[3][3])
{
	int c[3][3];

	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			c[i][j] = 0;
			for(int k=0; k<3; ++k) {
				c[i][j] += a[i][k] * b[k][j]; 
			}
		}
	}

	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			b[i][j] = c[i][j];
		}
	}

}

void translateMat(int a[3][3], int tx, int ty)
{
	a[0][0]=1; a[0][1]=0; a[0][2]=tx;
	a[1][0]=0; a[1][1]=1; a[1][2]=ty;
	a[2][0]=0; a[2][1]=0; a[2][2]=1;
}

void rotateMat(int a[3][3], int O)
{
	int c = round(cos(O*PI/180.0));
	int s = round(sin(O*PI/180.0));

	a[0][0]=c; a[0][1]=-s; a[0][2]=0;
	a[1][0]=s; a[1][1]=c; a[1][2]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=1;
}

void scaleMat(int a[3][3], int sx, int sy)
{
	a[0][0]=sx; a[0][1]=0; a[0][2]=0;
	a[1][0]=0; a[1][1]=sy; a[1][2]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=1;
}

void toIdentity(int a[3][3])
{
	a[0][0]=1; a[0][1]=0; a[0][2]=0;
	a[1][0]=0; a[1][1]=1; a[1][2]=0;
	a[2][0]=0; a[2][1]=0; a[2][2]=1;
}

void valMat(int a[3][3], int points[], int n)
{
	int _x, _y;

	for(int i=0; i<2*n; i+=2) {
		/*
		_x 			= points[i];
		_y 			= y(points[i+1]);
		points[i]	= a[0][0]*_x + a[0][1]*_y + a[0][2];
		points[i+1] = y(a[1][0]*_x + a[1][1]*_y + a[1][2]);
		*/
		_x 			= points[i];
		_y 			= points[i+1];
		points[i]	= a[0][0]*_x + a[0][1]*_y + a[0][2];
		points[i+1] = a[1][0]*_x + a[1][1]*_y + a[1][2];
	}
}
