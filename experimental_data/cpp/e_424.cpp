#include <bits/stdc++.h>

#define PB push_back

#define MP make_pair

#define F first

#define S second

#define SZ(x) ((int)(x).size())

#define ALL(x) (x).begin(),(x).end()

#ifdef _DEBUG_

	#define debug(...) printf(__VA_ARGS__)

#else

	#define debug(...) (void)0

#endif

using namespace std;

typedef long long ll;

typedef pair<int,int> PII;

typedef vector<int> VI;



typedef pair<char, char> PCC;

typedef pair<char, PCC> Level;

typedef vector<Level> Tower;



struct myhash {

	size_t operator () (const Tower &t) const {

		size_t val=0;

		for(Level u:t)

			val=val*73+u.F*19+u.S.F*5+u.S.S;

		return val;

	}

};



unordered_map< Tower, double, myhash > dp;



const double INF=1e9;

const Level Newlevel=Level('O', PCC('O', 'O') );

const char dice[4]="BGR";

const double prob[3]={2./6., 2./6., 1./6.};



// '_': taken out, 'O': Not yet put , 'A': some thing(don't care color)

void simply(Level &x) {

	if(x.F=='_' || x.S==PCC('_','_') || x==Newlevel) {

		x.F='Z';

		return;

	}

	if(x.S.F=='_' || x.S.S=='_') x.F='A';

	if(x.S.F>x.S.S) swap(x.S.F, x.S.S);

}



void simply(Tower &x) {

	Tower r;

	for(auto &u:x) {

		simply(u);

		if(u.F!='Z') r.PB(u);

	}

	x.swap(r);

	sort(x.begin(), x.end()-1);

}



int cnt;

double go(Tower x) {

	simply(x);

	if(SZ(x)==1) return 0;

	double &re=dp[x];

	if(re>0) return re;

	double remain=1./6.;

	double sum=0;

	for(int i=0;i<3;i++) {

		double best=INF;

		for(int j=0;j<SZ(x)-1;j++) {

			for(int k=0;k<3;k++) {

				//if(k==0 && (x[j].S.F=='_' || x[j].S.S=='_')) continue;

				if(k==0 && x[j].F  !=dice[i]) continue;

				if(k==1 && x[j].S.F!=dice[i]) continue;

				if(k==2 && x[j].S.S!=dice[i]) continue;

				Tower nxt=x;

				char out=dice[i];

				if(k==0) nxt[j].F  ='_';

				if(k==1) nxt[j].S.F='_';

				if(k==2) nxt[j].S.S='_';

				if(nxt.back().F!='O' && nxt.back().S.F!='O' && nxt.back().S.S!='O')

					nxt.PB(Newlevel);

				auto &u=nxt.back();

				for(int l=0;l<3;l++) {

					if(l==0 && u.F  !='O') continue;

					if(l==1 && u.S.F!='O') continue;

					if(l==2 && u.S.S!='O') continue;

					if(l==0) u.F  =out;

					if(l==1) u.S.F=out;

					if(l==2) u.S.S=out;

					best=min(best, go(nxt));

					if(l==0) u.F  ='O';

					if(l==1) u.S.F='O';

					if(l==2) u.S.S='O';

				}

			}

		}

		if(best>INF/2)

			remain+=prob[i];

		else

			sum+=best*prob[i];

	}

	if(remain>.99) return re=0; // should not happen(?)

	re=(sum+1)/(1-remain);

	debug("--- %.10f  (%d) sum=%.10f  %.10f\n",re,++cnt,sum,remain);

	for(Level u:x) debug("%c, %c%c\n",u.F,u.S.F,u.S.S);

	return re;

}



int main() {

	int n; scanf("%d",&n);

	Tower init;

	for(int i=0;i<n;i++) {

		char s[10]; scanf("%s",s);

		Level x;

		x.F=s[1], x.S.F=s[0], x.S.S=s[2];

		init.PB(x);

	}

	//reverse(ALL(init));

	printf("%.10f\n",go(init));

	return 0;

}