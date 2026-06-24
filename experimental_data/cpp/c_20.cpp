#include<bits/stdc++.h>

using namespace std;



#define fill(a,val) memset(a, (val), sizeof a)

#define pb push_back

#define lli long long int

#define scantype int

#define endl "\n"



lli MOD  = 1000000007;

lli inf = 1e15;



void scan(scantype &x);

lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

lli string_to_number(string s){lli x=0; stringstream convert(s); convert>>x; return x;}

lli add(lli a,lli b){lli x = (a+b)%MOD; return x; }

lli mul(lli a,lli b){lli x = (a*b)%MOD; return x; }

lli sub(lli a,lli b){lli x = (a-b+MOD)%MOD; return x; }

lli div(lli a,lli b){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}



#define N 100003



int n,m;

vector<pair<int,int> > edge[N];

lli dist[N],par[N];

bool vis[N];



class cmp

{

public:

       bool operator() (pair<int,int> a,pair<int,int> b)

       {

              if(a.second>b.second)return true;

              return false;

       }



};



void dijk(int src)

{

       for(int i=0;i<=n;i++)dist[i]=inf;



       priority_queue< pair<int,lli> , vector<pair<int,lli> >,cmp> line;

       par[src]=-1;

       line.push({src,dist[src]=0});



       while(!line.empty())

       {

              int node = line.top().first;

              lli ndis = line.top().second;

              line.pop();



              vis[node] = true;



              for(auto it : edge[node])

              {

                     int cnode = it.first;

                     lli cdist = it.second;



                     if(!vis[cnode] && ndis+cdist<dist[cnode])

                     {

                            par[cnode] = node;

                            line.push({cnode,dist[cnode]=ndis+cdist});

                     }

              }

       }

}



int main(void)

{

  cin>>n>>m;

  for(int i=0;i<m;i++)

  {

         int x,y,z;

         scan(x);scan(y);scan(z);

         edge[x].pb({y,z});

         edge[y].pb({x,z});

  }



  dijk(1);



  if(dist[n]>=inf)cout<<"-1";

  else

  {

         vector<int>path;

         int p = n;



         while(p!=-1)

         {

                path.pb(p);

                p=par[p];

         }



         for(int i=path.size()-1;i>=0;i--)

              printf("%d ",path[i]);

  }

  return 0;

}



















void scan(scantype &x)

{

    register int c = getchar(); //for negative/positive

    x = 0;

    int neg = 0;

    for(;((c<48 || c>57) && c != '-');c = getchar());

    if(c=='-') {neg=1;c=getchar();}

    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}

    if(neg) x=-x;

}