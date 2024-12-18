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

#define MOD 998244353

int t, n;
int l[3];
vector<vector<int>> mat;
int ansmat[1001][1001];

int modn(int a) {
	a = (a - 1 + 100000*n) % n;
	return a+1;
}
int main() {
	cin >> t;
	while (t--) {
		l[0] = 0, l[1] = 1, l[2] = 2;

		int m;
		cin >> n >> m;
		mat.clear();
		mat.resize(n + 1, vector<int>(n + 1));
		F0R(i, n) {
			F0R(j, n) {
				cin >> mat[i+1][j+1];
				mat[i][j];
			}
		}

		int loc[] = { 0, 0, 0 };
		F0R(i, m) {
			char dir;
			cin >> dir;
			switch (dir) {
			case 'R': loc[l[1]]++; break;
			case 'L': loc[l[1]]--; break;
			case 'D': loc[l[0]]++; break;
			case 'U': loc[l[0]]--; break;
			case 'I': {
				int tmp = l[1];
				l[1] = l[2];
				l[2] = tmp;
				break;
			}
			case 'C': {
				int tmp = l[0];
				l[0] = l[2];
				l[2] = tmp;
				break;
			}
			}
		}

		// loc: position of (0,0,0) in the old system
		auto mat2 = mat;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int x = modn(i + loc[0]), y = modn(j + loc[1]), z = modn(mat[i][j] + loc[2]);
				mat2[x][y] = z;
			}
		}
		auto mat3 = mat2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (l[0] == 0) {
					if (l[1] == 1) {
					}
					else if (l[1] == 2) {
						mat3[i][mat2[i][j]] = j;
					}
				}
				else if (l[0] == 1) {
					if (l[1] == 0) {
						mat3[j][i] = mat2[i][j];
					}
					else {
						mat3[j][mat2[i][j]] = i;
					}
				}
				else if (l[0] == 2) {
					if (l[1] == 0) {
						mat3[mat2[i][j]][i] = j;
					}
					else {
						mat3[mat2[i][j]][j] = i;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << mat3[i][j] << " ";
			}
			cout << endl;
		}
	}
}