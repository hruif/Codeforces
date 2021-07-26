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

int k, q;
string s;
int a[300000];
int lens[300000];

int main() {
	cin >> k;
	cin >> s;
	reverse(all(s));
	s = "2" + s;
	int len = sz(s);
	F0R(i, len / 2) {
		if (s[len - 1 - i] == '?') a[len - 1 - i] = 2;
		else a[len - 1 - i] = 1;
	}

	RFOR(i, len / 2, 1) {
		int ind = i;
		int sv = a[ind * 2 + 1], bv = a[ind * 2];
		if (s[ind] == '?') a[ind] = sv + bv;
		if (s[ind] == '0') a[ind] = sv;
		if (s[ind] == '1') a[ind] = bv;
	}

	cin >> q;
	while (q--) {
		int p;
		char c;
		cin >> p >> c;
		int ind = len - p;
		s[ind] = c;
		if (ind >= len / 2) {
			if (s[ind] == '?') a[ind] = 2;
			else a[ind] = 1;
		}
		else {
			int sv = a[ind * 2 + 1], bv = a[ind * 2];
			if (s[ind] == '?') a[ind] = sv + bv;
			if (s[ind] == '0') a[ind] = sv;
			if (s[ind] == '1') a[ind] = bv;
		}
		while (ind > 1) {
			ind /= 2;
			int sv = a[ind * 2 + 1], bv = a[ind * 2];
			if (s[ind] == '?') a[ind] = sv + bv;
			if (s[ind] == '0') a[ind] = sv;
			if (s[ind] == '1') a[ind] = bv;
		}
		cout << a[1] << '\n';
	}
}