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

#define MOD (ll)(1e9) + 7

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[1000];
ll Ms[1001];

ll exp(ll b, ll e) {
	if (e == 0) return 1;
	ll val = exp(b, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2 == 1) val *= b;
	return val % MOD;
}

int main() {
	ll M = 1;
	Ms[0] = 1;
	for (int i = 1; i <= 1000; i++) {
		M *= i;
		M %= MOD;
		Ms[i] = exp(M, MOD - 2);
	}

	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		F0R(i, n) cin >> a[i];
		sort(a, a + n);

		int small = 1000;
		ll samecnt = 0;
		int p = n - 1;
		RF0R(i, n - 1) {
			if (a[i] == small) samecnt++;
			else {
				small = a[i];
				samecnt = 1;
			}
			p--;
			if (n - p - 1 == k) break;
		}

		ll ans = 1;
		int x = 1;
		RF0R(i, p) {
			if (a[i] != small) break;
			x++;
			ans %= MOD;
			ans *= ++samecnt;
			ans %= MOD;
		}
		if (x > 1) ans *= Ms[x];
		cout << ans % MOD << '\n';
	}
}