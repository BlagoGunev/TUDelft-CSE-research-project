#include <bits/stdc++.h>
using namespace std;


int main() {
    long long t,x,y,n;

    scanf("%lld",&t);

    while(t--){

       scanf("%lld",&n);

       long long c = 0,c1 = 0;
       while(n != 1){
        if (n%6 == 0 && c < 2){
            n /= 6;
            c = 0;
            c1++;
        }
        else{
            n *= 2;
            c++;
            c1++;
        }
        if (c == 2)  break;
       }

       if (n != 1)  printf("-1\n");
       else  printf("%lld\n",c1);

    }

}