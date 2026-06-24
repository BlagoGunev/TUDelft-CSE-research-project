#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n=n-1;
        int t=n;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                t=t/i*(i-1);
                n=n/i;
            }
            while(n%i==0)
                n/=i;
        }
        cout<<t<<endl;
    }
}