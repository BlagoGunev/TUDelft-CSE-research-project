// LUOGU_RID: 100628472
#include <iostream>

int64_t n,x,y,ans;

signed main()

{

    std::cin>>n>>x>>y;

    for(int64_t i(1),k(0);i<=std::min(x,y);ans+=k*i,i<<=1,k=0)

        for(int64_t s=y;i<=s;s=s-1&y)

            if(s&i&&(n*s-i&x-i)==x-i)

                k^=1;

    std::cout<<ans*(n&1);

}