#include<bits/stdc++.h>

#define f first

#define s second

#define pb push_back

#define read(x) for(auto& qw : (x)) cin >> qw;

#define endl "\n"; //para problemas iterativos comentar essa linha

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pii;

const int INF = 0x3f3f3f3f;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9 + 7;

const ll NO_OPERTATION = -1;

const double eps = 1e-8;

const int MAX = 200000 + 100;

const int LOG = 20;



int n;

vector<int> graph [MAX];

int pai [MAX];

int up[MAX][LOG]; // up[v][j] is 2^j-th ancestor of v

int depth[MAX];



void dfs(int a, int p) {

	for(int b : graph[a]) {

        if(b==p){continue;}

		depth[b] = depth[a] + 1;

		up[b][0] = a; // a is parent of b

		pai[b]=a;

		for(int j = 1; j < LOG; j++) {

			up[b][j] = up[up[b][j-1]][j-1];  // a gnt faz essa parte aqui pq por ser uma dfs, ao chamar nessa parte garantimos que todo pathing antes dele esta feito

		}                                        // diferentemente de chamar a partir do 0 at� n-1 pois  nesse caso o 5 poderia estar acima do 2 por exemplo.

        dfs(b,a);

	}

}



int get_lca(int a, int b) { // O(log(N))

	if(depth[a] < depth[b]) {

		swap(a, b);

	}

	// 1) Get same depth.

	int k = depth[a] - depth[b];

	for(int j = LOG - 1; j >= 0; j--) {

		if(k & (1 << j)) {

			a = up[a][j]; // parent of a

		}

	}

	// 2) if b was ancestor of a then now a==b

	if(a == b) {

		return a;

	}

	// 3) move both a and b with powers of two

	for(int j = LOG - 1; j >= 0; j--) {

		if(up[a][j] != up[b][j]) {

			a = up[a][j];

			b = up[b][j];

		}

	}

	return up[a][0];

}



int main ()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cin>>n;

    depth[0]=0;

    for(int i=0;i<n-1;i++)

    {

        int a, b;

        cin>>a>>b;

        a--; b--;

        graph[a].pb(b);

        graph[b].pb(a);

    }

    int q;

    cin>>q;

    int vez=0;

    dfs(0,0);

    pai[0]=0;

    while(q--)

    {

        vez++;

        int m;

        cin>>m;

        vector<int> ordem(m);

        for(int i=0;i<m;i++)

        {

            cin>>ordem[i];

            ordem[i]--;

        }

        if(m==1)

        {

            cout<<"YES"<<endl;

        }

        else

        {

            int ponta1=ordem[0];

            int ponta2=-1;

            bool confere=true;

            int lca =ordem[0];

            for(int i=1;i<m;i++)

            {

                lca = get_lca(ordem[i],lca);

                int aux = get_lca(ponta1,ordem[i]);

               // cout<<aux<<" "<<ponta1<<" "<<ordem[i]<<" "<<ponta2<<endl;

                int aux2;

                if(ponta2==-1){aux2=-2;}

                else{aux2=get_lca(ponta2,ordem[i]);}

                if(aux==ponta1)

                {

                    ponta1=ordem[i];

                }

                else if(ponta2==aux2)

                {

                    ponta2=ordem[i];

                }

                else if(aux==ordem[i] or aux2==ordem[i]){;}

                else

                {

                    if(ponta2==-1){ponta2=ordem[i];}

                    else{confere=false; break;}

                }

            }

            //cout<<ponta1<<" "<<ponta2<<endl;

            if(ponta2!=-1 and get_lca(ponta1,ponta2)!=lca){confere=false;}

            if(confere){cout<<"YES"<<endl;}

            else{cout<<"NO"<<endl;}

        }

    }

    return 0;

}

/*

5

1 2

2 3

2 4

4 5

1

3

3 2 5

*/