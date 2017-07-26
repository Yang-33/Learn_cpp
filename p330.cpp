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

// 関数テンプレート
template <class Type>Type maxof(Type a, Type b) {
	return a > b ? a : b;
}

// Type 部分は何でもよい
template <class X>X mamam(X a, X b) {
	return a*b;
}

// 明示的な特殊化をした関数定義 -> 関数テンプレートをそのまま使用すべきでない型には専用の関数を定義しなければならない
template <> const char* maxof<const char*>(const char* a, const char *b) {
	return strcmp(a, b) > 0 ? a : b;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a = 3;
	int b = 4;
	char *s = "abc";
	char *t = "aaa";
	cout << maxof(a, b) << endl;
	cout << maxof(s, t) << endl;
	cout << maxof<const char*>(s, t) << endl;
	cout << maxof<const char*>(s, "ABC") << endl;


	char x[10];
	char y[10];
	cin >> x;
	cin >> y;
	cout << maxof(x, y) << endl; // アドレスの比較になってしまう
	cout << maxof<const char*>(x, y) << endl; // 文字列の大小をとることができる
	
	cout << mamam(a, b) << endl;

	return 0;
}
