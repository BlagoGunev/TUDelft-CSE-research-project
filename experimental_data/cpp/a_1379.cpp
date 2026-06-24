#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<stack>
#include<ctime>
#define forin(i,a,n) for(int i=a;i<=n;i++)
#define forni(i,n,a) for(int i=n;i>=a;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
const double eps=1e-7;
const int N=4e5+7 ,M=1e7+7 , INF=0x3f3f3f3f,mod=1e9+7;
inline ll read() {ll x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
while(c>='0'&&c<='9') {x=(ll)x*10+c-'0';c=getchar();} return x*f;}
void stin() {freopen("in_put.txt","r",stdin);freopen("my_out_put.txt","w",stdout);}

template<typename T> T gcd(T a,T b) {return b==0?a:gcd(b,a%b);}
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}

int T;
int n,m,k;
char str[60];
string temp="abacaba";

void solve() {  
    n=read();
    
    scanf("%s",str+1);
    
    int cnt=0;
    for(int i=1;i+6<=n;i++) {
        int j;
        for(j=0;j<7;j++) {
            if(str[i+j]!=temp[j]) {
                break;
            }
        }
        if(j==7) cnt++;
    }
    
    if(cnt>=2) printf("No\n");
    else if(cnt==1) {
        printf("Yes\n");
        for(int i=1;i<=n;i++) {
            if(str[i]=='?') printf("z");
            else printf("%c",str[i]);
        }
        printf("\n");
    }else {
        bool flag=false;
        for(int i=1;i+6<=n;i++) {
            vector<int> vec;
            int j;
            for(j=0;j<=6;j++) {
                if(str[i+j]!=temp[j]) {
                    if(str[i+j]!='?') {
                        break;
                    }else vec.push_back(i+j),str[i+j]=temp[j];
                }
            }
            
            if(j==7) {
                int res=0;
                for(int p=i-6;p<=i+6;p++) {
                    int l=p,r=l+6;
                    if(l>=1&&l<=n&&r>=1&&r<=n) {
                        int s,oi;
                        for(s=l,oi=0;s<=r;s++,oi++) {
                            if(str[s]!=temp[oi]) {
                                break;
                            }
                        }
                        if(s>r) res++;
                    }
                }
                
                if(res==1) flag=true;
            }
            
            if(flag) break;
            
            for(int k=0;k<vec.size();k++) str[vec[k]]='?';
        }
        
        if(flag) {
            printf("Yes\n");
            for(int i=1;i<=n;i++) {
                if(str[i]=='?') printf("z");
                else printf("%c",str[i]);
            }
            printf("\n");
        }else printf("No\n");
    }
}

int main() {
    // init();
    // stin();
    
    scanf("%d",&T);
    // T=1; 
    while(T--) solve();
    
    return 0;   
}