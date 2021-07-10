#include <iostream>
#include <cmath>
using namespace std;
#define N 50
int p, w, a, b;
float t;
void nhap(){
	cout << "Nhap p: ";
	cin >> p;
	cout << "Nhap w: ";
	cin >> w;
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
}
int bieudien_p(){
	float m;
	int uoc;
	m = log2(p);
	t = ceil(m/w);
		cout << "bieu dien p: " << endl;

	for (int i = t-1; i >= 0; i--){
		uoc = p/int(pow(2,i*w));
		p -= pow(2,i*w)*uoc;
		cout << "p[" << i << "] = " << uoc << endl;
	}
	return t;
}
void truchinhxacboi(){
	int f[N], g[N], c[N], e = 0, uoc;
	float m;
		cout << "tru chinh xac boi: " << endl;
	
	for (int i = t-1; i >= 0; i--){
		uoc = a/int(pow(2,i*w));
		a -= pow(2,i*w)*uoc;
		f[i] = uoc; 
	}
	for (int i = t-1; i >= 0; i--){
		uoc = b/int(pow(2,i*w));
		b -= pow(2,i*w)*uoc;
		g[i] = uoc;
	}
	
	for (int i = 0; i <= t -1; i++){
		int sub = f[i] - g[i] - e;
		c[i] = sub%int(pow(2,w));
		if (c[i] >= pow(2,w) || sub < 0) e = 1;
		else e = 0;
		cout << "c[" << i << "] = " << c[i] << ", e = " << e << endl;
	} 
}

int main(){
	nhap();
	bieudien_p();
	truchinhxacboi();
	return 0;
}

