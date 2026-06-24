// LUOGU_RID: 101586530
#include <bits/stdc++.h>



using LL = long long;



const int inf32 = 1e9;



struct SNode {

    SNode* son[2]{0};

    LL sum{0};

    int tag1{0}, tag2{inf32};

    int cnt{0}, len{0}, max[2]{-inf32, -inf32};

};

#define L(p) p->son[0]

#define R(p) p->son[1]

void SBuild(SNode* &p, int l, int r) {

    p = new SNode{};

    if (l == r) return;

    int mid = l + r >> 1;

    SBuild(L(p), l, mid);

    SBuild(R(p), mid + 1, r);

}

void SUp(SNode* p) {

    p->len = L(p)->len + R(p)->len;

    p->sum = L(p)->sum + R(p)->sum;

    if (L(p)->max[0] > R(p)->max[0]) {

        p->max[0] = L(p)->max[0];

        p->max[1] = std::max(L(p)->max[1], R(p)->max[0]);

    }

    else if (L(p)->max[0] < R(p)->max[0]) {

        p->max[0] = R(p)->max[0];

        p->max[1] = std::max(R(p)->max[1], L(p)->max[0]);

    }

    else {

        p->max[0] = L(p)->max[0];

        p->max[1] = std::max(L(p)->max[1], R(p)->max[1]);

    }

    p->cnt = 0;

    if (L(p)->max[0] == p->max[0]) p->cnt += L(p)->cnt;

    if (R(p)->max[0] == p->max[0]) p->cnt += R(p)->cnt;

}

void SAddTag1(SNode* p, int tag) {

    p->tag1 += tag;

    p->tag2 += tag;

    p->max[0] += tag;

    p->max[1] += tag;

    p->sum += 1ll * p->len * tag;

}

void SAddTag2(SNode* p, int tag) {

    if (tag < p->max[0]) {

        p->sum -= 1ll * (p->max[0] - tag) * p->cnt;

        p->max[0] = p->tag2 = tag;

    }

}

void SDown(SNode* p) {

    if (p->tag1) {

        SAddTag1(L(p), p->tag1);

        SAddTag1(R(p), p->tag1);

        p->tag1 = 0;

    }

    if (p->tag2 < inf32) {

        SAddTag2(L(p), p->tag2);

        SAddTag2(R(p), p->tag2);

        p->tag2 = inf32;

    }

}

void SUpdate1(SNode* p, int l, int r, int x, int y, int v) {

    if (x <= l && r <= y) return SAddTag1(p, v);

    int mid = l + r >> 1;

    SDown(p);

    if (x <= mid) SUpdate1(L(p), l, mid, x, y, v);

    if (y > mid) SUpdate1(R(p), mid + 1, r, x, y, v);

    SUp(p);

}

void SUpdate2(SNode* p, int l, int r, int x, int y, int v) {

    if (!p->cnt) return;

    if (v >= p->max[0]) return;

    if (x <= l && r <= y && v >= p->max[1]) return SAddTag2(p, v);

    int mid = l + r >> 1;

    SDown(p);

    if (x <= mid) SUpdate2(L(p), l, mid, x, y, v);

    if (y > mid) SUpdate2(R(p), mid + 1, r, x, y, v);

    SUp(p);

}

void SMark(SNode* p, int l, int r, int x, int v) {

    if (l == r) {

        p->cnt = 1;

        p->len = 1;

        p->sum = v;

        p->max[0] = v;

        return;

    }

    int mid = l + r >> 1;

    SDown(p);

    if (x <= mid) SMark(L(p), l, mid, x, v);

    else SMark(R(p), mid + 1, r, x, v);

    SUp(p);

}

#undef L

#undef R



const int max_n = 1.5e5 + 5;



int n, a[max_n], p[max_n], rk[max_n], bitSum[max_n];



void BITAdd(int x, int v) {for (; x <= n; x += x & -x) bitSum[x] += v;}

int BITQuery(int x) {

    int v = 0;

    for (; x; x -= x & -x) v += bitSum[x];

    return v;

}



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d", &a[i]);

        p[a[i]] = i;

        rk[a[i]] = BITQuery(a[i]) + 1;

        BITAdd(a[i], 1);

    }

    SNode *sRoot1, *sRoot2;

    SBuild(sRoot1, 1, n);

    SBuild(sRoot2, 1, n);

    for (int i = 1; i <= n; i++) {

        int pos = p[i], _pos = rk[i];

        SMark(sRoot1, 1, n, pos, 0), SMark(sRoot2, 1, n, pos, i + 1);

        if (pos < n) SUpdate1(sRoot1, 1, n, pos + 1, n, -1);

        if (pos < n) SUpdate2(sRoot1, 1, n, pos + 1, n, -_pos);

        if (pos < n) SUpdate1(sRoot2, 1, n, pos + 1, n, 1);

        if (pos > 1) SUpdate2(sRoot2, 1, n, 1, pos - 1, _pos);

        printf("%lld\n", sRoot1->sum + sRoot2->sum - i);

    }

    return 0;

}