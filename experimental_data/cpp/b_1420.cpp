#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
//const int N=1e5+10;
const int N=100;
const int inf=0x3f3f3f3f3f3f3f;const db eps=1e-7;
//=============================================================
int t,n,ans[N],fin;
//=============================================================不要混用scanf，printf，cout.precision(9);
int div(int aa){
    int re=0;
    while (aa!=0)
    {
        re++;
        aa/=2;
    }
    return re;
    
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--){
        fin=0;
        memset(ans,0,sizeof(ans));
        cin>>n;
        for(int i=1,a;i<=n;i++){
            cin>>a;
            int mm=div(a);
            ans[mm]++;
        }
        for(int i=1;i<=90;i++){
            if(ans[i]>1) fin+=ans[i]*(ans[i]-1)/2;
        }
        cout<<fin<<"\n";
    }
}