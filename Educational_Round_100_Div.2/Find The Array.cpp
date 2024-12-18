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
int a[50];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) {
			cin >> a[i];
		}

		ll t1 = 0;
		ll t2 = 1;
		FORI(i, 0, n, 2) {
			t1 += a[i] - 1;
		}
		FORI(i, 1, n, 2) {
			t2 += a[i] - 1;
		}
		if (t1 > t2) {
			F0R(i, n) {
				if (i != 0) cout << ' ';
				
				if (i % 2 == 1) cout << 1;
				else cout << a[i];
			}
			cout << '\n';
		}
		else {
			F0R(i, n) {
				if (i != 0) cout << ' ';

				if (i % 2 == 0) cout << 1;
				else cout << a[i];
			}
			cout << '\n';
		}
	}
}