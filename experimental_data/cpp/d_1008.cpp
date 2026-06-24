#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long LL;
typedef pair<int,int> pii;
int a, b, c;
int f[N];

void init() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            ++f[j];
        }
    }
}
inline LL count1(LL x, LL y, LL z) {
    return x*y*z;
}
inline LL count2(LL x, LL y) {
    return (x + x*(x-1)/2)*y;
}
inline LL count3(LL x) {
    return x + x*(x-1) + x*(x-1)*(x-2)/6;
}

int main() {
    /*
    freopen("out.txt", "w", stdout);
    string sa[] = {"a", "ab", "ac", "abc"};
    string sb[] = {"b", "ab", "bc", "abc"};
    string sc[] = {"c", "ac", "bc", "abc"};
    set<pair<string,pair<string,string> > > st;
    set<pair<string,string> > st2;
    for(auto a : sa) {
        for(auto b : sb) {
            for(auto c : sc) {
                if(a != b && c != a && b != c && !st.count({a, {b, c}})) {
                    printf("count1(%s, %s, %s) + ", a.c_str(), b.c_str(), c.c_str());
                    st.insert({a, {b, c}});
                    st.insert({a, {c, b}});
                    st.insert({b, {a, c}});
                    st.insert({b, {c, a}});
                    st.insert({c, {a, b}});
                    st.insert({c, {b, a}});
                }else if(a == b && b == c) {
                    printf("count3(%s)", a.c_str());
                }else {
                    if(a == b && !st2.count({a, c})) {
                        printf("count2(%s, %s) + ", a.c_str(), c.c_str());
                        st2.insert({a, c});
                    }else if(a == c && !st2.count({a, b})) {
                        printf("count2(%s, %s) + ", a.c_str(), b.c_str());
                        st2.insert({a, b});
                    }else if(b == c && !st2.count({b, a})) {
                        printf("count2(%s, %s) + ", b.c_str(), a.c_str());
                        st2.insert({b, a});
                    }
                }
            }
        }
    }*/
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
        int ab = __gcd(a, b), bc = __gcd(b, c), ac = __gcd(a, c);
        int abc = __gcd(ab, c);
        a = f[a];
        b = f[b];
        c = f[c];
        ab = f[ab];
        bc = f[bc];
        ac = f[ac];
        abc = f[abc];
        ab -= abc;
        ac -= abc;
        bc -= abc;
        a -= ab + ac + abc;
        b -= ab + bc + abc;
        c -= ac + bc + abc;
        long long ans = count1(a, b, c) + count1(a, b, ac) + count1(a, b, bc) + count1(a, b, abc) + count1(a, ab, c) + count1(a, ab, ac) + count1(a, ab, bc) + count1(a, ab, abc) + count1(a, bc, c) + count1(a, bc, ac) + count2(bc, a) + count1(a, bc, abc) + count1(a, abc, c) + count1(a, abc, ac) + count2(abc, a) + count1(ab, b, c) + count1(ab, b, ac) + count1(ab, b, bc) + count1(ab, b, abc) + count2(ab, c) + count2(ab, ac) + count2(ab, bc) + count2(ab, abc) + count1(ab, bc, c) + count1(ab, bc, ac) + count2(bc, ab) + count1(ab, bc, abc) + count1(ab, abc, c) + count1(ab, abc, ac) + count2(abc, ab) + count1(ac, b, c) + count2(ac, b) + count1(ac, b, bc) + count1(ac, b, abc) + count1(ac, ab, c) + count2(ac, ab) + count1(ac, bc, c) + count2(ac, bc) + count2(bc, ac) + count1(ac, bc, abc) + count1(ac, abc, c) + count2(ac, abc) + count2(abc, ac) + count1(abc, b, c) + count1(abc, b, bc) + count2(abc, b) + count1(abc, bc, c) + count2(bc, abc) + count2(abc, bc) + count2(abc, c) + count3(abc);
        printf("%lld\n", ans);
    }
    return 0;
}