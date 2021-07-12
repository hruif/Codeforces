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

struct Prob {
	double c, m, p;
	int turn;
	double bp;
	Prob() {}
	Prob(double c, double m, double p, int turn, double bp) {
		this->c = c;
		this->m = m;
		this->p = p;
		this->turn = turn;
		this->bp = bp;
	}
};

int t;
double v;

int main() {
	cin >> t;
	while (t--) {
		double c, m, p;
		cin >> c >> m >> p >> v;
		c *= 10000, m *= 10000, p *= 10000, v *= 10000;
		queue<Prob> q;
		q.push(Prob(c, m, p, 1, 1));
		double ans = 0;
		while (!q.empty()) {
			Prob cur = q.front();
			q.pop();
			double cc = cur.c, cm = cur.m, cp = cur.p, cbp = cur.bp;
			int ct = cur.turn;
			ans += cur.p * cur.bp * ct / 10000;
			if (cur.c != 0) {
				double nc = max(cc - v, 0.0), cdif = cc - nc;
				if (cm != 0) q.push(Prob(nc, cm + cdif / 2, cp + cdif / 2, ct + 1, cbp * cc / 10000));
				else q.push(Prob(nc, 0, cp + cdif, ct + 1, cbp * cc / 10000));
			}
			if (cur.m != 0) {
				double nm = max(cm - v, 0.0), mdif = cm - nm;
				if (cc != 0) q.push(Prob(cc + mdif / 2, nm, cp + mdif / 2, ct + 1, cbp * cm / 10000));
				else q.push(Prob(0, nm, cp + mdif, ct + 1, cbp * cm / 10000));
			}
		}

		cout << setprecision(12) << ans << '\n';
	}
}