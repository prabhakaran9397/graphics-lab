#include <graphics.h>
#include "lines.h"
#define DELAY_TIME 2000				//Microseconds

void init(void)
{
	int gd=DETECT;
	int gm;

	initgraph(&gd, &gm, NULL);
}

void draw(void)						// Draw here
{
	setbkcolor(BLACK);	
	setcolor(RED);					//DDA Method
	outtextxy(10, 10, "DDA Method Lines");
	myLineD(0, 0, 400, 150);		//X, +
	myLineD(0, 150, 400, 0);		//X, -
	myLineD(0, 0, 150, 400);		//Y, +
	myLineD(0, 400, 150, 0);		//Y, -

	delay(DELAY_TIME);

	setbkcolor(BLACK);	
	setcolor(GREEN);				//Graphic Library Lines
	outtextxy(10, 10, "Graphic Library Lines");
	myLineS(0, 0, 400, 150);		//X, +
	myLineS(0, 150, 400, 0);		//X, -
	myLineS(0, 0, 150, 400);		//Y, +
	myLineS(0, 400, 150, 0);		//Y, -
	
	delay(DELAY_TIME);

	setbkcolor(BLACK);
	setcolor(BLUE);					//Counter Method
	outtextxy(10, 10, "Counter Method Lines");
	myLineC(0, 0, 400, 150);		//X, +
	myLineC(0, 150, 400, 0);		//X, -
	myLineC(0, 0, 150, 400);		//Y, +
	myLineC(0, 400, 150, 0);		//Y, -

	delay(DELAY_TIME);

	setbkcolor(BLACK);
	setcolor(RED);
	outtextxy(10, 10, "All Lines; RED-GL; GREEN-DDA; BLUE-Counter");
	myLineS(0, 0, 400, 150);		//X, +
	myLineS(0, 150, 400, 0);		//X, -
	myLineS(0, 0, 150, 400);		//Y, +
	myLineS(0, 400, 150, 0);		//Y, -
	setcolor(GREEN);
	myLineD(0, 0, 400, 150);		//X, +
	myLineD(0, 150, 400, 0);		//X, -
	myLineD(0, 0, 150, 400);		//Y, +
	myLineD(0, 400, 150, 0);		//Y, -
	setcolor(BLUE);
	myLineC(0, 0, 400, 150);		//X, +
	myLineC(0, 150, 400, 0);		//X, -
	myLineC(0, 0, 150, 400);		//Y, +
	myLineC(0, 400, 150, 0);		//Y, -
}

void end(void)
{
	getchar();						// Don't close it 
	closegraph();
}

int main(int args, char *argv[])
{
	init();							// Initialise
	draw();							// Draw on the graph
	end();							
	return 0;
}
