#include<iostream>
#include<cmath>
using namespace std;

bool KiemTraNgTo(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0 && n != i) return false;
	}
	return true;
}

int main()
{
	int n;
	cout << "Nhap n > 0: ";
	cin >> n;
	if(n < 2) cout << "hop so";
	if(KiemTraNgTo(n) == false) cout << "hop so";
	else cout << "nguyen to";
	return 0;
	
}

