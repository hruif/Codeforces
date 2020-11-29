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
int a[30000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 0 << '\n';
		}
		else if (n == 2) {
			cout << 1 << '\n';
		}
		else if (n == 3) {
			cout << 2 << '\n';
		}
		else if (n % 2 == 0) {
			cout << 2 << '\n';
		}
		else {
			cout << 3 << '\n';
		}
	}
}