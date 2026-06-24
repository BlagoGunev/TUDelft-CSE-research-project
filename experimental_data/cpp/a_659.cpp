#include <bits/stdc++.h>



using namespace std;



typedef long long ll;



#define MAXN 100004

#define MAXM 32

ll n,m,r;



int main()

{cin>>n>>m>>r;

if((m+r)%n==0)

    cout<<n;

else if((m+r)%n>0)

    cout<<(m+r)%n;

else if((m+r)%n<0)

    cout<<(m+r+100*n)%n;

return 0;

}







//'\n'

// ||