#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define int long long 
#define re register int
#define pb emplace_back
#define lowbit(x) (x&-x)
#define fer(i,a,b) for(re i = a ; i <= b ; i ++)
#define der(i,a,b) for(re i = a ; i >= b ; i --)
#define snow ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}
typedef pair<int,int>PII;
typedef pair<int,string>PIS;
const int N=2e5+10;
int b[N];
int a[N];
int n;
bool check(int x){
    for(int i=1;i<=n;i++){
        b[i]=0;
    }
    for(int i=n;i>=1;i--){
        if(b[i]+a[i]<x)return false;
        if(i>=3){
            int y;
            if(b[i]>=x){
                y=a[i]/3;
                b[i-1]+=y;
                b[i-2]+=y*2;
            }
            else{
                int y=abs(b[i]-x);
                y=a[i]-y;
                y/=3;
                b[i-1]+=y;
                b[i-2]+=y*2;
            }
        }
    }
    return true;
}
signed main(){
    snow;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int MA=INT_MIN;
        for(int i=1;i<=n;i++){cin>>a[i];MA=max(MA,a[i]);}
        int l=1,r=MA;
        while(l<r){
            int mid=l+r+1>>1;
            if(check(mid))l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
    }
    return 0;
}