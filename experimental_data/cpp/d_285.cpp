#include <iostream>
#include <cstdio>
using namespace std;
long long sq[8]={1LL,3LL,15LL,133LL,
                 2025LL,37851LL,1030367LL,36362925LL};

int main()
{
    long long n,ans,i;
    scanf("%I64d",&n);
    if(n%2==0)
      printf("0\n");
    else
    {
        ans=1;
        for(i=n;i>0;i--)
          ans=(ans%1000000007*i)%1000000007;
        ans=ans*sq[n/2]%1000000007;
        printf("%I64d\n",ans);
    }
    return 0;
}