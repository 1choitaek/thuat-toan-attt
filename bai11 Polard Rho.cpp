#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b){
	int tmp;
	while(b != 0)
	{
		tmp = a%b;
		a = b; 
		b = tmp;
	}
	return a;
}

long long int Pollard_Rho(long long n, long long d)
{
	long long a, b;
	a = 2; b = 2;
	int count = 1; 
	cout << "step" << "\t|\t" << "\ta\t" << "\tb\t\t" << "d" << endl;
	cout << "_____________________________________________________________" << endl;
	do
	{
		a = (a*a + 1)%n;
		b = (b*b + 1)%n; b = (b*b + 1)%n;
		d = gcd(abs(a-b), n);
		cout << count << "\t|\t\t" << a << "\t\t" << b << "\t\t" << d << endl;
		count++;
	} while( d == 1);
	cout << "_____________________________________________________________" << endl;
	if(d == n) return false;
	if(1 < d < n) return d;
		
}

int main()
{
	long long n, d;
	cout << "nhap n: ";
	cin >> n;
	cout << "d = " << Pollard_Rho(n, d);
	return 0;
}

