#include <bits/stdc++.h>
#include <bits/stdc++.h>

#define PI acos(-1)

#define MX 1000000

#define MOD 1000000007

#define LL long long

using namespace std;

int main()

{



   // freopen("input.txt","r",stdin);

    //  freopen("output.txt","w",stdout);

    long long x,y,n,ans;

    scanf("%lld%lld%lld",&x,&y,&n);

    if(n%6!=0)n%=6;

    else

        n=6;

//cout<<n<<endl;

    if(n==1)

            ans=x%MOD;

     else if(n==2)

                ans=y%MOD;

      else if(n==3)

        ans=(y-x)%MOD;

         else if(n==4)

         ans=(-x)%MOD;

       else if(n==5)

        ans=(-y)%MOD;

       else

        ans=(-y+x)%MOD;

        if(ans<0)

             printf("%lld\n",1000000007+ans);

        else

       printf("%lld\n",ans);







    return 0;



}