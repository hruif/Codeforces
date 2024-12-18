#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>

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

#define MOD 998244353

int t;
char grid[300][300];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k = 0;
		F0R(i, n) {
			F0R(j, n) {
				cin >> grid[i][j];
				if (grid[i][j] != '.') k++;
			}
		}

		bool found = false;
		F0R(d, 3) {
			int cnt = 0;
			F0R(i, n) {
				F0R(j, n) {
					if (grid[i][j] == '.') continue;
					if ((i + j) % 3 != d) continue;

					if (grid[i][j] == 'X') grid[i][j] = 'O';
					cnt++;
				}
			}
			int tcnt = cnt;
			F0R(d2, 3) {
				if (d2 == d) continue;
				cnt = tcnt;
				F0R(i, n) {
					F0R(j, n) {
						if (grid[i][j] == '.') continue;
						if ((i + j) % 3 != d2) continue;

						if (grid[i][j] == 'O') grid[i][j] = 'X';
						cnt++;
					}
				}

				if (cnt <= k / 3) {
					bool win = false;
					F0R(i, n) {
						F0R(j, n) {
							char c = grid[i][j];

							if (c == '.') continue;
							if (i > 0 && i < n - 1) {
								if (grid[i - 1][j] == c && grid[i + 1][j] == c) {
									win = true;
									break;
								}
							}
							if (j > 0 && j < n - 1) {
								if (grid[i][j - 1] == c && grid[i][j + 1] == c) {
									win = true;
									break;
								}
							}
						}
					}
					if (!win) {
						found = true;
						break;
					}
				}

				F0R(i, n) {
					F0R(j, n) {
						if (grid[i][j] == '.') continue;
						if ((i + j) % 3 != d2) continue;

						if (grid[i][j] == 'X') grid[i][j] = 'O';
					}
				}
			}
			if (found) break;
			F0R(i, n) {
				F0R(j, n) {
					if (grid[i][j] == '.') continue;
					if ((i + j) % 3 != d) continue;

					if (grid[i][j] == 'O') grid[i][j] = 'X';
					cnt++;
				}
			}
		}
		F0R(i, n) {
			F0R(j, n) cout << grid[i][j];
			cout << '\n';
		}
	}
}