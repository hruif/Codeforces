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

int main() {
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> lcs(n, 0);
		vector<int> rcs(n, 0);
		F0R(i, l) {
			int c;
			cin >> c;
			lcs[c - 1]++;
		}
		F0R(i, r) {
			int c;
			cin >> c;
			rcs[c - 1]++;
		}
		int cost = 0;
		F0R(i, n) {
			while (lcs[i] > 0 && rcs[i] > 0) {
				lcs[i]--;
				rcs[i]--;
				r--;
				l--;
			}
			while (lcs[i] >= 2 && l > r) {
				lcs[i] -= 2;
				cost += 1;
				l -= 2;
			}
			while (rcs[i] >= 2 && r > l) {
				rcs[i] -= 2;
				cost += 1;
				r -= 2;
			}
		}
		cost += abs(r - l) / 2;
		cost += (r + l) / 2;
		cout << cost << '\n';
	}
}