#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0,t=1;
    cin>>n;
    vector<int>v(n),p;
    for(int i=0;i<n;i++){
              cin>>v[i];
              if(v[i]==1)count++;
    }
    int i;
    cout<<count<<endl;
    for( i=0;i<n-1;i++){
           if(v[i+1]==1)cout<<v[i]<<" ";
    }
    cout<<v[n-1];

    
   
    
    
    
    
    
    return 0;
}