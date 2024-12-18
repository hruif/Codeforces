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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[200000];
map<int, int> m;

int main() {
	cin >> t;
	while (t--) {
		m.clear();

		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		F0R(i, n) {
			m[a[i]]++;
		}
		vi v;
		for (auto x : m) {
			v.push_back(x.second);
		}
		sort(all(v));
		int cnt = max(0, v.back() * 2 - n);
		if (n % 2) cnt = max(cnt, 1);
		cout << cnt << '\n';

		/*int p = sz(v) - 1;
		RF0R(i, sz(v) - 1) {
			int val = min(v[i], v[p]);
			v[i] -= val;
			v[p] -= val;
			if (v[p] == 0) p = i;
			if (v[p] == 0) {
				p--;
				i--;
			}
		}
		if (p >= 0) cout << v[p] << '\n';
		else cout << 0 << '\n';*/
	}
}