#include<bits/stdc++.h>

#define ll long long

#define mp make_pair

#define pb push_back

using namespace std;

ll arr[100002];

pair<int,pair<int,int> > opr[100001];

int temp[100002];

int ans[100002];

int main()

{

   int n,m,k;

   scanf("%d%d%d",&n,&m,&k);

   for(int i=1;i<=n;i++) scanf("%d",&ans[i]);

   for(int i=1;i<=m;i++){

    int l,r,d;

    scanf("%d%d%d",&l,&r,&d);

    opr[i] = mp(d,mp(l,r));

   }

   for(int i=0;i<k;i++){

    int l,r;

    scanf("%d%d",&l,&r);

    temp[l]++;

    temp[r+1]--;

   }

   for(int i=1;i<=m;i++){

    temp[i]+=temp[i-1];

   }

   for(int i=1;i<=m;i++){

    ll val = 1ll*temp[i]*opr[i].first;

    int l = opr[i].second.first;

    int r = opr[i].second.second;

    arr[l] += val;

    arr[r+1] -= val;

   }

   for(int i=1;i<=n;i++){

    arr[i]+=arr[i-1];

    printf("%I64d ",arr[i]+ans[i]);

   }

   cout<<endl;

return 0;

}