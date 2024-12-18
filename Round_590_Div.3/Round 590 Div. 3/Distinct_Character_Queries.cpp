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
#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)\

string s;
vb sts[26];

void setst(vb& st, int n) {
	int sn = 1;
	while (sn < n) sn *= 2;
	st.resize(sn * 2, false);
}

void changeVal(vb& st, int k, bool x) {
	int sn = sz(st) / 2;
	k += sn;
	st[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = st[k * 2 + 1] || st[k * 2];
	}
}

bool findVal(vb& st, int a, int b) {
	int sn = sz(st) / 2;
	a += sn; b += sn;
	bool val = false;
	while (a <= b) {
		if (a % 2 == 1) val = st[a++] || val;
		if (b % 2 == 0) val = st[b--] || val;
		a /= 2; b /= 2;
	}
	return val;
}

int main() {
	cin >> s;
	F0R(i, 26) setst(sts[i], sz(s));
	F0R(i, sz(s)) {
		changeVal(sts[s[i] - 'a'], i, true);
	}

	int q;
	cin >> q;
	F0R(i, q) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			changeVal(sts[s[pos] - 'a'], pos, false);
			changeVal(sts[c - 'a'], pos, true);
			s[pos] = c;
		}
		else {
			int l, r;
			cin >> l >> r;
			l--; r--;
			int cnt = 0;
			F0R(i, 26) {
				if (findVal(sts[i], l, r)) cnt++;
			}
			cout << cnt << '\n';
		}
	}
}