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

const ll MOD = 998244353;

const ll NO_OPERTATION = -1;

const double eps = 1e-8;

const int MAX = 200000 + 10;

const int LOG = 20;







int main ()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin>>t;

    while(t--)

    {

        ll n;

        cin>>n;

        vector<ll> v(n); read(v);

        ll resp = LINF;

        stack<pii> s;

        vector<ll> pref(n+1);

        vector<ll> suf (n+1);

        for(int i=0;i<n;i++){pref[i+1]=pref[i]+v[i];}

        vector<ll> respE(n), respD(n);

        for(int i=0;i<n;i++){suf[i+1]=suf[i]+v[n-1-i];}

        for(ll i=0;i<n;i++) // Montando o respE

        {

            pii quem = {-1,-1};

            while(s.size()>0)

            {

                pii topo = s.top();

                if(v[i]-(i-topo.s)<=0){break;}

                if(topo.f<v[i]-i)

                {

                    quem = topo;

                    break;

                }

                else{s.pop();}

            }

            if(quem.s != -1)

            {

              //  cout<<respE[quem.s]<<" olha "<<v[quem.s]<<endl;

                respE[i] = respE[quem.s]-v[quem.s] + v[i] + pref[i+1] - pref[quem.s+1] - ((v[i]+(v[i]-(i-quem.s-1)))*(i-quem.s))/2;

            }

            else

            {

                ll vou = min(v[i]-1,i);

                respE[i] =v[i]+ pref[i+1] - pref[i-vou] - (((v[i]+(v[i]-vou)))*(vou+1))/2;

                respE[i] += pref[i-vou];

            }

            s.push({v[i]-i,i});

        //  cout<<i<<" "<<respE[i]<<endl;

        }

        //cout<<endl;

        while(s.size()>0){s.pop();}

        for(ll i=n-1;i>=0;i--) // Montando o respD -> tenho que pensar um pouco

        {

            ll j = n-i-1;

            pii quem = {-1,-1};

            while(s.size()>0)

            {

                pii topo = s.top();

                if(v[i]-(j-topo.s)<=0){break;}

                if(topo.f<v[i]-j)

                {

                    quem = topo;

                    break;

                }

                else{s.pop();}

            } //certo ate aqui

            if(quem.s != -1)

            {

                respD[i] = respD[abs(quem.s-n+1)]-v[abs(quem.s-n+1)] + v[i] + suf[j+1] - suf[quem.s+1] - ((v[i]+(v[i]-(j-quem.s-1)))*(j-quem.s))/2;

            }

            else

            {

                ll vou = min(v[i]-1,j);

              //  cout<<"veja => "<<v[i]<<" "<<suf[j+1]<<" "<<(((v[i]+(v[i]-vou)))*(vou+1))/2<<endl;

                respD[i] = v[i]+ suf[j+1] - suf[j-vou] - (((v[i]+(v[i]-vou)))*(vou+1))/2;

                respD[i] += suf[j-vou];

            //    cout<<"OI"<<endl;

            }

            s.push({v[i]-j,j});

           // cout<<i<<" "<<respD[i]<<endl;

        }

       // cout<<endl;

        for(int i=0;i<n;i++)

        {

           // cout<<i<<" "<<respE[i]<<" "<<respD[i]<<endl;

            resp=min(resp,respE[i]+respD[i]-v[i]);

        }

        cout<<resp<<endl;

    }

    return 0;

}