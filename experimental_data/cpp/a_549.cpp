#include<bits/stdc++.h>

using namespace std;

int main()

{

    char a[51][51];

    int i,j,n,m,f,a1,c,e,man=0;

    cin>>n>>m;

    for(i=0;i<n;i++)

    {

        for(j=0;j<m;j++)

        {

            cin>>a[i][j];

        }

    }

    for(i=0;i<n-1;i++)

    {

       // f=0,a1=0,c=0,e=0;

        for(j=0;j<m-1;j++)

        {

            f=0,a1=0,c=0,e=0;

         if(a[i][j]=='f'||a[i+1][j]=='f'||a[i][j+1]=='f'||a[i+1][j+1]=='f')

            f++;

         if(a[i][j]=='a'||a[i+1][j]=='a'||a[i][j+1]=='a'||a[i+1][j+1]=='a')

            a1++;

        if(a[i][j]=='c'||a[i+1][j]=='c'||a[i][j+1]=='c'||a[i+1][j+1]=='c')

            c++;

        if(a[i][j]=='e'||a[i+1][j]=='e'||a[i][j+1]=='e'||a[i+1][j+1]=='e')

            e++;

        if(a1==1&&f==1&&c==1&&e==1)

        //if (c+a1+f+e==4)

            man++;

        }

    }

    cout<<man<<endl;

    return 0;

}