#include <bits/stdc++.h>
using namespace std;
vector<int> important;
void makeImportant(int col) {
    for (int i = col-16; i <= col+16; i++) {
        important.push_back(i);
    }
}
char type[2010*35];
pair<int, int> loc[2010*35];
unordered_map<int, int> comp;
int revComp[2010*35];
bool bad[2010*35][9];
bool has[2010*35][9];
bool seen[2010*35][9];
int dist[2010*35][9];
void makeBad(int x, int y) {
    if (y >= 1 && y <= 8) bad[x][y] = 1;
}
void doDiags(int x, int y) {
    int i = x-1;
    int j = y-1;
    while (i >= 0 && j >= 1 && !has[i][j]) {
        bad[i][j] = 1;
        i--;
        j--;
    }

    i = x-1;
    j = y+1;
    while (i >= 0 && j <= 8 && !has[i][j]) {
        bad[i][j] = 1;
        i--;
        j++;
    }

    i = x+1;
    j = y-1;
    while (i < important.size() && j >= 1 && !has[i][j]) {
        bad[i][j] = 1;
        i++;
        j--;
    }
    
    i = x+1;
    j = y+1;
    while (i < important.size() && j <= 8 && !has[i][j]) {
        bad[i][j] = 1;
        i++;
        j++;
    }
}

void doRowCol(int x, int y) {
    int i = x-1;
    int j = y;
    while (i >= 0 && !has[i][j]) {
        bad[i][j] = 1;
        i--;
    }

    i = x+1;
    j = y;
    while (i < important.size() && !has[i][j]) {
        bad[i][j] = 1;
        i++;
    }

    i = x;
    j = y-1;
    while (j >= 1 && !has[i][j]) {
        bad[i][j] = 1;
        j--;
    }

    i = x;
    j = y+1;
    while (j <= 8 && !has[i][j]) {
        bad[i][j] = 1;
        j++;
    }
}
int dis(int x, int y, int x2, int y2) {
    if (x == x2) return 1;
    else return abs(revComp[x]-revComp[x2]);
}
int main() {
    pair<int, int> s, t;
    scanf("%d%d%d%d", &s.first, &s.second, &t.first, &t.second);
    makeImportant(s.first);
    makeImportant(t.first);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c%d%d", &type[i], &loc[i].first, &loc[i].second);
        makeImportant(loc[i].first);
    }

    sort(important.begin(), important.end());
    important.erase(unique(important.begin(), important.end()), important.end());
    for (int i = 0; i < important.size(); i++) {
        comp[important[i]] = i;
        revComp[i] = important[i];
    }
    for (int i = 0; i < n; i++) {
        loc[i].first = comp[loc[i].first];
        has[loc[i].first][loc[i].second] = 1;
    }
    s.first = comp[s.first];
    t.first = comp[t.first];

    for (int i = 0; i < n; i++) {
        bad[loc[i].first][loc[i].second] = 1;
        if (type[i] == 'K') {
            for (int x = loc[i].first-1; x <= loc[i].first+1; x++) {
                for (int y = loc[i].second-1; y <= loc[i].second+1; y++) {
                    makeBad(x, y);
                }
            }
        } else if (type[i] == 'Q') {
            doDiags(loc[i].first, loc[i].second);
            doRowCol(loc[i].first, loc[i].second);
        } else if (type[i] == 'R') {
            doRowCol(loc[i].first, loc[i].second);
        } else if (type[i] == 'B') {
            doDiags(loc[i].first, loc[i].second);
        } else if (type[i] == 'N') {
            int x = loc[i].first;
            int y = loc[i].second;
            makeBad(x-1, y-2);
            makeBad(x-1, y+2);
            makeBad(x+1, y-2);
            makeBad(x+1, y+2);
            makeBad(x-2, y-1);
            makeBad(x-2, y+1);
            makeBad(x+2, y-1);
            makeBad(x+2, y+1);
        } else assert(false);
    }

    seen[s.first][s.second] = 1;
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> > > > q;
    q.push({0, s});
    while (q.size()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        int d = q.top().first;
        q.pop();
        if (d != dist[x][y]) continue;
        //printf("%d %d: %d\n", x, y, d);
        for (int i = x-1; i <= x+1; i++) {
            for (int j = y-1; j <= y+1; j++) {
                if (j >= 1 && j <= 8 && i >= 0 && i < important.size()) {
                    int newd = dist[x][y] + dis(x, y, i, j);
                    if (!bad[i][j] && (!seen[i][j] || newd < dist[i][j])) {
                        seen[i][j] = 1;
                        dist[i][j] = newd;
                        q.push({newd, {i, j}});
                    }
                }
            }
        }
    }

    if (!seen[t.first][t.second]) printf("-1\n");
    else printf("%d\n", dist[t.first][t.second]);
}