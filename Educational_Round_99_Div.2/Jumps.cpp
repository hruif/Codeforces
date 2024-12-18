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
int mink = 1000000000;

int tryall(int x, int y, int k) {
	if (x == y) {
		return k;
	}
	int k1 = 1000000000, k2 = 1000000000;
	if (x > y) {
		k1 = tryall(x, y + k, k + 1);
	}
	if (y > 1000000) {
		k2 = tryall(x, y - 1, k + 1);
	}
	return min(k1, k2);
}

int main() {
	cin >> t;
	while (t--) {
		mink = 1000000000;
		int x;
		cin >> x;
		cout << tryall(x, 0, 1) << '\n';
	}
}