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

int n, m;
vpii a;
int maxquests[100];
vector<pair<int, pii>> b;

int main() {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	F0R(i, n) {
		cin >> a[i].first >> a[i].second;
	}
	F0R(i, m) {
		cin >> b[i].second.first >> b[i].second.second >> b[i].first;
	}
	sort(b.begin(), b.end());
	RF0R(i, b.size() - 1) {
		int toTower = 1000000000;
		F0R(i, n) {
			toTower = min(toTower, abs(b[i].second.first - a[i].first) + abs(b[i].second.second - a[i].second) + 1);
		}
		maxquests[i] = 1;
		FOR(j, i + 1, b.size()) {
			if (abs(b[i].second.first - b[j].second.first) + abs(b[i].second.second - b[j].second.second) <= abs(b[i].first - b[j].first) ||
				toTower <= abs(b[i].first - b[j].first)) {
				maxquests[i] = max(maxquests[i], maxquests[j] + 1);
			}
		}
	}
	int maxq = 0;
	F0R(i, n) {
		maxq = max(maxq, maxquests[i]);
	}
	cout << maxq << '\n';
}