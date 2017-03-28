#include <stdio.h>
#include <string.h>
#define SIZE	1000

void encode(char S[], char E[])
{
	int l = strlen(S);
	int c = 1;
	int k = 0;
	for(int i=0; i<l; ++i)
	{
		if(i+1 < l && S[i] == S[i+1])
		{
			c = c + 1;
		} 
		else
		{
			if(c > 1) 
			{
				int r = 0;
				while(c)
				{
					r = r*10 + c%10;
					c = c/10;
				}
				while(r)
				{
					E[k++] = r%10 + '0';
					r = r/10;
				}
			}
			E[k++] = S[i];
			c = 1;
		}
	}
	E[k] = 0;
}

void decode(char E[], char D[])
{
	int l = strlen(E);
	int c = 0;
	int k = 0;

	for(int i=0; i<l; ++i)
	{
		if('0' <= E[i] && E[i] <= '9')
		{
			c = c*10 + E[i] - '0'; 
		}
		else
		{
			if(c == 0)
			{
				D[k++] = E[i];	
			}
			else
			{
				for(int j=0; j<c; ++j)
				{
					D[k++] = E[i];
				}
				c = 0;
			}
		}
	}
	D[k] = 0;
}

int main(void)
{
	char S[SIZE];
	char Encode[SIZE];
	char Decode[SIZE];

	scanf("%s", S);
	encode(S, Encode);
	puts(Encode);

	decode(Encode, Decode);
	puts(Decode);

	return 0;
}