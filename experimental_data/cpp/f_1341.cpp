#include<bits/stdc++.h>



using namespace std;

#define N 100010

#define ll long long

#define ii pair<int,int>

#define fs first

#define sc second

#define pb push_back



int m,k,n,child[N],times[N];

vector<int>g[N];

ii kq[N*10];



void selfmax(int&A,int B)

{

    A=max(A,B);

}



void add(int u,int times)

{

   // cout<<u<<" "<<times<<endl;

    kq[++m]={u,times};

}



void DFS(int u,int p,int t)

{

    int times=t;

    for(auto v:g[u])

        if(v!=p)

        {

            if(times+1<=k)

            {

             // if(u==2)  cout<<m<<" "<<v<<" "<<times+1<<endl;

                add(v,times+1);

                child[u]--;

                DFS(v,u,times+1);

                times++;

            }else

            {

                times=t-1-child[u];

                add(u,times);

                add(v,times+1);

                child[u]--;

                DFS(v,u,times+1);

                times++;

            }

        }

    if(u!=1)

    {

        if(times!=t-1)

            add(u,t-1);

        add(p,t);

      //  kq[++m]={p,t};

    }

}



int main()

{

  //  freopen("A.inp","r",stdin);

  ////  freopen("A.out","w",stdout);

    ios::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);

    cin>>n;

    for(int i=1;i<n;i++)

    {

        int u,v;

        cin>>u>>v;

        g[u].pb(v);

        g[v].pb(u);

    }

    for(int i=1;i<=n;i++)

    {

        selfmax(k,g[i].size());

        child[i]=g[i].size()-(i!=1);

     //   cout<<child[i]<<endl;

    }

    kq[1]={1,0};

    m=1;

    DFS(1,0,0);

    cout<<m<<"\n";

    for(int i=1;i<=m;i++)

        cout<<kq[i].fs<<" "<<kq[i].sc<<"\n";

    return 0;

}