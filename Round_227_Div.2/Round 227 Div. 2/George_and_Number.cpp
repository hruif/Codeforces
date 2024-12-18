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

str p;

int find_max_size(str s) {
	int n = sz(s);
	int ind = 0;
	while (ind < n && (ind < (n + 1) / 2 || s[ind] == '0')) ind++;
	if (ind == (n + 1) / 2 && n % 2 == 0) {
		if (s.substr(0, ind) < s.substr(ind, n - ind)) ind++;
		while (ind < n && s[ind] == '0') ind++;
	}
	if (ind == n) {
		//cout << s << '\n';
		//cout << 1 << '\n' << '\n';
		return 1;
	}
	int cnt = 0;
	FOR(i, ind, n) {
		while (i < n && s[i] == '0') i++;
		if (i < n) cnt++;
	}
	int ans = find_max_size(s.substr(0, ind)) + cnt;
	/*cout << s << '\n';*/
	//cout << ans << '\n';
	return ans;
}

int main() {
	cin >> p;
	cout << find_max_size(p) << '\n';
}