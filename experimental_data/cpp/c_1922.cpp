#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n; 
        cin>>n;
        vector<int>arr(n);
        vector<int>left(n);
        vector<int>right(n);
        for(int i = 0; i<n;  i++)
        {
            cin>>arr[i];
        }
        right[0] = 1;
        for(int i = 1; i<n-1; i++)
        {
            if(arr[i]-arr[i-1]>arr[i+1]-arr[i])
            {
                right[i] = 1;
            }
            else
            {
                right[i]=arr[i+1]-arr[i];
            }
        }
        for(int i= n-1; i>0; i--)right[i] = right[i-1];
        right[0] = 0;
        left[n-1]=1;
        for(int i= n-2; i>0; i--)
        {
            if(arr[i]-arr[i-1]>arr[i+1]-arr[i])left[i] = arr[i]-arr[i-1];
            else left[i]=1;
        }
        for(int i = 0; i<n-1; i++)left[i] = left[i+1];
        left[n-1] = 0;
        // for(int i =0; i<n; i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 1; i< n; i++)
        {
            right[i] = right[i]+right[i-1];
        }
        // for(int i =0; i<n; i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        // for(int i =0; i<n; i++)
        // {
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        for(int i = n-2; i>=0; i--)
        {
            left[i] = left[i]+left[i+1];
        }
        // cout<<endl;
        // // for(int i =0; i<n; i++)
        // // {
        // //     cout<<left[i]<<" ";
        // // }
        // cout<<endl;
        int m;
        cin>>m;
        vector<int>result(m);
        for(int i = 0; i<m; i++)
        {
            int x; int y; 
            cin>>x>>y;
            int coins = 0;
            if(x<y)
            {
                coins = right[y-1]-right[x-1];
            }
            else
            {
                
                coins = left[y-1]-left[x-1];
            }
            result[i] = coins;
        }
        for(int i = 0; i<m; i++)
        {
            cout<<result[i]<<endl;
        }
    }
    return 0;
}