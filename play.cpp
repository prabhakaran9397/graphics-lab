#include <graphics.h>
#include "animation.h"
#define DELAY_TIME 10			//Microseconds

void init(void)
{
	int gd=DETECT;
	int gm;

	initgraph(&gd, &gm, NULL);
}

void draw(void)
{
	for(int i=0; i<360; ++i) {
		int points[]={150, 150, 200, 200, 200, 150, 150, 150};
		int n = (sizeof(points))/(2*sizeof(points[0]));
		int fpoints[8];

		int centroid_x = (points[0]+points[2]+points[4])/3.0;
		int centroid_y = (points[1]+points[3]+points[5])/3.0;

		putpixel(centroid_x, getmaxy()-centroid_y, getcolor());

		float I[3][3];
		float T[3][3];

		toIdentity(I);
		translateMat(T, -centroid_x, -centroid_y);
		combine(T, I);
		rotateMat(T, i);
		combine(T, I);
		translateMat(T, centroid_x,  centroid_y);
		combine(T, I);
		valMat(I, points, n);

		flipAxis(fpoints, points, n);
		drawpoly(n, fpoints);	

		delay(DELAY_TIME);
		setbkcolor(BLACK);
	}
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
