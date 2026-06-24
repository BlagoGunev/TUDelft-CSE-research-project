#include <bits/stdc++.h>
using namespace std;


string st;
int main(){
   long long x,w=0,e=0,n=0,s=0,nn,a=0;
   cin>>nn;
   for(int i=0 ; i<nn ; i++){
        cin>>x>>st;
        if(st[0]=='W'||st[0]=='E')
        {
            if(w==0||w==20000) a=1;
            continue;
        }
        if(st[0]=='S')
            w+=x;
        else
            w-=x;
        if(w>20000||w<0) a=1;
   }
   if(a||w) cout<<"NO";
   else cout<<"YES";
    return 0 ;
}