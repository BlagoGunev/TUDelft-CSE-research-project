// Aditya Varshney - coderaditya

#include <iostream>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

#define MOD 1000000007
#define pb push_back
#define mp make_pair

typedef long long int ll;


#define getcx getchar//_unlocked

ll scan()
{
    ll n=0;
    char ch = getcx();
    ll sign=1;
    while( ch < '0' || ch > '9' ) {
        if(ch=='-')
            sign = -1;
        ch=getcx();
    }
    while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0',
    ch=getcx();
    return(n * sign);
}

using namespace std;

ll a[111111];
ll b[111111];

int main()
{
    ll m,k,n,ans=0,tmpi,tmpj,i,x;
    n=scan();
    m=scan();
    k=scan();
    for(i=0;i<n;i++) {
        x=scan();
        b[i] = x;
        a[x] = i;
    }
    for(i=0;i<m;i++) {
        x=scan();
        ans+=(a[x]/k)+1;
        if(a[x]!=0) {
            tmpi=a[x];
            tmpj=a[x]-1;
            a[b[a[x]-1]]++;
            a[x]--;
            swap(b[tmpi],b[tmpj]);
        }
    }
    cout<<ans<<endl;
    return 0;
}