#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);		cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        
        vector <string> grid(n);
        for(auto &s : grid) 
        	cin >> s;

        auto gd = [&](int i, int j) -> int {
            return i * m + j;
        };
        
        int ts = n * m;
        vector<bool> mt(ts, false);
        vector<vector<int>> fv(ts, vector<int>());
        vector<vector<int>> q_rev(ts, vector<int>());
        vector<int> as(ts, 0);
        vector<pair<int, int>> ds = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        queue<int> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int id = gd(i,j);
                char c = grid[i][j];
                if(c == 'U' || c == 'D' || c == 'L' || c == 'R'){
                    int ni = i, nj = j;
                    switch(c){
                        case 'U': ni = i - 1; break;
                        case 'D': ni = i + 1; break;
                        case 'L': nj = j - 1; break;
                        case 'R': nj = j + 1; break;
                    }
                    
                    if(ni < 0 || ni >= n || nj < 0 || nj >= m){
                        if(!mt[id]){
                            mt[id] = true;
                            q.push(id);
                        }
                    }
                    else{
                        int tt = gd(ni, nj);
                        fv[tt].push_back(id);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int id = gd(i,j);
                char c = grid[i][j];
                if(c == '?'){
                    int cnt = 0;
                    for(auto &[di, dj] : ds){
                        int ni = i + di;
                        int nj = j + dj;
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                            cnt++;
                            int tt = gd(ni, nj);
                            q_rev[tt].push_back(id);
                        }
                    }
                    
                    as[id] = cnt;

                    if(cnt == 0){
                        if(!mt[id]){
                            mt[id] = true;
                            q.push(id);
                        }
                    }
                }
            }
        }

        while(!q.empty()){
            int cell = q.front(); 
            q.pop();

            for(auto &fixed_cell : fv[cell]){
                if(!mt[fixed_cell]){
                    mt[fixed_cell] = true;
                    q.push(fixed_cell);
                }
            }

            for(auto &q_cell : q_rev[cell]){
                if(!mt[q_cell]){
                    as[q_cell]--;
                    if(as[q_cell] == 0){
                    	mt[q_cell] = true;
                        q.push(q_cell);
                    }
                }
            }
        }

        int ct = 0;
        for(int i = 0; i < ts; i++) 
        	if(mt[i]) 
        		ct++;

        cout << (ts - ct) << endl;
    }
}