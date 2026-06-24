#include<bits/stdc++.h>
using namespace std;
// typedef vector<int>  vi;
// typedef long long int ll;


int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            
            if (i>0 && (a[i] <= a[i-1]))
            {
                int m = ((a[i-1]/a[i])+1);
                a[i] *=  m; 
            }
        }
        cout<<a[n-1]<<endl;
        
    }

    return 0;
}