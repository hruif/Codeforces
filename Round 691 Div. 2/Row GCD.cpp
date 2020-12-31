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

int n, m;
ll a[200000];
ll b[200000];

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cin >> n >> m;
	F0R(i, n) cin >> a[i];
	F0R(i, m) cin >> b[i];

	ll G = 0;
	FOR(i, 1, n) G = gcd(G, a[i] - a[0]);
	F0R(i, m) {
		if (i != 0) cout << ' ';
		cout << abs(gcd(G, a[0] + b[i]));
	}
	cout << '\n';
}