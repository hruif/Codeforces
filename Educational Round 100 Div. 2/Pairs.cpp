#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

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
int vals[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) {
			cin >> vals[i];
		}
		sort(vals, vals + n);

		int minmax = 0;

		int maxv = n * 2;
		int space = 0;
		RF0R(i, n - 1) {
			if (vals[i] == maxv) {
				if (space == 0) minmax++;
				else space--;
				maxv--;
			}
			else {
				space += maxv - vals[i];
				maxv = vals[i];
			}
		}
		int minmin = 0;
		space = 0;
		int minv = 1;
		F0R(i, n) {
			if (vals[i] == minv) {
				if (space == 0) minmin++;
				else space--;
				minv++;
			}
			else {
				space += vals[i] - minv;
				minv = vals[i];
			}
		}
		cout << n + 1 - minmin - minmax << '\n';
	}
}