#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18+7;

const ll MOD = 998244353;

typedef pair<ll,ll> ii;

#define iii pair<ll,ii>

#define ull unsigned ll

#define f(i,a,b) for(ll i = a;i < b;i++)

#define pb push_back

#define vll vector<ll>

#define F first

#define S second

#define all(x) (x).begin(), (x).end()

///I hope I will get uprating and don't make mistakes

///I will never stop programming

///sqrt(-1) Love C++

///Please don't hack me

///@TheofanisOrfanou Theo830

///Think different approaches (bs,dp,greedy,graphs,shortest paths,mst)

///Stay Calm

///Look for special cases

///Beware of overflow and array bounds

///Think the problem backwards

///Training

int main(void){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    ll t;

    cin>>t;

    while(t--){

        ll n,m;

        cin>>n>>m;

        string s;

        cin>>s;

        ll sum = 0;

        ll pre[n+1] = {0};

        f(i,0,n){

            sum += s[i] == '1';

            pre[i+1] = pre[i] + (s[i] == '1');

        }

        if((sum * m) % n != 0){

            cout<<-1<<"\n";

        }

        else{

            sum = (sum * m) / n;

            bool ok = 0;

            f(i,0,n - m + 1){

                if(pre[i + m] - pre[i] == sum){

                    ok = 1;

                    cout<<1<<"\n";

                    cout<<i+1<<" "<<i+m<<"\n";

                    break;

                }

            }

            if(!ok){

                cout<<2<<"\n";

                f(i,0,n){

                    if(pre[i+1] + pre[n] - pre[i+1+n - m] == sum){

                        ok = 1;

                        cout<<1<<" "<<i+1<<"\n";

                        cout<<i+2+n-m<<" "<<n<<"\n";

                        break;

                    }

                }

                assert(ok);

            }

        }

    }

}