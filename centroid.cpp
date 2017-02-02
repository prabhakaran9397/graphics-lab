#include <graphics.h>
#include "animation.h"
#define DELAY_TIME 2000				//Microseconds

void init(void)
{
	int gd=DETECT;
	int gm;

	initgraph(&gd, &gm, NULL);
}

void draw(void)
{
	int points[]={150, 150, 200, 200, 200, 150, 150, 150};
	int n = (sizeof(points))/(2*sizeof(points[0]));
	int fpoints[8];

	flipAxis(fpoints, points, n);
	drawpoly(n, fpoints);

	int centroid_x = (points[0]+points[2]+points[4])/3.0;
	int centroid_y = (points[1]+points[3]+points[5])/3.0;

	int I[3][3];
	int T[3][3];

	toIdentity(I);
	translateMat(T, -centroid_x, -centroid_y);
	combine(T, I);
	scaleMat(T, 2, 2);
	combine(T, I);
	rotateMat(T, 90);
	combine(T, I);
	translateMat(T, centroid_x,  centroid_y);
	combine(T, I);
	valMat(I, points, n);

	flipAxis(fpoints, points, n);
	drawpoly(n, fpoints);	
}

void end(void)
{
	while(getchar() == 0);						// Don't close it 
	closegraph();
}

int main(int args, char *argv[])
{
	init();							// Initialise
	draw();							// Draw on the graph
	end();							
	return 0;
}
