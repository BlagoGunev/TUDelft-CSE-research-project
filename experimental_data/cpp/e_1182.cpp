#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>

#define inf 9999999999;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define f first
#define s second
#define pi 3.141592653589793238
using namespace std;



	ll power(ll a, ll b,ll m)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1,m)*a)%m;
		ll q = power(a,b/2,m);
		return (q*q)%m;
	}
const int arraysize=5;
void matrixmultiplication(ll arr[arraysize][arraysize],ll arr2[arraysize][arraysize],ll mod){
	ll arr3[arraysize][arraysize];
	for(int i = 0; i < arraysize; i++){
		for(int j = 0; j < arraysize; j++){
			arr3[i][j]=0;
			for(int k = 0; k < arraysize; k++){
				arr3[i][j] += arr[i][k]*arr2[k][j];
                if(arr3[i][j]>mod){
				    arr3[i][j]%=mod;
                }
			}
		}
	}
	for(int i = 0; i < arraysize; i++){
		for(int j = 0; j < arraysize; j++){
			arr[i][j]=arr3[i][j];
		}
	}
}
void matrixpower(ll arr[arraysize][arraysize],ll b,ll mod){
	ll ans[arraysize][arraysize];
	for(int i = 0; i < arraysize; i++){
		for(int j = 0; j < arraysize; j++){
			ans[i][j]=0;
		}
		ans[i][i]=1;
	}
	while(b>0){
		if(b&1){
			matrixmultiplication(ans,arr,mod);
		}
		matrixmultiplication(arr,arr,mod);
		b /= 2;
	}
	for(int i = 0; i < arraysize; i++){
		for(int j = 0; j < arraysize; j++){
			arr[i][j]=ans[i][j];
		}
	}
}
const int upperlimit = 3e6+100;
const int mod = 1e9+7;
ll matrix[arraysize][arraysize]={{1,1,0,0,0},{1,0,1,0,0},{1,0,0,0,0},{1,0,0,1,0},{0,0,0,2,1}};
int main() {
	ll x1,x2,x3,n,c;
	cin >> n >> x1 >> x2 >> x3 >> c;
	matrixpower(matrix,n-3,mod-1);
	ll ans=power(x3,matrix[0][0],mod);
	ans*=power(x2,matrix[1][0],mod);ans%=mod;
	ans*=power(x1,matrix[2][0],mod);ans%=mod;
	ll temp=2*matrix[3][0];temp+=matrix[4][0];
	temp%=mod-1;
	ans*=power(c,temp,mod);ans%=mod;
	cout << ans << endl;
	return 0;
}