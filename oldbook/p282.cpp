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
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  xtimex  Problem: __CONTEST_NAME__  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

type_infoのname()は、name manglingされたままの文字列を返す。
とてもよみにくいのでこれを人間にわかりやすいように書き直す。

----解説ここまで---- */

ll N;

ll ans = 0LL;
// memory leaks
#include "cxxabi.h"
char* demangle(const char *demangle) {
	int status;
	return abi::__cxa_demangle(demangle, 0, 0, &status);
}

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

	N = 0;
	cout << typeid(bad_alloc).name() << endl;
	cout << typeid(N).name() << endl;
	int d;
	cout << typeid(d).name() << endl;
	cout << typeid(int).name() << endl;
	cout << typeid(long long).name() << endl;
	cout << typeid(char).name() << endl;
	cout << typeid(string).name() << endl;
	cout << typeid(vector<int>()).name() << endl;
	cout << typeid(vector<string >()  ).name() << endl;


	cout << demangle(typeid(bad_alloc).name()) << endl;
	cout << demangle(typeid(N).name()) << endl;
	cout << demangle(typeid(d).name()) << endl;
	cout << demangle(typeid(int).name()) << endl;
	cout << demangle(typeid(long long ).name()) << endl;
	cout << demangle(typeid(char).name()) << endl;
	cout << demangle(typeid(string ).name()) << endl;
	cout << demangle(typeid(vector<int>).name()) << endl;
	cout << demangle(typeid(vector<string >).name()) << endl;

	cout << Demangle(typeid(ll)) << endl;

	while (1) {
		cout << "made." << endl;
		try {
			double *a = new double[3000000000000000];
		}
		catch (bad_alloc) {
			int d;
			cout << typeid(bad_alloc).name() << endl;
			cout << typeid(N).name() << endl;
			cout << typeid(d).name() << endl;
			cout << "can't make array more." << endl;
			exit(1);
		}

	}
	return 0;
}
