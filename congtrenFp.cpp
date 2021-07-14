#include <iostream>
#include <cmath>
using namespace std;
long p, w, a ,b;
float t;
#define N 50
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
int phantich_p(){
	cout << "phan tich p: " << endl;
	float m;
	int uoc;
	m = log2(p);
	t = ceil(m/w);
	for (int i = t -1; i >= 0; i--){
		uoc = p/pow(2,w*i);
		p -= pow(2,w*i)*uoc;
		cout << "p[" << i << "] = " << uoc << endl;
	}
	return t;
}
void congchinhxacboi(){
	int f[N], g[N], c[N], e = 0, uoc, h[N];
	for (int i = t -1; i >= 0; i--){
		uoc = p/pow(2,w*i);
		p -= pow(2,w*i)*uoc;	
		h[i] = uoc;
	}
	cout << "Cong chinh xac boi: " << endl;
	for (int i = t -1; i >= 0; i--){
		uoc = a/pow(2,w*i);
		a -= pow(2,w*i)*uoc;
		f[i] = uoc;
	}
	for (int i = t -1; i >= 0; i--){
		uoc = b/pow(2,w*i);
		b -= pow(2,w*i)*uoc;
		g[i] = uoc;
	}
	for (int i = 0; i <= t-1; i++){
	int add = f[i] + g[i] + e;
	c[i] = add%int(pow(2,w*i));
		if (add > pow(2,w) || add < 0) e = 1;
		else e = 0;
		cout << "c[" << i << "] = " << c[i] << ", e = " << e << endl;
	}


			cout << "Cong tren Fp: " << endl;
	if (e == 1){
		e = 0;
		for (int i = 0; i <= t-1; i++){	
			int sub = c[i] - h[i] - e;
			c[i] = sub%int(pow(2,w));
			if (sub < 0){
				if (c[i] < 0) 
				c[i] += pow(2,w);
				e = 1;
			}
			else e = 0;
		cout << "c[" << i << "] = " << c[i] << ",e = " << e << endl; 
		}			
	} 
}


int main(){
	nhap();
	phantich_p();
	congchinhxacboi();
//	con
	return 0;
}
