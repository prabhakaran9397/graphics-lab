#include <graphics.h>
#include "transforms.h"
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
	int n = 4;

	mypolygon(points, n);

	int centroid_x = (points[0]+points[2]+points[4])/3.0;
	int centroid_y = (points[1]+points[3]+points[5])/3.0;

	float I[3][3];	toIdentity(I);
	float T[3][3];

	translateMat(T, -centroid_x, -centroid_y);	combine(T, I);
	scaleMat(T, 2, 2);							combine(T, I);
	rotateMat(T, 90);							combine(T, I);
	translateMat(T, centroid_x,  centroid_y);	combine(T, I);
	valMat(I, points, n);

	mypolygon(points, n);	
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
