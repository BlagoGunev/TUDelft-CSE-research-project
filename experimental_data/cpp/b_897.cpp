//Bismillah hirrahmanir rahim.//
#include<bits/stdc++.h>
using namespace std;
#define check(n,pos) (n& (1<<pos))
#define SET(n,pos) (n(1<<pos))

int main()
{
    long long n,m;
    long long num[] = {902,90002,9000002,900000002,90000000002,9000000000002};
    scanf("%lld%lld",&n,&m);
    long long ans = 0;
    long long st = 0;
    long long ten = 10;
    long long add = 11;
    int k=0;
    for(long long i=1; i<=n+1; i++){
        //cout << st << " "  << i << endl;
        ans = (ans%m + st%m)%m;
        if((i)==ten){
            st += num[k++];
            ten *= 10;
            add *= 10;
        }
        else if(i%100000==0)
            st += (add)/100000;
        else if(i%10000==0)
            st += (add)/10000;
        else if(i%1000 == 0)
            st += (add)/1000;
        else if(i%100 == 0){
            st += (add)/100;
        }
        else if((i)%10==0 && (i)!=ten){
            st += (add)/10;
        }
        else st += add;
    }
    cout << ans << endl;
}