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
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[100];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		int l = 0, r = n - 1;
		int low = a[0], lowi = 0;
		int high = a[0], highi = 0;
		F0R(i, n) {
			if (a[i] < low) {
				low = a[i];
				lowi = i;
			}
			if (a[i] > high) {
				high = a[i];
				highi = i;
			}
		}
		int ldis = min(lowi, highi) + 1;
		int rdis = r - max(lowi, highi) + 1;
		int cost;
		if (ldis < rdis) {
			cost = ldis;
			F0R(i, n) {
				l = i;
				if (i > min(lowi, highi)) {
					break;
				}
			}
			ldis = max(lowi, highi) - l + 1;
			rdis = r - max(lowi, highi) + 1;
			cost += min(ldis, rdis);
		}
		else {
			cost = rdis;
			RF0R(i, n) {
				r = i;
				if (r < max(lowi, highi)) {
					break;
				}
			}
			ldis = min(lowi, highi) - l + 1;
			rdis = r - min(lowi, highi) + 1;
			cost += min(ldis, rdis);
		}
		cout << cost << '\n';
	}
}