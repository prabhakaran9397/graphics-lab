#include <iostream>
#include <cmath>
using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int min(int a, int b)
{
	return a<b?a:b;
}

void myLineD(int sx, int sy, int ex, int ey)
{
	float x = sx;
	float y = sy;
	int dx = sx-ex;												//delta X
	int dy = sy-ey;												//delta Y
	int step = max(abs(dx), abs(dy));							//Number of steps
	float slope = (1.0*dy)/dx;									//Slope
	float slopi = (1.0*dx)/dy;									//Inverse Slope
	int major = abs(dx)>=abs(dy);								//1: X; 0: Y (Major)
	int sign = slope>0;											//1: +; 0: - (Slope Sign)

	for(int i=0; i<step; ++i) {
		putpixel(round(x), getmaxy()-round(y), getcolor());		//Plot the point
		x = major ? x+1 : x+abs(slopi);							//Never Decrement X
		y = major ? (sign ? y+abs(slope) : y-abs(slope)) : (sign ? y+1 : y-1);
	}

}

void myLineC(int x, int y, int ex, int ey)
{
	int dx = x-ex;												//delta X
	int dy = y-ey;												//delta Y
	int step = max(abs(dx), abs(dy));							//Number of steps
	int count = min(abs(dx), abs(dy));							//Count
	float slope = (1.0*dy)/dx;									//Slope
	int major = abs(dx)>=abs(dy);								//1: X; 0: Y (Major)
	int sign = slope>0;											//1: +; 0: - (Slope Sign)

	for(int i=0; i<step; ++i) {
		putpixel(x, getmaxy()-y, getcolor());					//Plot the point
		count+=min(abs(dx), abs(dy));
		x = major ? x+1 : (count<step ? x : x+1);
		y = major ? (count<step ? y : (sign ? y+1 : y-1)) : (sign ? y+1 : y-1);
		count = count<step ? count : count-step;
	}
}

void myLineB(int sx, int sy, int ex, int ey)					//Bresenham line algorithm
{
	int dx = sx-ex;
	int dy = sy-ey;
	int sign = (1.0*dy)/dx>0;
	int xmajor = abs(dx)>=abs(dy);
	int major = xmajor ? abs(dx) : abs(dy);
	int minor = !xmajor ? abs(dx) : abs(dy);
	int pk = 2*minor-major;

	while(sx!=ex && sy!=ey) {
		putpixel(sx, getmaxy()-sy, getcolor());
		sx = xmajor ? sx+1 : sx;
		sy = xmajor ? sy : sy+(sign?(1):(-1));
		if(pk>0) {
			sx = xmajor ? sx : sx+1;
			sy = xmajor ? sy+(sign?(1):(-1)) : sy;
			pk = pk + 2*minor - 2*major;
		} else {
			pk = pk + 2*minor;
		}
	}
}

void myLineS(int sx, int sy, int ex, int ey)
{
	line(sx, getmaxy()-sy, ex, getmaxy()-ey);					//Flip the origin vertically
}