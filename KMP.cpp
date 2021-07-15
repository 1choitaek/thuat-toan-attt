#include<iostream>
#include<string>
using namespace std;

void computeLPSArray(string P, int m, int lps[]) 
{
	int len = 0;
	lps[0] = 0; 
	
	int i = 1;
	while(i < m)
	{
		if(P[i] == P[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++; 
				
			}
		}
	}
}

void KMP_search(string T, string P)
{
	int n = T.size();
	int m = P.size();
	
	int i = 0; 
	int j = 0; 
	
	int lps[m];
	computeLPSArray(P, m, lps);
	int count = 0;
	
	while(i < n)
	{
		if(P[j] == T[i])
		{
			i++; 
			j++;
		}
		if(j == m)
		{
			cout << "tim thay chuoi tai vi tri: " << i-j << endl;
			j = lps[j-1];
			count++;
		}
		else if(i < n && P[j] != T[i])
		{
			if(j != 0)
				j = lps[j-1]; 
			else
				i++;
		}
	}
	if(count == 0) cout << "khong ton tai chuoi!";
}

int main()
{
	string T, P;
	
	cout << "Nhap chuoi: "; cin.ignore(T.size(),'\n'); 
	getline(cin, T);
	cout << "Nhap chuoi can tim kiem: "; cin.ignore(P.size(),'\n'); 
	getline(cin, P);
	
	KMP_search(T, P);
	return 0;
}

