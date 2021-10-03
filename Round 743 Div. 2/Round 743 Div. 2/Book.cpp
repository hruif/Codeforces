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
vector<set<int>> pars;
vvi ch;
vi uday;
vb understood;

void understand(int book) {
	if (understood[book]) return;
	if (pars[book].empty()) {
		understood[book] = true;
		if (uday[book] == -1) uday[book] = 1;
		int day = uday[book];
		F0R(i, sz(ch[book])) {
			int j = ch[book][i];
			if (understood[j]) continue;
			int tday = day;
			if (book > j) tday++;
			uday[j] = max(uday[j], tday);
			pars[j].erase(pars[j].find(book));
			understand(j);
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		pars.clear(); ch.clear(); uday.clear(); understood.clear();

		int n;
		cin >> n;
		// resizing
		{
			uday.rsz(n, -1);
			understood.rsz(n, false);
			pars.rsz(n); ch.rsz(n);
		} 

		// input
		F0R(i, n) {
			int k;
			cin >> k;
			F0R(j, k) {
				int p;
				cin >> p;
				p--;
				pars[i].insert(p);
			}
		}
		F0R(i, n) {
			for (auto x : pars[i]) {
				ch[x].push_back(i);
			}
		}

		F0R(i, n) {
			understand(i);
		}
		int ans = 0;
		F0R(i, n) {
			ans = max(ans, uday[i]);
			if (!understood[i]) ans = n * 2;
		}
		if (ans == n * 2) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}