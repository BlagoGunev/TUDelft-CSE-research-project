#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define RI(x) x = rit()
#define RII(a,b) a = rit(), b = rit()
#define RIII(a,b,c) a = rit(), b = rit(), c = rit()
#define REP(I, N) for(int I=0;I<(N);I++)
#define REPP(I, N) for(int I=1;I<=(N);I++)
#define SZ(x) (int)(x).size()
#define P pair<int, int>
#define F first
#define S second
#define PB(x) push_back(x)
#define endl "\n"
#define ll long long
#define DBAC(x,y) cout << x << " " << y << endl
#define int long long

//===================================================//

#define N 200000
#define modn 1000000007
#define INF 2147483647

using namespace std;
inline int rit(){
    int f=0,key=1;
    char ch;
    do{
        ch = getchar();
        if(ch=='-') key=-1;
    }while(ch<'0'||ch>'9');
    do{
        f = f*10+ch-'0';
        ch = getchar();
    }while(ch>='0'&&ch<='9');
    return f*key;
}
int n;
int arr[N+5], brr[N+5], sum ;
bool bye[1000005];
int32_t main(void){
    RI(n);
    REP(i,n){
        RI(arr[i]);
        sum+=arr[i];
        brr[i] = arr[i];
    }
    sort(arr, arr+n);
    REP(i,n-1){
        if( sum - arr[i] - arr[n-1] == arr[n-1] ){
            bye[ arr[i] ] = true;
        }
    }
    if( sum - arr[n-1] - arr[n-2] == arr[n-2] ) bye[ arr[n-1] ] = true;
    int cnt = 0;
    REP(i,n){
        if( bye[ brr[i] ] ) cnt++;
    }
    printf("%lld\n",cnt);
    REP(i,n) if( bye[ brr[i] ] ) printf("%lld%c",i+1," \n"[i==n-1]);
	return 0;
}