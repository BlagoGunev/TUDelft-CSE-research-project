#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

#define fi(i,a,b)   for(long long i=a;i<=b;i++)
#define fr(i,a)     for(long long i=0;i<a;i++)
#define fd(i,a,b)   for(long long i=b;i>=a;i--)
#define clr(x)      memset(x,0,sizeof(x))
#define cln(x)      memset(x,-1,sizeof(x))
#define __          printf(" ")
#define _           printf("\n")
#define _o          printf("1\n")
#define stree       long long lft=node<<1,rht=(node<<1)|1,mid=(s+e)>>1
#define mod         1000000007
#define read()      freopen("in.txt","r",stdin)
#define write()     freopen("out.txt","w",stdout)

map<long long,long long>mp;
map<long long,long long>::iterator it;

main(){
    long long n,x;
    scanf("%lld",&n);
    long long sum=0,ans;
    unsigned long long ans1,ans2;
    ans1=0,ans2=0;
    fr(i,n){
        scanf("%lld",&x);
        long long curS=sum;
        long long cnt=i;

        it=mp.find(x-1);
        if(it!=mp.end()){
            cnt-=it->second;
            curS-=(x-1)*(it->second);
        }
        it=mp.find(x+1);
        if(it!=mp.end()){
            cnt-=it->second;
            curS-=(x+1)*(it->second);
        }
        it=mp.find(x);
        if(it!=mp.end()){
            cnt-=it->second;
            curS-=(x)*(it->second);
        }
        ans=(x*cnt)-curS;
        sum+=x;
        mp[x]++;
        if(ans<0){
            ans=-ans;
            ans2+=(unsigned long long)ans;
        }
        else ans1+=(unsigned long long)ans;
    }

    if(ans1>=ans2){
        ans1-=ans2;
        cout<<ans1<<endl;
    }
    else{
        ans2-=ans1;
        cout<<"-"<<ans2<<endl;
    }
    return 0;
}