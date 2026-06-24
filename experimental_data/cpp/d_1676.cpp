#include <bits/stdc++.h>

using namespace std;

//#define int long long int

#define all(a) a.begin(), a.end()

#define endl "\n"

const int MAXN = 1e6 + 10;

int arr[210][210];

#define fastio()  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);

#define pub push_back

#define pob pop_back

#define ft first

#define sd second

// sort(vec.begin(),vec.end());

void solve()

{

     int n,m;   cin>>n>>m;

     for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cin>>arr[i][j];

        }

     }       

     int ans=0;

     for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            int ci = i, cj = j;

            int sum=arr[ci][cj];

            while(ci>0 && cj>0){

                ci--;

                cj--;

                sum+=arr[ci][cj];

            }

            ci = i, cj = j;

            while(ci>0 && cj<m-1){

                ci--;

                cj++;

                sum+=arr[ci][cj];

            }

            ci = i, cj = j;

            while(ci<n-1 && cj>0){

                ci++;

                cj--;

                sum+=arr[ci][cj];

            }

            ci = i, cj = j;

            while(ci<n-1 && cj<m-1){

                ci++;

                cj++;

                sum+=arr[ci][cj];

            }

            ans=max(ans,sum);

        }

     } 

 cout<<ans<<endl;



}





signed main()

{

    fastio();

    int t;   cin >> t;

    while (t--){

        solve(); }

}