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
pii a[200000];

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i].first;
		for (int i = 0; i < n; i++) a[i].second = i;
		sort(a, a + n);
		ll pcur = 1, ncur = 1;
		vll ans(n + 1, 0);
		ll cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (abs(pcur) == abs(ncur)) {
				cnt += pcur * 2 * a[i].first;
				ans[a[i].second + 1] = pcur++;
			}
			else {
				cnt += ncur * 2 * a[i].first;
				ans[a[i].second + 1] = -ncur++;
			}
		}
		cout << cnt << '\n';
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}