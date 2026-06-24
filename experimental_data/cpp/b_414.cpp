#include<iostream>



using namespace std;



const  int mod = 1e9 + 7;

long long d[3000][12], sum[3000];

long long k[20][3000];



long long ent( int i , int n)

{

	if( i == 0 || i == n)

		return 1;

	if( k[i][n] != 0)

		return k[i][n];

	k[i][n] = ent( i - 1 , n - 1) + ent( i , n - 1);

	k[i][n] %= mod;

	return ent( i - 1 , n - 1) + ent( i , n - 1);

}



int main(){

	int n, m, f, g;

	long long ans = 0;

	cin >> n >> m;



	for( int i = 1; i <= n; i++)

	{

		d[i][1] = 1;

		for( int j = 1; j <= 11 ; j++)

		{

		

			sum[j] += d[i][j];

			sum[j] %= mod;

			for (int z = 2 * i; z <= n; z += i)

			{

				d[z][j + 1] += d[i][j];

				d[z][j  + 1] %= mod;

			}

		}

	}



	for( int i = 1; i <= min(m , 11); i++)

	{

		long long h = ent( i - 1 , m - 1) * sum[i]; h %= mod;

		ans += h;

		ans %= mod;

	}

	cout << ans;

}