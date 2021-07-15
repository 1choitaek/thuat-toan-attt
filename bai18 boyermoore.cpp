#include<iostream>
#include<string>
using namespace std;

#define MAX_CHAR 256

void badCharHeuristic(string str, int size, int badchar[MAX_CHAR])
{
	int i;
	for(i = 0; i < MAX_CHAR; i++)
	{
		badchar[i] = -1; 
	}
		
	for(i = 0; i < size; i++)
	{
		badchar[(int) str[i]] = i; 		
	}
}

void Boyer_Moore(string T, string P)
{
	int n = T.size(); 
	int m = P.size(); 

	int badchar[MAX_CHAR];

	
	badCharHeuristic(P, m, badchar);
	int s = 0;
	int count = 0;
	while(s <= (n-m))
	{
		int j = m-1; 
		while(j >= 0 && P[j] == T[s+j]) 
			j--;
		if(j < 0) 
		{
			cout << "mau P trong T bat dau tu vi tri: " << s << endl;
			s +=(s+m < n) ? m - badchar[T[s+m]] : 1;

			count++;
		}
		else 
		{
			s += max(1, j - badchar[T[s+j]]);
			
		
		}
	}
	if(count == 0) cout << "khong co chuoi can tim!";
	if(count > 0) cout <<"Tim thay " << count << " ket qua!"; 
} 

int main()
{
	string T, P;

	cout << "Nhap chuoi: "; cin.ignore(T.size(),'\n'); 
	getline(cin, T);
	cout << "Nhap chuoi can tim kiem: "; cin.ignore(P.size(),'\n'); 
	getline(cin, P);
	
	Boyer_Moore(T, P);
	return 0;
}

