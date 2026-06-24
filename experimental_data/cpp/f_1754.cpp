#include<bits/stdc++.h>

using namespace std;



int wy[5][2]={

{1,0},{-1,0},{0,1},{0,-1},{0,0}

};



int sign[4]={

    1,1,2,2

};



map<char,int > trans={

    {'U',0},{'D',1},{'L',2},{'R',3},{'.',4}

};



map<char,int > trans2={

    {'U',1},{'D',1},{'L',2},{'R',2}

};



int wight[4];



int n,m;

vector<string > G;



bool check(int x,int y){

    return (x>=0&&x<n&&y>=0&&y<m&&G[x][y]!='#');

}



void solve(){

    vector<vector<long long > > dis(n,vector<long long > (m,1e18));

    priority_queue<tuple<long long,int ,int > > Q;

    for(int i=0;i<n;i++)

    for(int j=0;j<m;j++){

        if(G[i][j]=='.'){

            Q.emplace(0,i,j);

            dis[i][j]=0;

        }

    }

    while(Q.size()){

        long long w;

        int x,y;

        w=get<0>(Q.top());

        x=get<1>(Q.top());

        y=get<2>(Q.top());

        Q.pop();

        w=-w;

        for(int k=0;k<4;k++){

            int dx=x+wy[k][0],dy=y+wy[k][1];

            if(check(dx,dy)){

                int b=trans[G[dx][dy]];

                dx+=wy[b][0],dy+=wy[b][1];

                if(dx==x&&dy==y)continue;

                if(dis[dx][dy]>w+wight[sign[k]^trans2[G[dx][dy]]]){

                    dis[dx][dy]=w+wight[sign[k]^trans2[G[dx][dy]]];

                    Q.emplace(-dis[dx][dy],dx,dy);

                }

            }

        }

    }

    long long ans=1e18;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(G[i][j]=='#')continue;

            long long la=dis[i][j];

            for(int k=0;k<4;k++){

                int dx=i+wy[k][0];

                int dy=j+wy[k][1];

                if(check(dx,dy)){

                    ans=min(la+dis[dx][dy],ans);

                }

            }

        }

    }

    if(ans==1e18){

        cout<<-1<<endl;

    }

    else{

        cout<<ans<<endl;

    }

}



int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    cin>>n>>m;

    cin>>wight[3]>>wight[0];

    G.resize(n);

    for(int i=0;i<n;i++)cin>>G[i];

    solve();

}