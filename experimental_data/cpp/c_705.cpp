#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;

inline int readChar();

template <class T = int> inline T readInt();

template <class T> inline void writeInt( T x );

inline void writeChar( int x );





/** Read */



static const int buf_size = 16384;



inline int getChar() {

	static char buf[buf_size];

	static int len = 0, pos = 0;

	if (pos == len)

		pos = 0, len = fread(buf, 1, buf_size, stdin);

	if (pos == len)

		return -1;

	return buf[pos++];

}



template <class T>

inline T readInt() {

	int s = 1, c = getChar();

	while (c <= 32) c = getChar();

	T x = 0;

    while ('0' <= c && c <= '9')

		x = (x << 3)+(x<<1) + c - '0', c = getChar();

	return  x ;

}



/** Write */



static int write_pos = 0;

static char write_buf[buf_size];



inline void writeChar( int x ) {

	if (write_pos == buf_size)

		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;

	write_buf[write_pos++] = x;

}



template <class T>

inline void writeInt( T x) {





	register char s[24];

	int n = 0;

	while (x || !n)

		s[n++] = '0' + x % 10, x /= 10;

	while (n--)	writeChar(s[n]);

    writeChar('\n');



}







struct Flusher {

	~Flusher() {

		if (write_pos)

			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;

	}

} flusher;



static int read[300005] = {0};

vector<int>  last[300005];



int main(){

int n,q,a,b;

n=readInt();

q=readInt();

 int sizenow = 0;

int unread = 0 , lastunread = 0;

for(;q--;){

   a=readInt(); b=readInt();

   switch(a){



   case 1:

       

       last[b].push_back(sizenow);

       ++sizenow;

       ++unread;

       break;

   case 2 :

  {

      while(!last[b].empty()){

        int tmp = last[b].back();

        last[b].pop_back();

        if(tmp >= lastunread && read[tmp]==0){

         read[tmp]=1;

         --unread;

        }



      }



  }

        break;

   case 3 :

    if(lastunread < b){

      unread -= b;

      unread += lastunread;

      for(;lastunread<b;++lastunread) unread+=read[lastunread];





    }



     break;









   }

   writeInt(unread);



}





}