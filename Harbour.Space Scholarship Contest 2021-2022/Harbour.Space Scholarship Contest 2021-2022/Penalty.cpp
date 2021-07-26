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
		string s;
		cin >> s;
		int s1 = 0, s2 = 0;
		int rem1 = 5, rem2 = 5;
		int q1 = 0, q2 = 0;
		int ans = 10;
		F0R(i, 10) {
			if (i % 2 == 0) {
				if (s[i] == '?') q1++;
				if (s[i] == '1') s1++;
				rem1--;
				if (s1 + q1 > s2 + rem2) {
					ans = i + 1;
					break;
				}
				if (s1 + rem1 < s2 + q2) {
					ans = i + 1;
					break;
				}
			}
			else {
				if (s[i] == '?') q2++;
				if (s[i] == '1') s2++;
				rem2--;
				if (s2 + q2 > s1 + rem1) {
					ans = i + 1;
					break;
				}
				if (s2 + rem2 < s1 + q1) {
					ans = i + 1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}