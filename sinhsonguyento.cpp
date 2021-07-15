#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

bool prime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0) return false;
	}
	return true;
}

bool trial_division(int n)
{
	for(int i = 2; i < n; i++)
	{
		if(prime(i) == true)
		{
			if(n%i == 0) return false;
		}
	}
	return true;
}

int squareMulti(int a, int k, int n)
{
	int b = 1;
	int A = a;
	while(k > 0)
	{
		A = (A*A)%n;
		if(k%2 == 0) b = (b*A)%n;
	}
	return b;
}

bool Miller_Rabin(int n, int t) 
{
	int a, r, s, y;
	int mark = n-1;
	s = 0;
	while(mark%2 == 0)
	{
		mark/=2;
		s++;
	}
	r = mark;
	while(t > 0)
	{
		a = 2 + rand()%(n-2);
		y = squareMulti(a, r, n);
		if(y!=1 && y!=(n-1))
		{
			int j = 1;
			while(j < (s-1))
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

int Random_search(int k, int t)
{
	int mark1, mark2;
	mark1 = mark2 = 0;	
	int n;
	int max = 0;
	for(int i = 0; i < k; i++)
		max+=pow(2, i);	
	do
	{
		do
		{
			srand(time(NULL));
			n = 2 + rand()% max;
			if(trial_division(n) == false) mark1 = 0;
			else mark1 = 1;
		}while(mark1 == 0);
		if(Miller_Rabin(n, t) == true) return n;
		
	}while(mark2 == 0);
}

int main()
{
	cout << Miller_Rabin(15, 4);
	int k, t;
	cin >> k  >> t;
	
	cout << Random_search(k, t);
	return 0;
}

