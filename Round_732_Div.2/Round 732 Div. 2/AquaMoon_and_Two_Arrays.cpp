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
int a[100], b[100];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		F0R(i, n) cin >> b[i];
		int asum = 0, bsum = 0;
		F0R(i, n) asum += a[i];
		F0R(i, n) bsum += b[i];
		if (asum != bsum) cout << "-1\n";
		else {
			vpii ans; 
			/*RF0R(i, n) {
				if (i == 0) continue;
				while (a[i] > 0) {
					ans.push_back({ i + 1, i });
					a[i]--;
					a[i - 1]++;
				}
			}
			F0R(i, n - 1) {
				while (a[i] != b[i]) {
					if (a[i] < b[i]) {
						ans.push_back({ i + 2, i + 1 });
						a[i]++;
						a[i + 1]--;
					}
					else {
						ans.push_back({ i + 1, i + 2 });
						a[i]--;
						a[i + 1]++;
					}
				}
			}*/

			int sp = 0, bp = 0;
			while (sp < n && bp < n) {
				while (sp < n && a[sp] >= b[sp]) sp++;
				while (bp < n && a[bp] <= b[bp]) bp++;
				if (sp >= n || bp >= n) break;
				while (a[sp] != b[sp] && a[bp] != b[bp]) {
					ans.push_back({ bp + 1, sp + 1 });
					a[bp]--;
					a[sp]++;
				}
			}
			cout << sz(ans) << '\n';
			F0R(i, sz(ans)) {
				cout << ans[i].first << ' ' << ans[i].second << '\n';
			}
		}
	}
}