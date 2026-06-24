#include <algorithm>

#include <iostream>

#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



using namespace std;

using vi=vector<int>;



int t,n,ans;



int main()

{

    FAST

    cin>>t;

    while(t--)

    {

        ans=0;

        cin>>n;

        vi v(n);

        for(auto &i:v)

            cin>>i;

        sort(v.begin(),v.end());

        for(auto k=0; k<=n; k++)

            if(!k || v[k-1]<k)

                if(k==n || v[k]>k)

                    ans++;

        cout<<ans<<'\n';

    }

}