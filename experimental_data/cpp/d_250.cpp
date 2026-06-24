#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define fi first
#define se second
#define N 100005
#define For(i,a,b) for(int i=int(a);i<=int(b);i++)
using namespace std;
pair<int, int> y[N],y_1[N];
long double res;
int n,m,l[N],r1,r2,a,b;
long double sqr(long double a){return a*a;
}
long double dis(long double x0, long double y0, long double x1, long double y1){
    return sqrt(sqr(x1-x0)+sqr(y1-y0));
}
void Update(int i,int j){
    long double d=dis(0,0,a,y[i].fi)+dis(a,y[i].fi,b,y_1[j].fi)+1.0*l[y_1[j].se];
    if(d<res){
        res=d;
        r1=y[i].se;
        r2=y_1[j].se;
    }
}
void Solve(){
    int j=1;
    For(i,1,m){
        while(j<n&&1.0*b*y[j+1].fi<=1.0*a*y_1[i].fi)j++;
        Update(j,i);
        if(j<n)Update(j+1,i);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&a,&b);
    For(i,1,n){
        scanf("%d",&y[i].fi);
        y[i].se=i;
    }
    For(i,1,m){
        scanf("%d",&y_1[i].fi);
        y_1[i].se=i;
    }
    sort(y+1,y+n+1);
    sort(y_1+1,y_1+m+1);
    For(i,1,m)scanf("%d",&l[i]);
    res=1e9;
    Solve();
    cout<<r1<<" "<<r2<<endl;
    return 0;
}