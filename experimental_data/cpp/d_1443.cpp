#include<bits/stdc++.h>

#define GOBA ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;

const ll LOO=0x3f3f3f3f3f3f3f3f;

const long double EPS=1e-8;

int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};



struct Node{

    int level=0;

    bool vis=0;

    vector<Node *> nei={};

};

int BFS(Node *node){

    queue<Node*>q;

    q.push(node);

    node->vis=1;

    int mx;

    while(!q.empty()){

        auto nde=q.front();

        q.pop();

        for(auto &x:nde->nei){

            if(x->vis==0){

                x->vis=1;

                x->level=nde->level+1;

                mx=x->level;

                q.push(x);

            }

        }

    }

    return mx;

}



int main() {

    GOBA

    //freopen("alimagde.in","rt",stdin);

    //freopen("output.txt","wt",stdout);

    int t;

    cin>>t;

    while(t--){

       int n;

       cin>>n;

       vector<int>vec(n);

       for(int i=0;i<n;i++){

           cin>>vec[i];

       }

       int num=vec[0];

       for(int i=1;i<n;i++){

           vec[0]-= max(0,num-vec[i]);

           num=vec[i];

       }

        if(vec[0]<0)cout<<"NO\n";

        else cout<<"YES\n";



    }



    return 0;

}