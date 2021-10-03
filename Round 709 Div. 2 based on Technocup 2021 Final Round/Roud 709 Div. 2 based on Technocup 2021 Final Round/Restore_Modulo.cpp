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
int a[100000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		if (n == 1) cout << '0' << '\n';
		else if (a[0] == a[1]) {
			bool same = true;
			F1R(i, n) if (a[i] != a[i - 1]) same = false;
			if (same) cout << '0' << '\n';
			else cout << "-1\n";
		}
		else {
			int dif = a[1] - a[0];
			F1R(i, n) dif = max(dif, a[i] - a[i - 1]);
			if (dif < 0) {
				bool same = true;
				F1R(i, n) if (a[i] - a[i - 1] != dif) same = false;
				if (same) cout << '0' << '\n';
				else cout << "-1\n";
			}
			else {
				int mx = -1, mxn;
				F1R(i, n) {
					if (a[i] < a[i - 1]) {
						mx = a[i - 1];
						mxn = a[i];
					}
				}
				if (mx == -1) {
					bool same = true;
					F1R(i, n) if (a[i] - a[i - 1] != dif) same = false;
					if (same) cout << '0' << '\n';
					else cout << "-1\n";
				}
				else {
					int m = mx + dif - mxn;
					bool same = true;
					F1R(i, n) if ((a[i - 1] + dif) % m != a[i]) same = false;
					if (a[0] >= m) same = false;
					if (same) cout << m << ' ' << dif << '\n';
					else cout << "-1\n";
				}
			}
		}
	}
}