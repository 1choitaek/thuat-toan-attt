#include<iostream>
using namespace std;

void extended_Euclid(int a, int b)
{
	int d ,x, y;
	if(b == 0)
	{
		
		d = a; x = 1; y = 0;
		cout << "d = " << d << "\nx = " << x << "\ny = " << y;
	}
	int x1, x2, y1, y2;
	
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
	cout << "d = " << d << "\nx = " << x << "\ny = " << y << endl;
}

int main()
{	
	int a, b;
	cout << "2 so a va b la: ";
	cin >> a >> b;
	extended_Euclid(a, b);
	return 0;	
}
