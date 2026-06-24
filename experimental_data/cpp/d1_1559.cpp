#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define siz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define fo(i, n)		for(int i=0;i<(int)(n);++i)
#define fp(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define fn(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define fvec(i,vec) for(auto i:vec)
#define pb				push_back
#define MP			make_pair
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef unsigned long long ull;
typedef  long long ll;
const ll OO =10e7;
#define mine(x,y,z) min(x,min(y,z))
#define maxe(x,y,z) max(x,min(y,z))
const int N=1005 ;
void init(int n,vector<int>&par,vector<int>&sz)
{
    for ( int i = 1 ; i <= n ;i++){
        par[i] = i , sz[i] = 1;
    }
}
int findparent( int u,vector<int>&par)
{
    if(par[u] == u)
        return  u;
    return par[u] = findparent(par[u],par);
}
bool iscyclic = false;
void connect( int u , int v,vector<int>&par,vector<int>&sz)
{
    u = findparent(u,par);
    v = findparent(v,par);
    if ( u == v)
    {
        iscyclic =true;
        return;
    }
    if(sz[v] < sz[u])
        par[v] = u ,sz[u] += sz[v];
    else
        par[u] = v,sz[v] += sz[u];
}
bool isconnected(  int u , int v,vector<int>&par)
{
    return (findparent(u,par) == findparent(v,par));
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int num,m1,m2;cin>>num>>m1>>m2;
        vector<int> par1(num+1), sz1(num+1),par2(num+1),sz2(num+1);
        init(num,par1,sz1);
        init(num,par2,sz2);
        fo(i,m1){
            int u,v;cin>>u>>v;
            connect(u,v,par1,sz1);
        }
        fo(i,m2){
            int u,v;cin>>u>>v;
            connect(u,v,par2,sz2);
        }
        vector<pair<int,int>>vec;
        fp(i,1,num){
            fp(j,i+1,num){
                if(isconnected(i,j,par1)==false&&isconnected(i,j,par2)==false){
                    connect(i,j,par1,sz1);
                    connect(i,j,par2,sz2);
                    vec.pb({i,j});
                }
            }
        }

        cout<<vec.size()<<'\n';
        fvec(i,vec){
            cout<<i.first<<" "<<i.second<<'\n';
        }
}