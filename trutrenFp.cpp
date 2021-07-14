#include <iostream>
#include <cmath>
using namespace std;
#define N 50
long p, w, a, b;
float t;
void  nhap(){
	cout << "Nhap p: ";
	cin >> p;
	cout << "Nhap w: ";
	cin >> w;
	cout << "Nhap a: ";
	cin >> a; 
	cout << "Nhap b: ";
	cin >> b;
}
void trutrenFp(){
	float m;
	int uoc, h[N];
	m = log2(p);
	t = ceil(m/w); 
	cout << "Phan tich p: " << endl;
	for (int i = t-1; i >= 0; i--){
		uoc = p/pow(2,i*w);
		p = pow(2,i*w)*uoc;
		h[i] = uoc;
		cout << "p[" << i << "] = " << uoc << endl;
	}


	int f[N], g[N], c[N], e = 0;
	cout << "Tru chinh xac boi: " << endl;
	for (int i = t-1; i >= 0; i--){
		uoc = a/pow(2,i*w);
		a = pow(2,i*w)*uoc;
		f[i] = uoc;
	}
	for (int i = t-1; i >= 0; i--){
		uoc = b/pow(2,i*w);
		b = pow(2,i*w)*uoc;
		g[i] = uoc;
	}
	//tru Fp
	for (int i = 0; i <= t-1; i++){
	
	int sub = f[i] - g[i] - e;
	c[i] = sub%int(pow(2,w));
	if (sub >= pow(2,w) || sub < 0){	
	e = 1;
	if (sub < 0) c[i] += pow(2,w);
	}
	else e = 0;
	cout << "c[" << i << "] = " << c[i] << ",e = " << e << endl;
}
if (e == 1){
	e = 0;
	cout << "Tru tren Fp: " << endl;
	for (int i = 0; i <= t-1; i++){
		int add = c[i] + h[i] + e;
		c[i] = add%int(pow(2,w));
		if (add >= pow(2,w)){
			e = 1;
		}
		else e = 0;
		cout << "c[" << i << "] = " << c[i] << ",e = " << e << endl;
	}
}	
	 
}


int main(){
	nhap();
	trutrenFp();
	return 0;
}

