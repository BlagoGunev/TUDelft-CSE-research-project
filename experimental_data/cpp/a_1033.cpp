#include<bits/stdc++.h>
using namespace std;

#define all(c) c.begin(), c.end()
#define pb push_back
#define Size(c) (int)c.size()
#define fi first
#define se second
#define clr(v, d) memset(v, d, sizeof(v))
#define mp make_pair

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef pair<int, pair<int, int> > iii;
typedef vector<iii> vii;
typedef long long ll;
typedef long double Double;
const ll MOD = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 0x3f3f3f3f;



int main(){
    // freopen("input.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a1, a2, b1, b2, c1, c2;
    cin>>n;
    cin>>a1>>a2;
    cin>>b1>>b2;
    cin>>c1>>c2;

    if(b1<a1 && c1<a1 && b2<a2 && c2<a2){
        cout<<"YES"<<endl;
    }else if(b1<a1 && c1<a1 && b2>a2 && c2>a2){
        cout<<"YES"<<endl;
    }else if(b1>a1 && c1>a1 && b2>a2 && c2>a2){
        cout<<"YES"<<endl;
    }else if(b1>a1 && c1>a1 && b2<a2 && c2<a2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}

//RT => 
//TT => 
//CT => 
//DT =>