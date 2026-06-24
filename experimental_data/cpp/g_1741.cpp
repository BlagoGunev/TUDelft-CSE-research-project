#include <iostream>

#include <vector>

#include <queue>



#define MAXN 10000

#define MAXK 64

using namespace std;



struct node{

  int dist;

  int specialNodes;

  bool canReach[MAXK];

  vector <int> neighbours;

};



struct dequeStruct{

  int start, finish;

};



node graph[MAXN];

bool dp[MAXN + 1][MAXK];

int nrBits1[MAXK];

queue <int> q;

int friends[MAXN];

bool hasCar[MAXN];



void precalcNrBits1() {

  int i;



  for ( i = 0; i < MAXK; i++ ) {

    if ( (i << 1) < MAXK ) {

      nrBits1[(i << 1)] = nrBits1[i];

      if ( (i << 1) + 1 < MAXK )

        nrBits1[(i << 1) + 1] = nrBits1[i] + 1;

    }

  }

}



void addEdge(int a, int b) {

  graph[a].neighbours.push_back(b);

  graph[b].neighbours.push_back(a);

}



void resetNode(int pos) {

  int i;



  graph[pos].dist = 0;

  graph[pos].specialNodes = 0;

  graph[pos].neighbours.clear();

  for ( i = 0; i < MAXK; i++ ) {

    graph[pos].canReach[i] = false;

  }

}



void bfs() {

  int pos, i;



  graph[0].dist = 1;

  q.push(0);

  while ( !q.empty() ) {

    pos = q.front();

    q.pop();

    if ( graph[pos].specialNodes > 0 ) {

      for ( i = 0; i < MAXK; i++ ) {

        if ( graph[pos].canReach[i] ) {

          graph[pos].canReach[i | graph[pos].specialNodes] = true;

        }

      }

    }



    for ( int n : graph[pos].neighbours ) {

      if ( !graph[n].dist ) {

        graph[n].dist = graph[pos].dist + 1;

        q.push(n);

      }



      if ( graph[n].dist == graph[pos].dist + 1 ) {

        for ( i = 0; i < MAXK; i++ ) {

          graph[n].canReach[i] = graph[n].canReach[i] | graph[pos].canReach[i];

        }

      }

    }

  }

}



int main() {

  int t, n, m, i, a, b, k, nrFriends, i2, i3, maxx;



  precalcNrBits1();



  scanf("%d", &t);



  while ( t-- ) {

    scanf("%d%d", &n, &m);



    for ( i = 0; i < m; i++ ) {

      scanf("%d%d", &a, &b);

      a--;

      b--;



      addEdge(a, b);

    }



    for ( i = 0; i < n; i++ ) {

      graph[i].canReach[0] = true;

      graph[i].specialNodes = 0;

    }



    scanf("%d", &nrFriends);

    for ( i = 0; i < nrFriends; i++ ) {

      scanf("%d", &friends[i]);

      hasCar[i] = true;

      friends[i]--;

    }



    scanf("%d", &k);

    for ( i = 0; i < k; i++ ) {

      scanf("%d", &a);

      a--;

      hasCar[a] = false;



      graph[friends[a]].specialNodes += (1 << i);

    }



    bfs();



    dp[0][0] = true;

    for ( i = 1; i <= nrFriends; i++ ) {

      if ( hasCar[i - 1] ) {

        for ( i2 = 0; i2 < MAXK; i2++ ) {

          if ( dp[i - 1][i2] ) {

            for ( i3 = 0; i3 < MAXK; i3++ ) {

              if ( graph[friends[i - 1]].canReach[i3] ) {

                dp[i][i3 | i2] = true;

              }

            }

          }

        }

      } else {

        for ( i2 = 0; i2 < MAXK; i2++ ) {

          dp[i][i2] = dp[i - 1][i2];

        }

      }

    }



    maxx = 0;

    for ( i = 0; i < MAXK; i++ ) {

      maxx = max(maxx, dp[nrFriends][i] * nrBits1[i]);

    }

    printf("%d\n", k - maxx);



    for ( i = 0; i < n; i++ ) {

      resetNode(i);

    }

    for ( i = 0; i <= nrFriends; i++ ) {

      for ( i2 = 0; i2 < MAXK; i2++ ) {

        dp[i][i2] = false;

      }

    }

  }

  return 0;

}