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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int sieve[20000001];
int cnts[20000001];

ll fast_pow(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_pow(b, e / 2);
	val *= val;
	if (e % 2) val *= b;
	return val;
}

int main() {
	for (int i = 0; i <= 20000000; i++) sieve[i] = -1;
	for (ll i = 2; i <= 20000000; i++) {
		if (sieve[i] != -1) continue;
		for (ll j = i * i; j <= 20000000; j += i) {
			if (sieve[j] == -1) sieve[j] = i;
		}
	}
	for (int i = 2; i <= 20000000; i++) {
		if (sieve[i] == -1) cnts[i] = 1;
		else if (sieve[i] != sieve[i / sieve[i]] && sieve[i] != i / sieve[i]) cnts[i] = cnts[i / sieve[i]] + 1;
		else cnts[i] = cnts[i / sieve[i]];
	}

	cin >> t;
	while (t--) {
		int c, d, x;
		cin >> c >> d >> x;
		ll ans = 0;
		for (int g = 1; g * g <= x; g++) {
			if (x % g == 0) {
				int tx = x / g + d;
				if (tx % c == 0) ans += fast_pow(2, cnts[tx / c]);
				tx = g + d;
				if (tx % c == 0 && g * g != x) ans += fast_pow(2, cnts[tx / c]);
			}
		}
		cout << ans << '\n';
	}
}