#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <climits>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

ll exp(ll b, ll e) {
	if (e == 0) return 1;
	ll val = exp(b, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2) val *= b;
	return val % MOD;
}

int main() {
	cin >> t;
	vll p(200000);
	ll ttm = 1;
	F0R(i, 200000) {
		p[i] = ttm;
		ttm *= 2;
		ttm %= MOD;
	}
	while (t--) {
		int n, k;
		cin >> n >> k;
		ll val = 1;
		ll tmp = 1;
		F0R(i, n - 1) {
			val *= n - i;
			val %= MOD;
			val *= exp(i + 1, MOD - 2);
			val %= MOD;
			if (i % 2) {
				tmp += val;
				tmp %= MOD;
			}
		}
		val = tmp;

		if (n % 2) {
			ll ans = 1;
			F0R(i, k) {
				ans *= val + 1;
				ans %= MOD;
			}
			cout << ans << '\n';
		}
		else {
			ll ans = 1;
			ans *= exp(val, k);
			F0R(i, k) {
				ans %= MOD;
				ans += exp(p[k - 1 - i], n) * exp(val, i) % MOD;
				ans %= MOD;
			}
			cout << ans << '\n';
		}
	}
}