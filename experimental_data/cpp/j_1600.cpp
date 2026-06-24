#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'

int factory[1005][1005];

bool visited[1005][1005];

vector<int>room;

void dfs(int i,int j,int &sz)

{

    if(visited[i][j]) return;

    visited[i][j]=true;

    sz++;

    int curr=factory[i][j];

    if((curr&1)==0) dfs(i,j-1,sz);

    if(((curr>>1)&1)==0) dfs(i+1,j,sz);

    if(((curr>>2)&1)==0) dfs(i,j+1,sz);

    if(((curr>>3)&1)==0) dfs(i-1,j,sz);

}



signed main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    

    int n,m;

    cin>>n>>m;

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        cin>>factory[i][j];

    }

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        {

            if(visited[i][j]==false)

            {

                int sz=0;

                dfs(i,j,sz);

                room.push_back(sz);

            }

        }

    }

    sort(room.begin(),room.end(),greater<int>());

    for(int i=0;i<room.size();i++)

    cout<<room[i]<<" ";

    cout<<endl;

}