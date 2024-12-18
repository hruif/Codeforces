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
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int k;
string s, t;

int main() {
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		cin >> s >> t;
		vector<int> chars(26, 0);
		F0R(i, n) {
			chars[s[i] - 'a']++;
			chars[t[i] - 'a']++;
		}

		bool possible = true;
		F0R(i, 26) {
			if (chars[i] & 1) possible = false;
		}
		if (!possible) {
			cout << "No\n";
			continue;
		}

		vpii ans;
		F0R(i, n) {
			if (s[i] == t[i]) continue;

			int char_ind = -1;
			FOR(j, i + 1, n) {
				if (s[i] == s[j]) {
					char_ind = j;
					break;
				}
			}
			if (char_ind != -1) {
				ans.push_back({ char_ind + 1, i + 1 });
				swap(t[i], s[char_ind]);
			}
			else {
				FOR(j, i + 1, n) {
					if (s[i] == t[j]) {
						char_ind = j;
						break;
					}
				}
				ans.push_back({ char_ind + 1, char_ind + 1 });
				ans.push_back({ char_ind + 1, i + 1 });
				swap(s[char_ind], t[char_ind]);
				swap(t[i], s[char_ind]);
			}
		}
		cout << "Yes\n" << sz(ans) << '\n';
		F0R(i, sz(ans)) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
		}
	}
}