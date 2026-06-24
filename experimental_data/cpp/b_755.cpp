#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct str
{
    char ch[523];
}v[1023];
char ch2[523];
int ct1=0,ct2=0,as=0;
int comp(str a,str b)
{
    return strcmp(a.ch,b.ch)<0;
}
int main()
{
   // freopen ("in.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",v[i].ch);
    sort(v+1,v+n+1,comp);
    ct1=n,ct2=m;
    for(int i=1;i<=m;i++)
    {
        scanf("%s",ch2);
        int st=1,dr=n;
        while(st<=dr)
        {
            int mij=(st+dr)/2;
            int vr=strcmp(v[mij].ch,ch2);
            if(vr==0)
            {
                --ct1;
                --ct2;
                as=1-as;
                break;
            }
            else if(vr<0) st=mij+1;
            else dr=mij-1;
        }
    }
    if(as==1) --ct2;
    if(ct1<=ct2) printf("NO\n");
    else printf("YES\n");
}