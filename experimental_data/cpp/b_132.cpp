#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<string> a(m);
    for (int i = 0; i < m; ++ i) {
        cin >> a[i];
    }
    int w = a[0].length();
    int x = 0, y = 0;
    int dx = +1, dy =  0;
    int cx =  0, cy = -1;
    map<int,int> memo;
    for (int i = 0; i < n; ++ i) {
        while (0 <= x+dx && x+dx < w && 0 <= y+dy && y+dy < m) {
            if (a[y+dy][x+dx] != a[y][x]) break;
            x += dx;
            y += dy;
        }
        while (0 <= x+cx && x+cx < w && 0 <= y+cy && y+cy < m) {
            if (a[y+cy][x+cx] != a[y][x]) break;
            x += cx;
            y += cy;
        }
        if (0 <= x+dx && x+dx < w && 0 <= y+dy && y+dy < m && a[y+dy][x+dx] != '0') {
            x += dx;
            y += dy;
        } else {
            if (cx == dy && cy == -dx) {
                cx = -dy;
                cy = dx;
            } else {
                dx = cx;
                dy = cy;
                cx = dy;
                cy = -dx;
            }
        }
        {
            int h = x * 100 + y;
            h = h*3 + dx;
            h = h*3 + dy;
            h = h*3 + cx;
            h = h*3 + cy;
            if (memo.count(h)) {
                int p = (i+1) - memo[h];
                if (n-i-1 >= p) {
                    i += (n-i-1) / p * p;
                }
            } else {
                memo[h] = i+1;
            }
        }
    }
    cout << a[y][x] << endl;
}