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
int c[100000];

int main() {
	cin >> t;
	while (t--) {
		int k, n;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		int mincount = -1;
		FOR(i, 1, 101) {
			int count = 0;
			int paint = 0;
			for (int j = 0; j < n; j++) {
				if (paint > 0) {
					paint--;
					continue;
				}
				if (c[j] != i) {
					paint = k - 1;
					count++;
				}
			}
			if (count < mincount || mincount == -1) {
				mincount = count;
			}
		}
		cout << mincount << '\n';
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