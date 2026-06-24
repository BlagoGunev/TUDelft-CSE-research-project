#include <bits/stdc++.h>
using namespace std;
#define long long long int
int main()
{
    long n,m,k;
    while(cin>> n >> m >> k){
        if(k<n) cout<< k+1 << " " << 1 <<endl;
        else{
            k-=n-1;
            long x=k/(m-1);
            x=n-x+1;
            long y=k%(m-1);
            if(y) x--;
            if(x%2){
                if(y==0) cout<< x << " " << 2 <<endl;
                else cout<< x << " " << m-y+1 <<endl;
            }
            else{
                if(y==0) cout<< x << " " << m <<endl;
                else cout<< x << " " << y+1 <<endl;
            }
        }
    }
    return 0;
}