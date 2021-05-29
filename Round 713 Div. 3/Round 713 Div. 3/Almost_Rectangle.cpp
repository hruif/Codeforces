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
		int n;
		cin >> n;
		vector<vector<char>> field(n, vector<char>(n));
		int x1 = -1, y1, x2, y2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> field[i][j];
				if (field[i][j] == '*') {
					if (x1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}

		if (x1 == x2) {
			if (x1 > 0) {
				x1--;
				x2--;
			}
			else {
				x1++;
				x2++;
			}
		}
		if (y1 == y2) {
			if (y1 > 0) {
				y1--;
				y2--;
			}
			else {
				y1++;
				y2++;
			}
		}
		field[x1][y2] = '*';
		field[x2][y1] = '*';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << field[i][j];
			}
			cout << '\n';
		}
	}
}