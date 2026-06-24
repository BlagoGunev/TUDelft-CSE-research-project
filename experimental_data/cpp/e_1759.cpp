#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <functional>

using namespace __gnu_pbds;

using namespace std;



#define endl "\n"

typedef long long ll;

#define rip(i,a,b) for(ll i=a; i<b; i++)

#define f(i,n) for(ll i=0; i<n; i++)

#define f1(i,n) for(ll i=1; i<=n; i++)

#define rf(i,n) for(ll i=n-1; i>=0; i--)

#define c(n) cout<<n<<endl;

#define cin(arr,n) f(i,n){cin>>arr[i];}

#define prs(n) cout<<n<<' '; 

#define pb push_back

#define ppb pop_back



#define vl vector<ll> 

#define lb lower_bound

#define ub upper_bound

#define cinv(v,n) f(i,n){ll var;cin>>var;v.pb(var);}

#define vp vector<pair<ll,ll>> 

#define yes cout<<"Yes"<<endl;

#define no cout<<"No"<<endl;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;





//------------------------Actual Code Starts Here-----------







void solve(){

      ll n,k;cin>>n>>k;

      ll a[n];f(i,n){cin>>a[i];}sort(a,a+n);

      ll arr[3]={2,2,3};

      ll ans=0;

      do{

        ll val=k;ll ct=0;ll ans1=0;

        f(i,n){

            if(a[i]<val){

              val+=a[i]/2;ans1++;

            }

            else{

              while(a[i]>=val&& ct<=2){

                val*=arr[ct];

                ct++;

              }

              if(val>a[i]){

                val+=a[i]/2;ans1++;

              }

             else {break;}

            }

        }

        ans=max(ans,ans1);



      }while(next_permutation(arr,arr+3));

    cout<<ans<<endl;

}



signed main(){

 //faster input and output

std::ios::sync_with_stdio(false);

std::cin.tie(0);

ll t;

cin>>t;

while(t--){

     solve();

  }

  return 0;

}







 //        "***TIPS***"

//Always remember to assign new things earlier.. otherwise it can show WA ,  eg. define sqrt earlier as another variable like ll x=sqrt(a)

//Always prefer to use ll instead of ll .. it will better for every case





// #include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>

// #include <ext/pb_ds/tree_policy.hpp>

// #include <functional>

// using namespace __gnu_pbds;

// using namespace std;



// #define endl "\n"

// typedef long long ll;

// #define rip(i,a,b) for(ll i=a; i<b; i++)

// #define f(i,n) for(ll i=0; i<n; i++)

// #define f1(i,n) for(ll i=1; i<=n; i++)

// #define rf(i,n) for(ll i=n-1; i>=0; i--)

// #define c(n) cout<<n<<endl;

// #define cin(arr,n) f(i,n){cin>>arr[i];}

// #define prs(n) cout<<n<<' '; 

// #define pb push_back

// #define ppb pop_back



// #define vl vector<ll> 

// #define lb lower_bound

// #define ub upper_bound

// #define cinv(v,n) f(i,n){ll var;cin>>var;v.pb(var);}

// #define vp vector<pair<ll,ll>> 

// #define yes cout<<"Yes"<<endl;

// #define no cout<<"No"<<endl;

// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;





// //------------------------Actual Code Starts Here-----------







// void solve(){

//       ll n,k;cin>>n>>k;

//       vl a(n);

//       ll it=0,it1=0,it2=0;

//       f(i,n){

//         cin>>a[i];

//         if(a[i]==1){it++;it1++;it2++;}

//       }

//       sort(a.begin(),a.end());

//       if(it==n){cout<<it<<endl;return;}

//       vl v(a.begin()+it,a.end());

//       ll val=k;

//       ll h2=0,h3=0;

//       //2 2 3

//       f(i,v.size()){

//         if(val>v[i]){

//            val+=v[i]/2;

//         }

//         else if(val*2>v[i]&&h2<2){

//           val*=2; val+=v[i]/2;h2++;

//         }

//         else if(val*3>v[i]&&h3==0&&h2==2){

//           val*=3;val+=v[i]/2;h3++;

//         }

//         else if(val*4>v[i]&&h2==0){

//           val*=4;val+=v[i]/2;h2+=2;

//         }



//         else if(val*12>v[i]&&h2==0&&h3==0){

//           val*=12;val+=v[i]/2;h2+=2;h3++;

//         }

//         else{

//           break;

//         }

//         it++;

//       } 

//       val=k;h2=0,h3=0;

//       // 3 2 2

//       f(i,v.size()){

//         if(val>v[i]){

//            val+=v[i]/2;

//         }

//         else if(val*3>v[i]&&h3==0){

//           val*=3;val+=v[i]/2;h3++;

//         }

//         else if(val*2>v[i]&&h2<2&& h3==1){

//           val*=2; val+=v[i]/2;h2++;

//         }

//         else if(val*4>v[i]&&h2==0&&h3==1){

//           val*=4;val+=v[i]/2;h2+=2;

//         }

//         else if(val*6>v[i]&&h2<2&&h3==0){

//           val*=6;val+=v[i]/2;h2++;h3++;

//         }

//         else if(val*12>v[i]&&h2==0&&h3==0){

//           val*=12;val+=v[i]/2;h2+=2;h3++;

//         }

//         else{

//           break;

//         }

//         it1++;

//       } 

//        val=k;h2=0,h3=0;

//        // 2 3 2

//       f(i,v.size()){

//         if(val>v[i]){

//            val+=v[i]/2;

//         }

//         else if(val*2>v[i]&&h2<2){

//           val*=2; val+=v[i]/2;h2++;

//         }

//         else if(val*3>v[i]&&h3==0&& h2==1){

//           val*=3;val+=v[i]/2;h3++;

//         }

//         else if(val*6>v[i]&&h2<2&&h3==0){

//           val*=6;val+=v[i]/2;h2++;h3++;

//         }

//         else if(val*12>v[i]&&h2==0&&h3==0){

//           val*=12;val+=v[i]/2;h2+=2;h3++;

//         }

//         else{

//           break;

//         }

//         it2++;

//       } 

//       cout<<max(it1,max(it2,it))<<endl;



  

// }



// signed main(){

//  //faster input and output

// std::ios::sync_with_stdio(false);

// std::cin.tie(0);

// ll t;

// cin>>t;

// while(t--){

//      solve();

//   }

//   return 0;

// }







//  //        "***TIPS***"

// //Always remember to assign new things earlier.. otherwise it can show WA ,  eg. define sqrt earlier as another variable like ll x=sqrt(a)

// //Always prefer to use ll instead of ll .. it will better for every case



// // #include<bits/stdc++.h>

// // using namespace std;



// // #define endl "\n"

// // typedef long long ll;

// // #define rip(i,a,b) for(ll i=a; i<b; i++)

// // #define f(i,n) for(ll i=0; i<n; i++)

// // #define f1(i,n) for(ll i=1; i<=n; i++)

// // #define rf(i,n) for(ll i=n-1; i>=0; i--)

// // #define c(n) cout<<n<<endl;

// // #define cin(arr,n) f(i,n){cin>>arr[i];}

// // #define prs(n) cout<<n<<' '; 

// // #define pb push_back

// // #define ppb pop_back



// // #define vl vector<ll> 

// // #define cinv(v,n) f(i,n){ll var;cin>>var;v.pb(var);}

// // #define vp vector<pair<ll,ll>> 

// // //------------------------Actual Code Starts Here-----------



// // void solve(){

// //         ll n;cin>>n;

// //         ll h;cin>>h;

// //         ll hh=h;

// //         ll a[n];

// //         f(i,n){cin>>a[i];}

// //         sort(a,a+n);

// //         ll ct1=0,ct2=0;

// //         ll ct=0,ctt=0;

// //         f(i,n){

// //           if(a[i]<h){

// //             h+=a[i]/2;

// //           }

// //           else if(a[i]<3*h&&ct2<1){

// //             h*=3;

// //             h+=a[i]/2;

// //             ct2++;

// //           }

// //           else if(a[i]<2*h&& ct1<2){

// //             h*=2;ct1++;

// //             h+=a[i]/2;

// //           }

// //           // else if(a[i]<3*h&&ct2<1){

// //           //   h*=3;

// //           //   h+=a[i]/2;

// //           //   ct2++;

// //           // }

// //           else if(a[i]<4*h&& ct1<1){

// //             h*=4;

// //             h+=a[i]/2;

// //             ct1+=2;

// //           }

// //           else if(a[i]<6*h&& ct1<2&&ct2<1){

// //               h*=6;

// //             h+=a[i]/2;

// //             ct1+=1;ct2++;

// //           }

// //           else if(a[i]<12*h&& ct1<1&&ct2<1){

// //               h*=12;

// //             h+=a[i]/2;

// //             ct1+=2;ct2++;

            

// //           }

// //           else{

// //             break;

// //           }

// //           // cout<<h<<"-";

// //           ct++;

// //         }

// //         ct1=0,ct2=0;

// //         f(i,n){

// //           if(a[i]<hh){

// //             hh+=a[i]/2;

// //           }

         

// //           else if(a[i]<2*hh&& ct1<2){

// //             hh*=2;ct1++;

// //             hh+=a[i]/2;

// //           }

// //           else if(a[i]<3*hh&&ct2<1){

// //             hh*=3;

// //             hh+=a[i]/2;

// //             ct2++;

// //           }

// //           else if(a[i]<4*hh&& ct1<1){

// //             hh*=4;

// //             hh+=a[i]/2;

// //             ct1+=2;

// //           }

// //           else if(a[i]<6*hh&& ct1<2&&ct2<1){

// //               hh*=6;

// //             hh+=a[i]/2;

// //             ct1+=1;ct2++;

// //           }

// //           else if(a[i]<12*hh&& ct1<1&&ct2<1){

// //               hh*=12;

// //             hh+=a[i]/2;

// //             ct1+=2;ct2++;

            

// //           }

// //           else{

// //             break;

// //           }

// //           // cout<<hh<<"-";

// //           ctt++;

// //         }

// //         // cout<<ct<<endl;

// //         cout<<max(ct,ctt)<<endl;

  

// // }



// // signed main(){

// //  //faster input and output

// // std::ios::sync_with_stdio(false);

// // std::cin.tie(0);

// // ll t;

// // cin>>t;

// // while(t--){

// //      solve();

// //   }

// //     return 0;

// // }







// //  //        "***TIPS***"

// // //Always remember to assign new things earlier.. otherwise it can show WA ,  eg. define sqrt earlier as another variable like ll x=sqrt(a)

// // //Always prefer to use ll instead of ll .. it will better for every case