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

#define MOD 1

int t;
int sums[200000];
int b[200000];

int main() {
	cin >> t;
	while (t--) {
		int n, k, m;
		cin >> n >> k >> m;
		F0R(i, m) {
			cin >> b[i];
		}
		if (n == m) {
			cout << "YES\n";
			continue;
		}
		if ((n - m) % (k - 1) != 0) {
			cout << "NO\n";
			continue;
		}

		FOR(i, 1, m) {
			sums[i] = b[i] - b[i - 1] - 1;
		}
	}
}