#include <cstdio>
#include <cmath>
#include <algorithm>
const double eps = 1e-8;
int dcmp(double x) {
 if(fabs(x) <= eps) return 0;
 return x < 0 ? -1 : 1;
}
struct Vector {
 double x, y;
 bool operator == (Vector a) {
  return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0;
 }
 Vector operator - (Vector a) {
  return (Vector){x - a.x, y - a.y};
 }
 friend double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
 }
 friend double length(Vector a) {
  return sqrt(dot(a, a));
 }
};
typedef Vector Point;
struct Circle {
 Point c;
 double r;
 Point point(double rad) {//????????
  return (Point){c.x + r * cos(rad), c.y + r * sin(rad)};
 }
} cir[3];
double angle(Vector v) {//??????
 return atan2(v.y, v.x);
}
int CircleIntersection(Circle c1, Circle c2, Point res[]) {
 double d = length(c1.c - c2.c);
 if(dcmp(d) == 0) {
  if(dcmp(c1.r - c2.r) == 0) return -1;//????
  return 0;
 }
 if(dcmp(c1.r + c2.r - d) < 0) return 0;
 if(dcmp(fabs(c1.r - c2.r) - d) > 0) return 0;

 double a = angle(c2.c - c1.c);
 double da = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));

 Point p1 = c1.point(a - da), p2 = c1.point(a + da);

 res[0] = p1;
 if(p1 == p2) return 1;
 res[1] = p2;
 return 2;
}
int f[3][3];
Point res[3][3][3];
int main() {
 int n; scanf("%d", &n);
 for(int i = 0; i < n; i++) scanf("%lf%lf%lf", &cir[i].c.x, &cir[i].c.y, &cir[i].r);
 bool all_1 = true, flag_2 = false;
 for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
  f[j][i] = f[i][j] = CircleIntersection(cir[i], cir[j], res[i][j]);
  for(int k = 0; k < f[i][j]; k++) res[j][i][k] = res[i][j][k];
  if(f[i][j] != 1) all_1 = false;
  if(f[i][j] == 2) flag_2 = true;
 }
 int ans;
 if(n == 3) {
  if(all_1) {
   ans = 5;
   if(res[0][1][0] == res[0][2][0]) ans--;
  }
  else if(!flag_2) ans = 4;
  else {
   int i, j, k;
   for(int i_ = 0; i_ < n; i_++) for(int j_ = i_ + 1; j_ < n; j_++) {
    if(f[i_][j_] == 2) i = i_, j = j_;
   }
   for(k = 0; k < n; k++) {
    if(k != i && k != j) break;
   }
   int a = f[i][k], b = f[j][k];
   if(a < b) std::swap(a, b), std::swap(i, j);
   ans = 4;
   if(a == 0) ans += 1;
   else if(a == 1) {
    if(b == 0) ans += 1;
    else ans += 2;
   }
   else {
    if(b == 0) ans += 2;
    else if(b == 1) {
     ans += 3;
     if(res[i][k][0] == res[j][k][0] || res[i][k][1] == res[j][k][0])
      ans--;
    }
    else {
     ans += 4;
     for(int x = 0; x < 2; x++) for(int y = 0; y < 2; y++)
      if(res[i][k][x] == res[j][k][y]) ans--;
    }
   }
  }
 }
 else if(n == 2) {
  if(flag_2) ans = 4;
  else ans = 3;
 }
 else ans = 2;

 printf("%d\n", ans);
 return 0;
}