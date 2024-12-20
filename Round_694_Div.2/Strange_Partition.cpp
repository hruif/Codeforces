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

int t;
int a[100000];

int main() {
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		F0R(i, n) cin >> a[i];
		ll maxval = 0, minval = 0;
		F0R(i, n) {
			minval += a[i];
			maxval += a[i] / x + (a[i] % x ? 1 : 0);
		}
		minval = minval / x + (minval % x ? 1 : 0);
		cout << minval << ' ' << maxval << '\n';
	}
}