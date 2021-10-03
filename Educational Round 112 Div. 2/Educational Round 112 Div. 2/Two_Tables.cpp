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

int main() {
	cin >> t;
	while (t--) {
		int W, H;
		cin >> W >> H;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int w, h;
		cin >> w >> h;
		if (x2 - x1 + w > W && y2 - y1 + h > H) cout << -1 << '\n';
		else {
			ll dl = x2 - W + w, dr = w - x1, dd = y2 - H + h, du = h - y1;
			ll ans = max(W, H);
			if (x2 - x1 + w <= W) ans = min(ans, min(dl, dr));
			if (y2 - y1 + h <= H) ans = min(ans, min(dd, du));
			cout << max((ll)(0), ans) << '\n';
		}
	}
}