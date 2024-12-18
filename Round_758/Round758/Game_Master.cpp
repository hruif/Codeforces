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
int oa[100000], ob[100000];
vector<pair<int, int>> a, b;

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		a.resize(n); b.resize(n);
		for (int i = 0; i < n; i++) cin >> oa[i];
		for (int i = 0; i < n; i++) cin >> ob[i];
		for (int i = 0; i < n; i++) a[i] = { oa[i], i };
		for (int i = 0; i < n; i++) b[i] = { ob[i], i };
		sort(all(a)); sort(all(b));

		int p1 = n - 2, p2 = n - 2;
		int s1 = oa[b.back().second], s2 = ob[a.back().second];

		set<int> ans;
		ans.insert(a.back().second);
		ans.insert(b.back().second);
		while ((p1 >= 0 && a[p1].first > s1)) {
			int os1 = s1, os2 = s2;
			while (p1 >= 0 && a[p1].first > s1) {
				int i = a[p1].second;
				ans.insert(i);
				s2 = min(s2, ob[i]);
				p1--;
			}
			while (p2 >= 0 && b[p2].first > s2) {
				int i = b[p2].second;
				ans.insert(i);
				s1 = min(s1, oa[i]);
				p2--;
			}
		}
		vector<int> an(n, 0);
		for (auto x : ans) an[x] = 1;
		for (auto x : an) cout << x;
		cout << '\n';
	}
}