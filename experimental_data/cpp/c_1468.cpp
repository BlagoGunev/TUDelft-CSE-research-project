#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int start_up()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}
int main()
{
    start_up();
    priority_queue<pair<int,int>> pq;
    queue<pair<int,int>>q;
    set<int>st;
    int t,cnt=0,m;
    cin >>t;
    while(t--)
    {
        int x;
        cin >>x;
        if(x==1)
        {
            cin >>m;
            cnt++;
            q.push({cnt,m});
            pq.push({m,-cnt});
        }
        else if(x==2)
        {
            while (st.count(q.front().first))
            {
                q.pop();
            }
            cout <<q.front().first<<" ";
            st.insert(q.front().first);
            q.pop();
        }
        else if(x==3)
        {
            while (st.count(-pq.top().second))
            {
                pq.pop();
            }
            cout <<-pq.top().second<<" ";
            st.insert(-pq.top().second);
            pq.pop();
        }
    }
}