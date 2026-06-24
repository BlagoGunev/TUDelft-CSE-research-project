#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

const int N=2e5+100;

int t,n,m,cnt,bin[N];

bool vis[N][2];

ll a[N],b[N];

int pos[N][2];

vector<int>v[N];

queue<int>q;

int anc(int k){//其实是返回右边第一个不匹配的位置(也就是a[i]!=b[i]的位置)

    if(!bin[k]) return k;//如果这个点的bin没有赋值过，说明这个点不匹配

    return bin[k]=anc(bin[k]);//类似于路径压缩

}

void solve(int x){

    for(auto i:v[x]){//实质是枚举包含x点的区间

        int id=i<=m?i:i-m;

        if(!vis[id][i>m]){

            vis[id][i>m]=1;//id这个区间的左/右断点是否相等

            if(vis[id][i<=m]) q.emplace(id);//如果另一半端点也是相等的就把这个区间id加入到que

        }

    }

}





int main(){

    ios::sync_with_stdio(0);

    cin.tie(0),cout.tie(0);

    int t;cin>>t;

    while(t--){

        cnt =0;

        cin>>n>>m;n++;

        for(int i=2,now;i<=n;i++) cin>>now,a[i]=a[i-1]+now; 

        for(int i=2,now;i<=n;i++) cin>>now,b[i]=b[i-1]+now;

        for(int i=1;i<=n+1;i++){

            bin[i]=0;

            v[i].clear();

        } 

        for(int i=1;i<=m;i++){

            cin>>pos[i][0]>>pos[i][1];pos[i][1]+=1;

            vis[i][0]=vis[i][1]=0;

            v[pos[i][0]].emplace_back(i);

            v[pos[i][1]].emplace_back(i+m);

        }

        while(!q.empty()) q.pop();

        for(int i=1;i<=n;i++)

            if(a[i]==b[i]){

                solve(i);

                bin[i]=anc(i+1);

                ++cnt;

            }

        while(!q.empty()){

            int k=q.front();

            q.pop();

            for(int i=anc(pos[k][0]);i<=pos[k][1];i=anc(i+1)){//将相等区间里面的合并掉

                solve(i);

                bin[i]=i+1;

                ++cnt;

            }

        }

        cout<<(cnt>=n? "YES":"NO")<<endl;

    }





}