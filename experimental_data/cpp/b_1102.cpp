//g++  5.4.0

#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[5005],freq[5005]={0},flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
        if(freq[arr[i]]>k)
        {
            cout<<"NO";
            return 0;
        }
        if(freq[arr[i]]==k)
        {
            flag=1;
        }
    }cout<<"YES\n";
    int cnt=k;
  
      for(int i=1;i<=n;i++)
      {
          if(cnt>freq[arr[i]])cout<<cnt<<" ";
          else
          cout<<freq[arr[i]]<<" ";
          freq[arr[i]]--; 
          cnt--;
      }
}