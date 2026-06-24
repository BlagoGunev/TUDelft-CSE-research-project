#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,x=0;

    cin>>n;

    char a[n][n];

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<n;j++)

        cin>>a[i][j];

    }

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<n;j++)

        {

            int c=0;

            if(j-1>=0&&a[i][j-1]=='o')

            c++;

            if(j+1<n&&a[i][j+1]=='o')

            c++;

            if(i-1>=0&&a[i-1][j]=='o')

            c++;

            if(i+1<n&&a[i+1][j]=='o')

            c++;

            if(c%2==0)

         x++;

        }

    }

    if(x!=n*n)

    cout<<"NO";

    else

    cout<<"YES";

}