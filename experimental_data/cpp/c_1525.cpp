#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nd "\n"

#define all(x) (x).begin(), (x).end()

#define lol cout <<"i am here"<<nd;

#define py cout <<"YES"<<nd;

#define pp  cout <<"ppppppppppppppppp"<<nd;

#define pn cout <<"NO"<<nd;

#define ld long double

#define popcount(x)  __builtin_popcount(x)

#define make_unique(go)go.resize(unique(all(go))-go.begin())

#define clz(n) __builtin_clz(n)//31 -x

const  double PI = acos(-1.0);

double EPS = 1e-9;

#define mem(v,d)    memset(v,d,sizeof(v));

#define print2(x , y) cout <<x<<' '<<y<<nd;

#define print3(x , y , z) cout <<x<<' '<<y<<' '<<z<<nd;

#define watch(x) cout << (#x) << " = " << x << nd;

#define ull unsigned long long

template<class container>

void print(container v) { for (auto& it : v) cout << it<< ' '; cout << '\n'; }



void printpr(priority_queue<ll>&arr){ while(!arr.empty()){ cout <<arr.top()<<" "; arr.pop();}cout <<nd;}

const int N = 2e6+100;



ll fp(ll a , ll p){

    if(!p) return 1;

    ll v = fp(a , p>>1);

    v*=v;

    if(p & 1) v*=a;

    return v;

}



struct Robot{

    ll at  , idx ; char d;

    Robot(){};

    Robot(ll a , ll b , char x){

       at = a , idx = b; d = x;

    }

    bool operator < (const Robot & other) const{

        return other.at> at;

    }

    void ppp(){

        print3(at , idx , d);

    }

};



void solve(){

    ll n , limit; cin >>n>>limit;

    vector<Robot>arr(n);

    for (int i = 0; i < n; ++i)cin >>arr[i].at, arr[i].idx = i;



    vector<int>ans(n , -1);

    for (int i = 0; i < n; ++i) cin >>arr[i].d; sort(all(arr));



    auto calcLL =[&] (ll a , ll b)-> ll{

        return (a+b)/2;

    };

    auto calcRR=[&](ll a , ll b)->ll{

        return (2 *limit- (a+b))/2;

    };

    auto calcLR=[&](ll a , ll b)->ll{

        return  (2 *limit+a-b)/2;

    };

    auto calcRL=[&](ll a , ll b)->ll{

        return (b-a)/2;

    };

  ////  cout <<calcLL(2 , 6)<<' '<<calcRR(2 , 6)<<' '<<calcLR(2 , 6)<<nd;

  ///  for (int i = 0; i < n; ++i) arr[i].ppp();

    vector<Robot>odd , Evv;

    for (int i = 0; i  < n;++i){



       if(arr[i].at & 1){

           if (odd.empty()){

               odd.emplace_back(arr[i].at , arr[i].idx , arr[i].d);

           }

           else

           {

              if(arr[i].d == odd.back().d)

              {

                  if(arr[i].d == 'L'){

                      ll x = calcLL(odd.back().at , arr[i].at);

                      ans[arr[i].idx] = ans[odd.back().idx] = x;

                      odd.pop_back();

                  }

                  else{

                      odd.emplace_back(arr[i].at , arr[i].idx , arr[i].d);

                  }



              }else

              {

                  if (arr[i].d == 'L'){// RL

                      ll x= calcRL(odd.back().at , arr[i].at);

                      ans[arr[i].idx] = ans[odd.back().idx] = x;

                      odd.pop_back();

                  }

                  else



                  {// LR

                      odd.emplace_back(arr[i].at , arr[i].idx , arr[i].d);

                  }

              }



           }





       }else{

           if (Evv.empty()){

               Evv.emplace_back(arr[i].at , arr[i].idx , arr[i].d);

           }

           else

           {

               if(arr[i].d == Evv.back().d)

               {

                   if(arr[i].d == 'L')

                   {

                       ll x = calcLL(Evv.back().at , arr[i].at);

                       ans[arr[i].idx] = ans[Evv.back().idx] = x;

                       Evv.pop_back();

                   }else

                   {

                       Evv.emplace_back(arr[i].at , arr[i].idx , arr[i].d);

                   }



               }else{

                   if (arr[i].d == 'L')

                   {// RL

                       ll x= calcRL(Evv.back().at , arr[i].at);

                       ans[arr[i].idx] = ans[Evv.back().idx] = x;

                       Evv.pop_back();

                   }

                   else

                   {// LR

                       Evv.emplace_back(arr[i].at , arr[i].idx , arr[i].d);

                   }

               }



           }





       }



    }

   // pp;

  // for (int i = 0; i < (int)odd.size(); ++i) odd[i].ppp();

  /// cout << odd.size()<<nd;

 //   lol;

  ///for (int i = 0; i < (int)Evv.size(); ++i) Evv[i].ppp();

   /// pp;



    while ((int)odd.size() > 1){

        auto top1 = odd.back(); odd.pop_back();

        auto top2 = odd.back() ; odd.pop_back();

         if(top1.d== 'R' && top2.d == 'L'){// LR

             ll x = calcLR(top2.at , top1.at);

             ans[top2.idx] = ans[top1.idx] = x;

         }

         else if(top1.d == 'L' && top2.d == 'R'){

             ll x = calcRL(top2.at , top1.at);

             ans[top2.idx] = ans[top1.idx] = x;

         }

         else if (top1.d == 'L' ){

            ll x = calcLL(top2.at , top1.at);

            ans[top2.idx] = ans[top1.idx] = x;

        }else if(top1.d == 'R' ){

            ll x= calcRR(top2.at , top1.at);

            ans[top2.idx] = ans[top1.idx] = x;

        }

    }



    while ((int)Evv.size() > 1){

        auto top1 = Evv.back(); Evv.pop_back();

        auto top2 = Evv.back() ; Evv.pop_back();

        if(top1.d== 'R' && top2.d == 'L'){// LR

            ll x = calcLR(top2.at , top1.at);

            ans[top2.idx] = ans[top1.idx] = x;

        }

        else if(top1.d == 'L' && top2.d == 'R'){

            ll x = calcRL(top2.at , top1.at);

            ans[top2.idx] = ans[top1.idx] = x;

        }

        else if (top1.d == 'L' ){

            ll x = calcLL(top2.at , top1.at);

            ans[top2.idx] = ans[top1.idx] = x;

        }else if(top1.d == 'R' ){

            ll x= calcRR(top2.at , top1.at);

            ans[top2.idx] = ans[top1.idx] = x;

        }



    }



    print(ans);

















}



int main(){

    //create();

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("army.in","r",stdin);

    // freopen("output.txt","w",stdout);

    int t =1;cin >>t;

    while(t--)

        solve();

#ifndef ONLINE_JUDGE

    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";

#endif

    return 0;

}