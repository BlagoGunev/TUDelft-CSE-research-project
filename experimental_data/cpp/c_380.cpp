#include <cstdio>
#include <algorithm>
#include <stack>
const int N = 1000010;
const int M = 100010;
std::stack<int> st;
char s[N];
struct node{
    int l, r;
    int id;
    bool operator < (const node& cmp) const{
        return r < cmp.r;
    }
}q[M];
int n,ans[M],c[N];
void U(int x, int d){
    for ( ; x < N ; x += x & -x)  c[x] += d;
}
int S(int x){
    int ret = 0;
    for (;x;x -= x&-x) ret += c[x];
    return ret;
}
int main(){
    scanf("%s%d",s,&n);
    for (int i = 0 ; i < n ; ++i){
        scanf("%d%d" , &q[i].l , &q[i].r);
        q[i].l--; q[i].r--;
        q[i].id = i;
    }
    std::sort(q , q + n);
    int pt = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        while(pt <= q[i].r)
        {
            if (s[pt] == ')' && !st.empty())
            {
                U(st.top() + 1, 1);
                st.pop();
            }
            else if (s[pt] == '(') st.push(pt);
            pt++;
        }
        ans[q[i].id] = S(q[i].r + 1);
        if (q[i].l) ans[q[i].id] -= S(q[i].l);
    }
    for (int i = 0 ; i < n ; ++i){
        printf("%d\n" , ans[i] * 2);
    }
    return 0;
}