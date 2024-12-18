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

int q;
int a[300000], t[300000];
pair<pii, int> acs[300000];

int main() {
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		F0R(i, k) cin >> a[i];
		F0R(i, k) a[i]--;
		F0R(i, k) cin >> t[i];
		F0R(i, k) acs[i] = { {a[i], t[i]}, i };
		sort(acs, acs + k);
		vi valac(k, k);
		pii prev = { acs[k - 1].first.first, acs[k - 1].first.second };
		int pi = k - 1;
		RF0R(i, k - 1) {
			if (acs[i].first.second - prev.second > prev.first - acs[i].first.first) {
				valac[i] = pi;
			}
			else {
				prev = { acs[i].first.first, acs[i].first.second };
				pi = i;
			}
		}

		int p = 0, acp = 0;
		vi ans(n);
		while (p < n) {
			int nacp = valac[acp]; 
			bool ok = true;
			while (ok) {
				ok = false;
				while (acp + 1 < k && (acs[acp].first.second + abs(acs[acp].first.first - p)) > (acs[acp + 1].first.second + abs(acs[acp + 1].first.first - p))) {
					acp++;
					ok = true;
				}
				while (nacp < k && (acs[acp].first.second + abs(acs[acp].first.first - p)) >(acs[nacp].first.second + abs(acs[nacp].first.first - p))) {
					acp = valac[acp];
					nacp = valac[acp];
					ok = true;
				}
			}
			
			ans[p] = acp;
			p++;
		}
		F0R(i, n) cout << abs(acs[ans[i]].first.first - i) + acs[ans[i]].first.second << ' ';
		cout << '\n';
	}
}