#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,i,j;
    cin>>n;
    int ar[n+10];
    int l[5011]={1000000},r[5011]={-1};
    
    for(i=0;i<=5000;++i)
    l[i]=1000000,r[i]=-1;
    
    for(i=0;i<n;++i)
    {
    cin>>ar[i];
    if(l[ar[i]]>i)
    l[ar[i]]=i;
    r[ar[i]]=i;
    }
    
    
    int ct=0;
    int ans[5010],answ=0,pos[5010];
    for(i=0;i<5010;++i)
    ans[i]=-1,pos[i]=-1;
    for(i=0;i<n;++i)
    {
        answ=0;
        ct=0;
        for(j=i;j<n;++j)
        {
            if(l[ar[j]]<i)
            {
                break;
            }
            if(l[ar[j]]==j)
            {
            answ=answ^ar[j];
            ++ct;
            }
            if(r[ar[j]]==j)
            --ct;
            
            if(ct==0)
            {
            if(ans[i]<answ)
            {
                ans[i]=answ;
                pos[i]=j;
                break;
            }
            }
        }
    }
    
    int maxtill[5002];
    maxtill[n]=0;
    
    
    for(i=n-1;i>=0;--i)
    {
        if(ans[i]==-1)
        maxtill[i]=maxtill[i+1];
        else
        maxtill[i]=max(maxtill[i+1],ans[i]+maxtill[pos[i]+1]);
    }
    
    
    cout<<maxtill[0]<<endl;
    
	return 0;
}