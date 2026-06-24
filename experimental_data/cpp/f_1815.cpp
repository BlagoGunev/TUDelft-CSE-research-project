#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int o = 0;
int K = 1LL<<23;
int hashxy(int a, int b) {
    return (K-a)*K-b;
}

pair<int,int> unhash(int x) {
    return {(K*K-x)/K, ((-x)%K+K)%K};
}

void solve() {

    //for each edge, decide which vertex to add 1 to
    //then for each triangle, can either get 111 or 012 in any order
    //so make a mapping from edges to the deltas
    //and then when assigning if the req deltas all same just use 111 if not -2 from max -1 from middle -0 from min
    //the first process is done by taking min weight and choosing to keep this min weight
    //the same (so add 1 for every neighbour)
    int n,m;
    cin >> n >> m;
    vector<int> delta(n,0);
    vector<int> weights(n,0);
    vector<vector<int>> triangles;
    vector<vector<pair<int,int>>> adjlist(n);
    //vector<vector<int>> del(m,vector<int>(3,0));
    int del[m][3];
    for (int i=0; i<m; i++) {
        for (int j=0; j<3; j++) {
            del[i][j]=o=0;
        }
    }
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        weights[i] = x;
    }
    for (int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        triangles.push_back({a,b,c});
        adjlist[a].push_back({b,i});
        adjlist[b].push_back({a,i});
        adjlist[a].push_back({c,i});
        adjlist[c].push_back({a,i});
        adjlist[b].push_back({c,i});
        adjlist[c].push_back({b,i});
        weights[a]+=3;
        weights[b]+=3;
        weights[c]+=3;
        del[i][0]++;del[i][1]++;del[i][2]++;
    }
    vector<int> visited(n,0);
    set<pair<int,int>> unvisited;
    for (int i=0; i<n; i++) {
        unvisited.insert({weights[i],i});
    }
    vector<int> processed(n,0);
    while (unvisited.size()) {
        pair<int,int> n1 = *unvisited.begin();
        int index = n1.second;
        int wei = n1.first;
        processed[index] = 1;
        for (auto tau:adjlist[index]) {
            int j = tau.first;
            pair<int,int> H = {weights[j]+delta[j],j};
            int r = hashxy(H.first,H.second);
            pair<int,int> r2 = unhash(r);
            if (!processed[H.second]) {
                //if (unvisited.count(H)) {
                    unvisited.erase(unvisited.find(H));
                //}
                delta[j]++;
                unvisited.insert({weights[j]+delta[j],j});
                int ind = find(triangles[tau.second].begin(), triangles[tau.second].end(), j)-triangles[tau.second].begin();
                del[tau.second][ind]++;
            }
        }
        unvisited.erase(unvisited.begin());

    }
    for (int i=0; i<n; i++) {
        //cout << i+1 <<" " << delta[i] <<" " << weights[i]+delta[i] << endl;
    }
    //cout << endl;
    int ct=0;
    for (auto i:triangles) {
        int a,b,c;
        a=i[0];
        b=i[1];
        c=i[2];
        int u,v,w;
        u=del[ct][0];
        v=del[ct][1];
        w=del[ct][2];
        //cout << "abcuvw" << " " << a <<" " << b <<" "<< c <<" " << u <<" " << v <<" " << w << endl;
        int x,y,z; //x=ab,y=bc,z=ac 
        x = (u+v-w)/2;
        y = (v+w-u)/2;
        z = (u+w-v)/2;
        //cout << "ABC1 " << delta[a] <<" " << delta[b] <<" " << delta[c] << endl;
        //cout << "ABC2 " << delta[a] <<" " << delta[b] <<" " << delta[c] << endl;
        //cout << "DOING " << a <<" " << b <<" " << c <<" " << u <<" " << v <<" " << w << endl;
        cout << x+1 <<" " << y+1 <<" " << z+1 << endl;
        ct++;
    }
    for (auto i:delta) {
        //cout << i <<" ";
        //assert(i==0);
    }
    //cout <<endl;
    for (int i=0; i<n; i++) {
        //cout << i+1 <<" " << delta[i] <<" " << weights[i] << endl;
    }
    //cout << endl;
 
}

signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    #ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif //fast IO
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}