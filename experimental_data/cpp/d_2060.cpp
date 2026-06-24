#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        bool b=1;
        for(int i=1;i<n;i++)
        {
            int k=min(a[i-1],a[i]);
            if(a[i-1]>a[i])
            {
                cout<<"NO"<<endl;
                b=0;
                break;
            }
            else
            {
                a[i-1]=a[i-1]-k;
                a[i]=a[i]-k;
            }
        }
        if(b)cout<<"YES"<<endl;

    }
}