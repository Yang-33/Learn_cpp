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
public:
	Date();
	Date(int yy, int mm = 1, int dd = 1);
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }
	Date preceding_day() const;
	Date preceding_day2() const;
	std::string to_string() const;
};

std::ostream& operator << (std::ostream& s, const Date& x);


Date::Date() {
	time_t current = time(NULL);
	struct tm* local = localtime(&current);
	y = local->tm_year + 1900;
	m = local->tm_mon + 1;
	d = local->tm_mday;
}

//Date::Date(int yy, int mm, int dd) {
//	y = yy; m = mm; d = dd;
//}

/* データメンバの名前は見えなくなるのでよい */
Date::Date(int y, int m, int d) {
	this->y = y; this->m = m; this->d = d;
}

Date Date::preceding_day() const {
	int dmax[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	Date temp = *this; /* メンバ関数は所属するオブジェクトをthisポインタで持つ。これによってコピーを作成可能 */
	if (temp.d > 1) {
		temp.d--;
	}
	else {
		if (--temp.m < 1) {
			temp.y--;
			temp.m = 12;
		}
		temp.d = dmax[temp.m - 1];
	}
	return temp;
}
Date Date::preceding_day2() const {
	int dmax[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int y = this->y; // データメンバと同じ変数名で宣言した際には宣言した方の変数の名前が見えることになっている
	int m = this->m;
	int dd = this->d;
	if (dd > 1) {
		dd--;
	}
	else {
		if (--m < 1) {
			y--;
			m = 12;
		}
		dd = dmax[m - 1];
	}
	return Date(y, m, dd);
	// コンストラクタを明示的に呼び出すことによって一時オブジェクトを作成して返却値とするとよい
}

string Date::to_string() const {
	ostringstream s;
	s << y << "year " << m << "month " << d << "day";
	return s.str();
}

/* 挿入子の指定 */
ostream& operator << (ostream& s, const Date& x) {
	return s << x.to_string();
}

class Account {
private:
	string full_name;
	string number;
	long crnt_balance;
	Date open;
public:
	Account(string name, string num, long amnt, int y, int m, int d);

	string name() const {
		return full_name;
	}
	string no() const {
		return number;
	}

	long balance() const {
		return crnt_balance;
	}
	void deposit(long amnt) {
		crnt_balance += amnt;
	}
	void withdraw(long amnt) {
		crnt_balance -= amnt;
	}
	Date opening_date() const { return open; }
};

ostream & operator << (ostream& s, const Account& a) {
	return s << a.name() << " " << a.no() << " " << a.balance() << " " << a.opening_date();
}


//Account::Account(string name, string num, long amnt, int y, int m, int d) {
//	full_name = name;
//	number = num;
//	crnt_balance = amnt;
//	open = Date(y, m, d); // 一度 Date型openを初期化してからDateコンストラクタ(y,m,d)を代入している
//}

// よい Date型のメンバをクラスDateのコンストラクタで初期化している
Account::Account(string name, string num, long amnt, int y, int m, int d) :open(y, m, d) {
	full_name = name;
	number = num;
	crnt_balance = amnt;
}

// よい コンストラクタ初期化子,メンバ初期化子によって初期化している
Account::Account(string name, string num, long amnt, int y, int m, int d)
	:full_name(name),number(num),crnt_balance(amnt),open(y,m,d)
{
}




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	Account A("adfa", "12345", 1000, 1, 1, 1);
	cout << A << endl;
	return 0;
}
