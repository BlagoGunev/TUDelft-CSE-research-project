#include <bits/stdc++.h>

using namespace std;

int n, fr1[6], fr2[6];

/*
#include <bits/stdc++.h>

using namespace std;

int L,L2;
int t[200003];
char S[200003],cuv[200003],aux[200003];

bool Check(int k)
{
    int i,poz;
    for(i=1;i<=L;++i)
        aux[i]=S[i];
    aux[L+1]=0;
    for(i=1;i<=k;++i)
        aux[t[i]]='*';
    //cout<<aux+1<<"    "<<k<<"\n";
    //cout<<cuv+1<<"\n";
    poz=1;
    for(i=1;i<=L;++i)
    {
        if(aux[i]==cuv[poz])
            poz++;
        if(poz==L2+1)
            return true;
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    int i;
    cin>>(S+1);
    L=strlen(S+1);
    cin>>(cuv+1);
    L2=strlen(cuv+1);
    for(i=1;i<=L;++i)
        cin>>t[i];
    ///CautBin
    int st,dr,mijl,sol;
    st=0; dr=L;
    while(st<=dr)
    {
        mijl=(st+dr)/2;
        if(Check(mijl))
        {
            sol=mijl;
            st=mijl+1;
        }
        else
            dr=mijl-1;
    }
    //cout<<Check(4)<<"\n\n";
    cout<<sol<<"\n";
    return 0;
}
*/

int main()
{
    int i,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        fr1[x]++;
    }
    for(i=1;i<=n;i++)
    {
        cin>>x;
        fr2[x]++;
    }
    for(i=1;i<=5;i++)
        if((fr1[i]+fr2[i])%2==1)
        {
            cout<<"-1\n";
            exit(0);
        }
    int ans=0,rez;
    for(i=1;i<=5;++i)
    {
        rez=fr1[i]+fr2[i];
        //rez/=2;
        rez/=2;
        ans+=(max(fr1[i]-rez,rez-fr1[i]));
    }
    cout<<ans/2<<"\n";
    return 0;
}