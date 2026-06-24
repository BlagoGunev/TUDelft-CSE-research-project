#include<bits/stdc++.h>



using namespace std ;



typedef unsigned long long ll ;



const int N=2*1e3+9 ;



int dx[]={0,0,-1,1} ;



int dy[]={1,-1,0,0} ;



ll n , m , w , bestport=1e18 , a[N][N] ;



bool good(int x,int y)

{

    return(x>=0&&x<m&&y>=0&&y<n) ;

}



vector< vector<int> > lv(N,vector<int>(N,-1)),level(N,vector<int>(N,-1)) ;



void bfs(pair<int,int>src,vector<vector<int> >&walk)

{

    vector< vector<ll> > vis(N,vector<ll> (N,false)) ;



    queue<pair<int,int> > q ;



    q.push(src) ;



    walk[src.second][src.first] = 0 ;



    while(!q.empty())

    {

        ll x = q.front().first ;



        ll y = q.front().second;



        q.pop() ;



        if(vis[y][x])continue ;



        vis[y][x]=true ;



        for(int i=0;i<4;i++)

        {

            ll nx = x + dx[i] ;



            ll ny = y + dy[i] ;

            if(good(nx,ny)&&a[ny][nx]!=-1&&!vis[ny][nx])

            {

                walk[ny][nx]= walk[y][x] + 1 ;



                q.push({nx,ny}) ;

            }

        }

    }

    return ;

}



int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m >> w ;



    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        {

            cin>>a[i][j] ;

        }

    }

    bfs({0,0},lv) ;



    bfs({m-1,n-1},level) ;



    ll ans = lv[n-1][m-1] ;



    if(ans==-1)ans=1e18;

    else ans*=w;



    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        {

            if(a[i][j]>=1&&level[i][j]!=-1)

            {

                bestport=min(bestport,level[i][j]*w+a[i][j]) ;

            }

        }

    }

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        {

            if(a[i][j]>=1&&lv[i][j]!=-1&&bestport!=1e18)

            {

                ans=min(ans,a[i][j]+bestport+lv[i][j]*w) ;

            }

        }

    }

    if(ans==1e18)cout<<-1<<endl ;

    else cout<<ans<<endl ;

}