#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> steps(n);
        for(auto &p: steps){
            cin >> p.first >> p.second;
        }
        // Calculate rectangle positions
        vector<tuple<int, int, int, int>> rects;
        int cur_x = 0, cur_y = 0;
        for(int i=0;i<n;i++){
            cur_x += steps[i].first;
            cur_y += steps[i].second;
            rects.emplace_back(cur_x, cur_x + m, cur_y, cur_y + m);
        }
        // Collect unique x and y coordinates
        vector<int> xs, ys;
        for(auto &[x1, x2, y1, y2] : rects){
            xs.push_back(x1);
            xs.push_back(x2);
            ys.push_back(y1);
            ys.push_back(y2);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        // Initialize grid
        int w = xs.size()-1;
        int h = ys.size()-1;
        vector<vector<bool>> grid(w, vector<bool>(h, false));
        // Mark grid
        for(auto &[x1, x2, y1, y2] : rects){
            int x1_idx = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
            int x2_idx = lower_bound(xs.begin(), xs.end(), x2) - xs.begin();
            int y1_idx = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
            int y2_idx = lower_bound(ys.begin(), ys.end(), y2) - ys.begin();
            for(int i=x1_idx; i<x2_idx; i++) {
                for(int j=y1_idx; j<y2_idx; j++) {
                    grid[i][j] = true;
                }
            }
        }
        // Compute perimeter
        long long perimeter = 0;
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                if(grid[i][j]){
                    // Left
                    if(i == 0 || !grid[i-1][j]){
                        perimeter += ys[j+1] - ys[j];
                    }
                    // Right
                    if(i == w-1 || !grid[i+1][j]){
                        perimeter += ys[j+1] - ys[j];
                    }
                    // Bottom
                    if(j == 0 || !grid[i][j-1]){
                        perimeter += xs[i+1] - xs[i];
                    }
                    // Top
                    if(j == h-1 || !grid[i][j+1]){
                        perimeter += xs[i+1] - xs[i];
                    }
                }
            }
        }
        cout << perimeter << "\n";
    }
}