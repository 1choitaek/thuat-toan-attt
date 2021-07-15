#include<iostream>
#include<cmath>
using namespace std;

int Eratosthenes_PhanDoan(int n, int delta){
	bool prime[n] = {false};
	for(int i = 2; i <= (n); i+=delta) {
		for(int j = i; j <= (i+delta-1) && j<=n; j++) 
		{
			for(int p = 2; p <= sqrt(i+delta-1); p++) 
			{
				if(j%p == 0 && j != p)
					prime[j] = true;
				if(prime[j] == true) break;
			}
		}
		
	}
	prime[2] = false;
	for(int i = 2; i <= (n); i++)
	{
		if(prime[i] == false) cout << i << " ";
	}

}

int main(){
	int n, delta;;
	cout << "n = ";
	cin >> n;
	while(delta>sqrt(n)){
	cout << "delta (<= sqrt(n)) = ";
	cin >> delta;
	}
	cout << endl;
	Eratosthenes_PhanDoan(n, delta);
	return 0;
}

