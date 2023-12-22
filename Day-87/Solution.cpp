#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

const int MAXT = (1 << 9) << 2;
const int MAXN = 505;
const int inf  = 1000000000;

namespace IO {
  const int SIZE = 10500;
  char buff[ SIZE ], *p = buff + SIZE;
  inline char read_char() {
    if ( p == buff + SIZE ) {
      fread( buff, 1, SIZE, stdin );
      p = buff;
    }
    return *(p++);
  }
  inline int read_int() {
    char c;
    while ( !isdigit( c = read_char() ) );
    int r = c - '0';
    while ( isdigit( c = read_char() ) ) r = 10 * r + c - '0';
    return r;
  }
};

int N, M, D, R, C;
int A[ MAXN ][ MAXN ];
int dp[ MAXN ][ MAXN ];

int tree[ MAXT ][ MAXT ];
int p = 0;

inline void init()
{
  p = 0;
  for ( int i = 0; i < MAXT; ++i )
    for ( int j = 0; j < MAXT; ++j ) {
      tree[i][j] = inf;
      if ( i < MAXN && j < MAXN ) 
	dp[i][j] = inf;
    }
}

int Ux, Uy;

void update_y( int nx, int ny, int fx, int ly, int ry )
{
  if ( ly > ry ) return;

  if ( ly == ry ) {
    if ( fx ) tree[nx][ny] = dp[Ux][Uy];
    else tree[nx][ny] = min( tree[2*nx][ny], tree[2*nx+1][ny] );
    return;
  }

  int my = (ly + ry) >> 1;
  if ( Uy <= my ) update_y( nx, 2*ny, fx, ly, my );
  else update_y( nx, 2*ny+1, fx, my+1, ry );

  tree[nx][ny] = min( tree[nx][2*ny], tree[nx][2*ny+1] ); // ??
}

void update_x( int nx, int lx, int rx )
{
  if ( lx > rx ) return;

  if ( lx != rx ) {
    int mx = (lx + rx) >> 1;
    if ( Ux <= mx ) update_x( 2*nx, lx, mx );
    else update_x( 2*nx+1, mx+1, rx );
  }
  update_y( nx, 1, lx == rx, 0, M-1 );
}

int Qx1, Qy1, Qx2, Qy2;

int query_y( int nx, int ny, int yl, int yr, int ly, int ry )
{
  if ( ly > ry ) return inf;
  if ( ly == yl && ry == yr ) return tree[nx][ny];
  int my = (yl + yr) >> 1;
  return min( query_y( nx, 2*ny,  yl, my, ly, min(ry, my) ),
	      query_y( nx, 2*ny+1, my+1, yr, max(ly,my+1), ry ) );
}

int query_x( int nx, int xl, int xr, int lx, int rx )
{
  if ( lx > rx ) return inf;
  if ( xl == lx && rx == xr ) return query_y( nx, 1, 0, M-1, Qy1, Qy2 );
  int mx = (xl + xr) >> 1;
  return min( query_x( 2*nx,  xl, mx, lx, min(rx,mx) ),
	      query_x( 2*nx+1, mx+1, xr, max(mx+1,lx), rx ) );
}

struct Point
{
  int x, y, v;
  Point() {}
  Point(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}
} points[ MAXN * MAXN ];

inline bool cmp( const Point &a, const Point &b ) { 
  if ( a.v != b.v ) return a.v < b.v;
  if ( a.x != b.x ) return a.x < b.x;
  return a.y < b.y;
}

void solve()
{
  init();

  N = IO :: read_int();
  M = IO :: read_int();
  D = IO :: read_int();
  R = IO :: read_int();
  C = IO :: read_int();

  for ( int i = 0; i < N; ++i )
    for ( int j = 0; j < M; ++j ) {
      A[i][j] = IO :: read_int();
      points[p++] = Point( i, j, i*i + j*j );
    }

  if ( !R && !C ) { puts( "0" ); return; }

  dp[0][0] = 0;
  sort( points, points + p, cmp );

  Ux = 0; Uy = 0;
  update_x( 1, 0, N-1 );

  for ( int i = 1; i < p; ) {
    int j = i;
    for (; j < p && points[i].v == points[j].v; ++j ) {
      int x = points[j].x;
      int y = points[j].y;

      Qx1 = max( 0, x - D );
      Qy1 = max( 0, y - D );
      Qx2 = min( N-1, x + D );
      Qy2 = min( M-1, y + D );

      int m = query_x( 1, 0, N-1, Qx1, Qx2 );
      dp[x][y] = A[x][y] + m;
      if ( x == R && y == C ) { printf( "%d\n", dp[R][C] ); return; }
    }

    for ( int k = i; k < j; ++k ) { 
      Ux = points[k].x;
      Uy = points[k].y;
      update_x( 1, 0, N-1 ); 
    }

    i = j;
  }

  puts( "ERROR" );
}

int main()
{
  int test = IO :: read_int();
  while ( test-- ) solve();
}
