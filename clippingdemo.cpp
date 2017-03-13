#include "basics.h"

void init(void)
{
	int gd=DETECT;
	int gm;
	initgraph(&gd, &gm, NULL);
}

void draw(void)
{
	mylineclip(100, 100, 200, 200, 150, 150, 350, 400);
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