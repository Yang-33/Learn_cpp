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



----解説ここまで---- */

class Counter {
private:
	unsigned cnt;
public:
	Counter() : cnt(0) {}
	operator unsigned() const { return cnt; } // 変換関数

	bool operator ! () const { return cnt; } // ! の定義

	Counter & operator ++ () { // 前置演算子
		if (cnt < UINT_MAX)cnt++;
		return *this;
	}
	Counter operator ++(int) { // 後置演算子
		Counter x = *this;
		if (cnt < UINT_MAX)cnt++;
		return x;
	}

	Counter & operator -- () {
		if (cnt > 0)cnt--;
		return *this;
	}
	Counter operator --(int) {
		Counter x = *this;
		if (cnt > 0)cnt--;
		return x;
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	Counter x;
	Counter y;
	int num;
	cin >> num;
	FOR(i, 0, num) {
		cout << x++ << " " << ++y << endl; 
		// x の表記はclass であるが、先の定義から
		// x = cnt.operator unsigned(); とされている
	}
	FOR(i, 0, num) {
		cout << x-- << " " << --y << endl;
	}
	if (!x)cout << "x is xero." << endl;
	else cout << "x is not zero." << endl;
	return 0;
}
