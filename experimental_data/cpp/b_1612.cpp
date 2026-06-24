#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=1000,INF=0x3f3f3f3f;
int n, a, b, q[N], t;
bool st[N];

int main()
{
    io;
	int T;
	cin>>T;
    while (T--) {
        memset(st, 0, sizeof st);
        cin >> n >> a >> b;
        t = 0;
        
        for (int i = n; i >= a; i--) {
            if (t + 1 == n / 2) {
                q[++t] = a;
                st[a] = 1;
                break;
            }
            if (i != b) q[++t] = i, st[i] = 1;
        }

        if (t != n / 2) {
            cout<<"-1"<<endl;
            continue;
        }

        for (int i = 1; i <= b; i++) {
            if (st[i]) continue;
            q[++t] = i, st[i] = 1;
        }

        if (t == n) {
            for (int i = 1; i <= t; i++)
                cout << q[i] << ' '; cout << endl;
        }
        else 
        {
            cout<<"-1"<<endl;
        }
    }

    return 0;
}