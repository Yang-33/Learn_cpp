#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  xtimex  Problem: __CONTEST_NAME__  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

class Date {
	int y;
	int m;
	int d;
public:
	Date(int yy, int mm, int dd);
	int year() { return y; }
	int month() { return m; }
	int day() { return d; }
};

Date::Date(int yy, int mm, int dd) {
	y = yy; m = mm; d = dd;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Date A(2017, 5, 31);              // int i(5)
  Date B = A;// copy                // int i=j
  Date C = Date(2017, 7, 28);       // int i=int(5)
  cout << A.year() << " " << A.month() << " " << A.day() << endl;
  cout << B.year() << " " << B.month() << " " << B.day() << endl;
  cout << C.year() << " " << C.month() << " " << C.day() << endl;

  return 0;
}
