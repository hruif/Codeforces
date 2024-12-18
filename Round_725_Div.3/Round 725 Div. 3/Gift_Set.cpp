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

int main() {
	cin >> t;
	while (t--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		if (a > b) swap(a, b);
		int init_gifts = min(x / a, y / b);
		if (x - init_gifts * a < a || a == b) cout << init_gifts << '\n';
		else {
			int dif = b - a;
			int tx = x - a * init_gifts, ty = y - b * init_gifts;
			ll tdif = tx + ty;
			if (tdif < a + b) cout << init_gifts << '\n';
			else {
				ll d = tdif * a / b;
				ll d1 = (tx - d) / dif, d2 = (ty - d) / dif, d3 = (tx - d) / dif + 1, d4 = (ty - d) / dif + 1;
				//d3 += d3 / abs(d3), d4 += d4 / abs(d4);
				ll ans = min(tx / b, ty / a);
				ans = max(ans, min((tx - d1 * dif) / a, (ty + d1 * dif) / b));
				ans = max(ans, min((ty - d2 * dif) / a, (tx + d2 * dif)) / b);
				if ((tx - d) % dif) ans = max(ans, min((tx - d3 * dif) / a, (ty + d3 * dif) / b));
				if ((ty - d) % dif) ans = max(ans, min((ty - d4 * dif) / a, (tx + d4 * dif) / b));
				d++;
				d1 = (tx - d) / dif, d2 = (ty - d) / dif, d3 = (tx - d) / dif + 1, d4 = (ty - d) / dif + 1;
				//d3 += d3 / abs(d3), d4 += d4 / abs(d4);
				ans = max(ans, min((tx - d1 * dif) / a, (ty + d1 * dif) / b));
				ans = max(ans, min((ty - d2 * dif) / a, (tx + d2 * dif)) / b);
				if ((tx - d) % dif) ans = max(ans, min((tx - d3 * dif) / a, (ty + d3 * dif) / b));
				if ((ty - d) % dif) ans = max(ans, min((ty - d4 * dif) / a, (tx + d4 * dif) / b));
				cout << init_gifts + ans << '\n';
			}
		}
	}
}