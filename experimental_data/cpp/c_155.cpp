#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef long long LL;

typedef pair<int,int> ii;

typedef vector<ii> vii;

typedef vector<int> vi;



#ifdef DEBUG

    #define cek(x) cout<<x

#else

    #define cek(x) if(false){}

#endif // DEBUG



#define fi first

#define se second

#define INF 1000000000

#define INFLL 1000000000000000000LL

#define EPS 1e-9

#define PI acos(-1.0)

#define pb push_back

#define TC() while(tc--)

#define FOR(i,n) for(int i=0;i<n;i++)

#define FORN(i,n) for(int i=0;i<=n;i++)

#define REP(i,a,b) for(int i=a;i<b;i++)

#define REPN(i,a,b) for(int i=a;i<=b;i++)

#define reset(a,b) memset(a,b,sizeof(a))

#define sc(x) scanf("%d",&x)



int main(void){

    char str[100010];

    map<char, char> forbidden;

    char forb[10];

    scanf("%s", str);

    int len = strlen(str);

    int k;

    sc(k);

    FOR(i,k){

        scanf("%s", forb);

        forbidden[forb[0]] = forb[1];

        forbidden[forb[1]] = forb[0];

    }



    int tot = 0;

    int ct[27];

    reset(ct,0);

    char bef = '-';

    FOR(i,len){

        if(bef != str[i]){

            if(forbidden.find(bef) == forbidden.end()){

                //not forbidden at all.

                reset(ct, 0);

                ct[str[i]-'a']++;

            }else{

                if(forbidden[bef] == str[i]){

                    //still in a group.

                    ct[str[i]-'a']++;

                }else{

                    //diff group.

                    tot += min(ct[bef-'a'], ct[forbidden[bef]-'a']);

                    reset(ct, 0);

                    ct[str[i]-'a']++;

                }

            }

            bef = str[i];

        }else{

            ct[str[i]-'a']++;

        }

    }



    if(forbidden.find(bef) != forbidden.end()){

        tot += min(ct[bef-'a'], ct[forbidden[bef]-'a']);

    }





    cout << tot << endl;



    return 0;

}