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

int q;

bool cangoleft(string s, string t, int sp, int tp) {
	while (sp >= 0 && tp < sz(t)) {
		if (s[sp] != t[tp]) return false;
		sp--;
		tp++;
	}
	return tp == sz(t);
}

bool cangoright(string s, string t, int sp, int tp) {
	while (sp < sz(s) && tp < sz(t)) {
		if (s[sp] != t[tp]) return false;
		if (cangoleft(s, t, sp - 1, tp + 1)) return true;
		sp++;
		tp++;
	}
	return tp == sz(t);
}

int main() {
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s;
		cin >> t;
		bool poss = false;
		F0R(i, sz(s)) {
			if (cangoright(s, t, i, 0)) {
				poss = true;
				break;
			}
		}
		if (poss) cout << "YES\n";
		else cout << "NO\n";
	}
}