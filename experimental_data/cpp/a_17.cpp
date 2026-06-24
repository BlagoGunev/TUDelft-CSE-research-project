#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

#define mn(a,b) ((a<b) ? (a) : (b))             
#define mx(a,b) ((a<b) ? (b) : (a))         
#define ab(a) ((a<0) ? (-(a)) : (a))            
#define fr(a,b) for(int a=0; a<b; ++a)          
#define fe(a,b,c) for(int a=b; a<c; ++a)        
#define fw(a,b,c) for(int a=b; a<=c; ++a)       
#define df(a,b,c) for(int a=b; a>=c; --a)       
#define BIG 1000000000  
#define MAX_STRING 100000
#define PB push_back
#define MP make_pair

using namespace std;

int n,k,len,primes[1000];
bool mas[1001],prime[1001];

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
fw(i,2,1000)
    {
    bool p = true;
    fr(j,len)
        if(i%primes[j]==0)
            {
            p = false;
            break;
            }
    if(p) primes[len++] = i;
    }
fr(i,len-1)
    if(primes[i]+primes[i+1]+1<=1000)
        mas[primes[i]+primes[i+1]+1] = true;
fr(i,len)
    prime[primes[i]] = true;
cin>>n>>k;
len = 0;
fw(i,2,n)
    if(prime[i]&&mas[i])
        len++;
if(len>=k) cout<<"YES";
else cout<<"NO";
return 0;
}