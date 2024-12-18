#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

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

#define MOD ((ll)(1e9+7))

int t;
vector<int> ff;
unordered_map<int, ll> found;

ll exp(ll base, ll e) {
	if (e == 0) return 1;
	if (e == 1) return base;
	ll val = exp(base, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2 == 1) val *= base;
	return val % MOD;
}

ll Ss[101];
ll Cs[101];
ll Ms[101];
ll sum;
ll findcombos(int mini, int m, int k) {
	ll mins = found[mini];
	if (sum < m) return 0;

	ll C = 1;
	ll S = 1;
	Ss[0] = 1;
	for (int i = 1; i <= m; i++) {
		ll sub = (i - 1);
		S *= sum - mins - sub;
		S %= MOD;
		Ss[i] = S;
	}
	for (int i = 1; i <= m; i++) {
		ll sub = (i - 1);
		C *= mins - sub;
		C %= MOD;
		Cs[i] = C;
	}
	
	ll combos = 0;
	for (int i = 1; i <= m; i++) {
		combos += (((Cs[i] * Ms[i]) % MOD)
			* ((Ss[m - i] * Ms[m - i]) % MOD)) % MOD;
	}

	return combos % MOD;
}

int main() {
	cin >> t;
	ll M = 1;
	Ms[0] = 1;
	for (int i = 1; i <= 100; i++) {
		M *= i;
		M %= MOD;
		Ms[i] = exp(M, MOD - 2);
	}
	while (t--) {
		found.clear();
		ff.clear();

		int n, m, k;
		cin >> n >> m >> k;
		F0R(i, n) {
			int v;
			cin >> v;
			found[v]++;
		}
		ll total = 0;
		F0R(i, k + 1) sum += found[i];
		for (int i = 1; i <= n; i++) {
			sum += found[i + k];
			total += findcombos(i, m, k);
			sum -= found[i];
		}
		cout << total % MOD << '\n';
	}
}