/*********************
*@Author:   CKang *
*@Language: C++11    *
*********************/
#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
//#define DEBUG
#define RI register int
#define endl "\n"

using namespace std;

typedef long long ll;
//typedef __int128 lll;
//const int N=100000+10;
const int M=100000+10;
const int MOD=1e9+7;
const double PI = acos(-1.0);
const double EXP = 1E-9;
const int INF = 0x3f3f3f3f;

inline ll read(){
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int main()
{
#ifdef DEBUG
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout)
#endif
    //cout.tie(0);
    ll t = read() ;
    while(t--){
       ll n=read();
       int ans = 4*100000;
       int nums[n+5]={0};

       for(int i=1;i<=n;i++){
            int tmp=read();
            if(nums[tmp]==0)nums[tmp]=i;
            else {
                ans=min(ans,i-nums[tmp]+1);
                nums[tmp]=i;
            }
       }
       if(n==1){
            puts("-1");
            continue;
       }
       else if (ans!=4*100000)printf("%d\n",ans);
       else printf("-1\n");
    }

#ifdef DEBUG
    printf("Time cost : %lf s\n",(double)clock()/CLOCKS_PER_SEC);
#endif
    //cout << "Fuck You !" << endl;
    return 0;
}