#include <stdio.h>
#include<conio.h>
#define MAX 100
int max(int a, int b)
{
return (a > b) ? a : b;
}
void main()
{
int n, M;
int w[MAX], p[MAX];
int v[MAX][MAX];
int i = n, j = M;
int x[MAX] = {0};
clrscr();
printf("Enter number of items: ");
scanf("%d", &n);
printf("Enter weights of items:\n");
for(i = 1; i <= n; i++)
{
scanf("%d", &w[i]);
}
printf("Enter profits of items:\n");
for(i = 1; i <= n; i++)
{
scanf("%d", &p[i]);
}
printf("Enter maximum capacity: ");
scanf("%d", &M);
for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= M; j++)
		{
			if(i == 0 || j == 0)
			{
				v[i][j] = 0;
			}
			else if(w[i] <= j)
			{
				v[i][j] = max(v[i-1][j], v[i-1][j - w[i]] + p[i]);
			}
			else
			{
				v[i][j] = v[i-1][j];
			}
		}
	}
	for(i=0;i<=n;i++)
	{
	for(j=0;j<=M;j++)
	{
		printf("%d",v[i][j]);
	}
	printf("\n");
	}

printf("\nMaximum Profit = %d\n", v[n][M]);
i=n;
j=M;
while(i > 0 && j > 0)
{
if(v[i][j] != v[i-1][j])
{
x[i] = 1;
j = j - w[i];
}
i--;
}
printf("Selected items are:\n");
for(i = 1; i <= n; i++)
{
if(x[i] == 1)
{
printf("Item %d (Weight=%d, Profit=%d)\n", i, w[i], p[i]);
}
}
getch();
}