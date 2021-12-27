#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cmath>
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
#include <array>

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

#define MOD (ll)(998244353)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, k;
ll fac[50000], inv_fac[50000];
string s;

ll fast_pow(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_pow(b, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2) val *= b;
	return val %= MOD;
}

ll mod_mult(ll a, ll b) {
	return (a * b) % MOD;
}

int main() {
	fast_cin();
	fac[0] = 1;
	for (int i = 1; i < 50000; i++) fac[i] = (fac[i - 1] * i) % MOD;
	for (int i = 0; i < 50000; i++) inv_fac[i] = fast_pow(fac[i], MOD - 2);

	cin >> n >> k;
	cin >> s;
	if (k == 0) {
		cout << 1 << '\n';
	}
	else {
		int l = 0;
		int cnt = 0;
		ll ans = 0;
		int prev = -1;
		for (int i = 0; i <= n; i++) {
			if (i == n || s[i] == '1') cnt++;
			if (cnt > k) {
				int ra = i - l;
				ll raw = mod_mult(mod_mult(fac[ra], inv_fac[ra - k]), inv_fac[k]);
				if (prev == -1) {
					ans = raw;
				}
				else {
					int cnt2 = prev - l;
					if (cnt2 >= 0) {
						ll rep = mod_mult(mod_mult(fac[cnt2], inv_fac[cnt2 - (k - 1)]), inv_fac[k - 1]);
						ans += (raw - rep + MOD) % MOD;
					}
				}

				while (l < n && s[l] != '1') l++;
				l++;
				cnt--;
				prev = i;
			}
		}
		if (ans == 0) ans = 1;
		cout << ans % MOD << '\n';
	}
}