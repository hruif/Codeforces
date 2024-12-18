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

int T;
vi opp;

bool notval(int h, int m, int hv, int mv) {
	int nhv = opp[mv % 10] * 10 + opp[mv / 10];
	int nmv = opp[hv % 10] * 10 + opp[hv / 10];
	return (nhv >= h || nmv >= m);
}

int main() {
	opp.rsz(10);
	opp[0] = 0;
	opp[1] = 1;
	opp[2] = 5;
	opp[5] = 2;
	opp[8] = 8;
	vb vd(10, true);
	vd[3] = false;
	vd[4] = false;
	vd[6] = false;
	vd[7] = false;
	vd[9] = false;

	cin >> T;
	while (T--) {
		int h, m;
		cin >> h >> m;
		int hv, mv;
		char c;
		cin >> hv >> c >> mv;
		while (!vd[hv / 10] || !vd[hv % 10] || !vd[mv / 10] || !vd[mv % 10] || notval(h, m, hv, mv)) {
			mv++;
			if (mv == m) {
				mv = 0;
				hv++;
			}
			if (hv == h) hv = 0;
		}
		if (hv < 10) cout << 0;
		cout << hv << ':';
		if (mv < 10) cout << 0;
		cout << mv << '\n';
	}
}