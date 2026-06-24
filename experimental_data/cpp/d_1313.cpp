#include<bits/stdc++.h>

using namespace std;

#define taskname ""

struct line{

int l,r;

bool operator < (const line &p)const{

return l<p.l;

}

};

struct suzy{

int id,pos;

};

line a[100009];

int vis[8];

int dp[200009][1<<8];

int dp2[200009][1<<8];

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    //freopen(taskname".INP","r",stdin);

    //freopen(taskname".OUT","w",stdout);

    int n,m,k;

    cin>>n>>m>>k;

    vector<int>pos;

    map<int,int>dm;

    pos.push_back(m);

    dm[m]=1;

    for (int i=1;i<=n;i++){

        cin>>a[i].l>>a[i].r;

        if (dm[a[i].l]==0){

            pos.push_back(a[i].l);

            dm[a[i].l]=1;

        }

        if (dm[a[i].r+1]==0){

            dm[a[i].r+1]=1;

            pos.push_back(a[i].r+1);

        }

    }

    if (dm[m+1]==0)pos.push_back(m+1);

    sort(pos.begin(),pos.end());

    sort(a+1,a+1+n);

    int p=0;

    int mask=0;

    vector<suzy>last;

    int ans=0;

    for (int i=0;i<(int)pos.size()-1;i++){

        for (int j=0;j<k;j++){

            vis[j]=0;

        }

        mask=0;

        for (auto v:last){

            if (a[v.id].r<pos[i])continue;

            vis[v.pos]=v.id;

            //cout<<i<<" "<<v.pos<<'\n';

            mask+=(1<<v.pos);

        }

        vector<int>newline;

        for (int j=p+1;j<=n;j++){

            if (a[j].l==pos[i]){

                p=j;

                newline.push_back(j);

            }

            else break;

        }

        //cout<<newline.size()<<'\n';

        last.clear();

        int newmask=0,nmask=0;;

        for (int j=0;j<k;j++){

            if (vis[j]==0){

                if (newline.empty())continue;

                vis[j]=newline.back();

                newline.pop_back();

                last.push_back({vis[j],j});

                if (a[vis[j]].r>=pos[i+1])newmask+=(1<<j);

                nmask|=(1<<j);

            }

            else {

                last.push_back({vis[j],j});

                if (a[vis[j]].r>=pos[i+1])newmask+=(1<<j);

                nmask|=(1<<j);

                //cout<<i<<" "<<j<<'\n';

            }

        }

        //cout<<pos[i]<<" "<<last.size()<<'\n';

        //cout<<pos[i]<<" "<<nmask<<'\n';

        for (int j=0;j<(1<<k);j++){

            //beforemask

            if ((j&nmask)!=j)continue;

            int huhu=(j&mask);

            int sum=0;

            if (i>0)sum=dp2[i-1][huhu];

            if (__builtin_popcount(j)%2==1){

                sum+=(pos[i+1]-pos[i]);

            }

            dp[i][j]=sum;

            ans=max(ans,sum);

            //cout<<pos[i]<<" "<<j<<" "<<sum<<'\n';

        }

        //cout<<mask<<" "<<pos[i]<<'\n';

        //cout<<pos[i]<<" "<<newmask<<'\n';

        for (int j=0;j<(1<<k);j++){

            dp2[i][(j&newmask)]=max(dp2[i][(j&newmask)],dp[i][j]);

        }

        //cout<<i<<" "<<last.size()<<'\n';

    }

    cout<<ans;







}