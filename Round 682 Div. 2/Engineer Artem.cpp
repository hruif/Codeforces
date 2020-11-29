#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define FOR0(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RFOR0(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
int grid[100][100];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		FOR0(i, n) {
			FOR0(j, m) {
				cin >> grid[i][j];
				int odd = (i + j) % 2;
				if (grid[i][j] % 2 != odd) {
					grid[i][j]++;
				}
				if (j != 0) {
					cout << ' ';
				}
				cout << grid[i][j];
			}
			cout << '\n';
		}

	}
}