#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
vi digs;

int main() {
	cin >> t;
	while (t--) {
		digs.clear();

		int x;
		cin >> x;
		if (x > 45) {
			cout << "-1\n";
			continue;
		}
		if (x < 10) {
			cout << x << '\n';
			continue;
		}
		if (x < 18) {
			cout << x - 9 << 9 << '\n';
			continue;
		}
		if (x < 25) {
			cout << x - 17 << 89 << '\n';
			continue;
		}
		if (x < 31) {
			cout << x - 24 << 789 << '\n';
			continue;
		}
		if (x < 36) {
			cout << x - 30 << 6789 << '\n';
			continue;
		}
		if (x < 40) {
			cout << x - 35 << 56789 << '\n';
			continue;
		}
		if (x < 43) {
			cout << x - 39 << 456789 << '\n';
			continue;
		}
		if (x < 45) {
			cout << x - 42 << 3456789 << '\n';
			continue;
		}
		cout << "123456789\n";
	}
}