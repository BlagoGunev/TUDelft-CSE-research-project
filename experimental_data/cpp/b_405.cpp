#include <bits/stdc++.h>

#define F first

#define S second

#define pb push_back

#define P push

#define B begin()

#define E end()

#define SI size()

#define R return

#define C continue

#define W while

#define SF(x) scanf("%I64d",&x);

#define MEM(vis,i) memset(vis,i,sizeof(vis))

#define rep(i,x,n) for(int i=x;i<n;i++)

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

const long long MOD = 1e9+7;

const long long MAX = 1e14+8;

const long long MAXN = 1e5+8;



bool vis[3001];

int main(){

ll n;

cin>>n;

string s;

cin>>s;

ll res=0;

bool b=0;



for(int i=0;i<n;i++){

    if(s[i]=='L'||s[i]=='R'){

    b=1;

    }

    if(s[i]=='R'){

        for(int j=i+1;j<n;j++){

            if(s[j]=='L'){

                if((j-i)%2==0)

                res++;

                break;

            }

            if(s[j]=='R')

                break;

        }

    }

    if(s[i]=='L'){

        for(int j=i+1;j<n;j++){

            if(s[j]=='R'){

                res+=j-i-1;

                break;

            }

            if(s[j]=='L')

                break;

        }

    }

}

for(int i=0;i<n;i++){



    if(s[i]=='R'){

        res+=i;

        break;

    }

    if(s[i]=='L'){

        break;

    }

}

if(!b){

    cout<<n;

    R 0;

}

for(int i=n-1;i>=0;i--){

    if(s[i]=='L'){

        res+=n-i-1;

        break;

    }

    if(s[i]=='R'){

        break;

    }

}

cout<<res;



    return 0;

}