#include <bits/stdc++.h>

using namespace std;



#define fr(i,n) for(int i = 0; i<n; i++)

#define sz(v) (int)(v.size())

#define prin(a) cout << #a << " = " << a << endl

#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl

#define all(v) (v).begin(),(v).end()



typedef long long ll;



#define rmin(a,b) a = min<ll>(a,b)

#define rmax(a,b) a = max<ll>(a,b)



#define fi first

#define se second



int parede[23][362];

int circ[23][362];

int vis[23][362];



int di[] = {0,0,-1,1};

int dj[] = {-1,1,0,0};



void dfs(int i, int j){

    

    if(vis[i][j]) return;

    vis[i][j] = 1;

    

    /*

    prin(i);

    prin(j);

    cout << endl;

    */

    

    fr(k,4){

        //prin(k);

        int ni = i+di[k];

        int nj = j+dj[k];

        if(nj==-1) nj = 359;

        nj = nj%360;

        if(ni<0 or ni>21) continue;

        

        if(di[k]==-1){ //up

            if(circ[i][j]) continue;

            dfs(ni,nj);

        }

        if(di[k]==1){ //down

            if(circ[ni][nj]) continue;

            dfs(ni,nj);

        }

        

        if(dj[k]==-1){ //left

            if(parede[i][j]) continue;

            dfs(ni,nj);

        }

        if(dj[k]==1){ //right

            if(parede[ni][nj]) continue;

            dfs(ni,nj);

        }

        //prin(k);

    }

}



int main(){

    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    fr(tt,t){

        memset(parede,0,sizeof(parede));

        memset(circ,0,sizeof(circ));

        memset(vis,0,sizeof(vis));

        int n; cin >> n;

        fr(kk,n){

            char c; cin >> c;

            if(c=='C'){

                int r, ang1, ang2; cin >> r >> ang1 >> ang2;

                for(int i = ang1; i!=ang2; i = (i+1)%360){

                    circ[r][i] = 1;

                }

            } else{

                int r1, r2, ang; cin >> r1 >> r2 >> ang;

                for(int i = r1; i<r2; i++){

                    parede[i][ang] = 1;

                }

            }

        }

        //prin(tt);

        dfs(0,0);

        //prin(t);

        int ok = 0;

        fr(j,360) if(vis[21][j]) ok = 1;

        if(ok) cout << "YES\n";

        else cout << "NO\n";

        

        /*

        int soma = 0;

        fr(i,22) fr(j,360) soma+=vis[i][j];

        prin(soma);

        */

    }

}