#include<iostream>
using namespace std;

#define N 50
int t;
int *chuyenNhiPhan(int  k){
	static int bin[N];
	int i = 0;
	while(k > 0)
	{
		if(k%2 == 0) bin[i] = 0;
		else bin[i] = 1;
		k/=2;
		i++;
	}
	t = i-1;
	return bin;
}
int binhPhuongCoLap(int a, int k, int n){
	int *bin = chuyenNhiPhan(k);
	int b = 1;
	if(k == 0) cout << b;
	int A = a;

	for(int i = t; i >= 0; i--)
		cout << bin[i];
	cout << endl;

	if(bin[0] == 1) b = a;
	for(int i = 1; i <= t; i++)
	{
		A = (A*A)%n;
		if(bin[i] == 1) {
			b = (A*b)%n;		
		}
	}
	cout << "b = " << b;
} 

int main(){
	int a, k, n;
	cout << "a = ";
	cin >> a;
	cout << "k = ";
	cin >> k;
	cout << "n = ";
	cin >> n;
  
	binhPhuongCoLap(a, k, n);
	return 0;
}

