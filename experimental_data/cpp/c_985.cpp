#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read(){
    char c;int rec=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9')rec=rec*10+c-'0',c=getchar();
    return rec;
}
int n,k,l,m;
int a[100005];
int main(){
    n=read();k=read();l=read();
    int m=n*k;
    for(int i=1;i<=m;i++)a[i]=read();
    sort(a+1,a+1+m);
    if(a[n]-a[1]>l){
        cout<<0;return 0;
    }
    long long ans=0;
    int pos=n;
    for(int i=n+1;i<=m;i++){
        if(a[i]-a[1]<=l){
            pos=i;
        }
        else break;
    }
    int w=1;
    while(pos-w+1>=n){
        if(pos-w-k+1>=n){
            ans+=a[w];
            w+=k;
            --n;
        }
        else {
            ans+=a[w];
            --n;
            break;
        }
    }
    while(n){
        ans+=a[pos];
        pos--;n--;
    }
    cout<<ans;
    return 0;
}