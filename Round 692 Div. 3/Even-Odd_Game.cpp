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
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

int t;
ll a[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		sort(a, a + n);

		bool alice = true;
		ll asum = 0, bsum = 0;
		RF0R(i, n - 1) {
			if (a[i] % 2 == 0) {
				if (alice) asum += a[i];
			}
			else {
				if (!alice) bsum += a[i];
			}
			alice = !alice;
		}

		if (asum > bsum) cout << "Alice\n";
		if (bsum > asum) cout << "Bob\n";
		if (asum == bsum) cout << "Tie\n";
	}
}