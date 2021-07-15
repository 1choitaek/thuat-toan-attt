#include<iostream>
#include<string>
using namespace std;

int Vet_Can (string T, string P)
{
	int n = T.size(); 
	int m = P.size(); 


	int i, j; 
	i = j = 0; 
	int mark = 0; 
	int count = 0;	
	while(i < n)
	{
		if(T[i] == P[j] && i <n && j < m)
		{	
			mark++;
			i++;
			j++;
		}
		else i++;
		if(mark == m)
		{
			cout << "Tim thay chuoi tai vi tri " << i-m << endl;
			j = 0;
			mark = 0;
			count++;
			i++;
		} 
		
	}
	if(count == 0) cout << "Khong tim thay chuoi";	
	else cout << "Tim thay " << count << " ket qua!";
}

int main()
{
	string T, P;

	cout << "Nhap chuoi: "; cin.ignore(T.size(),'\n'); 
	getline(cin, T);
	cout << "Nhap chuoi can tim kiem: "; cin.ignore(P.size(),'\n'); 
	getline(cin, P);
	
	Vet_Can(T, P);
	return 0;
}

