#include<iostream>
#include<cmath>
using namespace std;

void sieve_Eratosthenes(int n){
	bool prime[n+1] = {false};
	for(int i = 2; i <= sqrt(n); i++){
		if(!prime[i])
		{
			for(int j = i*i; j <= n; j+=i)
				prime[j] = true;
		}
	}
	for(int i = 2; i <= n; i++){
		if(prime[i] == false) cout << i << ' ';
	}
	
}

int main(){
	int n;
	cin >> n ;
	sieve_Eratosthenes(n);
	return 0;
}

