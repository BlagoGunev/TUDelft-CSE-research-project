#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 1e9 + 7;
const int MAXN = 120;

int cnt[5];
int maxPoints[5];
int minute[MAXN + 5][5];
int n;

int fact[] =     {  2,    4,    8,   16,  32};
int maxScore[] = { 500, 1000, 1500, 2000, 2500, 3000};

pair<int,int> notBigger[5][6], bigger[5][6];

pair<int,int> getNotBigger(int x, int y, int f) {
    pair<int,int> ret = {0, MAX};
    ret.first = max(1LL * ret.first, min(1LL * MAX, 1LL * x * f - y));
    return ret;
}

pair<int,int> getBigger(int x, int y, int f, bool canWin) {
//    printf("%d / %d for 1 / %d\n",x , y, f);
    pair<int,int> ret = {0, MAX};
    if (x * f - y > 0) {
        if (!canWin) {
            int hobb = min(1LL * MAX, 1LL * x * f - y - 1);
            ret.second = min(ret.second, hobb);
        }
    } else {
        if (!canWin) ret = {1, 0};
        else {
            int hobb = min(1LL * MAX, 1 + (y - 1LL * x * f) / (f - 1));
            ret.first = max(ret.first, hobb);
        }
    }
    return ret;
}

pair<int,int> intersect(const pair<int,int>& p1, const pair<int,int>& p2) {
    return {max(p1.first, p2.first), min(p1.second, p2.second)};
}

int score(int i, int j, int maxi) {
    if (!~minute[i][j]) return 0;
    return maxi - maxi / 250 * minute[i][j];
}

int solve(int i, int s1, int s2, int from = 0, int to = MAX) {
    if (i == 5) return s1 > s2 ? from : MAX + 1;
    int ret = MAX + 1;
    for (int sc = 0; sc < 6; sc++) {
        pair<int,int> p = {from, to};
        if (sc > 0) p = intersect(p, notBigger[i][sc - 1]);
        if (sc < 5) p = intersect(p, bigger[i][sc]);
        if (p.first <= p.second) {
            ret = min(ret, solve(i + 1, s1 + score(0, i, maxScore[sc]), s2 + score(1, i, maxScore[sc]), p.first, p.second));
        }
    }
    return ret;
}

void init() {
    for (int c=0;c<n;c++)
        for (int c2=0;c2<5;c2++)
            cnt[c2] += !!~minute[c][c2];
    for (int c=0;c<5;c++) {
        for (int c2=0;c2<5;c2++) {
            notBigger[c][c2] = getNotBigger(cnt[c], n, fact[c2]);
            bigger[c][c2] = getBigger(cnt[c], n, fact[c2], ~minute[0][c]);
        }
    }
}

bool better(int i) {
    if (minute[0][i] == -1) return 0;
    if (minute[1][i] == -1) return 1;
    return minute[0][i] < minute[1][i];
}

int calcMax(int solved, int tot) {
    if (solved * 2LL > tot) return 500;
    if (solved * 4LL > tot) return 1000;
    if (solved * 8LL > tot) return 1500;
    if (solved * 16LL > tot) return 2000;
    if (solved * 32LL > tot) return 2500;
    return 3000;
}

int score(int i) {
    int ret = 0;
    for (int j = 0; j < 5; j++) {
        if (~minute[i][j])
            ret += maxPoints[j] - maxPoints[j] / 250 * minute[i][j];
    }
    return ret;
}

bool check(int added) {
    memset(cnt, 0, sizeof(cnt));
    int tot = n + added;
    for (int c=0;c<n;c++)
        for (int c2=0;c2<5;c2++)
            cnt[c2] += !!~minute[c][c2];
    for (int c=0;c<5;c++)
        cnt[c] += added * (!!~minute[0][c] && !better(c));
//    for (int c=0;c<5;c++) printf("%d ",cnt[c]);
//    printf("\n");
    for (int c=0;c<5;c++) {
        maxPoints[c] = calcMax(cnt[c], tot);
//        printf("%d ",maxPoints[c]);
    }
//    printf("\n");
    return score(0) > score(1);
}

int main() {
//    freopen("scoring.in","r",stdin);
    int c,c2;
    scanf("%d",&n);
    for (c=0;c<n;c++) {
        for (c2=0;c2<5;c2++)
            scanf("%d",&minute[c][c2]);
    }
    init();
//    printf("%d-%d and %d-%d\n",bigger[2][0].first, bigger[2][0].second, notBigger[2][0].first, notBigger[2][0].second);
    int ret = solve(0, 0, 0);
    if (ret > MAX) ret = -1;
    printf("%d\n",ret);
//    printf("%d\n",check(2));
//    int s = 0, e = MAX;
//    int ret = -1;
//    while (s <= e) {
//        int mid = s + e >> 1;
//        if (check(mid)) {
//            ret = mid;
//            e = mid - 1;
//        } else s = mid + 1;
//    }
//    printf("%d\n",ret);
    return 0;
}