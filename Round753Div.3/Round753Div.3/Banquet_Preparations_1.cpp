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
ll a[200000], b[200000];
ll eat_a[200000], eat_b[200000];

int main() {
	fast_cin();
	
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		F0R(i, n) cin >> a[i] >> b[i];
		F0R(i, n) eat_a[i] = eat_b[i] = 0;
		ll sa = 0, sb = 0;
		F0R(i, n) {
			if (a[i] >= m) {
				sa += a[i] - m;
				sb += b[i];
				eat_a[i] = m;
			}
			else {
				sb += b[i] - (m - a[i]);
				eat_a[i] = a[i];
				eat_b[i] = m - a[i];
			}
		}
		F0R(i, n) {
			if (sa < sb - 1) {
				ll dif = (sb - sa) / 2;
				if (b[i] - eat_b[i] >= dif) {

				}
				else {
					dif = b[i] - eat_b[i];
				}
				dif = min(dif, min(b[i] - eat_b[i], eat_a[i]));
				eat_b[i] += dif;
				eat_a[i] -= dif;
				sa += dif;
				sb -= dif;
			}
		}
		cout << abs(sa - sb) << '\n';
		F0R(i, n) {
			cout << eat_a[i] << ' ' << eat_b[i] << '\n';
		}
	}
}