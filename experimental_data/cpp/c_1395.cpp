#include<bits/stdc++.h>

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
long long arr[100005];
using namespace std;
ll arr2[10000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    bool done=0;
    for(int x=0;x<=(1<<9);x++){
        int ans=0;
        for(int i=0;i<n;i++){
            bool ok=false;
            for(int j=0;j<m;j++){
                if(((arr[i]&arr2[j])|x)==x)
                    ok=true;

            }
            ans+=ok;

        }
        if(ans==n){
            cout<<x<<endl;
            done=1;
            break;
        }
    }


    return 0;
}