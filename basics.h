#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;

//x control
int _x(int x)
{
	return getmaxx()/2+x;
}

//y control
int _y(int y)
{
	return getmaxy()/2-y;
}

//Draw point 
void point(int x, int y)
{
	x = _x(x);
	y = _y(y);
	if(0 < x && x < getmaxx() && 0 < y && y < getmaxy())
	{
		putpixel(x, y, getcolor());
	}
}

//swap function
void swap(int &sx, int &sy, int &ex, int &ey)
{
	int t;
	t = sx; sx = ex; ex = t;
	t = sy; sy = ey; ey = t;
}

//DDA line algorithm
void mylineD(int sx, int sy, int ex, int ey)
{
	if(sx > ex)
	{
		swap(sx, sy, ex, ey);
	}
	float x = sx;
	float y = sy;
	int dx = ex - sx;	//difference in x
	int dy = ey - sy;	//difference in y
	int sign = (1.0*dy)/dx > 0 ? 1 : -1;	//sign of the slope
	int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);	//maximum is chosen as step

	for(int i=0; i<step; ++i)
	{
		point(x, y);
		if(abs(dx) > abs(dy))	//X-major line
		{	
			x = x + 1;
			y = y + sign*fabs((1.0*dy)/dx);
		}
		else	//Y-major line
		{
			x = x + fabs((1.0*dx)/dy);
			y = y + sign;
		}
	}

}

//Counter method algorithm
void mylineC(int sx, int sy, int ex, int ey)
{
	if(sx > ex)
	{
		swap(sx, sy, ex, ey);
	}
	int dx = ex - sx;	//difference in x
	int dy = ey - sy;	//difference in y
	int sign = (1.0*dy)/dx > 0 ? 1 : -1;	//sign of the slope
	int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);	//maximum is chosen as step
	int count = abs(dx) <= abs(dy) ? abs(dx) : abs(dy);	//minimum is chosen as count

	for(int i=0; i<step; ++i)
	{
		point(sx, sy);
		if(abs(dx) > abs(dy))	//X-major line
		{	
			count = count + abs(dy);
			sx = sx + 1;
			if(count >= step)
			{
				sy = sy + sign;
				count = count-step;
			}
		}
		else	//Y-major line
		{
			count = count + abs(dx);
			if(count >= step)
			{
				sx = sx + 1;
				count = count-step;
			}
			sy = sy + sign;
		}
	}

}


//Bresenham line algorithm
void myline(int sx, int sy, int ex, int ey, int thick=1)
{
	if(sx > ex)
	{
		swap(sx, sy, ex, ey);
	}
	int dx = ex - sx;	//difference in x
	int dy = ey - sy;	//difference in y
	int sign = (1.0*dy)/dx > 0 ? 1 : -1;	//sign of the slope

	if(abs(dx) > abs(dy))	//X-major line
	{
		int pk = 2*abs(dy) - abs(dx);
		while(sx != ex || sy != ey)
		{
			for(int j=0; j<thick; ++j)
			{
					point(sx, sy+j);	//draw point
					point(sx, sy-j);
			}
			sx = sx + 1;	//increment x
			if(pk > 0)
			{	
				sy = sy + sign; //increment or decrement y
				pk = pk + 2*abs(dy) - 2*abs(dx);
			}
			else
			{	
				pk = pk + 2*abs(dy);
			}
		}
	}
	else	//Y-major line
	{
		int pk = 2*abs(dx) - abs(dy);
		while(sx != ex || sy != ey)
		{
			for(int j=0; j<thick; ++j)
			{
					point(sx+j, sy);	//draw point
					point(sx-j, sy);
			}
			sy = sy + sign; //increment or decrement y
			if(pk > 0)
			{	
				sx = sx + 1;	//increment x
				pk = pk + 2*abs(dx) - 2*abs(dy);
			}
			else
			{	
				pk = pk + 2*abs(dx);
			}
		}
	}

}

//Bresenham circle algorithm
void mycircle(int cx, int cy, int r)
{
	int pk = 1 - r;
	int x = 0;
	int y = r;

	while(x < y)
	{
		for(int i=-1; i<=1; i+=2)
		{
			for(int j=-1; j<=1; j+=2)
			{
				point(cx + i*x, cy + j*y);
				point(cx + i*y, cy + j*x);
			}
		}
		x = x + 1;
		if(pk > 0)
		{
			y = y - 1;
			pk = pk + 1 + 2*x - 2*y;
		}
		else
		{
			pk = pk + 1 + 2*x;
		}
	}
}

void mypolygon(int points[], int n, int thick=1)
{
	for(int i=0; i+3<2*n; i+=2)
	{
		myline(points[i], points[i+1], points[i+2], points[i+3], thick);
	}
}

//Draw Coordinates
void drawco(void)
{
	setcolor(GREEN);
	myline(0, 0, 0, getmaxy());
	myline(0, 0, getmaxx(), 0);
	myline(0, 0, 0, -getmaxy());
	myline(0, 0, -getmaxx(), 0);
	setcolor(WHITE);
}

void mylineclip(int xmin, int ymin, int xmax, int ymax, 
				int sx, int sy, int ex, int ey)
{
	myline(xmin, 0, xmin, getmaxy());
	myline(xmax, 0, xmax, getmaxy());
	myline(0, ymin, getmaxx(), ymin);
	myline(0, ymax, getmaxx(), ymax);

	if(sx > ex)
	{
		swap(sx, sy, ex, ey);
	}
	myline(sx, sy, ex, ey);

	int p[4], q[4], points[8], c=0;
	float u;

	p[0] = -abs(sx-ex);	q[0] = sx-xmin;
	p[1] = -p[0];		q[1] = xmax-sx;
	p[2] = -abs(sy-ey);	q[2] = sy-ymin;
	p[3] = -p[2];		q[3] = ymax-sy;

	if(xmin <= sx && sx <= xmax && ymin <= sy && sy <= ymax)
	{
		points[c] = sx;	points[c+1] = sy; c+=2;
	}

	for(int i=0; i<4; ++i)
	{
		if(p[i] != 0)
		{
			u = (1.0*q[i])/p[i];
			int x = sx + (ex-sx)*u;
			int y = sy + (ey-sy)*u;
			if(xmin <= x && x <= xmax && ymin <= y && y <= ymax)
			{
				if(sx <= x && x <= ex && sy <= y && y <= ey)
				{
					points[c] = x;	points[c+1] = y; c+=2;
				}
			}
		}
	}

	if(xmin <= ex && ex <= xmax && ymin <= ey && ey <= ymax)
	{
		points[c] = ex;	points[c+1] = ey; c+=2;
	}
	
	setcolor(RED);
	mypolygon(points, c/2);

}