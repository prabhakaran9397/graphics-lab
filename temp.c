#include <stdio.h>
#include <math.h>
#define PIDEG 0.017453

int main(void)
{
	int O;

	scanf("%d", &O);
	
	int c = round(cos(O*PIDEG));
	int s = round(sin(O*PIDEG));
	
	printf("Sin = %d\n", s);
	printf("Cos = %d\n", c);

	return 0;
}
