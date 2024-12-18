#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b);
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, k, m;
vi a;

int main() {
	cin >> n >> k >> m;
	int om = m;
	a.rsz(n);
	F0R(i, n) {
		cin >> a[i];
	}
	sort(all(a));
	ll sum = 0;
	vi b(sz(a));
	F0R(i, n) {
		sum += a[i];
		b[i] = a[i];
	}
	int last = n;
	RF0R(i, n) {
		F0R(j, k) {
			if (m == 0) break;
			last = i;
			b[i]++;
			sum++;
			m--;
		}
	}
	long double avg = sum / (long double)(n);
	F0R(i, min(om, sz(b) - 1)) {
		long double navg = (sum - b[i] - (b[i] == a[i] ? 1 : 0)) / (long double)(n - 1);
		if (navg > avg) {
			avg = navg;
			sum -= b[i];
			if (b[i] == a[i]) sum--;
			b[last]--;
			if (b[last] == a[last]) last++;
			n--;
			m++;
		}
		else break;
	}
	cout << setprecision(20) << avg << '\n';
}