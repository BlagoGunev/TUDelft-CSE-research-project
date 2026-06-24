#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<string>
#include<stdio.h>
#include<list>
#include<vector>
#include<set>
using namespace std;
int fd(char z)
{
    if(z>='a'&&z<='z')return z-'a';
    return z-'A'+26;
}
long long n;
int m;
long long b[66][66];
int cs=1000000007 ;
int main()
{
    int k;
    while(cin>>n>>m>>k)
    {
        for(int i=0;i<m;i++)
            for(int q=0;q<m;q++)
                b[i][q]=1;
        while(k--)
        {
            char x,y;
            cin>>x>>y;
            b[fd(x)][fd(y)]=0;
        }
        long long a[66];
        for(int i=0;i<m;i++)
            a[i]=1;
        n--;
        while(n)
        {
            if(n&1)
            {
                long long aa[66]={0};
                for(int i=0;i<m;i++)
                    for(int q=0;q<m;q++)
                        aa[i]+=a[q]*b[q][i]%cs;
                for(int i=0;i<m;i++)
                    a[i]=aa[i]%cs;
            }
            n>>=1;
            long long bb[55][55]={0};
            for(int i=0;i<m;i++)
                for(int q=0;q<m;q++)
                    for(int z=0;z<m;z++)
                        bb[i][q]+=b[i][z]*b[z][q]%cs;
            for(int i=0;i<m;i++)
                for(int q=0;q<m;q++)
                    b[i][q]=bb[i][q]%cs;
        }
        long long da=0;
        for(int i=0;i<m;i++)
            da+=a[i];
        cout<<da%cs<<endl;
    }
}