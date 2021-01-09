#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define INF (ll)(1e16)
#define MOD 1

int t;
vll k, c, cnt;

int main() {
	cin >> t;
	while (t--) {
		k.clear(), c.clear(), cnt.clear();

		int n, m;
		cin >> n >> m;
		k.resize(n, 0);
		c.resize(m, 0);
		cnt.resize(m, 0);
		F0R(i, n) {
			cin >> k[i];
			k[i]--;
		}
		F0R(i, m) cin >> c[i];

		ll total = 0;
		F0R(i, n) {
			cnt[k[i]]++;
			total += c[k[i]];
		}
		int gp = 0;
		int red = m - 1;
		while (red > gp) {
			while (red > gp && cnt[red] == 0) red--;
			total -= c[red] - c[gp++];
			cnt[red]--;
		}

		cout << total << '\n';
	}
}