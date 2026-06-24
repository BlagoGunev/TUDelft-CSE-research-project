#include<bits/stdc++.h>

using namespace std;



int main(){

    int n,m; cin >> n >> m;

    vector<int> arr(n+1);

    for(int i=1;i<=n;i++) cin >> arr[i];

    vector<int> g[n+1];

    vector<int> in(n+1,0);

    for(int i=0;i<m;i++){

        int x,y; cin >> x >> y;

        g[y].push_back(x);

        in[x]++;

    }

    for(int i=1;i<=n;i++){

        priority_queue<pair<int,int>> q;

        vector<int> deg = in;

        for(int j=1;j<=n;j++){

            if(deg[j] == 0 && j != i) {

                q.emplace(arr[j],j);

            }

        }

        for(int j = n; j > 0; j--){

            if(q.empty() || q.top().first < j){

                cout << j << ' ';

                break;

            }

            else{

                auto x = q.top().second; q.pop();

                for(auto it : g[x]){

                    if(--deg[it] == 0 && it != i) q.emplace(arr[it],it);

                }

            }

        }

    }

}