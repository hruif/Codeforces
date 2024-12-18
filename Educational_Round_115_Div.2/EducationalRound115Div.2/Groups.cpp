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

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> cnts(5);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				int p;
				cin >> p;
				if (p) cnts[j].push_back(i);
			}
		}
		bool poss = false;
		for (int i = 0; i < 5; i++) {
			if (sz(cnts[i]) < n / 2 + n % 2) continue;
			for (int j = i + 1; j < 5; j++) {
				if (sz(cnts[j]) < n / 2 + n % 2) continue;
				vector<bool> a(n, false);
				for (auto x : cnts[i]) a[x] = true;
				for (auto x : cnts[j]) a[x] = true;
				bool cur = true;
				for (auto x : a) if (!x) cur = false;
				if (cur) poss = true;
			}
		}
		if (poss) cout << "YES\n";
		else cout << "NO\n";
	}
}