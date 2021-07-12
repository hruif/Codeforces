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

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		bool r = false, n1 = false, c = false, n2 = false;
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == 'R') r = true;
			if (r && s[i] >= '0' && s[i] <= '9') n1 = true;
			if (n1 && s[i] == 'C') c = true;
			if (c && s[i] >= '0' && s[i] <= '9') n2 = true;
		}
		if (n2) {
			int cp;
			ll fn = 0, sn = 0;
			for (int i = 1; i < sz(s); i++) {
				if (s[i] == 'C') {
					cp = i;
					break;
				}
				else {
					sn *= 10;
					sn += s[i] - '0';
				}
			}
			for (int i = cp + 1; i < sz(s); i++) {
				fn *= 10;
				fn += s[i] - '0';
			}
			vc lets;
			while (fn > 0) {
				if (fn % 26 == 0) {
					lets.push_back('Z');
					fn -= 26;
				}
				else {
					lets.push_back(fn % 26 - 1 + 'A');
				}
				fn /= 26;
			}
			str ans;
			RF0R(i, sz(lets)) ans.push_back(lets[i]);
			cout << ans << sn << '\n';
		}
		else {
			ll fn = 0, sn = 0;
			int np;
			for (int i = 0; i < sz(s); i++) {
				if (s[i] >= '0' && s[i] <= '9') {
					np = i;
					break;
				}
				fn *= 26;
				fn += s[i] - 'A' + 1;
			}
			for (int i = np; i < sz(s); i++) {
				sn *= 10;
				sn += s[i] - '0';
			}
			cout << 'R' << sn << 'C' << fn << '\n';
		}
	}
}