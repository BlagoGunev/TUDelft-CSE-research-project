#include <bits/stdc++.h>

using namespace std;



const int LN  = 30;

const int MAX = 2e5 + 5;

const int LIM = MAX * LN;



struct trie_item {

    int cnt;

    trie_item *go[2];

};



static trie_item trie_allocator[LIM] = {};

static int trie_allocated = 0;



trie_item* trie = NULL;



inline trie_item* alloc_item() {

    trie_item *res = trie_allocator + (trie_allocated++);

    res->cnt = 0;

    res->go[0] = res->go[1] = NULL;

    return res;

}



inline int cnt(trie_item* t) {

    return t ? t->cnt : 0;

}



void add(trie_item* t, int n, int idx, int inc) {

    t->cnt += inc;

    if (idx == -1) {

        return;

    }

    int i = ((n & (1 << idx)) != 0) ? 1 : 0;

    if (!t->go[i]) {

        t->go[i] = alloc_item();

    }

    add(t->go[i], n, idx - 1, inc);

}



void max(trie_item* t, int n, int idx, int *res) {

    if (!(cnt(t->go[0]) || cnt(t->go[1]))) {

        return;

    }

    int i = ((n & (1 << idx)) != 0) ? 0 : 1;

    if (!cnt(t->go[i])) {

        i = !i;

        (*res) = (*res) * 2;

    }

    else {

        (*res) = (*res) * 2 + 1;

    }

    max(t->go[i], n, idx - 1, res);

}



void print(trie_item* t) {

    static char out_buffer[1000];

    static char* bufptr = out_buffer;

    if (!t) {

        return;

    }

    *bufptr = '\0';

    int i, outcnt = cnt(t) - cnt(t->go[0]) - cnt(t->go[1]);

    for (i = 0; i < outcnt; i++) {

        puts(out_buffer);

    }

    for (i = 0; i < 2; i++) {

        *(bufptr++) = '0' + i;

        print(t->go[i]);

        bufptr--;

    }

}



void add(int n, int inc) {

    add(trie, n, LN, inc);

}



int max(int n) {

    int res = 0;

    max(trie, n, LN, &res);

    return res;

}



void init() {

    trie = alloc_item();

    add(0, 1);

}



#define inchar          getchar

#define outchar(x)      putchar(x)



template<typename T> void inPos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}

template<typename T> void outPos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}

inline void inStr(char *str){register char c=0;register int i=0;while(c<33)c=inchar();while (c!='\n'&&c!=' '&&c!=EOF){str[i]=c;c=inchar();++i;}str[i]='\0';}



int main() {

    #ifndef ONLINE_JUDGE

        freopen("inp.txt", "r", stdin);

    #endif

    init();

    int q, x;

    char type[3];

    inPos(q);

    while(q--) {

        inStr(type), inPos(x);

        if (type[0] == '+') {

            add(x, 1);

        }

        else if (type[0] == '-') {

            add(x, -1);

        }

        else {

            outPos(max(x));

        }

    }

    return 0;

}