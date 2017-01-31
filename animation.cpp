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
	int points[]={0, y(0), 200, y(200), 200, y(150), 0, y(0)};
	int n = (sizeof(points))/(2*sizeof(points[0]));

	drawpoly(n, points);
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
