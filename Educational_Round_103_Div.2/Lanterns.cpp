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
int p[300000];
char dirs[300000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> p[i];
		int l = 0;
		int tor = 0;
		while (tor <= l) {
			int maxr = l;
			FOR(i, l + 1, n) {
				if (p[i] >= i) maxr = i;
			}
			if (maxr == 0) {
				cout << "NO\n";
				continue;
			}
			if (maxr == n - 1) {
				cout << "YES\n";
				F0R(i, n - 1) cout << 'R';
				cout << "L\n";
			}
			dirs[maxr] = 'L';
		}
		
		F0R(i, maxr) {
			dirs[i] = 'R';
			tor = max(tor, p[i] + i);
		}
		if (tor <= maxr) {
			cout << "NO\n";
			continue;
		}
		int pi = maxr + 1;
		while (tor < n - 1) {
			FOR(i, pi, tor + 1) {
				dirs[i] = 'R';
				int val = p[i] + i;
				tor = min(n - 1, max(val, tor));
			}
			if (pi > tor) break;
		}
		if (tor >= n - 1) {
			cout << "YES\n";
			F0R(i, n) {
				cout << dirs[i];
			}
			cout << '\n';
		}
		else cout << "NO\n";
	}
}