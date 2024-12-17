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
vector<pair<int, int>> rs;

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		rs.clear();

		int n;
		cin >> n;
		map<int, pair<int, int>> m;
		for (int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			rs.push_back({ l, r });
		}
		sort(rs.begin(), rs.end());

		for (int i = 1; i <= n; i++) {
			int l = n, r = 1;
			for (int j = 0; j < n; j++) {
				if (rs[j].first == i + 1) r = max(r, rs[j].second);
				if (rs[j].second == i - 1) l = min(l, rs[j].first);
			}
			if (l == n) l = i;
			if (r == 1) r = i;
			cout << l << ' ' << r << ' ' << i << '\n';
		}
		cout << '\n';
	}
}