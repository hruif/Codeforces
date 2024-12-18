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
int b[200001];

int main() {
	cin >> t;
	while (t--) {
		int n, k, m;
		cin >> n >> k >> m;
		vi pre(m, 0);
		vi po(m, 0);
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

		int p = 0;
		int cnt = 0;
		b[m] = n + 1;
		F0R(i, n) {
			if (i + 1 == b[p]) {
				pre[p] = cnt;
				p++;
			}
			else cnt++;
		}
		cnt = 0;
		p = m - 1;
		RF0R(i, n - 1) {
			if (i + 1 == b[p]) {
				po[p] = cnt;
				p--;
			}
			else cnt++;
		}
		bool imp = true;
		F0R(i, m) {
			if (pre[i] >= k / 2 && po[i] >= k / 2) imp = false;
		}

		if (imp) cout << "NO\n";
		else cout << "YES\n";
	}
}