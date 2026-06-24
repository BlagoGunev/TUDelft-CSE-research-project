#include<bits/stdc++.h>

#define MAXN 1010

using namespace std;

int parent[MAXN+1],child[MAXN+1],diameter[MAXN+1];

int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n,p,x,y,z,mini;

    queue<int> que;

    cin>>n>>p;

    while(p--){

        cin>>x>>y>>z;

        parent[y]=x;

        child[x]=y;

        diameter[y]=z;

    }

    for(int i=1;i<=n;i++)

        if(!diameter[i]&&child[i]){

            que.push(i);

            mini=1<<30;

            x=i;

            while(child[x]){

                mini=min(diameter[child[x]],mini);

                x=child[x];

            }

            que.push(x);

            que.push(mini);

        }

    cout<<(que.size()/3)<<"\n";

    while(!que.empty()){

        cout<<que.front()<<" ";

        que.pop();

        cout<<que.front()<<" ";

        que.pop();

        cout<<que.front()<<"\n";

        que.pop();

    }

    return 0;

}