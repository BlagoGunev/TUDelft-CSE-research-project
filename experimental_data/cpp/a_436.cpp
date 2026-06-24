#include <cstdio>
#include<vector>
#include<algorithm>
#define INF (1<<29)
using namespace std;
int n,H,t,hh,m,nowh;
struct node
{
    int h,m;
    bool operator<(const node& x) const
    {
        return m>x.m;
    }
};
vector<node> T[2];
vector<node> temp[2];
bool get0()
{
    int M=-1,pos;
    for(int i=0;i<temp[0].size();i++)
        if(nowh>=temp[0][i].h)
    {
        if(temp[0][i].m>M)
        {
            M=temp[0][i].m;
            pos=i;
        }
    }
    if(M==-1) return false;
    else{
        nowh+=M;
        temp[0][pos].h=INF;
        return true;
    }
}
bool get1()
{
    int M=-1,pos;
    for(int i=0;i<temp[1].size();i++)
        if(nowh>=temp[1][i].h)
    {
        if(temp[1][i].m>M)
        {
            M=temp[1][i].m;
            pos=i;
        }
    }
    if(M==-1) return false;
    else{
        nowh+=M;
        temp[1][pos].h=INF;
        return true;
    }
}
int main()
{

    scanf("%d%d",&n,&H);
    for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&t,&hh,&m);
            T[t].push_back((node){hh,m});
        }
    sort(T[0].begin(),T[0].end());
    sort(T[1].begin(),T[1].end());
    temp[0]=T[0];
    temp[1]=T[1];
    nowh=H;
    int tot1=0;
    while(1)
    {
        if(get0()) tot1++;
        else break;
        if(get1()) tot1++;
        else break;
    }
    temp[0]=T[0];
    temp[1]=T[1];
    nowh=H;
    int tot2=0;
    while(1)
    {
        if(get1()) tot2++;
        else break;
        if(get0()) tot2++;
        else break;
    }

    printf("%d",max(tot1,tot2));
    return 0;
}