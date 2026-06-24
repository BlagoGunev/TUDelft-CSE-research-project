#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int cnt[30], cs[30], ct[30];
char s[55], t[55];
vector<int> a1, a2;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt) );
        memset(cs, 0, sizeof(cs) );
        memset(ct, 0, sizeof(ct) );
        a1.clear(), a2.clear();
        int n;
        scanf("%d %s %s", &n, s, t);
        for(int i = 0; i < n; ++i) {
            ++cnt[s[i]-'a'];
            ++cnt[t[i]-'a'];
        }
        bool flag = true;
        for(int i = 0; i < 26; ++i)
            if(cnt[i] % 2) flag = false;
        if(!flag) {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(int i = 0; i < 26; ++i) {
            if(!cnt[i]) continue;
            memset(cs, 0, sizeof(cs) );
            memset(ct, 0, sizeof(ct) );
            for(int i = 0; i < n; ++i) {
                ++cs[s[i]-'a'];
                ++ct[t[i]-'a'];
            }
            if(cs[i] > ct[i]) {
                int d = cs[i] - ct[i];
                for(int j = n; j >= 0; --j) {
                    if(s[j] == i+'a') {
                        for(int k = 0; k < n; ++k) {
                            if(t[k] > i+'a' && s[k] == i+'a') {
                                swap(s[j], t[k]);
                                a1.push_back(j+1);
                                a2.push_back(k+1);
                                d-=2;
                                break;
                            }
                        }
                    }
                    if(!d) break;
                }
            }
            else if(cs[i] < ct[i]) {
                int d = ct[i] - cs[i];
                for(int j = n; j >= 0; --j) {
                    if(t[j] == i+'a') {
                        for(int k = 0; k < n; ++k) {
                            if(s[k] > i+'a' && t[k] == i+'a') {
                                swap(t[j], s[k]);
                                a1.push_back(k+1);
                                a2.push_back(j+1);
                                d-=2;
                                break;
                            }
                        }
                    }
                    if(!d) break;
                }
            }
            for(int j = 0; j < n; ++j) {
                if(s[j] == i+'a' && t[j] != s[j]) {
                    int k, l;
                    for(k = 0; k < n; ++k)
                        if(s[k] > i+'a') break;
                    for(l = 0; l < n; ++l)
                        if(t[l] == i+'a' && s[l] != t[l]) break;
                    swap(s[k], t[l]);
                    a1.push_back(k+1);
                    a2.push_back(l+1);
                    swap(s[k], t[j]);
                    a1.push_back(k+1);
                    a2.push_back(j+1);
                }
            }
            
        }
        printf("%d\n", a1.size() );
        for(int i = 0; i < a1.size(); ++i)
            printf("%d %d\n", a1[i], a2[i]);
    }
    return 0;
}