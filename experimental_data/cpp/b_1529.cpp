#include <bits/stdc++.h>

using namespace std;

#define fasterio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

#define endl "\n"

#define ll long long

int switcih(int n){

  if(n%2==0)

    return 0;

  else return 1;

}

int main() {

  #define int long long

  fasterio

    

      #ifndef ONLINE_JUDGE

    freopen("error.txt", "w", stderr);

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    int t;

    cin>>t;

    for(int i=0;i<t;i++)

    {

      int n;

      cin>>n;

      int max=0,flag=0;

      int arr[n];

      int diff[n-1];

      for(int i=0;i<n;i++)

        cin>>arr[i];

      sort(arr,arr+n);



      for(int i=0;i<n-1;i++)

        diff[i]=arr[i+1]-arr[i];



      for(int j=0;j<n;j++)

      {

        if(arr[j]>0)

        {

          for(int k=0;k<j;k++)

            if(abs(diff[k])<arr[j])

              {flag=1;break;}

            if(flag==0) max=j+1;

            else max=j;

            break;

        }}

        if(max>0) cout<<max<<endl; else cout<<n<<endl;}}