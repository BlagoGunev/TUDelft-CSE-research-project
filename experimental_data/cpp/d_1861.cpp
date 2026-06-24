#include <bits/stdc++.h>
#define int long long
#define mkp make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10;
int n;
void solve(){
    cin>>n;
    vector<int> a(n+1),pre1(n+5,0),pre2(n+5,0),suf1(n+5,0),suf2(n+5,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    bool ok=0;
    for(int i=1;i<n;i++){
        if(a[i]>=a[i+1]){
            ok=1;
            break;
        }
    }
    if(!ok){
        cout<<0<<'\n';
        return ;
    }
    ok=0;
    for(int i=1;i<n;i++){
        if(a[i]<=a[i+1]){
            ok=1;
            break;
        }
    }
    if(!ok){
        cout<<1<<'\n';
        return ;
    }
    int mn=1e12;
    int ans=0;
    for(int i=2;i<=n;i++){
        int x=a[i-1],y=a[i];
        if(x>=y){
            ans++;
        }
        pre1[i]=ans;
    }
    mn=min(mn,ans);
    ans=0;
    for(int i=n-1;i>=1;i--){
        int x=a[i],y=a[i+1];
        if(x>=y){
            ans++;
        }
        suf1[i]=ans;
    }
    mn=min(mn,ans);
    for(int i=1;i<=n;i++){
        a[i]=-a[i];
    }
    ans=1;
    pre2[1]=1;
    for(int i=2;i<=n;i++){
        int x=a[i-1],y=a[i];
        if(x>=y){
            ans++;
        }
        pre2[i]=ans;
    }
    mn=min(mn,ans);
    ans=1;
    suf2[n]=1;
    for(int i=n-1;i>=1;i--){
        int x=a[i],y=a[i+1];
        if(x>=y){
            ans++;
        }
        suf2[i]=ans;
    }
    mn=min(mn,ans);
//    cout<<mn<<'\n';
    for(int i=1;i<=n;i++){
//        cout<<pre1[i]<<' '<<suf2[i]<<'\n';
//        cout<<pre2[i]<<' '<<suf1[i]<<'\n';
//        mn=min(mn,1+pre1[i]+suf2[i]);
        mn=min(mn,pre2[i-1]+suf1[i]);
    }
    cout<<mn<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}