#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,dot=0,c=0;
    cin>>n;
    char a[n+10][n+10];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
                dot++;
        }
    }
    //cout<<"dot:"<<dot<<endl;
    if(dot%5!=0)
    {
        cout<<"NO";
        return 0;
    }
    if(a[1][1]=='.'||a[n][n]=='.'||a[1][n]=='.'||a[n][1]=='.')
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        for(i=2; i<n; i++)
        {
            for(j=2; j<n; j++)
            {
                if(a[i][j]=='.'&&a[i-1][j]=='.'&&a[i+1][j]=='.'&&a[i][j-1]=='.'&&a[i][j+1]=='.')
                {
                    c++;
                    a[i][j]='#';
                    a[i][j-1]='#';
                    a[i][j+1]='#';
                    a[i+1][j]='#';
                    a[i-1][j]='#';

                }
            }
        }
//        for(i=1; i<=n; i++)
//        {
//            for(j=1; j<=n; j++)
//            {
//                cout<<a[i][j];
//
//            }
//            cout<<endl;
//        }
        //cout<<"c:"<<c<<endl;
        if(c==0)
        {
            cout<<"NO";
            return 0;
        }
        if(dot/c==5 && dot%c==0)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }
}