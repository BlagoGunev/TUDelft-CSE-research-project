#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define NMAX 200005
typedef long long ll;
ll n;
ll a[NMAX];
ll lef[NMAX],righ[NMAX];
void enter(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
}
ll rem[NMAX];
void make_left(){
    ll cur=0;
    for(int i=1;i<=n;i++){
        while(cur&&(a[rem[cur]]|a[i])==a[i]&&a[rem[cur]]!=a[i]) cur--;
        if(cur){
            lef[i]=rem[cur];
            lef[i]++;
        }
        else lef[i]=1;
        rem[++cur]=i;
    }
}
void make_right(){
    ll cur=0;
    for(int i=n;i>=1;i--){
        while(cur&&(a[rem[cur]]|a[i])==a[i]) cur--;
        if(cur){
            righ[i]=rem[cur];
            righ[i]--;
        }
        else{
            righ[i]=n;
        }
        rem[++cur]=i;
    }
}
void solve(){
    ll kq=0;
    //for(int i=1;i<=n;i++) cout<<lef[i]<<" ";
    for(int i=1;i<=n;i++){
        ll leftval=(i-lef[i]);
        ll rightval=(righ[i]-i);
        ll chenhlech=righ[i]-lef[i];
        kq+=leftval*rightval+chenhlech;
    }
    kq=n*(n-1)/2-kq;
    writeln(kq);
}
int main(){
   // freopen("D.inp","r",stdin);
    enter();
    make_left();
    make_right();
    solve();
}