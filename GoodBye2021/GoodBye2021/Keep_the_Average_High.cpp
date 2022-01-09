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
ll a[50000];

void solve() {
	ll n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	vector<bool> selected(n, true);
	for (int i = 0; i < n; i++) {
		if (!selected[i]) continue;
		if (i < n - 1 && a[i] + a[i + 1] < x * 2) selected[i + 1] = false;
		else if (i < n - 2 && a[i] + a[i + 1] + a[i + 2] < x * 3 && selected[i + 1]) selected[i + 2] = false;
	}
	int cnt = 0;
	for (auto x : selected)
		if (x) cnt++;
	cout << cnt << '\n';
}

int main() {
	fast_cin();

	cin >> t;
	while (t--)
		solve();
}