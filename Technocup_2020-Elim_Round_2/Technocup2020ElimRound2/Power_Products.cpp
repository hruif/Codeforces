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

int n, k;
int a[100000];
map<vector<pair<int, int>>, int> m;

int main() {
	fast_cin();

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> v;
		int cnt = 0;
		while (a[i] % 2 == 0) {
			cnt++;
			a[i] /= 2;
		}
		cnt %= k;
		if (cnt > 0) v.push_back({ 2, cnt });
		for (int j = 3; j * j <= a[i]; j += 2) {
			cnt = 0;
			while (a[i] % j == 0) {
				a[i] /= j;
				cnt++;
			}
			cnt %= k;
			if (cnt > 0) v.push_back({ j, cnt });
		}
		if (a[i] > 1) v.push_back({ a[i], 1 });
		vector<pair<int ,int>> ov;
		for (auto x : v) ov.push_back({ x.first, k - x.second });
		ans += m[ov];
		m[v]++;
	}
	cout << ans << '\n';
}