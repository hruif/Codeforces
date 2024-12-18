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

int t;
int l[3];
int mat[1000][1000];
int ansmat[1000][1000];

int main() {
	cin >> t;
	while (t--) {
		l[0] = 0, l[1] = 1, l[2] = 2;

		int n, m;
		cin >> n >> m;
		F0R(i, n) {
			F0R(j, n) {
				cin >> mat[i][j];
				mat[i][j]--;
			}
		}

		int move[] = { 0, 0, 0 };
		F0R(i, m) {
			char dir;
			cin >> dir;
			switch (dir) {
			case 'R': move[1]--; break;
			case 'L': move[1]++; break;
			case 'D': move[0]--; break;
			case 'U': move[0]++; break;
			case 'I': {
				int tmp = move[1];
				move[1] = move[2];
				move[2] = tmp;
				tmp = l[1];
				l[1] = l[2];
				l[2] = tmp;
				break;
			}
			case 'C': {
				int tmp = move[0];
				move[0] = move[2];
				move[2] = tmp;
				tmp = l[0];
				l[0] = l[2];
				l[2] = tmp;
				break;
			}
			}
		}

		F0R(i, n) {
			F0R(j, n) {
				int x, y, z;
				F0R(k, 3) {
					if (l[k] == 0) x = k;
					if (l[k] == 1) y = k;
					if (l[k] == 2) z = k;
				}

				int vs[3];
				vs[x] = (n + ((i + move[x]) % n)) % n;
				vs[y] = (n + ((j + move[y]) % n)) % n;
				vs[z] = (n + ((mat[i][j] + move[z]) % n)) % n;
				ansmat[vs[0]][vs[1]] = vs[2];
			}
		}

		F0R(i, n) {
			F0R(j, n) {
				if (j != 0) cout << ' ';
				cout << ansmat[i][j] + 1;
			}
			cout << '\n';
		}
	}
}