#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, vector<vector<int>> &d1, vector<vector<int>> &d2, vector<int> &p, int i, vector<int> &depths, int n){
    stack<vector<int>> s;
    s.push({i, -1, 0});
    vector<int> visited(n, -1);
    while(!s.empty()){
        int top = s.top()[0];
        int par = s.top()[1];
        int dep = s.top()[2];
        if(visited[top] == -1){
            visited[top] = 0;
            p[top] = par;
            for(int j = 0; j<adj[top].size(); j++){
                if(visited[adj[top][j]] == -1){
                    s.push({adj[top][j], top, dep + 1});
                }
            }
        }
        else if(visited[top] == 0){
            int m1 = INT_MIN, m2 = INT_MIN;
            visited[top] = 1;
            s.pop();
            depths[top] = dep;
            for(int j = 0; j<adj[top].size(); j++){
                if(visited[adj[top][j]] == 1){
                    if(d1[adj[top][j]][0] + 1 > d1[top][0]){
                        d2[top] = d1[top];
                        d1[top] = {d1[adj[top][j]][0] + 1, adj[top][j]};
                    }
                    else if(d1[adj[top][j]][0] + 1 >= d2[top][0] ){
                        d2[top] = {d1[adj[top][j]][0] + 1, adj[top][j]};
                    }
                }
            }
            if(adj[top].size() == 1 && top!=0){
                d1[top] = {0, -1};
            }
        }
        else{
            s.pop();
        }
    }
}
void computeUp(vector<vector<int>> &adj, vector<vector<int>> &d1, vector<vector<int>> &d2, int i, int n, vector<vector<int>> &up){
    queue<int> q;
    q.push(i);
    vector<int> visited(n, -1);
    visited[i] = 1;
    while(!q.empty()){
        int ind = q.front();
        q.pop();
        int maxd = d1[ind][0];
        int maxi = d1[ind][1];
        int maxd2 = d2[ind][0];
        int maxi2 = d2[ind][1];
        for(int j = 0; j<adj[ind].size(); j++){
            if(visited[adj[ind][j]] == -1){
                visited[adj[ind][j]] = 1;
                q.push(adj[ind][j]);
                if(maxi == adj[ind][j]){
                    up[adj[ind][j]] = {max(up[ind][0] + 1, maxd2 + 1), ind};
                }
                else{
                    up[adj[ind][j]] = {max(up[ind][0]+1, maxd + 1), ind};
                }
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long c, k;
        cin >> n >> k >> c;
        vector<vector<int>> edg(n-1, vector<int> (2));
        vector<vector<int>> adj(n);
        for(int i = 0; i<n-1; i++){
            cin >> edg[i][0] >> edg[i][1];
            edg[i][0]--;
            edg[i][1]--;
            adj[edg[i][0]].push_back(edg[i][1]);
            adj[edg[i][1]].push_back(edg[i][0]);
        }
        vector<vector<int>> d1(n, {0, -1});
        vector<vector<int>> d2(n, {0, -1});
        vector<vector<int>> up(n, {0, -1});
        vector<int> depths(n);
        vector<int> p(n);
        dfs(adj, d1, d2, p, 0, depths, n); 
        computeUp(adj, d1, d2, 0, n, up);
        long long ans = INT_MIN;
        for(int i = 0; i<n; i++){
            long long cost = depths[i]*c;
            long long rev = max(up[i][0], d1[i][0])*k;
            ans = max(ans, rev - cost);
        }
        cout << ans << endl;
    }
}