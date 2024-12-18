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
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		vi lets(26, 0);
		F0R(i, sz(s)) lets[s[i] - 'a']++;
		string ans;
		int first = 0;
		F0R(i, 26) {
			if (lets[i] > 0) {
				ans.clear();
				if (lets[i] > 1) {
					int nc = lets[i] - 2;
					if (sz(s) - lets[i] >= nc) {
						ans.push_back(i + 'a');
						ans.push_back(i + 'a');
						lets[i] -= 2; 
						bool init = false, donedone = false;
						for (int k = i + 1; k < 26; k++) {
							if (init) {
								ans.push_back(k + 'a');
								lets[k]--;
								F0R(j, lets[i]) {
									ans.push_back(i + 'a');
								}
								lets[i] = 0;
							}
							init = true;
						}
						for (int k = i + 1; k < 26; k++) {
							if (init) {
								F0R(j, lets[i]) {
									ans.push_back(i + 'a');
								}
								lets[i] = 0;
							}
							F0R(j, lets[k]) {
								ans.push_back(k + 'a');
								if (lets[i] > 0) {
									ans.push_back(i + 'a');
									lets[i]--;
								}
							}
							init = true;
						}
					}
					else {
						ans.push_back(i + 'a');
						bool nextd = false;
						bool outed = false;
						for (int k = i + 1; k < 26; k++) {
							if (nextd && !outed) {
								for (int k = 0; k < lets[i] - 1; k++) ans.push_back(i + 'a');
								outed = true;
							}
							F0R(j, lets[k]) {
								ans.push_back(k + 'a');
								nextd = true;
							}
						}
						if (!outed) for (int k = 0; k < lets[i] - 1; k++) ans.push_back(i + 'a');
					}
					/*else {
						ans.push_back(i + 'a');
						ans.push_back(i + 'a');
						lets[i]--;
						lets[i]--;
						first = i;

						for (int k = i + 1; k < 26; k++) {
							F0R(j, lets[k]) {
								ans.push_back(k + 'a');
							}
						}
					}*/
				}
				else {
					ans.push_back(i + 'a');
					lets[i]--;
					first = i;

					for (int k = i + 1; k < 26; k++) {
						F0R(j, lets[k]) {
							ans.push_back(k + 'a');
						}
					}
				}
				break;
			}
		}
		cout << ans << '\n';
	}
}