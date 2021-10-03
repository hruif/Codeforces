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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m;
ll exc[4];
vector<vb> grid;
vvi dsq;

ll exp(ll b, ll e) {
	if (e == 0) return 1;
	ll val = exp(b, e / 2);
	val *= val;
	val %= MOD;
	if (e % 2) val *= b;
	return val % MOD;
}

int main() {
	cin >> n >> m;
	grid.rsz(n, vb(m, false));
	dsq.rsz(n, vi(m, 0));
	int cnt = 0;
	F0R(i, n) {
		F0R(j, m) {
			char c;
			cin >> c;
			if (c == 'o') {
				grid[i][j] = true;
				cnt++;
			}
		}
	}
	int tot = cnt;
	F0R(i, 4) exc[i] = exp(2, cnt - 2 - i);
	ll ans = 0;
	F0R(i, n) {
		cnt = 0;
		ll ocnt = 0, orr = 0, orb = 0;
		ll ecnt = 0, err = 0, erb = 0;
		F0R(j, m) {
			if (grid[i][j]) {
				cnt++;
				if (cnt % 2) {
					if (cnt == 1) orb = 1;
					else {
						int ncnt = ocnt * 4;
						ncnt += exp(2, cnt - 2);
						ncnt += orb;
						orr += exp(2, cnt - 2) - orr - orb;
						orb += exp(2, cnt - 2);
						ocnt = ncnt;
					}
				}
				else {
					int ncnt = ecnt * 4;
					err += exp(2, cnt - 2) - err - erb;
					ncnt += erb * 2;
					erb += exp(2, cnt - 2);
					ncnt += err;
					ecnt = ncnt;
				}
			}
			else {
				if (cnt % 2) ans += ocnt * exp(2, tot - cnt);
				else ans += ecnt * exp(2, tot - cnt);
				cnt = 0;
				ocnt = ecnt = 0;
				orr = err = 0;
				orb = erb = 0;
			}
		}
		if (cnt % 2) ans += ocnt * exp(2, tot - cnt);
		else ans += ecnt * exp(2, tot - cnt);
		cnt = 0;
		ocnt = ecnt = 0;
		orr = err = 0;
		orb = erb = 0;
	}
	F0R(j, m) {
		cnt = 0;
		ll ocnt = 0, orr = 0, orb = 0;
		ll ecnt = 0, err = 0, erb = 0;
		F0R(i, n) {
			if (grid[i][j]) {
				cnt++;
				if (cnt % 2) {
					if (cnt == 1) orb = 1;
					else {
						ll ncnt = ocnt * 4;
						ncnt += exp(2, cnt - 2);
						ncnt += orb;
						orr += exp(2, cnt - 2) - orr - orb;
						orb += exp(2, cnt - 2);
						ocnt = ncnt;

						orr %= MOD;
						orb %= MOD;
						ocnt %= MOD;
					}
				}
				else {
					ll ncnt = ecnt * 4;
					err += exp(2, cnt - 2) - err - erb;
					ncnt += erb * 2;
					erb += exp(2, cnt - 2);
					ncnt += err;
					ecnt = ncnt;

					err %= MOD;
					erb %= MOD;
					ecnt %= MOD;
				}
			}
			else {
				if (cnt % 2) ans += ocnt * exp(2, tot - cnt);
				else ans += ecnt * exp(2, tot - cnt);
				ans %= MOD;
				cnt = 0;
				ocnt = ecnt = 0;
				orr = err = 0;
				orb = erb = 0;
			}
		}
		if (cnt % 2) ans += ocnt * exp(2, tot - cnt);
		else ans += ecnt * exp(2, tot - cnt);
		ans %= MOD;
		cnt = 0;
		ocnt = ecnt = 0;
		orr = err = 0;
		orb = erb = 0;
	}
	cout << ans << '\n';
}