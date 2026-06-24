#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef long long int lli;

#define tst int t=0;cin>>t; while(t--)

#define forn(n) for(int i=0; i<n; i++)

#define fornn(n) for(int j=0; j<n; j++)

#define cin(vec) for(auto& i : vec) cin >> i

#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";

#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";

#define fixed(n)  cout<<fixed << setprecision(n);

#define all(vec) vec.begin(),vec.end()

#define rall(vec) vec.rbegin(),vec.rend()

#define sz size()

#define PI 3.14159265359

#define pb push_back

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

vector<ll>v;

vector<int>v2;

vector<int>b;

int d,n=1000000;

     void sieve()

     {map<int,bool>mp;

     mp[2]=0;

     for(int i=2;i<=n;i++)

     {

         if(mp[i]==0)

         {

             for(int j=i+i;j<=n;j+=i)

                mp[j]=1;

         }



     }

     mp[0]=1,mp[1]=1;

     forn(n)

     {

         if(!mp[i])

            v.pb(i);

     }

     }

     int a[110][110];

    void FAST()

    {

        ios_base::sync_with_stdio(0);

        cout.tie(0);

        cin.tie(0);



    }

    void file()

    {

        freopen("cases.in", "r", stdin);

    }



                    int main() {

                        FAST();

                    tst{

                    int n,d;

                    cin>>n>>d;

                    v.resize(n);

                    cin(v);

                    forn(n)

                    {

                        bool ok=0;

                        int x=v[i];

                        x%=d;

                        if(x==0)

                        {

                            ok=1;

                        }

                        while(x!=0&&x<v[i])

                        {

                            x+=d;

                            int z=x;

                            while(z)

                            {

                                if(z%10==d)

                                {

                                    ok=1;

                                    break;

                                }

                                z/=10;

                            }

                            if(ok)

                                break;

                        }

                        if(ok)

                            cout<<"YES\n";

                        else

                            cout<<"NO\n";



                    }



                    }



                    }