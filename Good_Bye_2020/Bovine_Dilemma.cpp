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
int xs[100000];
bool bs[100000];

int main() {
	cin >> t;
	while (t--) {
		memset(bs, false, sizeof(bs));

		int n;
		cin >> n;
		F0R(i, n) cin >> xs[i];
		sort(xs, xs + n);

		int cnt = 0;
		F0R(i, n - 1) {
			FOR(j, i + 1, n) {
				int base = xs[j] - xs[i];
				if (!bs[base]) {
					bs[base] = true;
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}