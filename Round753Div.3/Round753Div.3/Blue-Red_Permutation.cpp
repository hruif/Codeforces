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
int a[200000];

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		F0R(i, n) a[i]--;
		string s;
		cin >> s;
		vector<int> b, r;
		F0R(i, n) {
			if (s[i] == 'B') b.push_back(a[i]);
			else r.push_back(a[i]);
		}
		sort(all(b)); sort(all(r));
		vector<int> bcnts(n, 0), rcnts(n, 0);
		bool poss = true;
		F0R(i, sz(b)) if (b[i] < 0) poss = false;;
		F0R(i, sz(b)) if (b[i] >= n) b[i] = n - 1;
		F0R(i, sz(r)) if (r[i] < 0) r[i] = 0;
		F0R(i, sz(r)) if (r[i] >= n) poss = false;
		if (!poss) {
			cout << "NO\n";
			continue;
		}
		F0R(i, sz(b)) bcnts[b[i]]++;
		F0R(i, sz(r)) rcnts[r[i]]++;
		ll cnt = 0;
		F0R(i, n) {
			cnt += bcnts[i];
			if (cnt > i + 1) poss = false;
		}
		cnt = 0;
		RF0R(i, n) {
			cnt += rcnts[i];
			if (cnt > n - i) poss = false;
		}
		if (poss) cout << "YES\n";
		else cout << "NO\n";
	}
}