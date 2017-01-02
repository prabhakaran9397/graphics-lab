#include <iostream>
#include <cmath>
using namespace std;

void myCircleB(int sx, int sy, int r)					//Bresenham circle algorithm
{
	int pk = 1-r;
	int x = 0;
	int y = r;
	while(x<y) {
		putpixel(sx+x, getmaxy()-(sy+y), getcolor());
		putpixel(sx-x, getmaxy()-(sy+y), getcolor());
		putpixel(sx+x, getmaxy()-(sy-y), getcolor());
		putpixel(sx-x, getmaxy()-(sy-y), getcolor());
		putpixel(sx+y, getmaxy()-(sy+x), getcolor());
		putpixel(sx-y, getmaxy()-(sy+x), getcolor());
		putpixel(sx+y, getmaxy()-(sy-x), getcolor());
		putpixel(sx-y, getmaxy()-(sy-x), getcolor());
		++x;
		if(pk>0) {
			y = y-1;
			pk = pk + 1 + 2*x - 2*y;
		} else {
			pk = pk + 1 + 2*x;
		}
	}
}

void myCircleS(int x, int y, int r)					//System circle
{
	circle(x, getmaxy()-y, 50);
}
