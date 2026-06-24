#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define put(x) cout<<#x<<" = "<<x<<endl;
#define X first
#define Y second
#define push push_back
#define pop pop_back
#define make make_pair
using namespace std;
typedef long long num;
typedef pair<int,int> point;
const int maxn=1e5+10;

int n,c1,c2;
string s;

int main()
{
    cin>>n;
    cin>>s;
    rep(i,1,n)
	{
	    if(s[i-1]=='S' && s[i]=='F')
		c1++;
	    if(s[i-1]=='F' && s[i]=='S')
		c2++;
	}
    if(c1>c2)
	{
	    cout<<"YES\n";
	}
    else
	{
	    cout<<"NO\n";
	}
}