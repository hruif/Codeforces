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

int t;
char grid[50][50];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		F0R(i, n) {
			F0R(j, m) {
				cin >> grid[i][j];
			}
		}
		bool possible = true;
		char last = grid[0][0];
		F0R(i, n) {
			F0R(j, m) {
				if ((i + j) % 2 == 0) {
					if (grid[i][j] == '.') continue;
					if (last == '.') last = grid[i][j];
					else if (grid[i][j] != last) possible = false;
				}
			}
		}
		char evench = last;
		last = '.';
		F0R(i, n) {
			F0R(j, m) {
				if ((i + j) % 2 == 1) {
					if (grid[i][j] == '.') continue;
					if (last == '.') last = grid[i][j];
					if (grid[i][j] != last) possible = false;
				}
			}
		}
		bool ea = evench == '.', oa = last == '.';
		if (ea && oa) {
			evench = 'W';
			last = 'R';
		}
		else if (ea) {
			if (last == 'W') evench = 'R';
			else evench = 'W';
		}
		else if (oa) {
			if (evench == 'W') last = 'R';
			else last = 'W';
		}
		if (evench == last) possible = false;
		if (possible) {
			cout << "YES\n";
			F0R(i, n) {
				F0R(j, m) {
					if ((i + j) % 2 == 0) grid[i][j] = evench;
					else grid[i][j] = last;
					cout << grid[i][j];
				}
				cout << '\n';
			}
		}
		else {
			cout << "NO\n";
		}
	}
}