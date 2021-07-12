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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, cw, ch;
pair<pii, int> e[5000];
int maxE[5000];
int par[5000];

int main() {
	memset(par, -1, sizeof(par));

	cin >> n >> cw >> ch;
	F0R(i, n) cin >> e[i].first.first >> e[i].first.second;
	F0R(i, n) e[i].second = i;
	sort(e, e + n);
	F0R(i, n) {
		if (e[i].first.first > cw && e[i].first.second > ch) {
			maxE[i] = 1;
			RF0R(j, i) {
				if (e[i].first.first > e[j].first.first && e[i].first.second > e[j].first.second) {
					if (maxE[j] + 1 > maxE[i]) {
						maxE[i] = maxE[j] + 1;
						par[i] = j;
					}
				}
			}
		}
	}
	int maxEv = 0, maxEi;
	F0R(i, n) {
		if (maxE[i] > maxEv) {
			maxEv = maxE[i];
			maxEi = i;
		}
	}
	if (maxEv == 0) cout << "0\n";
	else {
		cout << maxEv << '\n';
		vi ans;
		while (maxEi != -1) {
			ans.push_back(e[maxEi].second);
			maxEi = par[maxEi];
		}
		RF0R(i, sz(ans)) cout << ans[i] + 1 << ' ';
		cout << '\n';
	}
}