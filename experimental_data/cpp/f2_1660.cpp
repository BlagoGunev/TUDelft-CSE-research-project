#include <bits/stdc++.h>

#define int long long

#define lowerbit(x) (x)&(-x)

using namespace std;

const int N=2e5+10;

const int M=2e5+10;

struct node{

    int c[N];

    int n;

    void init(int n){

         this->n=n;

         for(int i=0;i<=n;i++)c[i]=0;

    }

    void update(int x,int k){

       while(x<=n){

            c[x]+=k;

           x+=lowerbit(x);

       }

    }

    int query(int x){

        int cnt=0;

        while(x){

            cnt+=c[x];

            x-=lowerbit(x);

        }

        return cnt;

    }

}tr[3];

void solve()

{

    int n;

    cin>>n;

    string s;

    cin>>s;

    s=" "+s;

    vector<int>sum(n+1);

    int mmin=0;

    for(int i=1;i<=n;i++){

            sum[i]=sum[i-1]+(s[i]=='-'?1:-1);

            mmin=min(mmin,sum[i]);

    }

    for(int i=0;i<3;i++)tr[i].init(n+1);

    for(int i=0;i<=n;i++)sum[i]+=(-mmin+1);

    int ans=0;

    for(int i=0;i<=n;i++){

        int m=sum[i]%3;

        ans+=tr[m].query(sum[i]);

        tr[m].update(sum[i],1);

    }

    cout<<ans<<'\n';

}

signed main()

{

    ios::sync_with_stdio(false),cin.tie(0);

    int t=1;

	cin>>t;

    while(t--)

    {

        solve();

    }

    return 0;

}

/*

3

7 3

1 1 2 2 3 3

2 1 1

1 2

4

1

4 4 3

4 5 6 7

4 5 6 7

2 4 6

2 1 1

4 5

6

1

7 3

1 1 2 2 3 3

2 1 1

1 2

4

1

4 4 3

4 5 6 7

4 5 6 7

2 4 6

2 1 1

4 5

6

1

7 3

1 1 2 2 3 3

2 1 1

1 2

4

1

4 4 3

4 5 6 7

4 5 6 7

2 4 6

2 1 1

4 5

6

1

*/