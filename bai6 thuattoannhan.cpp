#include<iostream>
#include<cmath>
using namespace std;

#define N 50
long p, w, a, b;
long U, V, u[N], v[N];
void nhap()
{
	cout << "nhap p: ";
	cin >> p;
	cout << "nhap w: ";
	cin >> w;
	cout << "nhap a: ";
	cin >> a;
	cout << "nhap b: ";
	cin >> b;
	
}

int tinh_t()
{
	int m, t;
	m = (log2(p)) + 1;
	t = (m/w + 1); 

	return t;
}

int chuyenNhiPhan(int  k)
{

	long long uoc;
	
	for(int i = 2*w-1; i >= 0; i--)
	{
		u[i] = v[i] = 0;
		
		if(i>=w)
		{
			if(k >= pow(2, i))
			{
				u[i] = 1;
				uoc = k/pow(2, i);
				k -= uoc*pow(2, i);
			}	
			else u[i] = 0;
		}
	
		if(i<w)
		{
			if(k >= pow(2, i))
			{
				v[i] = 1;
				uoc = k/pow(2, i);
				k -= uoc*pow(2, i);
			}	
			else v[i] = 0;
		}
	}
	
	U = V = 0;
	for(int i = 2*w-1; i >= w; i--)
	{
		if(u[i] == 1)
			U += pow(2, i-w);
	
	}	

	for(int i = w-1; i >= 0; i--)
	{
		if(v[i] == 1)
			V+= pow(2, i);
			
	}

}

void nhanSoLon()
{

	int uoc, m, e = 0;
	int f[N], g[N], c[N];
	int t = tinh_t();

	for(int i = (t-1); i >= 0; i--)
	{
		uoc = a/(pow(2, i*w));
		a -= (pow(2, i*w)*uoc);
		f[i] = uoc;
		cout << f[i] << "\t";
	}
	cout<<endl;
	for(int i = (t-1); i >= 0; i--)
	{
		uoc = (b/(pow(2, i*w)));
		b -= (pow(2, i*w)*uoc);
		g[i] = uoc;	
		cout << g[i] << "\t";
	}
	cout<<endl;

	for(int i = 0; i  <= t-1; i ++)
	{
		long  k;
		c[i] = 0;
		for(int i = 0; i <= t-1; i++)
		{
			U = 0;
			for(int j = 0; j <= t-1; j++)
			{
				if(i == 0) c[j] = 0;
				k = c[i+j] + f[i]*g[j] + U;
				chuyenNhiPhan(k);	
				c[i+j] = V;
			}	
			c[i+t] = U;
		}
	}
	
	for(int i = 0; i < w; i++)
	{
		cout << "c[" << i << "] = " << c[i] <<  endl;
	}
}

int main()
{
	nhap();
	nhanSoLon();
	
	return 0;
	
}
