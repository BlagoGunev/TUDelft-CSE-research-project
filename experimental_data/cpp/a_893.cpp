#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pp pair <int ,int >
#define ppi pair < int , pair <int ,int > >
#define ull unsigned long long
#define INF (int)(1e9+7)
#define PI acos(-1)
#define f first
using namespace std;
int n;
int  x;
int rep;
int main()
{
    rep=3;
    int play1=1;
    int play2=2;
    scanf("%d",&n);
    for(int i(0);i<n;++i){
    scanf("%d",&x);
    if (x==rep){printf("NO");return  0;}
    else if(x==play1)swap(rep,play2);
    else swap(rep,play1);
    }
    printf("YES");
	return 0;
}