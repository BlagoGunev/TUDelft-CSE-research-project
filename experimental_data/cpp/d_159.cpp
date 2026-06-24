#include <bits/stdc++.h>

#include<string.h>

#define MAX 1000005

#define MOD 1000000007

#define PI 3.14159265358979323846264338327950

//const int  MAXA=1e15+1;

//const int INF=1e18;

using namespace std;

const int maxn=1e5+5;

typedef long long int  ll;

ll st[2005],en[2005];

int main()

{

    //freopen("B-small-practice (1).in","r+",stdin);

    //freopen("out.txt","w+",stdout);

    ios::sync_with_stdio(0);

    cin.tie(0);

    int i;

    string a;

    cin>>a;

    int n=a.length();

    for(i=0;i<n;i++)

    {

        st[i]++;

        en[i]++;

        int l=i-1;

        int r=i+1;

        while(l>=0&&r<n)

        {

            if(a[l]==a[r])

            {

                st[l]++;

                en[r]++;

                l--;

                r++;

            }

            else

                break;

        }

    }

    for(i=1;i<n;i++)

    {

        int l=i-1;

        int r=i;

        while(l>=0&&r<n)

        {

            if(a[l]==a[r])

            {

                st[l]++;

                en[r]++;

                l--;

                r++;

            }

            else

                break;

        }

    }

    ll temp=1,ans=0;

    for(i=1;i<n;i++)

    {

        ans+=temp*st[i];

        temp+=en[i];

    }

    cout<<ans<<endl;

    return 0;

}