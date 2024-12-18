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
char s[1000];

int main() {
	cin >> t;
	while (t--) {
		int n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h >> s;
		int z = 0, o = 0;
		FOR0(i, n) {
			if (s[i] == '0') {
				z++;
			}
			else {
				o++;
			}
		}
		int zs = o * h + n * c0;
		int os = z * h + n * c1;
		cout << min(min(zs, os), z * c0 + o * c1) << '\n';
	}
}