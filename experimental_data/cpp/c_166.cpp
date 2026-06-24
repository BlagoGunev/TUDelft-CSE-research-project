#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define sc(x)  scanf("%d",&x)

#define scl(x) scanf("%lld",&x)

#define pi 3.1415926535897932384

//ios::sync_with_stdio(0);

//  cin.tie(0);

//freopen("input.txt", "r", stdin);

//freopen("output.txt", "w", stdout);

int main()

{



    multiset<int>s;

    int n,x,ans=0;

    cin>>n>>x;

    while (n--)

    {

        int z;

        cin>>z;

        s.insert(z);

    }

    while (1)

    {

        int c=(s.size()+1)/2-1;

        multiset<int>:: iterator it=s.begin();

        while(c--)it++;

        if (*it==x)

            break;

        s.insert(x);

        ans++;

    }

    cout<<ans<<endl;

    return 0;

}