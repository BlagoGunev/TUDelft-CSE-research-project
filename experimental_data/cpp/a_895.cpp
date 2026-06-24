#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,A[1000]={},m=1000;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>A[i];
    if(n==1)
        cout<<"360";
    else
    {
    for(int i=0;i<n;i++)
    {
        int s=0,c=0,j=i;
        while(c==0)
        {
            s+=A[j];
            if(s<180)
            m=min(m,(360-s-s));
            else
                m=min(m,s-360+s);
            if(j==n-1)
                j=0;
            else
                j++;
            if(j==i)
                c++;
        }
    }
    cout<<m;
    }
    return 0;
}