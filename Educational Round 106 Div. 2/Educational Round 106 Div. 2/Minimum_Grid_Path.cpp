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
ll c[100000];

int main() {
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vll psum(n, 0);
		vll minh(n, 0), minv(n, 0);
		F0R(i, n) cin >> c[i];
		minv[0] = c[0];
		minh[0] = c[1];
		psum[0] = c[0];
		F1R(i, n) {
			psum[i] = psum[i - 1] + c[i];
			if (i % 2 == 0) {
				minv[i] = min(minv[i - 1], c[i]);
				minh[i] = minh[i - 1];
			}
			else {
				minh[i] = min(minh[i - 1], c[i]);
				minv[i] = minv[i - 1];
			}

		}
		ll cost = c[0] * n + c[1] * n;
		map<int, int> m;
		F0R(i, n) m[c[i]]++;
		int p = n - 1;
		ll ans = cost;
		RF0R(i, n) {
			if (i == 0) break;
			int vcnt = i / 2 + 1;
			int hcnt = i / 2;
			if (i % 2) hcnt++;
			ans = min(ans, psum[i] + minv[i] * (n - vcnt) + minh[i] * (n - hcnt));
		}
		cout << ans << '\n';
	}
}