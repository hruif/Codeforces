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

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
ll l[100000], r[100000], c[100000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i] >> c[i];
	int ls = 0, rs = 0;
	int oneseg = 0;
	cout << c[0] << '\n';
	for (int i = 1; i < n; i++) {
		bool lbet = l[i] <= l[ls], rbet = r[i] >= r[rs];
		if (lbet && rbet) {
			if (oneseg == -1) oneseg = i;
			else if (l[i] < l[oneseg] || r[i] > r[oneseg] || c[i] < c[oneseg]) oneseg = i;
			if (l[i] < l[ls]) ls = i;
			else if (c[i] < c[ls]) ls = i;
			if (r[i] > r[rs]) rs = i;
			else if (c[i] < c[rs]) rs = i;
		}
		else {
			if (lbet) {
				lbet = l[i] < l[ls];
				if (lbet) {
					oneseg = -1;
					ls = i;
				}
				else {
					if (c[i] < c[ls]) ls = i;
				}
			}
			else if (rbet) {
				rbet = r[i] > r[rs];
				if (rbet) {
					oneseg = -1;
					rs = i;
				}
				else {
					if (c[i] < c[rs]) rs = i;
				}
			}
		}
		ll cost = c[ls] + c[rs];
		if (oneseg != -1) cost = min(cost, c[oneseg]);
		cout << cost << '\n';
	}
}

int main() {
	fast_cin();

	cin >> t;
	while (t--)
		solve();
}