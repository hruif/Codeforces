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
ll a[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];

		ll ans = n + n - 1;
		if (n > 2) ans += n - 2;
		if (n > 3) ans += n - 3;
		//F0R(i, n) {
		//	bool ts = false, fs = false;
		//	FOR(j, i + 1, min(n, i + 3)) {
		//		ll d1 = j - i + abs(a[i] - a[j]);
		//		FOR(k, j + 1, min(n, i + 4)) {
		//			if (k == i + 2 && ts) continue;
		//			if (k == i + 3 && fs) continue;

		//			ll d2 = k - i + abs(a[k] - a[i]);
		//			ll d3 = k - j + abs(a[k] - a[j]);
		//			if ((d1 + d2 == d3 || d2 + d3 == d1 || d3 + d1 == d2)) {
		//				ans--;
		//				if (k == i + 2) ts = true;
		//				else fs = true;
		//			}
		//		}
		//	}
		//}
		F0R(i, n - 2) {
			ll d1 = 1 + abs(a[i] - a[i + 1]), d2 = 2 + abs(a[i] - a[i + 2]), d3 = 1 + abs(a[i + 2] - a[i + 1]);
			if (d1 + d2 == d3 || d2 + d3 == d1 || d1 + d3 == d2) ans--;
			if (i < n - 3) {
				d1 = 1 + abs(a[i] - a[i + 1]), d2 = 3 + abs(a[i] - a[i + 3]), d3 = 2 + abs(a[i + 3] - a[i + 1]);
				if (d1 + d2 == d3 || d2 + d3 == d1 || d1 + d3 == d2) ans--;
				else {
					d1 = 2 + abs(a[i] - a[i + 2]), d2 = 3 + abs(a[i] - a[i + 3]), d3 = 1 + abs(a[i + 2] - a[i + 3]);
					if (d1 + d2 == d3 || d2 + d3 == d1 || d1 + d3 == d2) ans--;
				}
			}
		}
		cout << ans << '\n';
	}
}