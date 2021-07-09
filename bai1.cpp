#include <iostream>
#include <cmath>
using namespace std;
#define N 50
int p, w, a, b;
void nhap()
{					
	cout << "Nhap p: ";
	cin  >> p;
	cout << "Nhap w: ";
	cin >> w;
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
}
int tinh_t()
{
	float m, t;
	int uoc;
	m = log2(p);
	t = ceil(m/w);
	cout << "Bieu dien p: " << endl;
	for (int i = t-1; i >= 0; i--){
		uoc = p/(pow(2,i*w));
		p -= pow(2,i*w)*uoc;
		
		cout << "p[" << i << "] = " << uoc << endl;
	}
	return t;
}
void congchinhxacboi() {
	cout << "Cong chinh xac boi: " << endl;
	int f[N], g[N], e = 0, c[N], uoc;
	int t = tinh_t();
	for (int i = t-1; i >= 0; i--){
		uoc = a/pow(2,i*w);
		a -= pow(2,i*w)*uoc;
		f[i] = uoc;
	}
	for (int i = t -1; i >= 0; i--){
		uoc = b/pow(2, i*w);
		b -= pow(2,i*w)*uoc;
		g[i] = uoc;
	}
	
		for (int i = 0; i <= t -1; i++){
		int tong;
		tong = f[i] + g[i] + e;
		c[i] = tong%int(pow(2,w));
		if (tong >= pow(2,w)) e = 1;
		else e = 0;
		cout << "c [" << i << "] = " << c[i] <<  ", e = " << e << endl; 
		}
	}
int main()
{
	nhap();
	tinh_t();
	congchinhxacboi();
	return 0;
}
	



