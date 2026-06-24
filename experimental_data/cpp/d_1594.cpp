#include<bits/stdc++.h>
using namespace std;
void show(){std::cerr << endl;}template<typename T,typename... Args>void show(T x,Args... args){std::cerr << "[ " << x <<  " ] , ";show(args...);}
typedef long long ll;
const int MAX = 2e5+50;
const int MOD = 1e9+7;

namespace Fast_IO{ ///orz laofu
    const int MAXL((1 << 18) + 1);int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],*iooS=ioof,*iooT=ioof+MAXL-1,ioc,iost[55];
    char Getchar(){
        if (ioiS == ioiT){
            ioiS=ioif;ioiT=ioiS+fread(ioif,1,MAXL,stdin);return (ioiS == ioiT ? EOF : *ioiS++);
        }else return (*ioiS++);
    }
    void Write(){fwrite(ioof,1,iooS-ioof,stdout);iooS=ioof;}
    void Putchar(char x){*iooS++ = x;if (iooS == iooT)Write();}
    inline int read(){
        int x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    inline long long read_ll(){
        long long x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    /**
    #define lll __int128
    inline lll read_lll(){
        lll x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }*/
    template <class Int>void Print(Int x, char ch = '\0'){
        if(!x)Putchar('0');if(x<0)Putchar('-'),x=-x;while(x)iost[++iotp]=x%10+'0',x/=10;
        while(iotp)Putchar(iost[iotp--]);if (ch)Putchar(ch);
    }
    void Getstr(char *s, int &l){
        for(ioc=Getchar();ioc==' '||ioc=='\n'||ioc=='\t';)ioc=Getchar();
        if(ioc==EOF)exit(0);
        for(l=0;!(ioc==' '||ioc=='\n'||ioc=='\t'||ioc==EOF);ioc=Getchar())s[l++]=ioc;s[l] = 0;
    }
    void Putstr(const char *s){for(int i=0,n=strlen(s);i<n;++i)Putchar(s[i]);}
} // namespace Fast_IO
using namespace Fast_IO;

int col[MAX];
int fa[MAX];
int cnt[MAX];

int find_fa(int x){
    if(x == fa[x])return x;
    return fa[x] = find_fa(fa[x]);
}

bool sam(int x,int y){
    return find_fa(x) == find_fa(y);
}

vector<int>TONG[MAX];

void add(int x,int y){
    int fx = find_fa(x);
    int fy = find_fa(y);
    if(fx != fy){
        if(cnt[fx] < cnt[fy]){
            for(auto it : TONG[fx]){
                TONG[fy].push_back(it);
            }
            TONG[fx].clear();
            fa[fx] = fy;
            cnt[fy] += cnt[fx];
        }else{
            for(auto it : TONG[fy]){
                TONG[fx].push_back(it);
            }
            TONG[fy].clear();
            fa[fy] = fx;
            cnt[fx] += cnt[fy];
        }

    }
}

int main()
{
    int T;T = read();

    while(T--){
        int n,m;
        n = read();m = read();
        for(int i = 1;i <= n;++i){
            fa[i] = i;
            col[i] = 1;
            cnt[i] = 1;
            TONG[i].clear();
            TONG[i].push_back(i);
        }

        bool contra = false;

        while(m--){
            int i,j,k;char op[20];
            i = read();j = read();Getstr(op,k);
            if(contra)continue;

            int fi = find_fa(i);
            int fj = find_fa(j);
            if(op[0] == 'i'){
                if(fi == fj){
                    if(col[i] == col[j]) contra = true;
                }else{
                    if(col[i] == col[j]){
                        if(cnt[fi] < cnt[fj]){
                            for(auto it : TONG[fi]){
                                col[it] ^= 1;
                            }
                        }else{
                            for(auto it : TONG[fj]){
                                col[it] ^= 1;
                            }
                        }
                    }
                    add(fi,fj);
                }
            }else{
                if(fi == fj){
                    if(col[i] != col[j]) contra = true;
                }else{
                    if(col[i] != col[j]){
                        if(cnt[fi] < cnt[fj]){
                            for(auto it : TONG[fi]){
                                col[it] ^= 1;
                            }
                        }else{
                            for(auto it : TONG[fj]){
                                col[it] ^= 1;
                            }
                        }
                    }
                    add(fi,fj);
                }
            }
        }


        if(contra){
            puts("-1");
            continue;
        }
        int ans = 0;
        for(int i = 1;i <= n;++i){
            if(TONG[i].size()){
                int cnt1 = 0,cnt2 = 0;
                for(auto it : TONG[i]){
                    if(col[it] == 0)cnt1++;
                    else cnt2++;
                }
                ans += max(cnt1,cnt2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/**

*/