#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;
const int maxn = 310000;
int deg[maxn];
vector<int> adj[maxn];
#define pb push_back
int num[maxn];
int a[maxn], b[maxn];
bool vis[maxn];
int ans[maxn];
int n;
void dfs( int s, int dep )
{
    vis[s] = 1;
    ans[dep] = s;
    for(int i=0; i<adj[s].size(); i++ ){
        int to = adj[s][i];
        if( vis[to] ) continue;
        else{
            dfs( to, dep+1  ); break;
        }
    }
}
int main()
{
    cin>>n;
    int nno = 0;
    for(int i=0; i<maxn; i++ ) adj[i].clear();
    for(int i=0; i<n; i++ ){

        scanf("%d%d", &a[i], &b[i] );
        num[nno++] = a[i];
        num[nno++] = b[i];
    }
    sort( num, num+nno );
    int i, j;
    for(i=1, j=0; i<nno; i++ )
        if( num[j] < num[i] )
            num[++j] = num[i];
    nno = j+1;
//    for(int i=0; i<nno; i++ ) cout<<num[i]<<endl;
    for(int i=0; i<n; i++ ){
        int e1 = lower_bound( num, num+nno, a[i] ) -num;
        int e2 = lower_bound( num, num+nno, b[i] )- num;
//        cout<<e1<<" -- "<<e2<<endl;
        adj[ e1 ].pb( e2 );
        adj[ e2 ].pb( e1 );
    }
    for(int i=0; i<maxn; i++ ) vis[i] = 0;
    for(int i=0; i<nno; i++ ){
//        cout<<num[i]<<" "<<adj[i].size()<<endl;
        if( adj[i].size() == 1  ){
            dfs( i, 0);
            break;
        }
    }
    printf("%d", num[ans[0]] );
    for(int i=1; i<nno; i++ )
        printf(" %d", num[ans[i]] );
    printf("\n");
    return 0;
}