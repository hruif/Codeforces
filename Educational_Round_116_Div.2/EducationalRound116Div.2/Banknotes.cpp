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
int a[10];

ll fast_pow(ll b, ll e) {
	if (e == 0) return 1;
	ll val = fast_pow(b, e / 2);
	val *= val;
	if (e % 2) val *= b;
	return val;
}

int main() {
	fast_cin();
	
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k++;
		F0R(i, n) cin >> a[i];
		sort(a, a + n);
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int dif = a[i + 1] - a[i];
			ll v = fast_pow(10, dif) - 1;
			if (v < k) {
				ans += fast_pow(10, a[i]) * v;
				k -= v;
			}
			else {
				ans += fast_pow(10, a[i]) * k;
				k = 0;
			}
		}
		ans += fast_pow(10, a[n - 1]) * k;
		cout << ans << '\n';
	}
}