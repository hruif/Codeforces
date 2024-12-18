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

int t;
int b[200000];
int sb[200000];
set<int> s;
map<int, int> m;
vi st;

void change_val(int k, int x) {
	int sn = st.size() / 2;

	k += sn;
	st[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = st[k * 2] + st[k * 2 + 1];
	}
}

int find_val(int a, int b) {
	int sn = st.size() / 2;

	a += sn; b += sn;
	int sum = 0;
	while (a <= b) {
		if (a % 2 == 1) sum += st[a++];
		if (b % 2 == 0) sum += st[b--];
		a /= 2; b /= 2;
	}
	return sum;
}

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> b[i];
		F0R(i, n) sb[i] = b[i];
		int maxv = 0;
		{
			sort(sb, sb + n);
			auto it = sb;
			int v = 0;
			while (it < sb + n) {
				m[*it] = v++;
				it = ub(sb, sb + n, *it);
			}
			maxv = v;
			F0R(i, n) b[i] = m[b[i]];
		}
		st.clear();
		int sn = 1;
		while (sn < maxv) sn *= 2;
		st.rsz(sn * 2, 0);


		bool poss = true;
		s.clear();
		F0R(i, n - 1) {
			int curv = b[i];
			int nextv = b[i + 1];
			int sv = min(curv, nextv), bv = max(curv, nextv);
			if (find_val(sv + 1, bv - 1) > 0) {
				poss = false;
				break;
			}
			change_val(curv, 1);
		}
		if (poss) cout << "YES\n";
		else cout << "NO\n";
	}
}