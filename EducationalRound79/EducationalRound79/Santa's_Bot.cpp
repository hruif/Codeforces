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

#define MOD (ll)(998244353)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
vector<int> a[1000000];
int colors[1000000];

ll fast_pow(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_pow(b, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2) val *= b;
	return val % MOD;
}

int main() {
	fast_cin();

	t = 1;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			a[i].rsz(k);
			for (int j = 0; j < k; j++) cin >> a[i][j];
			for (int j = 0; j < k; j++) a[i][j]--;
			for (int j = 0; j < k; j++) colors[a[i][j]]++;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll cur = fast_pow(n, MOD - 2);
			for (int j = 0; j < a[i].size(); j++) {
				ans += fast_pow(n, MOD - 2) * fast_pow(a[i].size(), MOD - 2) % MOD * colors[a[i][j]] % MOD * fast_pow(n, MOD - 2) % MOD;
				ans %= MOD;
			}
		}
		cout << ans << '\n';
	}
}