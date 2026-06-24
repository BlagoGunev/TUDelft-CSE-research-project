#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<string, int> si;

typedef pair<int, int> ii;



int main(){

	

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    int n, m, k;

    cin>>n>>m>>k;

    

    map<string, int> mapa;

    mapa.insert(si("Monday", 0));

	mapa.insert(si("Tuesday", 1));

	mapa.insert(si("Wednesday", 2));

	mapa.insert(si("Thursday", 3));

	mapa.insert(si("Friday", 4));

	mapa.insert(si("Saturday", 5));

	mapa.insert(si("Sunday", 6));

	vector<vector<bool> > trabaja(n, vector<bool>(7, false));

	vector<vector<int> > proyecto(k);

	set<int> vacaciones;

	for(int i = 0; i<n; i++){

		int r; cin>>r;

		while(r--){

			string s;

			cin>>s;

			trabaja[i][mapa[s]] = true;

		}

	}

	for(int i = 0; i<m; i++){

		int c; cin>>c;

		c--;

		vacaciones.insert(c);

	}

	for(int i = 0; i<k; i++){

		int r; cin>>r;

		while(r--){

			int c; cin>>c;

			c--;

			proyecto[i].push_back(c);

		}

	}

	vector<priority_queue<int, vector<int>, greater<int> > > q(n);

	vector<int> vamos(k, 0);

	int t = 0;

	int contar = 0;

	vector<int> res(k);

	vector<set<int> > trabajador(7);

	for(int i = 0; i<k; i++){

		q[proyecto[i][0]].push(i);

		for(int j = 0; j<7; j++){

			if(trabaja[proyecto[i][0]][j] == true){

				trabajador[j].insert(proyecto[i][0]);

			}

		}

	}

	

	while(contar < k){

		if(vacaciones.count(t) == 1){

			t++;

			continue;

		}

		vector<int> pendiente;

		vector<int> borrador;

		for(auto u: trabajador[t%7]){//trabajadores

			int proyectox = q[u].top();

			q[u].pop();

			if(q[u].size() == 0){

				borrador.push_back(u);

			}

			pendiente.push_back(proyectox);

		}

		for(auto u: borrador){

			for(int i = 0; i<7; i++){

				if(trabaja[u][i] == true){

					trabajador[i].erase(u);

				}

			}

		}

		for(auto u: pendiente){

			//cout<<t<<" "<<u<<"\n";

			int v = vamos[u];

			v++;

			if(v == proyecto[u].size()){

				contar++;

				res[u] = t;

			}

			else{

				q[proyecto[u][v]].push(u);

				for(int i = 0; i<7; i++){

					if(trabaja[proyecto[u][v]][i] == true){

						trabajador[i].insert(proyecto[u][v]);

					}

				}

			}

			vamos[u]++;

		}

		t++;

	}

	

	for(int i = 0; i<k; i++){

		cout<<res[i] + 1<<" ";

	}

	cout<<"\n";

	

	return 0;

}