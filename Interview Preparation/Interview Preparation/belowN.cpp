#include "All.h"

int count(int n)
{
	if (n < 4) 
		return n;        
	if (n >= 4 && n <=9) 
		return n - 1;
	int orderPower = log10(n);
	int order = pow(10.0, orderPower);
	int d = n / order;
	int remainder = n % order; // rest
	if (d == 4)
		remainder = pow(10, orderPower) - 1;
	int ninePower = pow(9, orderPower);     // xyyyy -> y[0:9]-4
	if (d < 4) 
		return d * ninePower + count(remainder);
	else 
		return (d - 1) * ninePower + count(remainder);       
}

int main()
{
	cout << count(4444) <<endl;
	return 0;
}