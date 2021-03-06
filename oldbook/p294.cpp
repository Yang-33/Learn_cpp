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

#include <cxxabi.h>

class Demangle
{
private:
	char * realname;

public:
	Demangle(std::type_info const & ti)
	{
		int status = 0;
		realname = abi::__cxa_demangle(ti.name(), 0, 0, &status);
	}

	Demangle(Demangle const &) = delete;
	Demangle & operator = (Demangle const &) = delete;

	~Demangle()
	{
		std::free(realname);
	}

	operator char const * () const
	{
		return realname;
	}

};



int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  const char *s = "abc\0adcde";
  cout << s << endl; // null以降は表示されない
  cout << sizeof(s) << endl; // sizeは認識される
  cout << Demangle(typeid(s)) << endl;

  return 0;
}
