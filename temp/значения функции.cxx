#include<stdio.h>
#include<math.h>

int main(void)
{
	const double eps = 0.000000006;
	double start = 0, end = 0, h = 0, y1 = 0, y2 = 0;
	do {
	printf("Enter start : ");
	scanf("%lf", &start);
	printf("Enter end : ");
	scanf("%lf", &end);
	printf("Enter h : ");
	scanf("%lf", &h);

	} while(start > end || h == 0);
	printf("      X                  Y1               Y2\n");
	for(start; start <= end; start += h) {
		double x = start; 
		if (fabs(x) < eps) {
			printf("                   X = ZERO\n");
			}
		else {	
		y1 = cbrt(x);
		y2 = 1/x * sin(x);
		printf("|x = %.5lf  |   y1 = %.5lf  |  y2 = %.5lf|\n",x ,y1 ,y2);
		} 
		}
}