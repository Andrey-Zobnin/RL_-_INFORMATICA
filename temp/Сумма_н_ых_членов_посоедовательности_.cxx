#include<stdio.h>
#include<math.h>

int main()
{
	int x, y;

	const double eps = 0.0000007;

	double b1 = 0;
	// num, b, c, k = 0
	// double b1 = 0, b2 = 0;
	
	printf("Enter last num: ");
	
	scanf("%d", &y);
	
	for(x = 1; x < y; x++)
	{
		double m = double (2*x +1) / pow(pow(2*x + 1, 2)+1, 2);

		b1 += m;

		if (m > eps) {
		printf("x = %d      b = %.4lf\n", x, b1);
		}
		else {
			break;
		}
	}
	return 0;
}