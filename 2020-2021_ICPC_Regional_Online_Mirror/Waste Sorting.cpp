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
int cs[3];
int as[5];

int main() {
	cin >> t;
	while (t--) {
		cin >> cs[0] >> cs[1] >> cs[2];
		cin >> as[0] >> as[1] >> as[2] >> as[3] >> as[4];
		cs[0] -= as[0];
		cs[1] -= as[1];
		cs[2] -= as[2];
		if (cs[0] < 0 || cs[1] < 0 || cs[2] < 0) {
			cout << "NO\n";
			continue;
		}
		as[3] -= min(cs[0], as[3]);
		as[4] -= min(cs[1], as[4]);
		cs[2] -= as[3] + as[4];
		if (cs[2] < 0) cout << "NO\n";
		else cout << "YES\n";
	}
}