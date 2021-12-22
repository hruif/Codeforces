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
int a[500000], sa[500000];
vector<int> st;

void set_st(int n) {
	st.clear();
	int sn = 1;
	while (sn < n) sn *= 2;
	st.resize(sn * 2, 0);
}

int find_val(int a, int b) {
	int sn = st.size() / 2;
	a += sn; b += sn;
	int val = 0;
	while (a <= b) {
		if (a % 2 == 1) val += st[a++];
		if (b % 2 == 0) val += st[b--];
		a /= 2; b /= 2;
	}
	return val;
}

void change_val(int k, int x) {
	int sn = st.size() / 2;
	k += sn;
	st[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = st[k * 2] + st[k * 2 + 1];
	}
}

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) sa[i] = a[i];
		sort(sa, sa + n);
		map<int, int> m;
		for (int i = 0; i < n; i++) m[a[i]]++;
		bool non_dist = false;
		for (auto x : m) if (x.second > 1) non_dist = true;
		if (non_dist) cout << "YES\n";
		else {
			set_st(n + 1);
			for (int i = 0; i < n; i++) m[sa[i]] = i;
			for (int i = 0; i < n; i++) a[i] = m[a[i]];
			ll inv = 0;
			for (int i = 0; i < n; i++) {
				inv += find_val(a[i], n);
				change_val(a[i], 1);
			}
			if (inv % 2) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}