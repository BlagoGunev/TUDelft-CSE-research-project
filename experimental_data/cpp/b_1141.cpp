#include <bits/stdc++.h>
#ifndef LOCAL
//#pragma GCC diagnostic ignored "-Wpragmas"
//#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC optimize(3)
//#pragma GCC optimize("-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2,-ffast-math")
//#pragma GCC optimize("-fsched-spec,-falign-jumps,-falign-loops,-falign-labels,-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves,-fcrossjumping,-fthread-jumps,-funroll-loops,-fwhole-program,-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns,-fschedule-insns2,-fstrict-aliasing,-fdelete-null-pointer-checks")
//#pragma GCC optimize("-fstrict-overflow,-falign-functions,-fcse-skip-blocks,-fcse-follow-jumps,-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining,-freorder-functions,-findirect-inlining,-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop,-finline-small-functions,-ftree-switch-conversion,-ftree-tail-merge")
//#pragma GCC optimize("-foptimize-sibling-calls,-fexpensive-optimizations,-funsafe-loop-optimizations")
//#pragma GCC optimize("rename-registers,unroll-loops,inline-functions,inline-small-functions,vpt")
//#pragma GCC optimize("inline-functions-called-once,tracer")
//#pragma GCC optimize("unroll-loops,fast-math,Ofast,inline,Ofast,no-stack-protector,profile-values,data-sections")
//#pragma GCC optimize("move-loop-invariants,profile-reorder-functions,unswitch-loops,function-sections")
//#pragma GCC optimize("branch-target-load-optimize,branch-target-load-optimize2,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,avx,avx2,popcnt,abm,mmx,tune=native")
//#pragma warning(disable:4996)
//#pragma comment(linker, "/STACK:256000000")
#endif
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<char> arr(n);
    for (char &el : arr) {
        cin >> el;
        el -= '0';
    }
    int l = 0, r = 0;
    for (int i = 0; i < n && arr[i] == 1; i++) l++;
    for (int i = n - 1; i >= 0 && arr[i] == 1; i--) r++;
    int mx = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            cur++;
        else {
            if (cur > mx)
                mx = cur;
            cur = 0;
        }
    }
    if (cur > mx)
        mx = cur;
    cout << max(l + r, mx);

}