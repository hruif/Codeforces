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

int t;
str a[10];

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		F0R(i, n) cin >> a[i];
		bool ispossible = true;
		pii p = { -1, -1 };
		F0R(i, n) {
			FOR(j, i + 1, n) {
				int cnt = 0;
				F0R(k, m) {
					if (a[i][k] != a[j][k]) cnt++;
				}
				if (cnt > 2) ispossible = false;
				if (cnt == 2) p = { i, j };
			}
		}
		if (!ispossible) cout << "-1\n";
		else {
			if (p.first == -1) cout << a[0] << '\n';
			else {
				vector<str> possible;
				pii dif = { -1, -1 };
				F0R(i, m) {
					if (a[p.first][i] != a[p.second][i]) {
						if (dif.first == -1) dif.first = i;
						else dif.second = i;
					}
				}
				possible.push_back(a[p.first]);
				possible.push_back(a[p.first]);
				possible[0][dif.first] = a[p.second][dif.first];
				possible[1][dif.second] = a[p.second][dif.second];
				F0R(i, n) {
					F0R(j, sz(possible)) {
						int cnt = 0;
						F0R(k, m) {
							if (a[i][k] != possible[j][k]) cnt++;
						}
						if (cnt > 1) {
							possible.erase(possible.begin() + j--);
						}
					}
				}
				if (sz(possible) > 0) {
					cout << possible[0] << '\n';
				}
				else cout << "-1\n";
			}
		}
	}
}