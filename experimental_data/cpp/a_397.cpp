#include <bits/stdc++.h>

#include <limits>

using namespace std;

typedef long long ll;

bool comp(int a,int b)

{

    return a>b;

}

int n,a=0,q=0,c;

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int n;

    cin>>n;int arr[101]={},q,w,t=0;

    for (int i=0;i<n;i++)

    {

        int a,b;

        cin>>a>>b;

        if (i!=0)

        {

            for (int j=a;j<b;j++)

                arr[j]=1;

        }

        else

        {

            q=a,w=b;

        }

    }

    for (int i=q;i<w;i++)

        if (!arr[i])t++;

    cout<<t<<endl;

    return 0;

}