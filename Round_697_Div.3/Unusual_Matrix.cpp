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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vi> a(n, vi(n)), b(n, vi(n));
		F0R(i, n) {
			F0R(j, n) {
				char bit;
				cin >> bit;
				a[i][j] = bit - '0';
			}
		}
		F0R(i, n) {
			F0R(j, n) {
				char bit;
				cin >> bit;
				b[i][j] = bit - '0';
			}
		}

		vi rows(n, 0), cols(n, 0);
		bool inv = false;
		F0R(i, n) {
			F0R(j, n) {
				int bit = a[i][j];
				F0R(k, rows[i] + cols[j]) bit ^= 1;
				if (bit != b[i][j]) {
					if (rows[i] || j > 0) {
						if (cols[j] || i > 0) inv = true;
						else cols[j] = 1;
					}
					else rows[i] = 1;
				}
			}
		}
		F0R(i, n) {
			rows[i] = 0;
			cols[i] = 0;
		}
		rows[0] = true;
		F0R(i, n) {
			F0R(j, n) {
				int bit = a[i][j];
				F0R(k, rows[i] + cols[j]) bit ^= 1;
				if (bit != b[i][j]) {
					if (rows[i]) {
						if (cols[j]) inv = true;
						else cols[j] = 1;
					}
					else rows[i] = 1;
				}
			}
		}
		if (!inv) cout << "YES\n";
		else cout << "NO\n";
	}
}