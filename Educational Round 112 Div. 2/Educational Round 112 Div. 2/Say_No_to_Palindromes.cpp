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

int n, m;
string s;

int main() {
	cin >> n >> m;
	cin >> s;
	vector<vvi> pos(3, vvi(3, vi(n, 0)));
	F0R(i, n) {
		if (i > 0) {
			F0R(j, 3) {
				F0R(k, 3) {
					pos[j][k][i] = pos[j][k][i - 1];
				}
			}
		}

		int c = s[i] - 'a';
		int p = i % 3;
		pos[c][p][i]++;
	}
	F0R(q, m) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		int ans = r - l + 1;
		int si, sj, sk;
		si = sj = sk = ans / 3;
		if (ans % 3) si++;
		if (ans % 3 > 1) sj++;
		if (l % 3) {
			if (l % 3 == 1) {
				swap(si, sj);
				swap(si, sk);
			}
			else {
				swap(si, sk);
				swap(si, sj);
			}
		}
		int s[3] = { si, sj, sk };
		F0R(i, 3) {
			int ci = pos[0][i][r];
			if (l > 0) ci -= pos[0][i][l - 1];
			int di = max(0, s[i] - ci);

			F0R(j, 3) {
				if (i == j) continue;
				int cj = pos[1][j][r];
				if (l > 0) cj -= pos[1][j][l - 1];
				int dj = max(0, s[j] - cj);

				F0R(k, 3) {
					if (i == k || j == k) continue;
					int ck = pos[2][k][r];
					if (l > 0) ck -= pos[2][k][l - 1];
					int dk = max(0, s[k] - ck);

					ans = min(ans, di + dj + dk);
				}
			}
		}
		cout << ans << '\n';
	}
}