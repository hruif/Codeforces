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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef LOCAL_DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#else
#define fin cin
#define fout cout
#endif

int t;
int h[100];

int main() {
	fin >> t;
	while (t--) {
		int n, k;
		fin >> n >> k;
		F0R(i, n) fin >> h[i];

		int bs = 0;
		int ans = -2;
		F0R(i, n - 1) {
			if (h[i] >= h[i + 1]) continue;
			if (i > 0 && h[i - 1] < h[i + 1]) {
				bs += h[i - 1] - h[i] + 1;
				h[i] = h[i - 1] + 1;
			}
			else {
				bs += h[i + 1] - h[i];
				h[i] = h[i + 1];
			}
			if (bs >= k) {
				ans = i;
				break;
			}
			i = -1;
		}

		fout << ans + 1 << '\n';
	}
}