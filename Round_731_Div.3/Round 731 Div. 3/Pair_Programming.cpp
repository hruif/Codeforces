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
		int k, n, m;
		cin >> k >> n >> m;
		F0R(i, n) cin >> a[i];
		F0R(i, m) cin >> b[i];
		vi ans;
		int ap = 0, bp = 0;
		bool poss = true;
		while (ap < n || bp < m) {
			if (ap == n) {
				if (b[bp] > k) {
					poss = false;
					break;
				}
				else {
					if (b[bp] == 0) k++;
					ans.push_back(b[bp++]);
				}
			}
			else if (bp == m) {
				if (a[ap] > k) {
					poss = false;
					break;
				}
				else {
					if (a[ap] == 0) k++;
					ans.push_back(a[ap++]);
				}
			}
			else if (a[ap] > k) {
				if (b[bp] > k) {
					poss = false;
					break;
				}
				else {
					if (b[bp] == 0) k++;
					ans.push_back(b[bp++]);
				}
			}
			else {
				if (a[ap] == 0) k++;
				ans.push_back(a[ap++]);
			}
		}

		if (poss) {
			F0R(i, sz(ans)) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
		else cout << "-1\n";
	}
}