//Allah vorosha
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007
char a[101];
int main()
{
    //std::ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll t,n,i,flag;
    scanf("%lld",&t);
    while(t--)
    {
        flag=0;
        scanf("%lld%s",&n,a);
        for(i=0;i<=n-11;i++)
        if(a[i]=='8')
        {
            flag=1;
            break;
        }
        if(flag==0)
            printf("NO\n");
        else
            printf("YES\n");

    }
    return 0;
}