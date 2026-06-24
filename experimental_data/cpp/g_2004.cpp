/*
lib:        https://github.com/old-yan/CP-template
author:     oldyan
*/
#include <algorithm>
#include <bit>
#include <bits/stdc++.h>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <numeric>
#include <vector>
/*
lib code is above
temp code is below
*/
#ifndef __OY_INFODEQUE__
#define __OY_INFODEQUE__
namespace OY {
    namespace INFODEQUE {
        using size_type = uint32_t;
        struct Ignore {};
        template <typename Tp, typename Operation>
        struct InfoPair {
            using sum_type = Tp;
            Tp m_val, m_sum;
        };
        template <typename Tp>
        struct InfoPair<Tp, Ignore> {
            using sum_type = void;
            Tp m_val;
        };
        template <typename Tp>
        struct VectorAdapter : std::vector<Tp> {
            static constexpr bool is_special = false;
            using Base = std::vector<Tp>;
            const Tp &top() const { return Base::back(); }
            template <typename Callback1, typename Callback2>
            void drop_head(Callback1 &&call1, Callback2 &&call2) {
                size_type sz = Base::size();
                call1((*this)[(sz - 1) / 2].m_val);
                for (size_type i = (sz - 1) / 2 - 1; ~i; i--) call2((*this)[i].m_val);
                Base::erase(Base::begin(), Base::begin() + (sz + 1) / 2);
            }
        };
        template <typename Tp, size_t N>
        struct StaticAdapter {
            static inline Tp *s_buf = new Tp[N];
            struct type1 {
                static constexpr bool is_special = true;
                Tp *m_l = s_buf + N / 2, *m_r = s_buf + N / 2;
                bool empty() const { return m_l == m_r; }
                size_type size() const { return m_r - m_l; }
                void push_back(const Tp &x) { *--m_l = x; }
                void pop_back() { m_l++; }
                const Tp &top() const { return *m_l; }
                Tp &operator[](size_type i) const { return *(m_r - i - 1); }
            };
            struct type2 {
                static constexpr bool is_special = true;
                Tp *m_l = s_buf + N / 2, *m_r = s_buf + N / 2;
                bool empty() const { return m_l == m_r; }
                size_type size() const { return m_r - m_l; }
                void push_back(const Tp &x) { *m_r++ = x; }
                void pop_back() { m_r--; }
                const Tp &top() const { return *(m_r - 1); }
                Tp &operator[](size_type i) const { return m_l[i]; }
            };
        };
        template <typename Tp, typename Operation = Ignore, typename Adapter1 = VectorAdapter<InfoPair<Tp, Operation>>, typename Adapter2 = VectorAdapter<InfoPair<Tp, Operation>>>
        struct Deque {
            static constexpr bool is_ignore = std::is_same<Operation, Ignore>::value;
            mutable Adapter1 m_left;
            mutable Adapter2 m_right;
            Operation m_op;
            void _trans_left() const {
                if constexpr (Adapter1::is_special && Adapter2::is_special) {
                    size_type sz = m_right.size();
                    m_left.m_l = m_right.m_l, m_left.m_r = m_right.m_l = m_right.m_l + (sz + 1) / 2;
                    if constexpr (!is_ignore) {
                        m_left[0].m_sum = m_left[0].m_val;
                        for (size_type i = 1, sz = m_left.size(); i != sz; i++) m_left[i].m_sum = m_op(m_left[i].m_val, m_left[i - 1].m_sum);
                    }
                } else {
                    auto call1 = [&](const Tp &x) {
                        if constexpr (is_ignore)
                            m_left.push_back({x});
                        else
                            m_left.push_back({x, x});
                    };
                    auto call2 = [&](const Tp &x) {
                        if constexpr (is_ignore)
                            m_left.push_back({x});
                        else
                            m_left.push_back({x, m_op(x, m_left.top().m_sum)});
                    };
                    m_right.drop_head(call1, call2);
                }
                if constexpr (!is_ignore)
                    if (!m_right.empty()) {
                        m_right[0].m_sum = m_right[0].m_val;
                        for (size_type i = 1, sz = m_right.size(); i != sz; i++) m_right[i].m_sum = m_op(m_right[i - 1].m_sum, m_right[i].m_val);
                    }
            }
            void _trans_right() const {
                if constexpr (Adapter1::is_special && Adapter2::is_special) {
                    size_type sz = m_left.size();
                    m_right.m_r = m_left.m_r, m_right.m_l = m_left.m_r = m_left.m_r - (sz + 1) / 2;
                    if constexpr (!is_ignore) {
                        m_right[0].m_sum = m_right[0].m_val;
                        for (size_type i = 1, sz = m_right.size(); i != sz; i++) m_right[i].m_sum = m_op(m_right[i - 1].m_sum, m_right[i].m_val);
                    }
                } else {
                    auto call1 = [&](const Tp &x) {
                        if constexpr (is_ignore)
                            m_right.push_back({x});
                        else
                            m_right.push_back({x, x});
                    };
                    auto call2 = [&](const Tp &x) {
                        if constexpr (is_ignore)
                            m_right.push_back({x});
                        else
                            m_right.push_back({x, m_op(m_right.top().m_sum, x)});
                    };
                    m_left.drop_head(call1, call2);
                }
                if constexpr (!is_ignore)
                    if (!m_left.empty()) {
                        m_left[0].m_sum = m_left[0].m_val;
                        for (size_type i = 1, sz = m_left.size(); i != sz; i++) m_left[i].m_sum = m_op(m_left[i].m_val, m_left[i - 1].m_sum);
                    }
            }
            Deque(Operation op = Operation()) : m_op(op) {}
            void push_back(const Tp &x) {
                if constexpr (is_ignore)
                    m_right.push_back({x});
                else if (m_right.empty())
                    m_right.push_back({x, x});
                else
                    m_right.push_back({x, m_op(m_right.top().m_sum, x)});
            }
            void pop_back() {
                if (m_right.empty()) _trans_right();
                m_right.pop_back();
            }
            void push_front(const Tp &x) {
                if constexpr (is_ignore)
                    m_left.push_back({x});
                else if (m_left.empty())
                    m_left.push_back({x, x});
                else
                    m_left.push_back({x, m_op(x, m_left.top().m_sum)});
            }
            void pop_front() {
                if (m_left.empty()) _trans_left();
                m_left.pop_back();
            }
            const Tp &front() const {
                if (m_left.empty()) _trans_left();
                return m_left.top().m_val;
            }
            const Tp &back() const {
                if (m_right.empty()) _trans_right();
                return m_right.top().m_val;
            }
            bool empty() const { return m_left.empty() && m_right.empty(); }
            size_type size() const { return m_left.size() + m_right.size(); }
            typename InfoPair<Tp, Operation>::sum_type query_all() const {
                static_assert(!is_ignore, "Operation Mustn't Be Ignore");
                if (m_left.empty())
                    return m_right.top().m_sum;
                else if (m_right.empty())
                    return m_left.top().m_sum;
                else
                    return m_op(m_left.top().m_sum, m_right.top().m_sum);
            }
            const Tp &operator[](size_type i) const { return i < m_left.size() ? m_left[m_left.size() - 1 - i].m_val : m_right[i - m_left.size()].m_val; }
        };
    }
    template <typename Tp, typename Operation, size_t N>
    using GlobalInfoDeque = INFODEQUE::Deque<Tp, Operation, typename INFODEQUE::StaticAdapter<INFODEQUE::InfoPair<Tp, Operation>, N>::type1, typename INFODEQUE::StaticAdapter<INFODEQUE::InfoPair<Tp, Operation>, N>::type2>;
    template <typename Tp, typename Operation = INFODEQUE::Ignore>
    using VectorInfoDeque = INFODEQUE::Deque<Tp, Operation, INFODEQUE::VectorAdapter<INFODEQUE::InfoPair<Tp, Operation>>, INFODEQUE::VectorAdapter<INFODEQUE::InfoPair<Tp, Operation>>>;
}
#endif
using namespace std;
constexpr int inf = 0x3f3f3f3f;
struct item {
    int val[10][10];
    item() = default;
    item(int v) {
        for (int pre = 0; pre < 10; pre++) {
            for (int suf = 0; suf < 10; suf++) {
                if (!pre) {
                    if (!suf)
                        val[0][0] = inf;
                    else
                        val[0][suf] = suf == v ? 0 : inf;
                } else {
                    if (!suf)
                        val[pre][0] = pre;
                    else if (pre == suf)
                        val[pre][suf] = pre;
                    else
                        val[pre][suf] = inf;
                }
            }
        }
    }
    item operator+(const item &rhs) const {
        item res;
        for (int pre = 0; pre < 10; pre++) {
            for (int suf = 0; suf < 10; suf++) {
                res.val[pre][suf] = inf;
            }
        }
        for (int pre = 0; pre < 10; pre++) {
            for (int mid = 0; mid < 10; mid++)
                if (val[pre][mid] != inf)
                    for (int suf = 0; suf < 10; suf++)
                        res.val[pre][suf] = min(res.val[pre][suf], val[pre][mid] + rhs.val[mid][suf]);
        }
        return res;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(20);
#ifdef OY_LOCAL
    freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
#endif
    int t = 1;
#ifdef OY_LOCAL
    cin >> t;
#endif
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        OY::GlobalInfoDeque<item, plus<item>, 400000> Q;
        for (int l = 0, r = 0; l + k <= n; l++) {
            while (r < l + k) {
                Q.push_back(s[r++] - '0');
            }
            cout << Q.query_all().val[0][0] << ' ';
            Q.pop_front();
        }
        cout << '\n';
    }
}