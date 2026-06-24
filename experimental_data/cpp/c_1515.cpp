#include <bits/stdc++.h>

#define int long long int 

typedef std::numeric_limits< double > dbl;

using namespace std;

 

int32_t main() {

    std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    cout.precision(dbl::max_digits10);

  

    int tt;

    cin>>tt;

  

    while(tt--){

        

        int n,m,x;

        cin>>n>>m>>x;

        

        vector<pair<int,int>>  h(n);

        for(int i=0;i<n;i++)  {cin>>h[i].first; h[i].second=i;}

      //  sort(begin(h),end(h));

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<m;i++) pq.push({0,i});

        vector<int>  ans(n);

        for(int i=n-1;i>=0;i--){

           

            auto x=pq.top(); pq.pop(); pq.push({h[i].first+x.first, x.second});

            // cout<<i<<" "<<h[i].first<<" "<<h[i].second<<" "<<x.first<<" "<<x.second<<"\n";

            ans[h[i].second]=x.second+1;

        }

        int mn=INT_MAX;

        int mx=INT_MIN;

        while(!pq.empty()){

            mx=max(mx,pq.top().first);

            mn=min(mn,pq.top().first);

            pq.pop();

        }

        

       // cout<<mx-mn<<"\n";

        

        if(mx-mn>x){

            cout<<"NO";

        }

        else{

            cout<<"YES\n";

            for(int i=0;i<n;i++) cout<<ans[i]<<" ";

        }

        

        cout<<"\n";

    }

  

  return 0;

}