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

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int k[4], xy[4][200000];

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < 4; i++) {
			cin >> k[i];
			for (int j = 0; j < k[i]; j++) {
				cin >> xy[i][j];
			}
		}
		ll ans = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == i) continue;
				for (int l = 0; l < k[j]; l++) {
					ll height, width;
					if (i < 2) {
						width = xy[i][k[i] - 1] - xy[i][0];
						if (j < 2) height = h;
						else {
							if (i == 0) height = xy[j][l];
							else height = h - xy[j][l];
						}
					}
					else {
						height = xy[i][k[i] - 1] - xy[i][0];
						if (j < 2) {
							if (i == 2) width = xy[j][l];
							else width = w - xy[j][l];
						}
						else width = w;
					}
					ans = max(ans, height * width);
				}
			}
		}
		cout << ans << '\n';
	}
}