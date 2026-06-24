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

const int N=2e6+10,mod=988244355;

int n;

int a[N];

int gcd(int a, int b) {  if (b == 0) {return a;}  return gcd(b, a % b);}

int lcm(int a, int b) {return a * b / gcd(a, b);}

int ksm(int x, int n){int res = 1;  x=x%mod;  while(n>0){if(n%2)res=(res*x)%mod;x*=x%mod;n=n/2;}    return res;}

void solve()

{		

	cin>>n;

	int l=1e9,r=-1;

	int wl=1e9,wr=1e9,alf=1e9,art=-1,w3=1e9;

	while(n--){

		int a,b,val;

		cin>>a>>b>>val;

		if(a<=l){

			if(l==a)

			wl=min(val,wl);

			else wl=val;

			l=a;

		}

		if(b>=r){

		if(r==b)wr=min(val,wr);

		else wr=val;

		r=b;

		}

		if(a<=alf&&b>=art){

			if(a==alf&&b==art)w3=min(w3,val);

			else w3=val;

			alf=a,art=b;

			//	cout<<alf<<" "<<art<<" ";

			//	cout<<val<<" "<<w3<<endl;

		}



		if(alf<=l&&art>=r)

		cout<<min(wl+wr,w3)<<endl;

		else cout<<wl+wr<<endl; 

	}

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