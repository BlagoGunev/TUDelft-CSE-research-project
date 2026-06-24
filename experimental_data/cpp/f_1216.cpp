#include <iostream>
#include <queue>
using namespace std;
#define N 200200
const long long inf = (1LL << 60);
long long d[N];
int i,n,k;
long long x,curr;
char v[N];
priority_queue < pair<long long,int> ,vector <pair <long long,int> >, greater<pair<long long,int> > > pq;
int main()
{
    cin >> n >> k;
    for (i = 0; i < n; ++i){
        cin >> v[i];
        d[i] = inf;
    }
    for (i = n - 1; i > -1; --i){
        curr = inf;
        while (!pq.empty() && pq.top().second > i + k)
            pq.pop();
        if (!pq.empty())
            curr = pq.top().first;
        d[i] = min(curr,d[i + 1] + i + 1);
        if (v[i] > '0'){
            //d[i] = min (d[i],d[min(n,i + k + 1)] + i + 1);
            x = d[min(n,i + k + 1)] + i + 1;
            x = min (curr + i + 1, x);
            if (d[i] >= x)
                d[i] = x;
            pq.push (make_pair (x,i));
        }
    }
    cout << d[0];
    return 0;
}