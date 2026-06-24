#include <bits/stdc++.h>

using namespace std;


/*
*****************************************
************    I/O    ******************
*****************************************
*/


/** Interface */

template <class T = int> inline T readInt();            
inline int readUInt();           
inline int readChar();           
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, int len );
template <class T> inline void writeUInt( T x, int len );
template <class T> inline void writeInt( T x ) { writeInt(x, -1); };
template <class T> inline void writeUInt( T x ) { writeUInt(x, -1); };
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

/** Read */

static const int buf_size = 4096;

static char buf[buf_size];
static int buf_len = 0, pos = 0;

inline bool isEof() {
  if (pos == buf_len) {
    pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
    if (pos == buf_len)
      return 1;
  }
  return 0;
}

inline int getChar() { 
  return isEof() ? -1 : buf[pos++];
}

inline int peekChar() { 
  return isEof() ? -1 : buf[pos];
}

inline bool seekEof() { 
  int c;
  while ((c = peekChar()) != -1 && c <= 32)
    pos++;
  return c == -1;
}

inline int readChar() {
  int c = getChar();
  while (c != -1 && c <= 32)
    c = getChar();
  return c;
}

inline int readUInt() {
  int c = readChar(), x = 0;
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return x;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

inline void readWord( char *s ) { 
  int c = readChar();
  while (c > 32)
    *s++ = c, c = getChar();
  *s = 0;
}

inline bool readLine( char *s ) { 
  int c = getChar();
  while (c != '\n' && c != -1)
    *s++ = c, c = getChar();
  *s = 0;
  return c != -1;
}


inline void skip(int k) {
    while (k-- > 0) getChar();
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

template <class T> 
inline void writeUInt( T x, int output_len ) {
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;
  int t = (int)x;
  writeUInt(t), x -= t;
  writeChar('.');
  for (int i = output_len - 1; i > 0; i--) {
    x *= 10;
    t = std::min(9, (int)x);
    writeChar('0' + t), x -= t;
  }
  x *= 10;
  t = std::min(9, (int)(x + 0.5));
  writeChar('0' + t);
}



/*
********************************************
************   SOLUTION   ******************
********************************************
*/
int boy[1000000];

void solve() {
    int n = readInt(), q = readInt(), cur = 0, even = 0, odd = 0;
    for (int i = 0; i < q; i++) {
        int type = readInt();
        if (type == 1) {
            int x = readInt();
            if (x < 0)
                x += n;
            even += x;
            odd += x;
            if (x % 2 == 1)
                cur = 1 - cur;
        } else {
            if (!cur)
                even--, odd++;
            else
                even++, odd--;
            cur = 1 - cur; 
        }
        if (odd < 0)
            odd += n;
        if (even < 0)
            even += n;
        if (odd >= n)
            odd -= n;
        if (even >= n)
            even -= n; 
    }
    for (int i = 0; i < n; i++) {
        int pos = (i + (i % 2 == 0 ? odd : even)) % n;
        boy[pos] = i;
    }
    for (int i = 0; i < n; i++)
        writeInt(boy[i] + 1), writeChar(' ');
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);    
    solve();
    flush();
    return 0;
}