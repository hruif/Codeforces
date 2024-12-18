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

#define MOD (ll)(998244353)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
string s;

int main() {
	fast_cin();

	cin >> n;
	string s;
	int config = 0;
	bool valid = true;
	long long ans = 1;
	for (int i = 0; i < n * 2; i += 2) {
		int l = i, r = i + 1;
		int nl = (i + 2) % n, nr = (i + 3) % n;
		if (s[l] != '?' || s[nr] != '?') {
			if (s[l] == s[nr]) valid = false;
			if (s[l] != '?') {
				if (s[l] == 'W') s[nr] = 'B';
				else s[nr] = 'W';
			}
			else {
				if (s[nr] == 'W') s[l] = 'B';
				else s[l] = 'W';
			}
		}
		else {
			ans *= 2;
		}
	}
	if (!valid) cout << "0\n";
	else cout << ans << '\n';
}