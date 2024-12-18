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
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vi as;
		F0R(i, n) {
			if (s[i] == 'a') as.push_back(i);
		}
		int ans = n + 1;
		for (int i = 1; i < sz(as); i++) {
			int b = 0, c = 0;
			for (int j = as[i - 1] + 1; j < as[i]; j++) {
				if (s[j] == 'b') b++;
				else c++;
			}
			if (b <= 1 && c <= 1) {
				ans = min(ans, as[i] - as[i - 1] + 1);
			}
			if (i + 1 < sz(as)) {
				for (int j = as[i] + 1; j < as[i + 1]; j++) {
					if (s[j] == 'b') b++;
					else c++;
				}
				if (b <= 2 && c <= 2) {
					ans = min(ans, as[i + 1] - as[i - 1] + 1);
				}
			}
		}
		if (ans == n + 1) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}