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
string s;

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		ll n, k, x;
		cin >> n >> k >> x;
		k;
		cin >> s;
		vector<ll> asts;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a') continue;
			for (int j = i + 1; j <= s.size(); j++) {
				if (j == s.size() || s[j] == 'a') {
					asts.push_back(j - i);
					i = j - 1;
					break;
				}
			}
		}
		reverse(all(asts));
		vector<ll> cnts;
		x--;
		for (int i = 0; i < asts.size(); i++) {
			ll cur = asts[i] * k;
			cnts.push_back(x % (cur + 1));
			x /= (cur + 1);
		}
		reverse(all(cnts));
		int cur = 0;
		string ans;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a') ans.push_back('a');
			else {
				for (int j = 0; j < cnts[cur]; j++) ans.push_back('b');
				cur++;
				for (int j = i + 1; j <= s.size(); j++) {
					if (j == s.size() || s[j] == 'a') {
						i = j - 1;
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}