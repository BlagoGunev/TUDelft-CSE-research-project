#include<bits/stdc++.h>
using namespace std;
const int N = 1000100;
vector<pair<int,int> >adj[N];
pair<int,int> arr[N];

long long bitSum[N];
long long bitNum[N];

void update(int idx , int add , long long val)
{
    for( ; idx < N ; idx += idx & -idx)
        bitNum[idx] += add , bitSum[idx] += val;
}

pair<long long,long long> getAns(int idx)
{
    long long num = 0;
    long long sum = 0;
    for( ; idx ; idx -= idx & -idx)
    {
        num += bitNum[idx];
        sum += bitSum[idx];
    }
    return {num , sum};
}


long long have;
long long dfs(int u = 1 , long long cur = 0)
{
    long long rem  = have - cur;
    if(rem < 0) return -1;
    int l = 0 , r = N - 5;
    pair<long long,long long>p;
    while(l<r)
    {
        int mid = l + (r-l+1)/2;
        p = getAns(mid);
        if(p.second <= rem) l = mid;
        else r = mid-1;
    }
    p = getAns(l);
    long long can = p.first;
    rem -= p.second;
    if(l != N - 5)
    {
        can += rem / (l+1);
    }
    vector<long long> vec;
    for(auto v : adj[u])
    {
        int idx = v.first;
        update(arr[idx].second , arr[idx].first , 1ll*arr[idx].first * arr[idx].second);
        vec.push_back(dfs(idx , cur + 2*v.second));
        update(arr[idx].second , -arr[idx].first , -1ll*arr[idx].first * arr[idx].second);
    }
    sort(vec.rbegin() , vec.rend());
    if(u == 1 && !vec.empty()) return max(can , vec[0]);
    else if(vec.empty() || vec.size() == 1) return can;
    else
    {
        if(vec[1] < can) return can;
        else return vec[1];
    }
}


int main() {
    int n;
    cin>>n>>have;
    for(int i = 1 ; i<=n ; ++i)
    {
        scanf("%d" , &arr[i].first);
    }
    for(int i = 1 ; i<=n ; ++i)
    {
        scanf("%d" , &arr[i].second);
    }
    for(int i = 2 ; i<=n ; ++i)
    {
        int x,c;
        scanf("%d%d" , &x , &c);
        adj[x].push_back({i,c});
    }
    update(arr[1].second , arr[1].first , 1ll*arr[1].first * arr[1].second);
    cout<<dfs()<<endl;
}