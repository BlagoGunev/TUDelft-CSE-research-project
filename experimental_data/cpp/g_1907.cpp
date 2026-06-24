#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define INF (int)1e16
#define endl '\n'
#define veci(arr){for(int ii=0;ii<arr.size();ii++){cin>>arr[ii];}}
#define veco(arr){for(int ii=0;ii<arr.size();ii++){cout<<arr[ii]<<" ";}cout<<"\n";}
vector<int> dfs(int start, vector<vector<int>> &graph, string &s){
    vector<int> f;
    f.push_back(start);
    int cur = graph[start][0];
    int count = 1;
    while(cur != start){
        if(s[cur-1] == '1'){
            if(count%2 == 0) f.push_back(cur);
            count++;
        }
        if(count%2 && s[cur-1] == '0'){
            f.push_back(cur);
        }
        cur = graph[cur][0];
    }
    return f;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> arr(n+1);
    for(int i = 1; i < arr.size(); i++) cin >> arr[i];

    vector<vector<int>> graph(n+1, vector<int> ());
    vector<int> indeg(n+1, 0);
    vector<int> ans;
    for(int i = 1; i < arr.size(); i++){
        graph[i].push_back(arr[i]);
        indeg[arr[i]]++;
    }
    queue<int> q;
    for(int i = 1; i < indeg.size(); i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(q.size()){
        auto it = q.front();
        q.pop();

        if(s[it-1] =='1'){

            s[it-1] = '0';
            s[arr[it]-1] == '0' ? s[arr[it]-1] = '1' : s[arr[it]-1] = '0';
            ans.push_back(it);
        }
        for(auto v: graph[it]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
    vector<int> visited(n+1, false);
    for(int i = 1; i < indeg.size(); i++){
        if(indeg[i] && !visited[i]){
            int count = 0;
            int cur = i;
            int first = -1 , second = -1;
            while(!visited[cur]){
                visited[cur] = true;
                cur = graph[cur][0];
                if(s[cur-1] == '1'){
                    count++;
                    if(first == -1) first = cur;
                    else if(second == -1) second = cur;
                }
            }
            if(count%2){
                cout<<-1<<endl;
                return;
            }
            if(!count) continue;
            vector<int> f = dfs(first, graph, s);
            vector<int> sc = dfs(second, graph, s);
            if(f.size() < sc.size()){
                for(auto x : f) ans.push_back(x);
            }
            else for(auto x : sc) ans.push_back(x);
        }
    }
    cout<<ans.size()<<endl;
    veco(ans);
}

signed main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    int tt = t;
    while(t--){
        // cout<<"Case #"<<tt-t<<": ";
        solve();
        // cout<<endl;
    }
    return 0;
}