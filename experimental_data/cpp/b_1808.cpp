#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define k_square                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

int main() {
    k_square
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector <vector<long long int>> a(m,vector<long long int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[j][i];
            }
        }
        for(int i=0;i<m;i++){
            sort(a[i].begin(),a[i].end());
        }
        
        long long int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                sum+=(n-(2*j)-1)*(abs(a[i][n-1-j]-a[i][j]));
            }
        }
        cout<<sum<<endl;


       
}
}