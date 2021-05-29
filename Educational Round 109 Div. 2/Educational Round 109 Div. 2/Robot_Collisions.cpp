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

int t;
int x[300000];
int ans[300000];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		F0R(i, n) ans[i] = -1;
		vector<pair<pii, int>> e, o;
		F0R(i, n) {
			cin >> x[i];
		}
		F0R(i, n) {
			char d;
			cin >> d;
			int dir = d == 'L' ? -1 : 1;
			if (x[i] % 2) o.push_back({ { x[i], dir }, i });
			else e.push_back({ { x[i], dir }, i });
		}
		set<pii> dists;
		F0R(i, o.size()) {
			int xi = o[i].first.first, dir = o[i].first.second;
			int index = o[i].second;
			if (dir == -1) {
				if (dists.empty()) {
					dists.insert({ -xi + 2, index });
				}
				else {
					int px = (*dists.rbegin()).first;
					int pi = (*dists.rbegin()).second;
					int ex = (xi - px) / 2;
					ans[index] = ex;
					ans[pi] = ex;
					dists.erase(dists.find({ px, pi }));
				}
			}
			else {
				dists.insert({ xi, index });
			}
		}
		for (auto i : dists) {

		}
	}
}