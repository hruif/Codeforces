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
int balls[100][2];

int dist(int a, int b) {
	return abs(balls[a][0] - balls[b][0]) + abs(balls[a][1] - balls[b][1]);
}

int main() {
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		F0R(i, n) {
			cin >> balls[i][0] >> balls[i][1];
		}
		bool cando = true;
		F0R(i, n) {
			cando = true;
			F0R(j, n) {
				if (dist(i, j) > k) {
					cando = false;
					break;
				}
			}
			if (cando) break;
		}
		if (cando) cout << 1 << '\n';
		else cout << -1 << '\n';
	}
}