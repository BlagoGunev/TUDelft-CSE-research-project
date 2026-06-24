#include <bits/stdc++.h>
using namespace std;

/*
 We store the set of possible joker positions as a list of disjoint, sorted intervals.
 Each operation transforms that set into a new set via:
   - top-move transform
   - bottom-move transform
 plus possibly adding position 1 or n if X is in an interval.
 Then we take the union and merge into disjoint form.

 We'll define helper functions:

   // intervals are sorted, disjoint
   // shiftTop(X, intervals, n) -> vector< pair<int,int> >
   // shiftBottom(X, intervals, n) -> vector< pair<int,int> >
   // then we union them, also add {1} or {n} if X in intervals.

 We then merge them. O(#intervals) is constant-ish each time, so O(q) total.
*/

// Merge overlapping or adjacent intervals in-place.
// intervals must be sorted by .first already.
static void mergeIntervals(vector<pair<int,int>> &v) {
    // standard merge for intervals
    if(v.empty()) return;
    vector<pair<int,int>> ans;
    ans.reserve(v.size());
    ans.push_back(v[0]);
    for(size_t i=1; i<v.size(); i++){
        auto &prev = ans.back();
        auto &cur  = v[i];
        // If cur overlaps or is adjacent to prev => merge them
        if(cur.first <= prev.second + 1) {
            // merge
            if(cur.second > prev.second){
                prev.second = cur.second;
            }
        } else {
            ans.push_back(cur);
        }
    }
    v.swap(ans);
}

// We apply the "move-to-top" transformation to an interval [s,e] *excluding* X itself.
//
//   If p < X => p -> min(p+1, n)
//   If p > X => p -> p
//
// but we do NOT apply it to p = X. We'll handle p = X as a separate "joker jumps to 1" scenario.
static vector<pair<int,int>> shiftTopInterval(int X, int s, int e, int n) {
    // Cases:
    // 1) If e < X => all p in [s,e] < X, so p -> p+1 (and clamp to n).
    //    That yields interval [s+1, e+1], possibly clamped at the upper end to n.
    // 2) If s > X => all p in [s,e] > X, so p -> p (no change).
    //    That yields interval [s, e].
    // 3) If [s,e] intersects X, we split:
    //    [s, X-1],   (X),   [X+1, e].
    //    (X) is excluded from transformation (the "joker is that card" scenario).
    //    For [s, X-1], each p-> p+1 => [s+1, X].
    //    For [X+1, e], each p-> p => [X+1, e].
    // Then we union them (they might or might not connect).
    //
    // We'll produce at most 2 intervals. Some might be empty if e < s.

    vector<pair<int,int>> ret;
    if(e < X) {
        // Entire interval < X => all shift up by 1 (clamp).
        int ns = s+1, ne = e+1;
        if(ne > n) ne = n;  // clamp if needed
        if(ns <= ne) {
            ret.push_back({ns, ne});
        }
    }
    else if(s > X) {
        // Entire interval > X => no change
        ret.push_back({s, e});
    }
    else {
        // Overlaps X, so split around X.
        // Part 1: [s, X-1] => shift up => [s+1, X]
        int leftS = s, leftE = X-1;
        if(leftS <= leftE) {
            int ns = leftS+1, ne = leftE+1;  // clamp up to n
            if(ne > n) ne = n;
            if(ns <= ne) {
                ret.push_back({ns, ne});
            }
        }
        // Part 2: [X+1, e] => no change => [X+1, e]
        int rightS = X+1, rightE = e;
        if(rightS <= rightE) {
            ret.push_back({rightS, rightE});
        }
    }
    return ret;
}

// Similarly for the "move-to-bottom" transformation, excluding X:
static vector<pair<int,int>> shiftBottomInterval(int X, int s, int e, int n) {
    // If p < X => p-> p  (no change)
    // If p > X => p-> p-1 (clamp to 1)
    // Exclude p= X from the transformation (that is the "joker=card" scenario).
    //
    // Cases:
    // 1) if e < X => [s,e] => no change
    // 2) if s > X => [s,e] => all p-> p-1 => [s-1, e-1] (clamp)
    // 3) if [s,e] crosses X => split around X into [s,X-1] and [X+1,e].
    //    - [s,X-1] => no change
    //    - [X+1,e] => p-> p-1 => [X, e-1]
    // Then union.

    vector<pair<int,int>> ret;
    if(e < X) {
        // entire < X => no change
        ret.push_back({s,e});
    }
    else if(s > X) {
        // entire > X => shift down by 1
        int ns = s-1, ne = e-1;
        if(ns < 1) ns = 1;
        if(ns <= ne) {
            ret.push_back({ns, ne});
        }
    }
    else {
        // crosses X
        // part1: [s, X-1] => no change
        int leftS = s, leftE = X-1;
        if(leftS <= leftE) {
            ret.push_back({leftS, leftE});
        }
        // part2: [X+1,e] => shift down => [X, e-1] (clamp)
        int rightS = X+1, rightE = e;
        if(rightS <= rightE) {
            int ns = rightS-1, ne = rightE-1;
            if(ns < 1) ns = 1;
            if(ns <= ne) {
                ret.push_back({ns, ne});
            }
        }
    }
    return ret;
}

// Combine the per-interval transformations to get a set of intervals:
static vector<pair<int,int>> shiftTopAll(int X, const vector<pair<int,int>> &intervals, int n) {
    // apply shiftTopInterval(X,...) to each interval and union them
    // We'll just collect them in a vector, then we'll merge them afterwards.
    vector<pair<int,int>> out;
    out.reserve(intervals.size()*2); // each interval can produce up to 2
    for(auto &iv: intervals){
        auto tmp = shiftTopInterval(X, iv.first, iv.second, n);
        for(auto &t: tmp) out.push_back(t);
    }
    return out;
}
static vector<pair<int,int>> shiftBottomAll(int X, const vector<pair<int,int>> &intervals, int n) {
    vector<pair<int,int>> out;
    out.reserve(intervals.size()*2);
    for(auto &iv: intervals){
        auto tmp = shiftBottomInterval(X, iv.first, iv.second, n);
        for(auto &t: tmp) out.push_back(t);
    }
    return out;
}

// Check if X lies in any interval of intervals:
static bool inAnyInterval(int X, const vector<pair<int,int>> &intervals) {
    // intervals are disjoint, sorted
    // do a quick binary search or linear check (they are few, so linear is fine).
    for(auto &iv: intervals){
        if(X < iv.first) break;
        if(iv.first <= X && X <= iv.second) return true;
    }
    return false;
}

// Returns the sum of lengths of all intervals in intervals
static long long totalSize(const vector<pair<int,int>> &intervals) {
    long long ans = 0;
    for(auto &iv : intervals){
        ans += (long long)(iv.second - iv.first + 1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long N;  // up to 1e9
        int M, Q;     // M in [1..N], Q up to 2e5
        cin >> N >> M >> Q;

        vector<int> A(Q);
        for(int i=0; i<Q; i++){
            cin >> A[i];
        }

        // We'll store the set of possible positions as disjoint intervals.
        // Initially, it's just [m,m].
        vector<pair<int,int>> intervals;
        intervals.push_back({M, M});  // the joker is definitely at position M initially.

        for(int i=0; i<Q; i++){
            int X = A[i];  // the position from the current deck perspective

            // We'll build the union of shiftTopAll(...) and shiftBottomAll(...).
            // Then, if X is in intervals, we also add discrete point "1" (top scenario) or "n" (bottom scenario).
            // Then we merge everything.

            // 1) shift-top part
            auto topPart = shiftTopAll(X, intervals, (int)N);

            // 2) shift-bottom part
            auto botPart = shiftBottomAll(X, intervals, (int)N);

            // Combine them
            vector<pair<int,int>> newSet;
            newSet.reserve(topPart.size() + botPart.size() + 2);

            // Add all intervals from topPart
            for(auto &iv: topPart){
                newSet.push_back(iv);
            }
            // Add all intervals from botPart
            for(auto &iv: botPart){
                newSet.push_back(iv);
            }

            // If X is in intervals, then the joker could *be* that card => it jumps to {1} or {n}.
            if(inAnyInterval(X, intervals)) {
                // add discrete intervals [1,1] and [n,n]
                newSet.push_back({1,1});
                newSet.push_back({(int)N, (int)N});
            }

            // Now sort + merge
            sort(newSet.begin(), newSet.end());
            mergeIntervals(newSet);

            // That newSet is our updated set of possible positions.
            intervals.swap(newSet);

            // The answer after this operation is the total # of positions in 'intervals'
            long long ans = totalSize(intervals);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}