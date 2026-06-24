/*input
8 7
4
4 4
2 8
8 1
6 1

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		int n,d,m,x,y;
		cin>>n>>d;
		int a[2],b[2];
		a[0]=d;
		a[1]=n+(n-d);
		b[0]=-1*d;
		b[1]=d;
		cin>>m;
		rep(i,0,m){
			cin>>x>>y;
			int c[2];
			c[0]=x+y;
			c[1]=y-x;
			if(c[0]<=a[1] && c[0]>=a[0] && c[1]>=b[0] && c[1]<=b[1]) cout<<"YES\n";
			else cout<<"NO\n";
		}	
	}
	return 0;
}