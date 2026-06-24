#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,a,b,c,d,i,j;
    cin>>t;
    while(t--){
     cin>>a>>b>>c>>d;
     i=a;
     while(i<=b){
      j=c;
      while(j<=d){
       if(i!=j){
        cout<<i<<" "<<j<<endl;
        j=d;
        i=b;
       }
       j++;
      }
      i++;
     }
    }
    return 0;
}