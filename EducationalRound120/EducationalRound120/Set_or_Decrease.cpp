#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cmath>
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
#include <array>

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
int a[200000];

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ll cur = 0;
		for (int i = 0; i < n; i++) cur += a[i];
		ll steps = 0;
		ll ind = n - 1;
		while (cur > k) {
			if (ind == 0) {
				ll ex = (cur - k) / n;
				if ((cur - k) % n) ex++;
				cur -= ex * n;
				steps += ex;
			}
			else {
				ll cnt = n - ind;
				if (cnt > a[ind] - a[0]) {
					a[0]--;
					cur -= cnt;
					steps++;
				}
				else {
					cur -= a[ind] - a[0];
					ind--;
					steps++;
				}
			}
		}
		cout << steps << '\n';
	}
}