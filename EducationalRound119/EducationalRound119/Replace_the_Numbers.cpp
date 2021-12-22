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

int q;
map<int, int> m;
vector<pair<int, int>> qs;

int main() {
	fast_cin();

	cin >> q;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		qs.push_back({ -1, -1 });
		if (t == 1) cin >> qs.back().second;
		else cin >> qs.back().first >> qs.back().second;
	}
	vector<int> ans;
	for (int i = q - 1; i >= 0; i--) {
		if (m[qs[i].second] == 0) m[qs[i].second] = qs[i].second;
		if (qs[i].first == -1) ans.push_back(m[qs[i].second]);
		else m[qs[i].first] = m[qs[i].second];
	}
	reverse(all(ans));
	for (auto x : ans) cout << x << ' ';
	cout << '\n';
}