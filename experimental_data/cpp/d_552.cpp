#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n,x[2005],y[2005],cnt[405][405];

ll ans;

int main()

{

    cin>>n;

    for(int i=1; i<=n; i++) cin>>x[i]>>y[i];

    ans=(ll)n*(n-1)*(n-2)/6;

    for(int i=1; i<=n; i++){

        memset(cnt,0,sizeof(cnt));

        for(int j=i+1; j<=n; j++){

            int dx=x[i]-x[j],dy=y[i]-y[j];

            int g=__gcd(dx,dy);

            dx=dx/g+200,dy=dy/g+200;

            ans-=cnt[dx][dy];

            cnt[dx][dy]++;

        }

    }

    cout<<ans<<endl;

}