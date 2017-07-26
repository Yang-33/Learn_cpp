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

ll N;

ll ans = 0LL;

// 名前なし名前空間にはそれが定義されたソースファイルのみに通用することになるので。
// static を用いて混同しやすい内部結合表現よりもこちらをつかうとよい。　

namespace {
	int kotae = int(1);
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cout << kotae << endl;
  kotae = int(5);
  cout << kotae << endl;
  cout << ::kotae << endl; // 名前空間 無
  return 0;
}
