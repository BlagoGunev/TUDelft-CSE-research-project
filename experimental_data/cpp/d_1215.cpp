#include<cstdio>
using namespace std;
int n,lsum,rsum,lunk,runk;
int main()
{
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n>>1;++i)
    {
        char c=getchar();
        c=='?'?++lunk:lsum+=c-'0';
    }
    for(int i=1;i<=n>>1;++i)
    {
        char c=getchar();
        c=='?'?++runk:rsum+=c-'0';
    }
    puts(((lunk-runk)>>1)*9==rsum-lsum?"Bicarp":"Monocarp");
    return 0;
}