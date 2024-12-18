#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

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
bool plat[100000];
int cells[100000];

int main() {
	cin >> t;
	while (t--) {
		memset(cells, 0, sizeof(cells));

		int n, p, k;
		int x, y;
		cin >> n >> p >> k;
		F0R(i, n) {
			char b;
			cin >> b;
			if (b == '0') plat[i] = false;
			else		  plat[i] = true;
		}
		cin >> x >> y;
		RF0R(j, n - 1) {
			if (!plat[j]) {
				cells[j] = 1;
			}
			if (j <= n - k - 1) {
				cells[j] += cells[j + k];
			}
		}
		int mincost = -1;
		FOR(i, p - 1, n) {
			int cost = cells[i] * x + (i - p + 1) * y;
			if (cost < mincost || mincost == -1) mincost = cost;
		}
		cout << mincost << '\n';
	}
}

/*
* think everything through before starting coding
* start with simplest method
* actually calculate complexities
*/

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
*/