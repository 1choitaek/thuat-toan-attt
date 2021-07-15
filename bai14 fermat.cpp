#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

#define N 50
int  d;

int *chuyenNhiPhan(int k)
{
	static int bin[N];
	int i = 0;

	while(k>0)
	{
		if(k%2 == 0) bin[i] = 0;
		else bin[i] = 1;
		k/=2;
		i++;
	}
	d = i-1;
	return bin;
}
int binhPhuongCoLap(int a, int k, int n) 
{
	int *bin = chuyenNhiPhan(k);
	int b = 1;
	if(k == 0) return b;
	int A = a;
	if(bin[0] == 1) b = a;
	for(int i = 1; i <= d; i++)
	{
		A = (A*A)%n;
		if(bin[i] == 1) 
			b = (A*b)%n;
	}
	return b;
} 

bool Fermat(int n, int t)
{
	for(int i = 1; i <= t; i++)
	{
		int a;
		a = 2 + rand()% (n-2);
		int r;
		r = binhPhuongCoLap(a, n-1, n);
		if(r!=1) return false;
	}
	if(n < 2) return false;
	return true;
}

int main()
{
	int n, t;
	cout << "nhap n: "; cin >> n;
	cout << "nhap so lan kiem tra: "; cin >> t;
	if(Fermat(n, t) == false) cout << "hop so";
	else cout <<"nguyen to";
	return 0;
}

