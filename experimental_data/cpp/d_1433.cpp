#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int Ull;
typedef pair<int ,int> PII;
template <typename T>
inline T  read()
{
    char c=getchar();
    T x=0,f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
template <typename T>
inline void write(T x) 
{
    if(x < 0) x = (~x) + 1, putchar('-');
    if(x / 10) write(x / 10);
    putchar(x % 10 | 48);
}
const int INF = 0x3f3f3f3f;
const ll N = 1e5+10;
int arr[5005];
//int vis[5005];
int main(){
    //ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int t = read<int>();
    while(t--){
        int n = read<int>();
        for(int i = 1; i <= n; i++) arr[i] = read<int>();
        bool flag = 0;
        int ii;
        for(int i = 1; i <= n; i++){
            if(arr[i] != arr[1]){
                flag = 1;
                ii = i;
                break;
            }
        }
        if(!flag) printf("NO\n");
        else{
            //memset(vis,0,sizeof(vis));
            //vis[1] = 1;
            printf("YES\n");
            for(int i = 2; i <= n; i++){
                if(arr[i] != arr[1]) printf("1 %d\n",i);
                else printf("%d %d\n",ii,i);
            }
        }
    }
}