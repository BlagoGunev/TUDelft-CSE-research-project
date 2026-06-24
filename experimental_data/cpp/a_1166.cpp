#include<bits/stdc++.h>
#define int         long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


void solve(){
    int n,c=0;
    string s;
    int a[26]={};
    cin>>n;
    rep(i,0,n)
    {
      cin>>s;
       a[s[0]-97]++;
    }
rep(i,0,26)
    {
     if(a[i]>2)
     {int x=a[i]/2;
     int y= a[i]-x;
        c=c+ ((x-1)*(x))/2+ ((y-1)*(y))/2;
     }
    }

    cout<<c;

}
//
signed main(){
   ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
   // cin>>t;
    while(t--) solve();
    return 0;
}