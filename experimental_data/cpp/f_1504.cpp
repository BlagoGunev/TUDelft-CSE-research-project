#include <bits/stdc++.h>

using namespace std;

const int maxn=4e5+10;

int n,a[maxn],v[maxn],suf[maxn],pre;

vector<int> v1,v2;

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    cin>>n;

    int x,y;

    for(int i=1;i<=n;i++){

        cin>>x>>y;

        int t=0;

        if(x>y){

            swap(x,y);

            t++;

        }

        if(y<=n){

            cout<<"-1\n";

            return 0;

        }

        a[x]=y;

        v[x]+=t;

    }

    suf[n+1]=-1;

    for(int i=n;i>=1;i--)suf[i]=max(suf[i+1],a[i]);

    int pre=INT_MAX;

    int c1=0,c2=0,ans=0;

    v1.clear();v2.clear();

    for(int i=1;i<=n;i++){

        pre=min(pre,a[i]);

     //   cout<<i<<" "<<pre<<endl;

        if(v1.empty()||a[v1.back()]>a[i]){

            v1.push_back(i);

            c1+=v[i];

        }

        else if(v2.empty()||a[v2.back()]>a[i]){

            v2.push_back(i);

            c2+=v[i];

        }

        else {

            cout<<"-1\n";

            return 0;

        }

        if(pre>suf[i+1]){

            int l1=v1.size(),l2=v2.size();

            ans+=min(l1-c1+c2,l2-c2+c1);

            v1.clear();

            v2.clear();

            c1=0;c2=0;

        }

    }

    cout<<ans<<endl;

    return 0;

}