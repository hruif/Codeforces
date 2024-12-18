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
ll a[200001];
vll scores;

int main() {
	cin >> t;
	while (t--) {
		scores.clear();

		ll n;
		cin >> n;
		scores.resize(n + 1, -1);
		F0R(i, n) cin >> a[i + 1];
		RF0R(i, n - 1) {
			scores[i + 1] = a[i + 1];
			if (i + 1 + a[i + 1] <= n) scores[i + 1] += scores[i + 1 + a[i + 1]];
		}
		ll maxs = 0;
		F0R(i, n) {
			if (scores[i + 1] > maxs) maxs = scores[i + 1];
		}

		cout << maxs << '\n';
	}
}