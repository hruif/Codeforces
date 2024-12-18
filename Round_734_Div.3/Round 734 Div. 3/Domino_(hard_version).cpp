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

int t;

int main() {
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n % 2) {
			if (k < m / 2) {
				cout << "NO\n";
			}
			else {
				k -= m / 2;
				if (k % 2 == 0) {
					vvi doms(n, vi(m, -1));
					int let = 0;
					cout << "YES\n";
					F0R(i, m / 2) {
						if (i > 0) {
							while (doms[0][i * 2 - 1] == let) {
								let++;
								let %= 26;
							}
						}
						doms[0][i * 2] = let;
						doms[0][i * 2 + 1] = let;
						let++;
					}
					int col = 0;
					while (k > 0) {

					}
				}
				else cout << "NO\n";
			}
		}
		else {
			if (m % 2) {
				int cnt = n * (m - 1) / 2;
				cnt -= k;
				if (cnt % 2 || cnt < 0) cout << "NO\n";
				else cout << "YES\n";
			}
			else {
				if (k % 2) cout << "NO\n";
				else cout << "YES\n";
			}
		}
	}
}