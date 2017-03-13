#include "basics.h"

void init(void)
{
	int gd=DETECT;
	int gm;
	initgraph(&gd, &gm, NULL);
}

void draw(void)
{
	myline(0, 0, 400, 150);		//X, +
	myline(0, 150, 400, 0);		//X, -
	myline(0, 0, 150, 400);		//Y, +
	myline(0, 400, 150, 0);		//Y, -
	
	mycircle(200, 150, 50);

	int points[] = {200, 200, 200, 300, 350, 350, 200, 200};
	mypolygon(points, 4);
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