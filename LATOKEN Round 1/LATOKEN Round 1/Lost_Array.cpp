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
#include <map>
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

int n, k;

int main() {
	cin >> n >> k;
	bool possible = true;
	if ((n & 1) && !(k & 1)) {
		possible = false;
	}
	int sum = 0;
	int d = 0;
	while (possible) {
		d++;
		if (d > 500) {
			possible = false;
			break;
		}
		if (d * k < n) continue;
		if (((d * k) & 1) != (n & 1)) continue;
		int extra_pairs = (d * k - n) / 2;
		if (1 + (extra_pairs + n - 1) / n * 2 > d) continue;
		vector<pair<int, int>> toGive(n);
		for (int i = 0; i < n; i++) {
			toGive[i] = { 1 + (extra_pairs + i) / n * 2, i };
		}
		while (d--) {
			nth_element(toGive.begin(), toGive.end() - k, toGive.end());
			cout << "?";
			for (int i = n - k; i < n; i++) {
				cout << " " << toGive[i].second + 1;
				toGive[i].first--;
			}
			cout << '\n' << flush;
			int x;
			cin >> x;
			sum ^= x;
		}
		cout << "! " << sum << '\n' << flush;
		break;
	}
	if (!possible) cout << "-1\n" << flush;
}