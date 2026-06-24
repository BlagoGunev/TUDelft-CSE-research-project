#include<bits/stdc++.h>

using namespace std;

#define N 1123456
typedef long long int LL;

int ch[N][26];
int nc;
string s;
char in[N];
int heada[N], taila[N];
int headb[N], tailb[N];
int nxta[N], nxtb[N];
LL ans;
int rnk[N];
int match[N];

void InsertA(int x){
    int rt = 0;
    int l = s.length();
    for(int i = 0; i < l; ++i){
        if(ch[rt][s[i] - 'a'] == -1){
            ch[rt][s[i] - 'a'] = nc;
            rnk[nc] = rnk[rt] + 1;
            nc++;
        }
        rt = ch[rt][s[i] - 'a'];
    }
    if(heada[rt] == -1){
        heada[rt] = x;
        taila[rt] = x;
    }
    else{
        nxta[taila[rt]] = x;
        taila[rt] = x;
    }
}

void InsertB(int x){
    int rt = 0;
    int l = s.length();
    for(int i = 0; i < l; ++i){
        if(ch[rt][s[i] - 'a'] == -1){
            ch[rt][s[i] - 'a'] = nc;
            rnk[nc] = rnk[rt] + 1;
            nc++;
        }
        rt = ch[rt][s[i] - 'a'];
    }
    if(headb[rt] == -1){
        headb[rt] = x;
        tailb[rt] = x;
    }
    else{
        nxtb[tailb[rt]] = x;
        tailb[rt] = x;
    }
}

void go(int rt){
    for(int c, i = 0; i < 26; ++i){
        c = ch[rt][i];
        if(c != -1){
            go(c);
            if(heada[c] != -1){
                if(heada[rt] == -1){
                    heada[rt] = heada[c];
                    taila[rt] = taila[c];
                }
                else{
                    nxta[taila[rt]] = heada[c];
                    taila[rt] = taila[c];
                }
            }
            if(headb[c] != -1){
                if(headb[rt] == -1){
                    headb[rt] = headb[c];
                    tailb[rt] = tailb[c];
                }
                else{
                    nxtb[tailb[rt]] = headb[c];
                    tailb[rt] = tailb[c];
                }
            }
        }
    }
    while(heada[rt] != -1 && headb[rt] != -1){
        match[heada[rt]] = headb[rt];
        heada[rt] = nxta[heada[rt]];
        headb[rt] = nxtb[headb[rt]];
        ans += rnk[rt];
    }
}

int main(){
    int n, i;
    memset(ch, -1, sizeof ch);
    memset(nxta, -1, sizeof nxta);
    memset(nxtb, -1, sizeof nxtb);
    memset(heada, -1, sizeof heada);
    memset(headb, -1, sizeof headb);
    cin>>n;
    nc = 1;
    rnk[0] = 0;
    for(i = 0; i < n; i++){
        scanf("%s", in);
        s = in;
        InsertA(i);
    }
    for(i = 0; i < n; i++){
        scanf("%s", in);
        s = in;
        InsertB(i);
    }
    go(0);
    cout<<ans<<endl;
    for(i = 0; i < n; ++i){
        printf("%d %d\n", i + 1, match[i] + 1);
    }
}