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

int n;

int main() {
	cin >> n;
	vector<bool> b(n, false);
	vector<set<int>> edges(n);
	cout << "? 1\n";
	cout.flush();
	int cnt = -1;
	F0R(i, n) {
		int d;
		cin >> d;
		if (d % 2 == 0) {
			b[i] = true;
			cnt++;
		}
		if (d == 1) edges[0].insert(i);
	}
	int upp = (n - 1) / 2;
	bool ch;
	if (cnt <= upp) {
		ch = true;
	}
	else {
		ch = false;
	}
	FOR(i, 1, n) {
		if (b[i] == ch) {
			cout << "? " << i + 1 << '\n';
			cout.flush();
			F0R(j, n) {
				int d;
				cin >> d;
				if (d == 1) {
					edges[min(i, j)].insert(max(i, j));
				}
			}
		}
	}
	cout << "!\n";
	F0R(i, n) {
		for (auto j : edges[i]) {
			cout << i + 1 << ' ' << j + 1 << '\n';
		}
	}
}