#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        int min=INT_MAX;
    for(int i=0;i<n;i++)
     {
         ll count=0;
         for(int j=0;j<n;j++)
         {
             ll diff = abs(arr[i]-arr[j]);
             if(diff&1)
             {
                 count++;
             }

         }
         if(count<min)
            min=count;
     }
     cout<<min<<endl;
}