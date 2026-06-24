// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v1 , v2;
ll k;
int n , k1 , k2;

bool cmp(pair<ll, ll> A , pair<ll , ll> B)
{
    return A.first>B.first;
}

int main(void)
{

    scanf("%d %d %d",&n , &k1 , &k2);

    k = k1+k2;

    priority_queue<ll>pq;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v1.push_back(in);
    }

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v2.push_back(in);
    }

    for(int i=0;i<n;i++){

        pq.push(abs(v1[i]-v2[i]));
    }


    for(int i=0;i<k;i++){

        ll temp = pq.top();
        pq.pop();
        if(temp>0)pq.push(temp-1);
        else pq.push(temp+1);
    }

    ll ans = 0;

    while(!pq.empty()){

        ll temp = pq.top();
        pq.pop();
        ans+=temp*temp;
    }

    printf("%lld\n",ans);

    return 0;
}