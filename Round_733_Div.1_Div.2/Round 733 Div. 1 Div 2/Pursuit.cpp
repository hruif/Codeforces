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
#include <climits>

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
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[100000], b[100000];
int ssuma[100001], ssumb[100001];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		F0R(i, n) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);

		ssuma[n] = 0; ssumb[n] = 0;
		ssuma[n - 1] = a[n - 1];
		ssumb[n - 1] = b[n - 1];
		RF0R(i, n - 1) {
			ssuma[i] = ssuma[i + 1] + a[i];
			ssumb[i] = ssumb[i + 1] + b[i];
		}
		int p = n / 4;
		if (ssuma[p] >= ssumb[p]) cout << "0\n";
		else {
			int toadd = 0;
			int cur = 0;
			while (ssuma[p] + toadd < ssumb[max(0, p - cur)]) {
				toadd += 100;
				n++;
				cur++;
				p = n / 4;
			}
			cout << toadd / 100 << '\n';
		}
	}
}