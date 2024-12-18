#include <iostream>
#include <fstream>
#include <vector>
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
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
int p[4][2];

int main() {
	cin >> t;
	while (t--) {
		F0R(i, 4) {
			cin >> p[i][0] >> p[i][1];
		}
		int mindist = -1;
		F0R(i, 3) {
			FOR(j, i + 1, 4) {
				int i1, j1;
				F0R(k, 4) {
					if (k != i && k != j) {
						i1 = k;
						break;
					}
				}
				F0R(k, 4) {
					if (k != i && k != j && k != i1) {
						j1 = k;
					}
				}
				int dist = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
				dist += abs(p[i1][0] - p[j1][0]) + abs(p[i1][1] + p[j1][1]);
				if (mindist > dist || mindist == -1) {
					mindist = dist;
				}
			}
		}
		cout << mindist << '\n';
	}
}