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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

ll fast_exp(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_exp(b, e / 2);
	val = val * val % MOD;
	if (e % 2) val *= b;
	return val % MOD;
}

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int zc = 0, gc = 0;
		if (s[0] == '0') zc++;
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == '1' && s[i] == '1') {
				gc++;
				i++;
				if (i < n && s[i] == '0') zc++;
			}
			else if (s[i] == '0') {
				zc++;
				i++;
				if (i < n && s[i] == '0') zc++;
			}
		}
		ll ans = 1;
		for (int i = 0; i < gc; i++) {
			ans *= zc + gc - i;
			ans %= MOD;
		}
		for (int i = 1; i <= gc; i++) {
			ans *= fast_exp(i, MOD - 2);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}