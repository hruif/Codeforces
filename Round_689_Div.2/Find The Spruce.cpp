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

int t, n, m;
bool grid[500][500];
int lrs[500][500][2];
int len[500][500];

int findlen(int x, int y, int plen) {
	if (y + (plen - 1) >= m || y < plen - 1 || x >= n) return plen;
	if (y - lrs[x][y][0] < plen - 1 || lrs[x][y][1] - y < plen - 1) return plen;
	int nl = findlen(x + 1, y, plen + 1);
	len[x][y] = nl - plen;
	return nl;
}

int main() {
	cin >> t;
	while (t--) {
		memset(grid, false, sizeof(grid));
		memset(lrs, -1, sizeof(lrs));

		cin >> n >> m;
		F0R(i, n) {
			F0R(j, m) {
				char g;
				cin >> g;
				if (g == '*') grid[i][j] = true;
				len[i][j] = 1;
			}
		}

		F0R(i, n) {
			int last = -1;
			F0R(j, m) {
				if (grid[i][j]) {
					if (last == -1) last = j;
					lrs[i][j][0] = last;
				}
				else last = -1;
			}
			last = -1;
			RF0R(j, m - 1) {
				if (grid[i][j]) {
					if (last == -1) last = j;
					lrs[i][j][1] = last;
				}
				else last = -1;
			}
		}

		int total = 0;
		F0R(i, n) {
			F0R(j, m) {
				if (grid[i][j]) {
					total += findlen(i + len[i][j], j, len[i][j] + 1) - 1;
				}
			}
		}

		cout << total << '\n';
	}
}