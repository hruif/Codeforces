#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
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

#define MOD 1

int t;
int r[100], b[100];
int rpsum[101], bpsum[101];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		F0R(i, n) cin >> r[i];
		cin >> m;
		F0R(i, m) cin >> b[i];
		rpsum[0] = r[0];
		bpsum[0] = b[0];
		rpsum[n] = 0;
		bpsum[m] = 0;
		FOR(i, 1, n) rpsum[i] = rpsum[i - 1] + r[i];
		FOR(i, 1, m) bpsum[i] = bpsum[i - 1] + b[i];

		int maxsum = 0;
		F0R(i, n + 1) {
			F0R(j, m + 1) {
				maxsum = max(maxsum, rpsum[i] + bpsum[j]);
			}
		}

		cout << maxsum << '\n';
	}
}