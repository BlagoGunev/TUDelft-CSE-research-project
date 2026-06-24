#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int a[N],prv[N],nxt[N],pos[N];
long long tadd[N<<2];
int tmin[N<<2];
int st[25][N];
int lg[N];

void buildadd(int v,int tl,int tr){
    if(tl==tr)tadd[v]=0;
    else{
        int tm=(tl+tr)/2;
        buildadd(v*2,tl,tm);
        buildadd(v*2+1,tm+1,tr);
        tadd[v]=0;
    }
}

void updadd(int v,int tl,int tr,int l,int r,long long add){
    if(l>r)return;
    if(l==tl&&r==tr){
        tadd[v]+=add;
    }else{
        int tm=(tl+tr)/2;
        updadd(v*2,tl,tm,l,min(r,tm),add);
        updadd(v*2+1,tm+1,tr,max(l,tm+1),r,add);
    }
}

long long getadd(int v,int tl,int tr,int pos){
    if(tl==tr)return tadd[v];
    int tm=(tl+tr)/2;
    if(pos<=tm)return tadd[v]+getadd(v*2,tl,tm,pos);
    return tadd[v]+getadd(v*2+1,tm+1,tr,pos);
}

void buildst(int n){
    for(int i=1;i<=n;i++)st[0][i]=a[i];
    for(int i=1;i<=20;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}

int getmin(int l,int r){
    if(l>r)return 1e9;
    int i=lg[r-l+1];
    return min(st[i][l],st[i][r-(1<<i)+1]);
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i,nxt[i]=n+1,prv[i]=0;
    buildadd(1,1,n);
    buildst(n);
    stack<int> st;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.top()]>a[i]){
            nxt[a[st.top()]]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n;i>=1;i--){
        while(!st.empty()&&a[st.top()]>a[i]){
            prv[a[st.top()]]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n;i>=1;i--){
        long long tot=1LL*(pos[i]-prv[i])*(nxt[i]-pos[i]);
        updadd(1,1,n,1,prv[i]-1,tot*i);
        updadd(1,1,n,nxt[i]+1,n,tot*i);
        tot=1LL*(pos[i]-prv[i]-1)*(nxt[i]-pos[i]);
        updadd(1,1,n,prv[i]+1,pos[i]-1,tot*i);
        tot=1LL*(pos[i]-prv[i])*(nxt[i]-pos[i]-1);
        updadd(1,1,n,pos[i]+1,nxt[i]-1,tot*i);
        if(prv[i]!=0){
            int ppos=0,l=1,r=prv[i]-1;
            while(l<=r){
                int m=(l+r)/2;
                if(getmin(m,prv[i]-1)<i){
                    ppos=m;
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            tot=1LL*(pos[i]-ppos-1)*(nxt[i]-pos[i]);
            updadd(1,1,n,prv[i],prv[i],tot*i);
        }
        if(nxt[i]!=n+1){
            int npos=n+1,l=nxt[i]+1,r=n;
            while(l<=r){
                int m=(l+r)/2;
                if(getmin(nxt[i]+1,m)<i){
                    npos=m;
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            tot=1LL*(pos[i]-prv[i])*(npos-pos[i]-1);
            updadd(1,1,n,nxt[i],nxt[i],tot*i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<getadd(1,1,n,i)<<' ';
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    lg[1]=0;
    for(int i=2;i<=(int)5e5;i++){
        lg[i]=lg[i/2]+1;
    }

    int t;cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}