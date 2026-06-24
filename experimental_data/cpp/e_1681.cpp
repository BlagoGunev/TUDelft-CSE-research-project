#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N=100013;

int x[2][N],y[2][N],lg[N],f[N][18][2][2];

int len(int x0,int y0,int x1,int y1){return abs(x0-x1)+abs(y0-y1);}

int calc(int x0,int y0,int x1,int y1){

    int s=max(x0,y0),t=max(x1,y1);

    if(s>t)swap(s,t),swap(x0,x1),swap(y0,y1);

    if(s==t)return len(x0,y0,x1,y1);

    int d0=len(x0,y0,x[0][s],y[0][s]),d1=len(x0,y0,x[1][s],y[1][s]);--t;

    while(t^s){

        int D0=min(f[s][lg[t-s]][0][0]+d0,f[s][lg[t-s]][1][0]+d1),D1=min(f[s][lg[t-s]][0][1]+d0,f[s][lg[t-s]][1][1]+d1);

        d0=D0,d1=D1,s+=1<<lg[t-s];

    }

    return min(d0+1+len(x[0][t]+1,y[0][t],x1,y1),d1+1+len(x[1][t],y[1][t]+1,x1,y1));

}

signed main(){

    cin.tie(0);ios::sync_with_stdio(0);

    int n;cin>>n;

    lg[0]=-1;for(int i=1;i<N;i++)lg[i]=lg[i>>1]+1;

    for(int i=1;i<n;i++)cin>>x[0][i]>>y[0][i]>>x[1][i]>>y[1][i];

    for(int i=1;i<n-1;i++)for(auto l:{0,1})for(auto r:{0,1})f[i][0][l][r]=len(x[l][i]+1-l,y[l][i]+l,x[r][i+1],y[r][i+1])+1;

    for(int i=1;i<18;i++)for(int j=1;j+(1<<i)<n;j++)for(int l:{0,1})for(int r:{0,1})

        f[j][i][l][r]=min(f[j][i-1][l][0]+f[j+(1<<(i-1))][i-1][0][r],f[j][i-1][l][1]+f[j+(1<<(i-1))][i-1][1][r]);

    int q;cin>>q;

    while(q--){

        int x0,y0,x1,y1;

        cin>>x0>>y0>>x1>>y1,cout<<calc(x0,y0,x1,y1)<<'\n';

    }

}