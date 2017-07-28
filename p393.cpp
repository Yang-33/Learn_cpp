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

class Date {
	int y;
	int m;
	int d;
	mutable int cnt; // constでも書き換えられる (const の働きを取り消す効果)
public:
	Date();
	Date(int yy, int mm, int dd);
	int year() const { cnt++; return y; }
	int month() const{ cnt++; return m; }
	int day() const{ cnt++; return d; }
	int count() const{ return cnt; }
};

Date::Date(int yy, int mm, int dd) {
	y = yy; m = mm; d = dd; cnt = 0;
}
Date::Date() {
	y = 1; m = 1; d = 1; cnt = 0;

}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	const Date A;

	const Date B = Date(1, 2, 3);

	cout << A.year() << " " << A.month() << " " << A.day() << endl;
	cout << B.year() << " " << B.month() << " " << B.day() << endl;
	cout << "member call times : " << A.count() << endl;
	cout << "member call times : " << B.count() << endl;
	
	return 0;
}
