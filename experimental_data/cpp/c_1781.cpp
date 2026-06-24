#include<bits/stdc++.h>

#define rp(i,a,n) for(int i=a;i<n;i++)

#define rep(i,a,n) for(int i=a;i<=n;i++)

#define ll long long

#define int long long

#define deq vector<ll>

#define mii map<ll,ll>

#define pii pair<ll,ll>

#define pb push_back

#define f first

#define s second

#define sz(a) (int)a.size()

#define all(x) (x).begin(), (x).end()

#define lb(a,b) lower_bound((a).begin(),(a).end(),b)

const ll M = 1000000007;

using namespace std;



signed main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    cout << fixed << setprecision(20);



    int t = 1;

    cin >> t;



    while(t--){



        int n;

        cin >> n;

        string a;

        cin >> a;



        int cnt[26]={0};



        for(int i = 0; i < n; i++){

            cnt[a[i]-'a']++;

        }



        vector<pair<int,char>> letters;



        rp(i,0,26){

            letters.pb({cnt[i],(char)(i+'a')});

        }



        sort(all(letters));

        reverse(all(letters));



        int ans = LLONG_MAX,total;



        for(int i = 1; i <= 26;i++){

            if(n%i!=0)continue;

            

            int num =  n/i;

            int extra = 0,changes = 0;

            for(int j = 0; j < i; j++){

                if(letters[j].f>num){

                    extra+=(letters[j].f-num);

                    changes+=(letters[j].f-num);

                }

                else if(letters[j].f<num){

                    int y = num-letters[j].f;

                    if(extra>=y){

                        extra-=y;

                    }

                    else{

                        y-=extra;

                        extra = 0;

                        changes+=y;

                    }

                }

            }



            if(ans>changes){

                ans = changes;

                total = i;

            }

            

        }



        string ans1 = a;

        int freq = n/total;



        int to_remove[26] = {0};

        set<pair<int,char>> to_insert;



        for(int i = 0; i < 26; i++){

            int x = letters[i].f;

            char y = letters[i].s;

            if(i>=total){

                to_remove[y-'a'] = x;

                continue;

            }

            if(x>freq){

                to_remove[y-'a'] = x-freq;

            }

            else if(x<freq){

                to_insert.insert({x-freq, y});

            }

        }



        for(int i = 0; i < n; i++){

            if(to_remove[ans1[i]-'a']>0){

                to_remove[ans1[i]-'a']--;

                auto fg = *(to_insert.begin());

                to_insert.erase(to_insert.begin());

                ans1[i] = fg.s;

                to_insert.insert({fg.f+1,fg.s});

            }

        }



        cout << ans << "\n" << ans1 << "\n";



    }



    return 0;}