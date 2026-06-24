#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int mxn=5e5+5;
char s[mxn],t[mxn];
int n,k;
int main(){
    scanf("%d%d%s%s",&n,&k,s,t);
    ll ans=0,a=0,b=0;
    for(int i=0;i<n;++i){
        a<<=1;b<<=1;
        a+=s[i]-'a';
        b+=t[i]-'a';
        if(b-a<k)ans+=b-a+1;
        else{
            ans+=1LL*(n-i)*k;
            break;
        }
    }
    return printf("%lld\n",ans),0;
}