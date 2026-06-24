#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct In
{
    double x,v,w;
    int i;
}s[20];
bool cmp(In a,In b)
{
    return a.x<b.x;
}
bool cmpi(In a,In b)
{
    return a.i<b.i;
}
void cra(int p)
{
    double v1,v2;
    v1=((s[p-1].w-s[p].w)*s[p-1].v+2.0*s[p].w*s[p].v)/(s[p-1].w+s[p].w);
    v2=((s[p].w-s[p-1].w)*s[p].v+2.0*s[p-1].w*s[p-1].v)/(s[p].w+s[p-1].w);
    s[p-1].v=v1;
    s[p].v=v2;
}
int main()
{
    //freopen("in","r",stdin);
    int n,i,p;
    double t,temp,v,x,tt;
    cin>>n>>t;
    for(i=0;i<n;i++)
    {
        cin>>s[i].x>>s[i].v>>s[i].w;
        s[i].i=i;
    }
    sort(s,s+n,cmp);
    while(1)
    {
        temp=1e20;
        for(i=1;i<n;i++)
        {
            if(s[i].v>=0.0&&s[i-1].v<s[i].v)continue;
            else if(s[i-1].v<=0.0&&s[i-1].v<s[i].v) continue;
            else
            {
                x=s[i].x-s[i-1].x;
                v=s[i-1].v-s[i].v;
                tt=x/v;
            }
            if(tt<temp)
            {
                temp=tt;
                p=i;
            }
        }
        if(t-temp>0.0)
        {
            for(i=0;i<n;i++)
            {
                s[i].x=s[i].x+s[i].v*temp;
            }
            cra(p);
            t-=temp;
        }
        else{
            for(i=0;i<n;i++)
            {
                s[i].x=s[i].x+s[i].v*t;
            }
            break;
        }
    }
    sort(s,s+n,cmpi);
    for(i=0;i<n;i++)
    {
        printf("%.6lf\n",s[i].x);
    }

}