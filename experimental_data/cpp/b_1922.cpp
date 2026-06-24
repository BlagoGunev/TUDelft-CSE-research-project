#include<bits/stdc++.h>
using namespace std;

long long nCr(long long n,long long r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
 
    return p;
}
int main(){
 int t;
 cin>>t;
 while(t--){
       int n; 
       cin>>n;
       vector<int>a(n);
       map<int,int>mp;
       for(int i=0;i<n;i++){
          cin>>a[i];
          mp[a[i]]++;
       }
       sort(a.begin(),a.end());
       long long cnt=0;
       long long temp=0;
       bool fl=0;
       int re=3;
       for(int i=2;i<n;i++){
           if(a[i]==a[i-1] && a[i-2]<a[i-1]) {
              cnt+=(i-1);
              temp=i-1;
              fl=0;
            }
           else if((a[i]==a[i-1]) && (a[i-1]==a[i-2]) && (fl==0)){
             fl=1;
             cnt-=temp;
             cnt+=(temp)*nCr(mp[a[i]],2);
             
           }
           
       }
       for(auto x : mp){
          if(x.second>=3) cnt+=nCr(x.second,3);
       }

       cout<<cnt<<endl;

  }
}