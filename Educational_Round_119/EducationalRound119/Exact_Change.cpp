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
int a[100];

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int c3 = 0, c2 = 0, c1 = 0;
		for (int i = 0; i < n; i++) c3 = max(c3, a[i] / 3);
		for (int i = 0; i < n; i++) {
			if (a[i] == c3 * 3 + 1) c1 = 1;
			if (a[i] == c3 * 3 + 2) c2 = 1;
		}
		if (c2 != 0 && c1 != 0) cout << c3 + 2 << '\n'; // c3 * 3 + 2 and + 1
		else {
			for (int i = 0; i < n; i++) {
				if (a[i] % 3 == 1) c1 |= 2;
				if (a[i] % 3 == 2) c2 |= 2;
			}
			if (!(c1 & 1) && !(c2 & 1)) { // no bigger than c3 * 3
				if (!(c1 & 2) && !(c2 & 2)) cout << c3 << '\n'; // no non-multiples of 3
				else cout << c3 + 1 << '\n'; // c3 - 1, 1, 1
			}
			else {
				if (c1 & 1) { // c3 * 3 + 1 but no c3 * 3 + 2
					if (c2 & 2) { // need to account for % 3 == 2
						bool val = true;
						for (int i = 0; i < n; i++) if (a[i] == c3 * 3 || a[i] == 1) val = false; // check if can c3 - 1, 2, 0
						if (val) cout << c3 + 1 << '\n';
						else cout << c3 + 2 << '\n'; // no way to reduce further
					}
					else cout << c3 + 1 << '\n'; // only % 3 == 1s
				}
				else { // c3 * 3 + 2 but no c3 * 3 + 1
					if (c1 & 2) cout << c3 + 2 << '\n'; // if need to account for % 3 == 1, no way to reduce
					else cout << c3 + 1 << '\n'; // otherwise, of course
				}
			}
		}
	}
}