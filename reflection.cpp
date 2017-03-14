#include "transforms.h"

void init(void)
{
	int gd = DETECT;
	int gm;
	initgraph(&gd, &gm, NULL);
}

void draw(void)
{
	drawco();
	myline(-250, -250, 250, 250);
	
	int points[] = {60, 40, 150, 100, 200, 100};
	int n = sizeof(points)/(2*sizeof(points[0]));
	mypolygon(points, n);

	float I[3][3];	toIdentity(I);
	float T[3][3] = {
						{0, 1, 0},
						{1, 0, 0},
						{0, 0, 0}
					};
	combine(T, I);
	valMat(I, points, n);
	mypolygon(points, n);
}

void end(void)
{
	while(getchar()==0);
	closegraph();
}

int main(void)
{
	init();
	draw();
	end();
	return 0;
}