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
int u[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vll> universities(n, vll());
		vector<vll> upsums(n, vll());
		F0R(i, n) cin >> u[i];
		F0R(i, n) {
			ll s;
			cin >> s;
			universities[u[i] - 1].push_back(s);
		}
		set<int> hasteam;
		F0R(i, n) {
			if (universities[i].empty()) continue;
			hasteam.insert(i);

			sort(all(universities[i]));
			upsums[i].rsz(sz(universities[i]));
			upsums[i][0] = universities[i][0];
			F1R(j, sz(universities[i])) {
				upsums[i][j] = upsums[i][j - 1] + universities[i][j];
			}
		}
		F0R(i, n) {
			int ts = i + 1;
			ll sum = 0;
			vi toerase;
			for (auto x : hasteam) {
				int rem = sz(universities[x]) % ts;
				sum += upsums[x][sz(upsums[x]) - 1];
				if (rem > 0) sum -= upsums[x][rem - 1];
				if (sz(universities[x]) == ts) toerase.push_back(x);
			}
			F0R(i, sz(toerase)) hasteam.erase(hasteam.find(toerase[i]));
			cout << sum << ' ';
		}
		cout << '\n';
	}
}