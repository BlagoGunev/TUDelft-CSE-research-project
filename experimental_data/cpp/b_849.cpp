#include <bits/stdc++.h>
/*#include <bits/stdc++.h>
using namespace std;
int a[1005];
double b[1005];
bool vis[1005];
int n;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", a+i);
    }
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int tmp = a[j]-a[i];
            for(int k=j; k<n; k+=j-i){

            }
        }
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3;
#define LL long long

pair<LL, LL> node[maxn];
LL vis[maxn];

LL pd(pair<LL, LL> a1, pair<LL, LL> a2, pair<LL, LL> a3) {
    LL x1 = a1.first;
    LL x2 = a2.first;
    LL x3 = a3.first;
    LL y1 = a1.second;
    LL y2 = a2.second;
    LL y3 = a3.second;
    if((x2-x1)*(y3-y1) == (x3-x1)*(y2-y1))
        return 1;
    return 0;
}

LL pd2(pair<LL, LL> a1, pair<LL, LL> a2, pair<LL, LL> a3, pair<LL,LL> a4) {
    LL x1 = a1.first;
    LL x2 = a2.first;
    LL x3 = a3.first;
    LL x4 = a4.first;
    LL y1 = a1.second;
    LL y2 = a2.second;
    LL y3 = a3.second;
    LL y4 = a4.second;
    if((x2-x1)*(y4-y3) == (x4-x3)*(y2-y1))
        return 1;
    return 0;
}

int main() {
    LL n;
    LL y;
    cin >> n;
    for(LL i = 1; i <= n; i++) {
        scanf("%lld", &y);
        node[i].first = i;
        node[i].second = y;
    }
    int flag = 0;
    for(LL i = 2; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        vis[i] = 1;
        for(LL j = 2; j <= n; j++) {
            if(vis[j]==0) {
                if(pd(node[1],node[i], node[j]))
                    vis[j] = 1;
            }
        }
        int cnt = 0;
        int a1,a2;
        int flag1 = 0;
        for(int j = 2; j <= n; j++)  {
            if(vis[j]==0)  {
                if(cnt == 0) {
                    a1 = j;
                    cnt++;
                }
                else if(cnt == 1)  {
                    a2 = j;
                    cnt++;
                }
                else  {
                    if(!pd(node[a1],node[a2],node[j])) {
                        flag1 = 1;
                        break;
                    }
                }
            }
        }
        if(cnt == 0)
            continue;
        if(cnt == 1) {
            flag = 1;
            break;
        }
        if(!pd2(node[1],node[i],node[a1],node[a2]))
            continue;
        if(flag1 == 0)  {
            flag = 1;
            break;
        }
    }
    if(!pd(node[1],node[2],node[3]))
    for(int i = 4; i <= n; i++) {
        if(!pd(node[2],node[3],node[i]))
            break;
        if(i == n)
            flag = 1;
    }
    if(flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}