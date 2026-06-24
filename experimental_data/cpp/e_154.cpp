#include <bits/stdc++.h>
using namespace std;
#define double long double

const double eps = 1e-8;
const double PI = 3.1415926535897932384626;

struct Point {
    double x, y;
};

Point operator-(const Point &A, const Point &B) {
    return {A.x - B.x, A.y - B.y};
}

Point operator+(const Point &A, const Point &B) {
    return {A.x + B.x, A.y + B.y};
}

double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y;
}

double cross(const Point &A, const Point &B) {
    return A.x * B.y - A.y * B.x;
}

double cross(const Point &A, const Point &B, const Point &C) {
    return cross(Point{B.x - A.x, B.y - A.y}, Point{C.x - A.x, C.y - A.y});
}

double abs2(const Point &A) {
    return dot(A, A);
}

bool operator<(const Point &A, const Point &B) {
    if (fabsl(A.x - B.x) > eps) return A.x < B.x;
    return A.y < B.y;
}

void computeConvexHull(vector<Point> &points) {
    sort(points.begin(), points.end());
    vector<Point> hullPoints(1, points[0]);
    for (int ct = 0; ct < 2; ++ct, reverse(points.begin(), points.end())) {
        size_t i = 1, t = hullPoints.size();
        if (i < points.size()) {
            do {
                while (hullPoints.size() > t &&
                       (cross(hullPoints[hullPoints.size()-2], hullPoints.back(), points[i]) <= eps))
                    hullPoints.pop_back();
                hullPoints.push_back(points[i]);
                i++;
            } while (i < points.size());
        }
    }
    hullPoints.pop_back();
    points.swap(hullPoints);
}


Point excenter(Point p0, Point p1, Point p2) {
    p1 = p1 - p0;
    p2 = p2 - p0;
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double m = 2.0 * cross(p1, p2);
    if(fabsl(m) < eps) return {0, 0};
    Point center;
    center.x = (x1*x1 * y2 - x2*x2 * y1 + y1*y2*(y1 - y2)) / m;
    center.y = (x1*x2*(x2 - x1) - y1*y1 * x2 + x1*y2*y2) / m;
    return center;
}

typedef pair<double, array<int,3>> CandidateEntry;

struct CandidateComparator {
    bool operator()(const CandidateEntry &A, const CandidateEntry &B) const {
        return A.first < B.first;
    }
};

double calculateSectorArea(double R, double chord) {
    double ratio = min(chord / (2.0 * R), 1.0L);
    double angle = asinl(ratio);
    return R * R * angle - 0.5 * chord * sqrtl(R * R - 0.25 * chord * chord);
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numBuildings;
    double R;
    cin >> numBuildings >> R;
    vector<Point> buildings(numBuildings);
    for (int i = 0; i < numBuildings; i++){
        cin >> buildings[i].x >> buildings[i].y;
    }
    
    computeConvexHull(buildings);
    int hullSize = (int)buildings.size();
    
    if(hullSize == 1) {
        cout << fixed << setprecision(10) << 0.0 << "\n";
        return 0;
    }
    if(hullSize == 2) {
        double d = sqrtl(abs2(buildings[0] - buildings[1]));
        if(d <= R + eps) {
            double alpha = acosl(min(d/(2.0*R), (double)1.0));
            double lensArea = 2.0 * R * R * alpha - 0.5 * d * sqrtl(4.0 * R * R - d*d);
            cout << fixed << setprecision(10) << (double)lensArea << "\n";
        } else {
            cout << fixed << setprecision(10) << (double)(PI * R * R) << "\n";
        }
        return 0;
    }
    
    set<int> activeIndices;
    for (int i = 0; i < hullSize; i++) activeIndices.insert(i);
    priority_queue<CandidateEntry, vector<CandidateEntry>, CandidateComparator> removalCandidates;
    vector<int> removed(hullSize, 0);
    
    auto getPrev = [&](set<int>::iterator it) -> set<int>::iterator {
        if (it == activeIndices.begin()) return --activeIndices.end();
        return prev(it);
    };
    auto getNext = [&](set<int>::iterator it) -> set<int>::iterator {
        auto nxt = next(it);
        if (nxt == activeIndices.end()) return activeIndices.begin();
        return nxt;
    };
    
    auto insertCandidate = [&](int idx) {
        if(activeIndices.size() <= 2) return;
        auto it = activeIndices.find(idx);
        int idxPrev = *getPrev(it), idxNext = *getNext(it);
        if( abs2(buildings[idxPrev] - buildings[idxNext]) >= 
            abs2(buildings[idx] - buildings[idxPrev]) + abs2(buildings[idxNext] - buildings[idx]) - eps )
            removalCandidates.push({ abs2(excenter(buildings[idxPrev], buildings[idx], buildings[idxNext])),
                                      {idxPrev, idx, idxNext} });
    };
    for (int i = 0; i < hullSize; i++) {
        insertCandidate(i);
    }
    
    while (!removalCandidates.empty()) {
        auto [candKey, indices] = removalCandidates.top();
        removalCandidates.pop();
        
        auto [idxPrev, idxCurr, idxNext] = indices;
        
        if (candKey < R * R + eps) break;
        
        if (!removed[idxPrev] && !removed[idxCurr] && !removed[idxNext]) {
            removed[idxCurr] = 1;
            activeIndices.erase(idxCurr);
            insertCandidate(idxPrev);
            insertCandidate(idxNext);
        }
    }
    
    
    vector<Point> generatorPositions;
    for(auto idx : activeIndices)
        generatorPositions.push_back(buildings[idx]);
    //a
    double protectedArea = 0.0;
    int numGenerators = (int)generatorPositions.size();
    
    for (int i = 0; i < numGenerators; i++) {
        int j = (i + 1) % numGenerators;
        double areaContribution = cross(generatorPositions[i], generatorPositions[j]) * 0.5;
        protectedArea += areaContribution;
    
        double chordLength = sqrtl(abs2(generatorPositions[i] - generatorPositions[j]));
        protectedArea += calculateSectorArea(R, chordLength);
    }
    
    protectedArea = fabsl(protectedArea);
    
    cout << fixed << setprecision(10) << (double)protectedArea << "\n";
    return 0;
}