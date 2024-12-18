#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
vpii segs;
vi ls, rs;

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ls.resize(n);
		rs.resize(n);
		segs.resize(n);

		F0R(i, n) {
			cin >> ls[i] >> rs[i];
			segs[i] = make_pair(ls[i], rs[i]);
		}
		sort(ls.begin(), ls.end());
		sort(rs.begin(), rs.end());

		int minex = 100000000;
		F0R(i, n) {
			int l = segs[i].first, r = segs[i].second;
			int ex = lower_bound(rs.begin(), rs.end(), l) - rs.begin();
			ex += n - (upper_bound(ls.begin(), ls.end(), r) - ls.begin());
			minex = min(minex, ex);
		}
		cout << minex << '\n';
	}
}