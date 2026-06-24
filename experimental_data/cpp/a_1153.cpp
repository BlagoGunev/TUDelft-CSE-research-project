#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    pair<int,int> arr[n];
    int a,b;
    for(int x=0;x<n;x++)
    {
        cin>>a>>b;
        if(t>=a)
        arr[x].first=(a)+ceil((double)(t-a)/b)*b;
        else
            arr[x].first=a;
           arr[x].second=x;
    }
    sort(arr,arr+n);
    cout<<arr[0].second+1;
}