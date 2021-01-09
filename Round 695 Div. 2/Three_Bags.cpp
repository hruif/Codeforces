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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n1, n2, n3;
ll a[300000];

int main() {
	fast_cin();

	cin >> n1 >> n2 >> n3;
	F0R(i, n1 + n2 + n3) cin >> a[i];
	ll sum = 0;
	F0R(i, n1 + n2 + n3) sum += a[i];
	sort(a, a + n1);
	sort(a + n1, a + n2);
	sort(a + n1 + n2, a + n1 + n2 + n3);

	ll n1s = 0, n2s = 0, n3s = 0;
	F0R(i, n1) n1s += a[i];
	F0R(i, n2) n2s += a[i + n1];
	F0R(i, n3) n3s += a[i + n1 + n2];

	cout << max(sum - min(n1s - a[0], a[n1]) - (a[0] * 2), 
		max(sum - min(n2s - a[n1], a[n1 + n2]) (a[n1] * 2), sum - min(n3s - a[n1 + n2], a[0]) - (a[n1 + n2] * 2))) << '\n';
}