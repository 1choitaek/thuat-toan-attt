#include<iostream>
using namespace std;

int extended_Euclid(long a, long b){
	long d ,x, y, g, h;
	g = a, h = b;
	int x1, x2, y1, y2;
	if(b == 0)
	{
		
		d = a; x = 1; y = 0;
		cout << "d = " << d << "\nx = " << x << "\ny = " << y;

	}
		
	x2 = 1; x1 = 0;
	y2 = 0; y1 = 1;
	while(b > 0)
	{
		int r;
		int q;
		q = a/b;
		r = a-q*b;
		x = x2 - q*x1;
		y = y2 - q*y1;
		a = b;
		b = r;
		x2 = x1; x1 = x;
		y2 = y1; y1 = y;
		
	}
	d = a; x = x2; y = y2;
	cout <<"gcd(" << g << "," << h << ") = " << d<<endl;
	if(d == 1) 
	{
		cout << g << "^(-1) mod " << h << " = " << x <<endl;
		cout << h << "^(-1) mod " << g << " = " << y <<endl;

	}
	else cout << "khong co nghich dao";
				
}

int main()
{	
	long  a, b;
	a = b = 0;
	while(a <= 0 || b <= 0)
	{
		cout << "Nhap a > 0: "; cin >> a;
		cout << "Nhap b > 0: "; cin >> b;
	}
	extended_Euclid(a, b);
	return 0;	
}

