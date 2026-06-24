#include <iostream>



#define MAXN 200000

using namespace std;



int m[MAXN][2];



int main() {

  int n, i, max0, max1, oldMax0, oldMax1, max00, max11, newMax0, newMax1, newMax11, newMax00;

  int first1;

  bool first1in1, existOldMax1, existMax11;

  char ch;



  scanf("%d ", &n);



  for ( i = 0; i < n; i++ ) {

    ch = fgetc(stdin);

    m[i][0] = (ch == '1');

  }

  ch = fgetc(stdin);

  for ( i = 0; i < n; i++ ) {

    ch = fgetc(stdin);

    m[i][1] = (ch == '1');

  }



  max0 = max1 = oldMax0 = oldMax1 = max00 = max11 = 0;

  first1in1 = true;

  existMax11 = false;

  existOldMax1 = false;

  first1 = -1;

  for ( i = 0; i < n; i++ ) {

    newMax0 = max0;

    newMax00 = max00;

    newMax1 = max1;

    newMax11 = max11;

    if ( m[i][0] ) {

      newMax0 = max(oldMax0 + 1, max(oldMax1 + 1, max(max0 + 1, max11 + 1)));

      if ( existMax11 ) {

        newMax0 = max(newMax0, max11 + 1 + m[i][1]);

      }

      if ( existOldMax1 ) {

        newMax0 = max(newMax0, oldMax1 + 1 + m[i][1]);

      }

      newMax00 = max0 + 1;

    }

    if ( m[i][1] ) {

      newMax1 = max(oldMax0 + 1, max(max1 + 1, max00 + 1));

      if ( existOldMax1 ) {

        newMax1 = max(newMax1, oldMax1 + 1);

      }

      newMax11 = max1 + 1;

      if ( m[i][0] ) {

        newMax1 = max(newMax1, max(oldMax0 + 2, max00 + 2));

      }

    }

    oldMax0 = max0;

    oldMax1 = max1;

    max0 = newMax0;

    max1 = newMax1;

    max00 = newMax00;

    if ( !first1in1 )

      max11 = newMax11;

    if ( first1 != -1 && m[i][1] ) {

      existMax11 = true;

    }

    if ( first1 != -1 && i - first1 > 0 ) {

      existOldMax1 = true;

    }

    if ( m[i][1] ) {

      if ( first1 == -1 )

        first1 = i;

      first1in1 = false;

    }

  }



  printf("%d\n", max(max0, max1));



  return 0;

}