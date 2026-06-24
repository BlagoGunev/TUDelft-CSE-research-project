// Problem: E. Turtle vs. Rabbit Race: Optimal Trainings
// Contest: Codeforces - Codeforces Round 929 (Div. 3)
// URL: https://codeforces.com/contest/1933/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
#define LF(x)   fixed<<setprecision(x)// c++ 保留小数
typedef long long LL;
typedef unsigned long long ULL;
typedef tuple<int,int,int> TUP;
typedef pair<int, int> PII;
const int N=1000010,M=1010,INF=0x3f3f3f3f,pp=13331,mod=1e9+7;
const double pai=acos(-1.0);// pai
int t,n,m;

void solve(){
   
    cin>>n;
    vector<LL> a(n+5);
    for(int i=1;i<=n;i++){
    	 cin>>a[i];
    	 a[i]+=a[i-1];
    }
    cin>>m;
    while(m--){
    	LL L,u; cin>>L>>u;
    	int l=L,r=n;
    	while(l<r){
    		int mid=l+r>>1;
    		if(a[mid]-a[L-1]>=u) r=mid;
    		else l=mid+1;
    	}
    	if(a[l]-a[L-1]<=u){
    		cout<<l<<' ';
    	}
    	else{
    		LL num1=a[l]-a[L-1];
    		LL res1=(LL)(2*u+1-num1)*num1/2;
    		LL num2=a[l-1]-a[L-1];
    		LL res2=(LL)(2*u+1-num2)*num2/2;
    		if(res2>=res1){
    			cout<<max(l-1,(int)L)<<' ';
    		}
    		else cout<<l<<' ';
    	}
    }
    cout<<endl;
    return ;
}

signed main (){
	
    ios::sync_with_stdio(0); 
    cin.tie(0),cout.tie(0);
    
    int _;
    _=1;
    cin>>_;
    while(_--){
    	solve();
    }
    
}