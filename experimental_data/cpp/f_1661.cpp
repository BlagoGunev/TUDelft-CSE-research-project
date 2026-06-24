//نفعكم الله ووفقكم -ادع لي-

//اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين

//اللهم اطمس على أعداء الدين والمدنسين -اليهود اللصوص-

//اللهم حرر فلسطين من كيد اليهود واجعل كيدهم

// Many thanks to Eng. Mahmoud (mfighter01) -ely mkan4 fahem satr el output by3ml eh bs ana sa3edtoh- 34an 4ara7ly el solution.

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

//                      dataType,     , sorting,   rbTreeType

#define multi_ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define numOf1sIntBin(n) __builtin_popcount(n)     //works for integers

#define getUnique(e) {sort(e.begin(),e.end());e.erase(unique(e.begin(),e.end()),e.end());}

#define PI 3.1415926535



template<class T>

bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

template<class T>

bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }



typedef long long ll;

const int N = 1e2+9, M = 2e5 + 6, MOD = 1e9+7, OO = 0x3f3f3f3f, SQR = 320;

const ll LOO = 0x3f3f3f3f3f3f3f3f;

const long double eps = 1e-7;

int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};

int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};

bool valid(int x, int y, int nnn, int mmm){return x>=0&&x<nnn&&y>=0&&y<mmm;}

int Log2(int x){return 31-__builtin_clz(x);}

ll cost(int length, int cnt){

    int p1=length/cnt;

    int p2=p1+1;

    int rem2=length%cnt;

    int rem1=cnt-rem2;

    return 1ll*p1*p1*rem1 + 1ll*p2*p2*rem2;

}

pair<ll, ll> check(ll costChange, deque<int>&arr){

    ll ansC=0, ansP=0;

    for(int i=0;i<arr.size();i++){

        int st=1, e=arr[i]-1, mid, temp=0;

        while(st<=e){

            mid=(st+e)>>1;

            if(cost(arr[i], mid) - cost(arr[i], mid+1) >= costChange){

                temp=mid;

                st=mid+1;

            }

            else e=mid-1;

        }

        ansP+=temp;

        ansC+= cost(arr[i], temp+1);

    }

    return {ansC, ansP};

}

void TT(){

    int n;

    cin>>n;

    deque<int>arr(n);

    for(auto &x:arr) cin>>x;



    for(int i=n-1;i;i--) arr[i]-=arr[i-1];

    arr.push_front(0);

    ll m;

    cin>>m;

    pair<ll, ll>ans;

    ll st=1, e=m, mid, k;

    while(st<=e){

        mid=(st+e)>>1;

        auto temp=check(mid, arr);

        if(m>=temp.first){

            ans=temp;

            st=mid+1;

            k=mid;

        }

        else e=mid-1;

    }

    cout<<ans.second-(m-ans.first)/k<<endl;

}

int main() {

//    freopen("input.txt","r",stdin);

//    freopen("output.txt","w",stdout);

    FAST

    int testCases = 1;

//    cin>>testCases;

    while (testCases--) TT();

    clock_t tStart = clock();

    cerr << fixed << setprecision(10) << "Time Taken: " << (double) (clock() - tStart) / CLOCKS_PER_SEC << endl;



    return 0;

}

// You Got this! Bear those in your mind:

//      * BrainStorm & Think Twice, code once.

//      * Overcome Corner Cases.