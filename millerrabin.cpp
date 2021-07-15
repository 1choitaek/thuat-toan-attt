#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

#define N 50
int d;

int *chuyenNhiPhan(int k){
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

int binhPhuongCoLap(int a, int k, int n) {
	int *bin = chuyenNhiPhan(k);
	int b = 1;
	int A = a;
	if(k == 0) return b;
	if(bin[0] == 1)  b = a;
	for(int i = 1; i <= d; i++)
	{
		A = (A*A)%n;
		if(bin[i] == 1) b = (b*A)%n;
	}
	return b;
}

bool Miller_Rabin(int n, int t)
{
	int s, r;
	s = 0;
	int mark = n-1;
	while(mark%2 == 0)
	{
		s++;
		mark/=2;
	}
	r = mark;
	while(t > 0)
	{
		int a, y;
		
		a = 2 +rand()%(n-2);
		y = binhPhuongCoLap(a, r, n);
		
		if(y != 1 && y != (n-1))
		{
			int j = 1;
			while(j <= (s-1) && y != (n-1))
			{
				y = (y*y)%n;
				if(y == 1) return false;
				j++;
			}
			if(y != (n-1)) return false;
		}
		t--;
	}
	return true;
}

int main(){
	int n, t;
	while(n < 2)
	{
		cout << "Nhap n>=2: "; cin >> n;
	}
	cout << "Nhap so lan kiem tra: "; cin >> t;
	if(n == 2) cout << "nguyen to";
	else
	{
		if(Miller_Rabin(n, t) == false) cout << "hop so";
		else cout << "nguyen to";
	}
	
	return 0;
}

