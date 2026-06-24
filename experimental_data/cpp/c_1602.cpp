#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0)

#define endl "\n" 

#define int long long 

#define fo(i,a,n) for (int i=a;i<=n;i++)

#define ro(i,a,n) for (int i=n;i>=a;i--)

#define yes cout<<"YES"<<endl

#define no  cout<<"NO"<<endl

#define fi first

#define se second

#define pb push_back 

using namespace std;

typedef pair<int,int> PII;

const int N=2e5+10,mod=988244355;

int n;

int a[N];

int gcd(int a, int b) {  if (b == 0) {return a;}  return gcd(b, a % b);}

int lcm(int a, int b) {return a * b / gcd(a, b);}

int ksm(int x, int n){int res = 1;  x=x%mod;  while(n>0){if(n%2)res=(res*x)%mod;x*=x%mod;n=n/2;}    return res;}

void solve()

{		

	cin>>n;

	fo(i,0,31)a[i]=0;

	fo(i,1,n){

		int x;

		cin>>x;

		fo(j,0,30){

	//		if(x&1)cout<<1111<<endl;

			a[j]+=(x&1);

			x>>=1;

		}

	}

	int ggcd=0;

	fo(i,0,30)ggcd=gcd(ggcd,a[i]);

	//cout<<ggcd<<endl;

	if(ggcd==0){

		fo(i,1,n)cout<<i<<" ";cout<<endl;

		return ;

	}

	fo(i,1,ggcd){

		if(ggcd%i==0)cout<<i<<" "; 

	}

	cout<<endl;

}

signed main()

{

	IOS;

	int t;

	cin>>t;

	while(t--){

		solve();

	}

	return 0;

}