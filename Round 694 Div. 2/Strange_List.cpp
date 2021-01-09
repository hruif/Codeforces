#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

struct qarr {
	ll a;
	ll ts;
	qarr() {}
	qarr(ll a, ll ts) {
		this->a = a;
		this->ts = ts;
	}
};

int t;
queue<qarr> qa;

int main() {
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		F0R(i, n) {
			ll a;
			cin >> a;
			qa.push(qarr(a, 1));
		}

		ll sum = 0;
		while (!qa.empty()) {
			qarr f = qa.front();
			sum += f.a * f.ts;
			qa.pop();

			if (f.a % x == 0) qa.push(qarr(f.a / x, x * f.ts));
			else break;
		}
		while (!qa.empty()) {
			sum += qa.front().a * qa.front().ts;
			qa.pop();
		}

		cout << sum << '\n';
	}
}