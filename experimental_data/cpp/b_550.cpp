#include <bits/stdc++.h>

using namespace std;

#define lp(i,a,b) for(int i=a;i<b;i++)

#define lpi(i,a,b) for(int i=a;i>=b ;i--)

#define mp make_pair

#define pb push_back

#define ll long long

int n,l,r,x;

int a[16];

int ans ;

int cnt(string s){

	int mn =100000000;

	int mx =0;

	int sum =0;

	int num =0;

	lp(i,0,n){

		if(s[i]=='0')continue;

		sum+=a[i];

		num++;

		mn = min(mn, a[i]);

		mx = max(mx,a[i]);

	}

	int t=mx-mn;

	if( num>=2 && sum<=r && sum>= l &&t>=x)return 1;

	else return 0;

	}

void gen (int i,string s){

	if(i==n){

		ans +=cnt(s);return ;}

	gen(i+1,s+'0');

	gen(i+1,s+'1');

	}

int main() {

    cin>>n>>l>>r>>x;

    lp(i,0,n){

        cin>>a[i];

    }

    gen(0,"");

    cout<<ans;

	return 0;

}