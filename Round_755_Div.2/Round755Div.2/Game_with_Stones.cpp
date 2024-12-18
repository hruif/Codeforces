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
int a[300000];
vi es;

void set_st(vi& st, int n) {
	st.clear();
	int sn = 1;
	while (sn < n) sn *= 2;
	st.rsz(sn * 2, 0);
}

int find_val(vi& st, int a, int b) {
	int sn = st.size() / 2;
	a += sn; b += sn;
	int val = 0;
	while (a <= b) {
		if (a % 2 == 1) val += st[a++];
		if (b % 2 == 0) val += st[b--];
		a /= 2; b /= 2;
	}
	return val;
}

void change_val(vi& st, int k, int x) {
	int sn = st.size() / 2;
	k += sn;
	st[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = st[k * 2] + st[k * 2 + 1];
	}
}

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set_st(es, n);
		F0R(i, n) cin >> a[i];
		vll psum(n, 0);
		psum[0] = a[0];
		F1R(i, n) psum[i] = psum[i - 1] + a[i];
		F0R(i, n) if (psum[i] % 2 == 0) change_val(es, i, 1);
		vi lr(n), rl(n);
		int cur = 0, prev = -1;
		F0R(i, n) {
			if (a[i] <= prev) cur++;
			else cur = 0;
			rl[i] = cur;
			prev = a[i];
		}
		cur = 0, prev = -1;
		RF0R(i, n) {
			if (a[i] <= prev) cur++;
			else cur = 0;
			lr[i] = cur;
			prev = a[i];
		}
		ll ans = 0;
		F0R(i, n) {
			int l, r;
			if (i > 0) {
				if (lr[i - 1] == 0 || rl[i] == 0) continue;
				l = i - lr[i - 1];
				r = i + rl[i] - 1;
				ll ex = l == 0 ? 0 : psum[l - 1], ex2 = psum[i - 1];
				ex2 -= ex;
				ll lt = i - l, rt = r - i + 1;
				ll lv = find_val(es, l, i - 1), rv = find_val(es, i, r);
				if (ex % 2) {
					if (ex2 % 2 == 0) ans += (lt - lv) * rv + lv * (rt - rv);
					else ans += lv * rv + (lt - lv) * (rt - rv);
				}
				else {
					if (ex2 % 2 == 0) ans += lv * rv + (lt - lv) * (rt - rv);
					else ans += (lt - lv) * rv + lv * (rt - rv);
				}
			}
			/*if (i < n - 1) {
				l = i - lr[i];
				r = i + rl[i + 1] + 1;
				ll ex = l == 0 ? 0 : psum[l - 1];
				ll lt = i - l + 1, rt = r - i;
				ll lv = find_val(es, l, i), rv = find_val(es, i + 1, r);
				if (ex % 2) {
					ans += (lt - lv) * rv + lv * (rt - rv);
				}
				else {
					ans += lv * rv + (lt - lv) * (rt - rv);
				}
			}*/
			if (a[i] == 0) ans++;
		}
		cout << ans << '\n';
	}
}