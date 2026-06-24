#include <iostream>
#include <fstream>
 using namespace std;

 const int MAXN = 3e5 + 121, MAXM = 1e7 + 121;
 int Next[MAXM][2],cnt[MAXM],n,a[MAXN];
 int root;
 int cntVertex;
 int p[31];

 inline bool getBit(int val,short posBit){
    return((val & p[posBit])>0);
 }

 inline int check(int &a){
    if(!a) a = ++cntVertex;
    return a;
 }

 inline void add(int val){
    int Vertex = root;
    for(short i = 30; i >= 0; --i){
        Vertex = check(Next[Vertex][getBit(val, i)]);
        ++cnt[Vertex];
    }
 }

 inline int solve(int val){
    int Vertex = root;
    int newVal = 0;
    for(short i = 30; i >= 0; --i){
        bool bit = getBit(val, i);
        int num = Next[Vertex][bit];
        if(num>0 && cnt[num]>0){
            Vertex = num;
            --cnt[Vertex];
            newVal += bit * p[i];
        } else
        {
            bit^=1;
            Vertex = Next[Vertex][bit];
            --cnt[Vertex];
            newVal += (bit) * p[i];
        }
    }
    return val ^ newVal;
 }

 char ch;

 inline void read(int &x){
    x = 0;
    while(1){
        ch = getchar();
        if(!(ch>='0' && ch<='9'))return;
        x*=10;
        x+=ch - '0';
    }
 }

 int cnt_w,mass_w[20];

 inline void write(int x){
    cnt_w = 0;
    while(1){
        mass_w[++cnt_w] = x % 10;
        x /= 10;
        if(!x)break;
    }
    for(int i = cnt_w; i > 0; --i)
        putchar(char('0' + mass_w[i]));
    putchar(' ');
 }

 main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

     root = 1;
     cntVertex = 1;

     p[0] = 1;
     for(int i = 1; i < 31; ++i)
        p[i] = p[i - 1] << 1;

    read(n);
    for(int i = 1; i <= n; ++i){
        read(a[i]);
    }
    for(int i = 1; i <= n; ++i){
        int p;
        read(p);
        add(p);
    }

    for(int i = 1; i <= n; ++i){
        write(solve(a[i]));
    }

    return 0;
}