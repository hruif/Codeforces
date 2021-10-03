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
		int n;
		cin >> n;
		string s[3];
		cin >> s[0] >> s[1] >> s[2];
		int freq[3][2];
		F0R(i, 3) {
			int o = 0, z = 0;
			F0R(j, 2 * n) {
				if (s[i][j] == '0') z++;
				else o++;
			}
			if (z >= n) {
				freq[i][0] = 0;
				freq[i][1] = z;
			}
			else {
				freq[i][0] = 1;
				freq[i][1] = o;
			}
		}
		string ans = "NO\n";
		F0R(i, 3) {
			F0R(j, 3) {
				if (i == j) continue;
				if (freq[i][0] == freq[j][0]) {
					ans.clear();
					if (freq[i][1] < freq[j][1]) swap(i, j);
					int p = 0;
					F0R(k, 2 * n) {
						if (s[i][k] == freq[i][0] + '0') {
							if (p < 2 * n && s[j][p] == freq[i][0] + '0') p++;
							else {
								while (p < n * 2 && s[j][p] != freq[i][0] + '0') {
									ans.push_back(s[j][p++]);
								}
								p++;
							}
						}
						else {
							if (p < 2 * n && s[i][k] == s[j][p]) p++;
						}
						ans.push_back(s[i][k]);
					}
					while (p < 2 * n) ans.push_back(s[j][p++]);
					break;
				}
			}
			if (ans != "NO\n") break;
		}
		cout << ans << '\n';
	}
}