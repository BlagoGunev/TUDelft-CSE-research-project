#include<bits/stdc++.h>

using namespace std;

 

/*

 

*/

 

void solve(int testCase)

{

    long long n,c;

    cin >> n >> c;

    int a;

    vector<int> cnt(c+10,0);

    for(int i=0;i<n;++i)

    {

        cin >> a;

        ++cnt[a];

    }

    for(int i=1;i<(int)cnt.size();++i)

    {

        cnt[i]+=cnt[i-1];

    }

    int j=0;    

    int ans = 0;

    for(long long z=1;z<=c;++z)

    {

        if(cnt[z] == cnt[z-1])

            continue;

        for(long long j=1;j*z<=c;++j)

        {

            if(cnt[j]-cnt[j-1]>0)

                continue;

            if(cnt[min(c,z*(j+1)-1)]-cnt[z*j-1])

            {

                cout << "No\n";

                return;

            }   

        }

    }

    cout << "Yes\n";

}

 

/*

 

*/

 

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int t; cin >> t;

    for(int testCase=1;testCase<=t;++testCase)

    {

        solve(testCase);

    }

}