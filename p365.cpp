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


class Account {
private:
	string full_name;
	string number;
	long crnt_balance;
public:
	Account(string name, string nummmmmmmm, long am); // 適当でもよい

	string name() {
		return full_name;
	}
	string no() {
		return number;
	}

	long balance() {
		return crnt_balance;
	}

	/* 外部で詳細な定義を書くことができるが関数の宣言は必要 */
	void deposit(long a); //　名前は適当でよい
	void withdraw(long amnt);// 冒頭の関数宣言のように型、名前、引数の型だけ示せばよい
};

/*  !!!!!!!!!  以降非 inline 関数*/
Account::Account(string name, string num, long amnt) {
	full_name = name;
	number = num;
	crnt_balance = amnt;
}
void Account::deposit(long amnt) {
	crnt_balance += amnt;
}

void Account::withdraw(long amnt) {
	crnt_balance -= amnt;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	Account suzuki("SuzukiRyuuiti", "12345678", 1000);
	Account takeda("TakedaHirohumi", "87654321", 200);

	suzuki.withdraw(200);
	takeda.deposit(100);
	cout << "Suzuki account : " << suzuki.name() << " " << suzuki.no() << " " << suzuki.balance() << endl;
	cout << "Takeda account : " << takeda.name() << " " << takeda.no() << " " << takeda.balance() << endl;
	// cout << suzuki.crnt_balance; // private なのでアクセスできない。
	return 0;
}

