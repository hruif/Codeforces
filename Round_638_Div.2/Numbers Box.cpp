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
#define FOR0(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RFOR0(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
int box[10][10];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ncount = 0;
		int sum = 0;
		int low = -1;
		FOR0(i, n) {
			FOR0(j, m) {
				cin >> box[i][j];
				if (box[i][j] < 0) {
					ncount++;
				}
				sum += abs(box[i][j]);
				if (abs(box[i][j]) < low || low < 0) {
					low = abs(box[i][j]);
				}
			}
		}
		if (ncount % 2 == 1) {
			sum -= low * 2;
		}
		cout << sum << '\n';
	}
}