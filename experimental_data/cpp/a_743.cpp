#include <cstdio>

using namespace std;
char p[100005];

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    a--;b--;
    scanf("%s",p);
    if(p[a]==p[b]) puts("0"); else puts("1");
    return 0;
}