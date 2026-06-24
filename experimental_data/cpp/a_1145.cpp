typedef long long int ll;
#define rep(i,a,b) for(i=a;i<b;i++) 
#define push_back pb
#define sz(a) (int)(a.size())
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
int maxel(vector<int> &v,int a,int b){
    int i,count=1,high=-1;
    rep(i,a,b){
        if(v[i]<=v[i+1]){ count++;}
        else { high=max(high,count);count=1; }
        high=max(high,count);
    }
    return high;
}
int main() {
    //your code goes here...
    int n,temp,i,dis,thigh=-1;
    scanf("%d",&n);
    vector<int> v(n+1,0);v[0]=0;
    rep(i,1,n+1){ scanf("%d",&temp); v[i]=(temp);}
    int a=1,b=n,ret,c=0,add=2;
    for(i=1;c<=n;){
        c=i+add-1;
        ret=maxel(v,i,c);
        if(ret==c-i+1) thigh=ret;
        //cout<<ret<<" "<<i<<" "<<c<<" "<<endl;
        i=i+add;
        if(c==n){ c=0;add=add*2;i=1;}
        if(add>n) break;
        
    }
    if(thigh==-1) thigh=1;
    printf("%d",thigh);
    return 0;
}