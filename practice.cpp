#include <graphics.h>
#include <math.h>
#include "transforms.h"

void init(void)
{
	int gd = DETECT;
	int gm;
	initgraph(&gd, &gm, NULL);
}
/*
int _x(int a)
{
	return a;
}

int _y(int a)
{
	return getmaxy()-a;
}

void mypoint(int x, int y)
{
	x = _x(x);
	y = _y(y);
	if(0 <= x && x <= getmaxx())
		if(0 <= y && y <= getmaxy())
			putpixel(x, y, getcolor());
}

void myline(int sx, int sy, int ex, int ey)
{
	if(sx > ex)
	{ // Always left to right
		int t;
		t = sx; sx = ex; ex = t;
		t = sy; sy = ey; ey = t;
	}
	int dx = ex - sx;
	int dy = ey - sy;
	int st = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
	int sn = (dy * 1.0) / dx > 0 ? 1 : -1;
	float x = sx;
	float y = sy;
	for(int i=0; i<st; ++i)
	{
		mypoint(x, y);
		if(abs(dx) > abs(dy))
		{	// X-major
			x = x + 1;
			y = y + sn * fabs((dy * 1.0) / dx);
		}
		else
		{	// Y-major
			x = x + fabs((dx * 1.0) / dy);
			y = y + sn;
		}
	}
}
*/

void draw(void)
{
	/*
	myline(0, 0, 400, 150);		//X, +
	myline(0, 150, 400, 0);		//X, -
	myline(0, 0, 150, 400);		//Y, +
	myline(0, 400, 150, 0);		//Y, -
	*/
	int points[] = {50, 150, 125, 250, 200, 125};
	mypolygon(points, sizeof(points)/(2 * sizeof(points[0])));

	for(int i=0; i<10; ++i)
	{
		float cx = (points[0]+points[2]+points[4])/3;
		float cy = (points[1]+points[3]+points[5])/3;

		float I[3][3];	toIdentity(I);
		float T[3][3];
		translateMat(T, -points[0], -points[1]);	combine(T, I);
		scaleMat(T, 0.75, 0.75);		combine(T, I);
		translateMat(T, points[4], points[5]);	combine(T, I);

		valMat(I, points, sizeof(points)/(2 * sizeof(points[0])));
		mypolygon(points, sizeof(points)/(2 * sizeof(points[0])));
	}

}

void end(void)
{
	while(getchar() == 0);
	closegraph();
}

int main(void)
{
	init();
	draw();
	end();

	return 0;
}