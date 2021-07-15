#include<iostream>
#include<cmath>
using namespace std;

bool KiemTraNgTo(int n){
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0 && n != i) return false;
	}
	return true;
}

int NgTo(int n){
	for(int i = 2; i <= n; i++)
	{
		if(KiemTraNgTo(i) == true) cout << i <<" ";
	}
}

int main(){
	int n;
	cout << "Nhap n > 0: ";
	cin >> n;
	if(n < 2) cout << "khong co so nguyen to!";
	else NgTo(n);
	return 0;	
}

