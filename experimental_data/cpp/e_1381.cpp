#include <bits/stdc++.h>

using namespace std;



const double EPS = 1e-7;

using quadratic = array<double, 3>;



struct intpt {

  int x, y;

};



quadratic operator + (const quadratic& a, const quadratic& b) {

  quadratic c;

  for (int i = 0; i < 3; i++) c[i] = a[i]+b[i];

  return c;

}



double eval(const quadratic& a, double x) {

  return a[0]+a[1]*x+a[2]*x*x;

}



struct event {

  double x;

  quadratic diff;

};



bool operator < (const event& a, const event& b) {

  return make_pair(a.x, a.diff) < make_pair(b.x, b.diff);

}



long long cross(intpt a, intpt b) {

  return 1LL*a.x*b.y-1LL*a.y*b.x;

}



intpt operator - (intpt& a, intpt& b) {

  return intpt{a.x-b.x, a.y-b.y};

}



int main () {

  ios_base::sync_with_stdio(0); cin.tie(0);

  cout << fixed << setprecision(12);

  int n, q;

  cin >> n >> q;

  vector<intpt> poly(n);



  int miny = 1e9;

  int argminy = -1;

  vector<int> ycoords;

  for (int i = 0; i < n; i++) {

    int x, y;

    cin >> x >> y;

    ycoords.push_back(y);

    poly[i] = intpt{x, y};

    if (y < miny) {

      miny = y;

      argminy = i;

    }

  }

  rotate(poly.begin(), poly.begin()+argminy, poly.end());

  if (cross(poly[n-1]-poly[0], poly[1]-poly[0]) > 0) {

    reverse(poly.begin()+1, poly.end());

  }



  int maxy = -1e9;

  int argmaxy = -1;

  for (int i = 0; i < n; i++) {

    if (poly[i].y > maxy) {

      maxy = poly[i].y;

      argmaxy = i;

    }

  }

  sort(ycoords.begin(), ycoords.end());

  ycoords.resize(unique(ycoords.begin(), ycoords.end())-ycoords.begin());

  int m = ycoords.size();



  vector<double> rx(m), lx(m), mx(m);

  int j = 0;

  for (int i = 0; i <= argmaxy; i++) {

    while (ycoords[j] != poly[i].y) {

      assert(i > 0);

      rx[j] = poly[i-1].x + 

        (ycoords[j]-poly[i-1].y)*(double)(poly[i].x-poly[i-1].x)/(poly[i].y-poly[i-1].y);

      j++;

    }

    rx[j++] = poly[i].x;

  }



  reverse(poly.begin()+1, poly.end());

  argmaxy = n-argmaxy;

  j = 0;

  for (int i = 0; i <= argmaxy; i++) {

    while (ycoords[j] != poly[i].y) {

      assert(i > 0);

      lx[j] = poly[i-1].x + 

        (ycoords[j]-poly[i-1].y)*(double)(poly[i].x-poly[i-1].x)/(poly[i].y-poly[i-1].y);

      j++;

    }

    lx[j++] = poly[i].x;

  }

  for (int i = 0; i < m; i++) {

    mx[i] = (lx[i]+rx[i])/2;

  }



  vector<event> events;

  auto add_triangle = [&] (double x1, double x2, double h) {

    if (abs(x1-x2) <= EPS) return;

    events.push_back(event{x1, {0.5*h*x1*x1/(x2-x1), -h*x1/(x2-x1), 0.5*h/(x2-x1)}});

    events.push_back(event{x2, {0.5*h*x2*(x2-2*x1)/(x2-x1), h*x1/(x2-x1), -0.5*h/(x2-x1)}});

  };

  double area = 0;

  for (int i = 0; i < m-1; i++) {

    double h = ycoords[i+1]-ycoords[i];

    area += (rx[i+1]+rx[i]-lx[i+1]-lx[i])*h/2;

    events.push_back(event{lx[i], {lx[i]*h, -h, 0}});

    events.push_back(event{mx[i], {-2*mx[i]*h, 2*h, 0}});

    events.push_back(event{rx[i], {rx[i]*h, -h, 0}});

    add_triangle(lx[i+1], lx[i], -h);

    add_triangle(mx[i+1], mx[i], 2*h);

    add_triangle(rx[i+1], rx[i], -h);

  }

  sort(events.begin(), events.end());

  int z = events.size();

  vector<double> event_coords(z);

  vector<quadratic> funcs(z+1);

  funcs[0] = {area, 0, 0};

  for (int i = 0; i < z; i++) {

    event_coords[i] = events[i].x;

    funcs[i+1] = funcs[i]+events[i].diff;

  }



  while (q--) {

    int f;

    cin >> f;

    int i = lower_bound(event_coords.begin(), event_coords.end(), f)-event_coords.begin();

    cout << eval(funcs[i], f) << '\n';

  }

}