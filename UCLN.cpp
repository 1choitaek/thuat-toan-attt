#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int tmp;
	while(b > 0)
	{
		tmp = a%b;
		a = b; b = tmp;
	}
	return a;
} 

int main()
{
	int a, b;
	cout << "2 so lan luot la: ";
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}
