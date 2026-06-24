#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int N=100005;
int k, kk, t[N], ilo;
long long wyn, n;
vector<int> dz, il, ob;
int main()
{
        scanf("%lld%d", &n, &k);
        kk=k;
        for(int i=2;i*i<=k;i++)
        {
                if(k%i==0)
                {
                        dz.push_back(i);
                        il.push_back(0);
                        while(k%i==0)
                        {
                                il[il.size()-1]++;
                                k/=i;
                        }
                }
        }
        if(k!=1)
        {
                dz.push_back(k);
                il.push_back(1);
        }
        for(int i=1;i<=n;i++) scanf("%d", &t[i]);
        int licz=1;
        for(int i=0;i<dz.size();i++) ob.push_back(0);
        for(int i=1;i<=n;i++)
        {
                while((licz<=n && ilo!=dz.size()) || licz<=i)
                {
                        for(int j=0;j<ob.size();j++)
                        {
                                int ll=0;
                                int hh=t[licz];
                                while(hh%dz[j]==0)
                                {
                                        hh/=dz[j];
                                        ll++;
                                }
                                int tmp=ob[j];
                                ob[j]+=ll;
                                if(ob[j]>=il[j] && tmp<il[j]) ilo++;
                        }
                        licz++;
                }
                if(ilo==dz.size())
                wyn+=n-(long long)(licz)+(long long)(2);
                for(int j=0;j<ob.size();j++)
  {
                        int ll=0;
                        int hh=t[i];
                        while(hh%dz[j]==0)
                        {
                                hh/=dz[j];
                                ll++;
                        }
                        int tmp=ob[j];
                        ob[j]-=ll;
                        if(ob[j]<il[j] && tmp>=il[j]) ilo--;
                }
        }
        if(kk==1) wyn=((n)*(n+1))/2;
        printf("%lld", wyn);
        return 0;
}