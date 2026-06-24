#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define M 100001
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main(){
    fast;
    int t,a,b,c,d,e,x1,x2;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>e;
        x1=a/c+((a%c==0)?0:1);
        x2=b/d+((b%d==0)?0:1);
        if((x1+x2)<=e){
            cout<<x1<<" "<<x2<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}