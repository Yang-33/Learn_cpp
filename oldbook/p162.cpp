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

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	enum animal { Dog, Cat, Monkey, Invalid };// Invalid によって追加に対応できる
	int typea;

	do {
		cout << "0-3" << endl;
		cin >> typea;
	} while (typea < Dog || Invalid < typea);

	if (typea != Invalid) {
		//int selected = typea;
		animal selected = static_cast<animal>(typea); // 型変換が無くてもできるがはっきりする
		switch (selected) {
		case Dog: cout << "gau!" << endl; break;
		case Cat: cout << "nyan!" << endl; break;
		case Monkey: cout << "chi!" << endl; break;
		}
	}

	cout << ans << endl;

	return 0;
}
