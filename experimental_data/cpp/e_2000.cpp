#include <bits/stdc++.h>  
#define int long long
using namespace std;

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("newoutput.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        int k;
        cin >> k;
        int w;
        cin >> w;
        int arr[n+2][m+2];
        int a[w+1];
        for(int i=1;i<=w;i++){
            cin >> a[i];
        }
        for(int i=0;i<n+2;i++){
            for(int j=0;j<m+2;j++){
                arr[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+k-1)<=n && (j+k-1)<=m){
                    arr[i][j]++;
                    arr[i+k][j]--;
                    arr[i][j+k]--;
                    arr[i+k][j+k]++;
                }
            }
        }
        vector<int> ok;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j];
                ok.push_back(arr[i][j]);
            }
        }
        sort(a+1,a+w+1);
        sort(ok.begin(),ok.end());
        int ind = (n*m)-1;
        int ans=0;
        for(int i=w;i>0;i--){
            ans+=(a[i]*ok[ind]);
            ind--;
        }
        cout << ans << '\n';
        
    }
}