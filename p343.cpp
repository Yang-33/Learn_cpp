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

namespace aaa {
	int a = int(6);
	void pri_A() {
		cout << a << endl;
	}
}
namespace alta = aaa;

//namespace alta{ // このような表現はできない
//	void pri_Aalt() {
//		cout << "!?" << endl;
//	}
//}

namespace sss {
	int vz = int(1);
	void print_hell() {
		cout << "this position is hell." << endl;
	}
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  aaa::pri_A();
  alta::pri_A();
  using namespace sss;
  using sss::print_hell;// sss名前空間の利用を宣言
 // using sss::print_hell; // using 指令は避けるべき。
  // using namespace stdはこういうこと

  print_hell();

  return 0;
}
